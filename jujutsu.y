/* ================================================================== */
/*  jujutsu.y — Bison parser for JujutsuLang                           */
/*  Phase 2: Syntax Analysis (Parser)                                 */
/*                                                                    */
/*  Build with Flex:                                                  */
/*      bison -d jujutsu.y                                            */
/*      flex -o lex.yy.c jujutsu.l                                    */
/*      g++ -x c++ -o jujutsu jujutsu.tab.c lex.yy.c -lfl             */
/* ================================================================== */

%code top {
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
}

%code provides {
    #define YY_DECL int yylex(void)
    extern int yylex(void);
    extern FILE *yyout;
    extern int line_number;
}

%{
#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <algorithm>
#include <regex>
#include <unordered_map>
#include <set>
using namespace std;

/* ---- Symbol Table for Variables ---- */
map<string, double> variables;
map<string, int> var_types;  // 0=int, 1=float, 2=double, 3=char, 4=void

struct SymbolInfo {
    int type;
    double value;
    bool initialized;
};
map<string, SymbolInfo> symbol_table;

/* ---- Intermediate Representation (IR) ---- */
struct Quad {
    string op;
    string arg1;
    string arg2;
    string result;
};
vector<Quad> ir;
int temp_counter = 0;

/* ---- Function Table ---- */
struct FunctionDef {
    vector<pair<string, int>> params;  // (name, type)
    int body_line;  // Line where function body starts
    bool has_return;
    double return_value;
};
map<string, FunctionDef> functions;

/* ---- Execution Control Flow ---- */
bool break_flag = false;
bool continue_flag = false;
double return_value = 0;
bool return_flag = false;
int function_depth = 0;
int current_decl_type = 0;

/* ---- Execution Context (for control-flow correctness in semantic actions) ---- */
int execution_enabled = 1;
vector<int> exec_stack;
vector<int> if_cond_stack;
vector<map<string, double>> variables_snapshots;
vector<map<string, int>> var_types_snapshots;
vector<map<string, SymbolInfo>> symbol_table_snapshots;
vector<vector<Quad>> ir_snapshots;
vector<int> temp_counter_snapshots;
vector<int> return_flag_snapshots;
vector<double> return_value_snapshots;
string input_source_path;

/* ---- Forward Declarations ---- */
void yyerror(const char *s);
double eval_expression(int type, double value);

string type_to_string(int t);
string format_num(double v);
string new_temp();
void emit_ir(const string &op, const string &arg1, const string &arg2, const string &result);
void write_ir_file(const string &path);
void write_c_code(const string &path);
void write_symbol_table_file(const string &path);
void declare_symbol(const string &name, int type, double value, bool initialized);
bool symbol_exists(const string &name);
bool is_integer_value(double v);
double coerce_to_type(int target_type, double value, const string &name, const string &context);
double assign_typed_value(const string &name, double raw_value, const string &context);
bool try_read_scan_input(const string &name, double &input_value);

extern FILE *yyin, *yyout;
extern int line_number;

%}

/* ================================================================== */
/*  Token and Type Declarations                                       */
/* ================================================================== */

%union {
    int ival;
    double fval;
    char cval;
    char *sval;
}

/* Keywords */
%token KW_INT KW_FLOAT KW_DOUBLE KW_CHAR KW_VOID
%token KW_IF KW_ELSE KW_SWITCH KW_CASE KW_FOR KW_WHILE KW_DO
%token KW_BREAK KW_CONTINUE KW_RETURN
%token KW_STRUCT KW_TYPEDEF KW_ENUM
%token KW_CONST KW_STATIC KW_EXTERN KW_SIZEOF KW_GOTO KW_MAIN
%token KW_UNION KW_VOLATILE KW_REGISTER KW_SIGNED KW_UNSIGNED
%token KW_BREAKPOINT
%token KW_PRINTF KW_SCANF

/* Operators */
%token OP_ADD OP_DRAIN OP_MUL OP_DIV OP_MOD
%token OP_ASSIGN OP_EQ OP_NEQ OP_LT OP_GT OP_LTE OP_GTE
%token OP_AND OP_OR OP_NOT OP_INC

/* Literals and Identifiers */
%token <ival> LIT_INT
%token <fval> LIT_FLOAT
%token <cval> LIT_CHAR
%token <sval> LIT_STRING IDENTIFIER

/* Type declarations for non-terminals */
%type <ival> type
%type <ival> if_else_part
%type <fval> expression assignment_expr logical_or_expr logical_and_expr
%type <fval> equality_expr relational_expr additive_expr multiplicative_expr
%type <fval> unary_expr postfix_expr primary_expr

/* Punctuation */
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA DOT COLON ARROW AMPERSAND HASH

/* ================================================================== */
/*  Precedence and Associativity                                      */
/* ================================================================== */

%left OP_OR
%left OP_AND
%left OP_EQ OP_NEQ
%left OP_LT OP_GT OP_LTE OP_GTE
%left OP_ADD OP_DRAIN
%left OP_MUL OP_DIV OP_MOD
%nonassoc LOWER_THAN_ELSE
%nonassoc KW_ELSE
%right OP_NOT OP_INC
%right OP_ASSIGN
%expect 2

/* ================================================================== */
/*  Grammar Rules                                                     */
/* ================================================================== */

%%

program:
    /* empty */
    | program declaration
    | program statement
    | program function_def
    ;

/* ---- Declarations ---- */
declaration:
    type declarator_list SEMICOLON
    | KW_STRUCT IDENTIFIER LBRACE declaration_list RBRACE SEMICOLON
    {
        fprintf(yyout, "[DECL] Struct declared: %s\n", $2);
    }
    ;

declarator_list:
    declarator
    | declarator_list COMMA declarator
    ;

declarator:
    IDENTIFIER
    {
        if (current_decl_type == 4) {
            fprintf(stderr, "[SEMANTIC ERROR] Variable '%s' cannot have type void at line %d\n", $1, line_number);
        } else if (execution_enabled) {
            variables[$1] = 0;
            var_types[$1] = current_decl_type;
            declare_symbol($1, current_decl_type, 0, false);
            emit_ir("DECL", type_to_string(current_decl_type), "", $1);
            fprintf(yyout, "[DECL] Variable '%s' declared (initial value: 0)\n", $1);
        }
    }
    | IDENTIFIER OP_ASSIGN expression
    {
        if (current_decl_type == 4) {
            fprintf(stderr, "[SEMANTIC ERROR] Variable '%s' cannot have type void at line %d\n", $1, line_number);
        } else if (execution_enabled) {
            double typed_value = coerce_to_type(current_decl_type, $3, $1, "declaration");
            variables[$1] = typed_value;
            var_types[$1] = current_decl_type;
            declare_symbol($1, current_decl_type, typed_value, true);
            emit_ir("DECL", type_to_string(current_decl_type), "", $1);
            emit_ir("ASSIGN", format_num(typed_value), "", $1);
            fprintf(yyout, "[DECL] Variable '%s' declared with initial value: %g\n", $1, typed_value);
        }
    }
    ;

declaration_list:
    declaration
    | declaration_list declaration
    ;

type:
    KW_INT       { $$ = 0; current_decl_type = $$; }
    | KW_FLOAT   { $$ = 1; current_decl_type = $$; }
    | KW_DOUBLE  { $$ = 2; current_decl_type = $$; }
    | KW_CHAR    { $$ = 3; current_decl_type = $$; }
    | KW_VOID    { $$ = 4; current_decl_type = $$; }
    ;

/* ---- Statements ---- */
statement:
    expression_statement
    | compound_statement
    | io_statement
    | if_statement
    | switch_statement
    | loop_statement
    | return_statement
    | break_statement
    | continue_statement
    ;

io_statement:
    KW_PRINTF LPAREN LIT_STRING RPAREN SEMICOLON
    {
        if (execution_enabled) {
            emit_ir("PRINT_STR", $3, "", "");
            fprintf(yyout, "[PRINT] %s\n", $3);
        }
    }
    | KW_PRINTF LPAREN IDENTIFIER RPAREN SEMICOLON
    {
        if (execution_enabled) {
            if (!symbol_exists($3)) {
                fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", $3, line_number);
            } else {
                emit_ir("PRINT_VAR", $3, "", "");
                fprintf(yyout, "[PRINT] %g\n", variables[$3]);
            }
        }
    }
    | KW_PRINTF LPAREN expression RPAREN SEMICOLON
    {
        if (execution_enabled) {
            emit_ir("PRINT_NUM", format_num($3), "", "");
            fprintf(yyout, "[PRINT] %g\n", $3);
        }
    }
    | KW_SCANF LPAREN LIT_STRING COMMA AMPERSAND IDENTIFIER RPAREN SEMICOLON
    {
        if (execution_enabled) {
        double input_value = 0;
        try_read_scan_input($6, input_value);

        if (!symbol_exists($6)) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", $6, line_number);
        } else {
            assign_typed_value($6, input_value, "scanf");
            emit_ir("SCAN", "", "", $6);
            fprintf(yyout, "[SCAN] %s = %g\n", $6, variables[$6]);
        }
        }
    }
    | KW_SCANF LPAREN IDENTIFIER RPAREN SEMICOLON
    {
        if (execution_enabled) {
        double input_value = 0;
        try_read_scan_input($3, input_value);

        if (!symbol_exists($3)) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", $3, line_number);
        } else {
            assign_typed_value($3, input_value, "scanf");
            emit_ir("SCAN", "", "", $3);
            fprintf(yyout, "[SCAN] %s = %g\n", $3, variables[$3]);
        }
        }
    }
    | KW_SCANF LPAREN AMPERSAND IDENTIFIER RPAREN SEMICOLON
    {
        if (execution_enabled) {
        double input_value = 0;
        try_read_scan_input($4, input_value);

        if (!symbol_exists($4)) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", $4, line_number);
        } else {
            assign_typed_value($4, input_value, "scanf");
            emit_ir("SCAN", "", "", $4);
            fprintf(yyout, "[SCAN] %s = %g\n", $4, variables[$4]);
        }
        }
    }
    ;

expression_statement:
    expression SEMICOLON
    | SEMICOLON
    ;

compound_statement:
    LBRACE statement_list RBRACE
    {
        fprintf(yyout, "[BLOCK] Compound statement executed\n");
    }
    ;

statement_list:
    /* empty */
    | statement_list statement
    | statement_list declaration
    ;

if_statement:
    KW_IF LPAREN expression RPAREN
    {
        exec_stack.push_back(execution_enabled);
        if_cond_stack.push_back($3 != 0);
        execution_enabled = execution_enabled && ($3 != 0);
    }
    statement if_else_part
    %prec LOWER_THAN_ELSE
    {
        int parent_exec = exec_stack.back();
        int cond_true = if_cond_stack.back();
        exec_stack.pop_back();
        if_cond_stack.pop_back();
        execution_enabled = parent_exec;

        if (parent_exec) {
            if ($7) {
                emit_ir("IF_ELSE", format_num($3), "", "(then/else)");
                if ($3) {
                    fprintf(yyout, "[IF-ELSE] Executed then block (condition true)\n");
                } else {
                    fprintf(yyout, "[IF-ELSE] Executed else block (condition false)\n");
                }
            } else {
                emit_ir("IF", format_num($3), "", "(then)");
                if (cond_true) {
                    fprintf(yyout, "[IF] Condition true at line %d\n", line_number);
                } else {
                    fprintf(yyout, "[IF] Condition false at line %d\n", line_number);
                }
            }
        }
    }
    ;

if_else_part:
    /* empty */
    {
        $$ = 0;
    }
    | KW_ELSE
    {
        int parent_exec = exec_stack.back();
        int cond_true = if_cond_stack.back();
        execution_enabled = parent_exec && !cond_true;
    }
    statement
    {
        $$ = 1;
    }
    ;

loop_statement:
    KW_FOR LPAREN expression SEMICOLON expression
    {
        exec_stack.push_back(execution_enabled);
        execution_enabled = execution_enabled && ($5 != 0);
    }
    SEMICOLON expression RPAREN
    statement
    {
        int parent_exec = exec_stack.back();
        exec_stack.pop_back();
        execution_enabled = parent_exec;

        if (parent_exec) {
            emit_ir("FOR", format_num($3), format_num($5), format_num($8));
            fprintf(yyout, "[LOOP] For loop condition = %g\n", $5);
        }
    }
    | KW_WHILE LPAREN expression RPAREN
    {
        exec_stack.push_back(execution_enabled);
        execution_enabled = execution_enabled && ($3 != 0);
    }
    statement
    {
        int parent_exec = exec_stack.back();
        exec_stack.pop_back();
        execution_enabled = parent_exec;

        if (parent_exec) {
            emit_ir("WHILE", format_num($3), "", "");
            fprintf(yyout, "[LOOP] While condition = %g\n", $3);
        }
    }
    | KW_DO statement KW_WHILE LPAREN expression RPAREN SEMICOLON
    {
        if (execution_enabled) {
            emit_ir("DO_WHILE", format_num($5), "", "");
            fprintf(yyout, "[LOOP] Do-while loop executed (single-pass parser execution model)\n");
        }
    }
    ;

return_statement:
    KW_RETURN SEMICOLON
    {
        if (function_depth <= 0) {
            fprintf(stderr, "[SEMANTIC ERROR] 'SukunaRelease' is only valid inside a function (line %d)\n", line_number);
        } else if (execution_enabled) {
            return_flag = true;
            return_value = 0;
            emit_ir("RETURN", "", "", "");
            fprintf(yyout, "[RETURN] Return (no value)\n");
        }
    }
    | KW_RETURN expression SEMICOLON
    {
        if (function_depth <= 0) {
            fprintf(stderr, "[SEMANTIC ERROR] 'SukunaRelease' is only valid inside a function (line %d)\n", line_number);
        } else if (execution_enabled) {
            return_flag = true;
            return_value = $2;
            emit_ir("RETURN", format_num($2), "", "");
            fprintf(yyout, "[RETURN] Return value: %g\n", $2);
        }
    }
    ;

break_statement:
    KW_BREAK SEMICOLON
    {
        if (execution_enabled) {
            break_flag = true;
            emit_ir("BREAK", "", "", "");
            fprintf(yyout, "[BREAK] Break statement\n");
        }
    }
    ;

continue_statement:
    KW_CONTINUE SEMICOLON
    {
        if (execution_enabled) {
            continue_flag = true;
            emit_ir("CONTINUE", "", "", "");
            fprintf(yyout, "[CONTINUE] Continue statement\n");
        }
    }
    ;

switch_statement:
    KW_SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE
    {
        if (execution_enabled) {
            emit_ir("SWITCH", format_num($3), "", "");
            fprintf(yyout, "[SWITCH] Switch statement executed\n");
        }
    }
    ;

case_list:
    case_item
    | case_list case_item
    ;

case_item:
    KW_CASE expression COLON statement_list
    {
        if (execution_enabled) {
            emit_ir("CASE", format_num($2), "", "");
            fprintf(yyout, "[CASE] Case %g executed\n", $2);
        }
    }
    ;

/* ---- Expressions ---- */
expression:
    assignment_expr
    {
        $$ = $1;
    }
    ;

assignment_expr:
    logical_or_expr
    {
        $$ = $1;
    }
    | IDENTIFIER OP_ASSIGN assignment_expr
    {
        if (!execution_enabled) {
            $$ = $3;
        } else if (!symbol_exists($1)) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", $1, line_number);
            $$ = 0;
        } else {
            $$ = assign_typed_value($1, $3, "assignment");
            emit_ir("ASSIGN", format_num($$), "", $1);
            fprintf(yyout, "[ASSIGN] %s = %g\n", $1, $$);
        }
    }
    ;

logical_or_expr:
    logical_and_expr
    {
        $$ = $1;
    }
    | logical_or_expr OP_OR logical_and_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($1 || $3) ? 1 : 0;
            emit_ir("OR", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g || %g = %g\n", $1, $3, $$);
        }
    }
    ;

logical_and_expr:
    equality_expr
    {
        $$ = $1;
    }
    | logical_and_expr OP_AND equality_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($1 && $3) ? 1 : 0;
            emit_ir("AND", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g && %g = %g\n", $1, $3, $$);
        }
    }
    ;

equality_expr:
    relational_expr
    {
        $$ = $1;
    }
    | equality_expr OP_EQ relational_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($1 == $3) ? 1 : 0;
            emit_ir("EQ", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g == %g = %g\n", $1, $3, $$);
        }
    }
    | equality_expr OP_NEQ relational_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($1 != $3) ? 1 : 0;
            emit_ir("NEQ", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g != %g = %g\n", $1, $3, $$);
        }
    }
    ;

relational_expr:
    additive_expr
    {
        $$ = $1;
    }
    | relational_expr OP_LT additive_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($1 < $3) ? 1 : 0;
            emit_ir("LT", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g < %g = %g\n", $1, $3, $$);
        }
    }
    | relational_expr OP_GT additive_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($1 > $3) ? 1 : 0;
            emit_ir("GT", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g > %g = %g\n", $1, $3, $$);
        }
    }
    | relational_expr OP_LTE additive_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($1 <= $3) ? 1 : 0;
            emit_ir("LTE", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g <= %g = %g\n", $1, $3, $$);
        }
    }
    | relational_expr OP_GTE additive_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($1 >= $3) ? 1 : 0;
            emit_ir("GTE", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g >= %g = %g\n", $1, $3, $$);
        }
    }
    ;

additive_expr:
    multiplicative_expr
    {
        $$ = $1;
    }
    | additive_expr OP_ADD multiplicative_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = $1 + $3;
            emit_ir("ADD", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g + %g = %g\n", $1, $3, $$);
        }
    }
    | additive_expr OP_DRAIN multiplicative_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = $1 - $3;
            emit_ir("SUB", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g - %g = %g\n", $1, $3, $$);
        }
    }
    ;

multiplicative_expr:
    unary_expr
    {
        $$ = $1;
    }
    | multiplicative_expr OP_MUL unary_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = $1 * $3;
            emit_ir("MUL", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g * %g = %g\n", $1, $3, $$);
        }
    }
    | multiplicative_expr OP_DIV unary_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else if ($3 != 0) {
            $$ = $1 / $3;
            emit_ir("DIV", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g / %g = %g\n", $1, $3, $$);
        } else {
            fprintf(stderr, "[ERROR] Division by zero at line %d\n", line_number);
            $$ = 0;
        }
    }
    | multiplicative_expr OP_MOD unary_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else if ($3 != 0) {
            $$ = (int)$1 % (int)$3;
            emit_ir("MOD", format_num($1), format_num($3), new_temp());
            fprintf(yyout, "[OP] %g %% %g = %g\n", $1, $3, $$);
        } else {
            fprintf(stderr, "[ERROR] Modulo by zero at line %d\n", line_number);
            $$ = 0;
        }
    }
    ;

unary_expr:
    postfix_expr
    {
        $$ = $1;
    }
    | OP_NOT unary_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = ($2 != 0) ? 0 : 1;
            emit_ir("NOT", format_num($2), "", new_temp());
            fprintf(yyout, "[OP] !%g = %g\n", $2, $$);
        }
    }
    | OP_DRAIN unary_expr
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = -$2;
            emit_ir("NEG", format_num($2), "", new_temp());
            fprintf(yyout, "[OP] -%g = %g\n", $2, $$);
        }
    }
    | OP_INC IDENTIFIER
    {
        if (!execution_enabled) {
            $$ = 0;
        } else if (symbol_exists($2)) {
            variables[$2]++;
            symbol_table[$2].value = variables[$2];
            $$ = variables[$2];
            emit_ir("INC_PRE", $2, "", $2);
            fprintf(yyout, "[OP] ++%s = %g\n", $2, $$);
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s\n", $2);
            $$ = 0;
        }
    }
    ;

postfix_expr:
    primary_expr
    {
        $$ = $1;
    }
    | IDENTIFIER OP_INC
    {
        if (!execution_enabled) {
            $$ = 0;
        } else if (symbol_exists($1)) {
            $$ = variables[$1];
            variables[$1]++;
            symbol_table[$1].value = variables[$1];
            emit_ir("INC_POST", $1, "", $1);
            fprintf(yyout, "[OP] %s++ = %g (post-increment)\n", $1, $$);
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s\n", $1);
            $$ = 0;
        }
    }
    | IDENTIFIER LPAREN RPAREN
    {
        if (!execution_enabled) {
            $$ = 0;
        } else if (functions.find($1) != functions.end()) {
            FunctionDef &fdef = functions[$1];
            $$ = fdef.has_return ? fdef.return_value : 0;
            emit_ir("CALL", $1, "", new_temp());
            fprintf(yyout, "[CALL] Function: %s() => %g\n", $1, $$);
        } else {
            fprintf(stderr, "[ERROR] Undefined function: %s\n", $1);
            $$ = 0;
        }
    }
    | IDENTIFIER LPAREN argument_list RPAREN
    {
        if (!execution_enabled) {
            $$ = 0;
        } else if (functions.find($1) != functions.end()) {
            FunctionDef &fdef = functions[$1];
            $$ = fdef.has_return ? fdef.return_value : 0;
            emit_ir("CALL", $1, "", new_temp());
            fprintf(yyout, "[CALL] Function: %s(...) => %g\n", $1, $$);
        } else {
            fprintf(stderr, "[ERROR] Undefined function: %s\n", $1);
            $$ = 0;
        }
    }
    ;

argument_list:
    expression
    | argument_list COMMA expression
    ;

primary_expr:
    IDENTIFIER
    {
        if (!execution_enabled) {
            $$ = 0;
        } else if (symbol_exists($1)) {
            $$ = variables[$1];
            emit_ir("LOAD", $1, "", new_temp());
            fprintf(yyout, "[REF] Variable reference: %s = %g\n", $1, $$);
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", $1, line_number);
            $$ = 0;
        }
    }
    | LIT_INT
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = $1;
            emit_ir("CONST", format_num($1), "", new_temp());
            fprintf(yyout, "[LIT] Integer literal: %d\n", (int)$1);
        }
    }
    | LIT_FLOAT
    {
        if (!execution_enabled) {
            $$ = 0;
        } else {
            $$ = $1;
            emit_ir("CONST", format_num($1), "", new_temp());
            fprintf(yyout, "[LIT] Float literal: %f\n", $1);
        }
    }
    | LPAREN expression RPAREN
    {
        $$ = $2;
        fprintf(yyout, "[EXPR] Parenthesized expression: %g\n", $$);
    }
    ;

/* ---- Function Definitions ---- */
function_def:
    type IDENTIFIER LPAREN RPAREN
    {
        exec_stack.push_back(execution_enabled);

        function_depth++;

        variables_snapshots.push_back(variables);
        var_types_snapshots.push_back(var_types);
        symbol_table_snapshots.push_back(symbol_table);
        ir_snapshots.push_back(ir);
        temp_counter_snapshots.push_back(temp_counter);
        return_flag_snapshots.push_back(return_flag ? 1 : 0);
        return_value_snapshots.push_back(return_value);

        return_flag = false;
        return_value = 0;
        execution_enabled = 1; /* execute in sandbox to derive function return */
    }
    compound_statement
    {
        int parent_exec = exec_stack.back();
        exec_stack.pop_back();

        FunctionDef fdef;
        fdef.params.clear();
        fdef.body_line = line_number;
        fdef.has_return = return_flag;
        fdef.return_value = return_value;
        functions[$2] = fdef;

        variables = variables_snapshots.back();
        variables_snapshots.pop_back();
        var_types = var_types_snapshots.back();
        var_types_snapshots.pop_back();
        symbol_table = symbol_table_snapshots.back();
        symbol_table_snapshots.pop_back();
        ir = ir_snapshots.back();
        ir_snapshots.pop_back();
        temp_counter = temp_counter_snapshots.back();
        temp_counter_snapshots.pop_back();
        return_flag = return_flag_snapshots.back();
        return_flag_snapshots.pop_back();
        return_value = return_value_snapshots.back();
        return_value_snapshots.pop_back();
        execution_enabled = parent_exec;
        function_depth--;

        fprintf(yyout, "[FUNC] Function '%s' defined (no parameters)\n", $2);
    }
    | type IDENTIFIER LPAREN parameter_list RPAREN
    {
        exec_stack.push_back(execution_enabled);

        function_depth++;

        variables_snapshots.push_back(variables);
        var_types_snapshots.push_back(var_types);
        symbol_table_snapshots.push_back(symbol_table);
        ir_snapshots.push_back(ir);
        temp_counter_snapshots.push_back(temp_counter);
        return_flag_snapshots.push_back(return_flag ? 1 : 0);
        return_value_snapshots.push_back(return_value);

        return_flag = false;
        return_value = 0;
        execution_enabled = 1; /* execute in sandbox to derive function return */
    }
    compound_statement
    {
        int parent_exec = exec_stack.back();
        exec_stack.pop_back();

        FunctionDef &fdef = functions[$2];
        fdef.body_line = line_number;
        fdef.has_return = return_flag;
        fdef.return_value = return_value;

        variables = variables_snapshots.back();
        variables_snapshots.pop_back();
        var_types = var_types_snapshots.back();
        var_types_snapshots.pop_back();
        symbol_table = symbol_table_snapshots.back();
        symbol_table_snapshots.pop_back();
        ir = ir_snapshots.back();
        ir_snapshots.pop_back();
        temp_counter = temp_counter_snapshots.back();
        temp_counter_snapshots.pop_back();
        return_flag = return_flag_snapshots.back();
        return_flag_snapshots.pop_back();
        return_value = return_value_snapshots.back();
        return_value_snapshots.pop_back();
        execution_enabled = parent_exec;
        function_depth--;

        fprintf(yyout, "[FUNC] Function '%s' defined (with parameters)\n", $2);
    }
    ;

parameter_list:
    type IDENTIFIER
    {
        if (!functions.empty()) {
            // no-op placeholder: parameters are displayed; functional arg binding is outside this educational scope
        }
        fprintf(yyout, "[PARAM] Parameter: %s\n", $2);
    }
    | parameter_list COMMA type IDENTIFIER
    {
        fprintf(yyout, "[PARAM] Parameter: %s\n", $4);
    }
    ;

%%

/* ================================================================== */
/*  Error Handler                                                     */
/* ================================================================== */
void yyerror(const char *s)
{
    fprintf(stderr, "[SYNTAX ERROR] Line %d: %s\n", line_number, s);
}

/* ================================================================== */
/*  main() — Driver for Phase 2 (Bison Parser) + Phase 3 (Execution) */
/* ================================================================== */
int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.jjk>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }

    yyout = stdout;
    input_source_path = argv[1];

    fprintf(yyout, "╔════════════════════════════════════════════════════════╗\n");
    fprintf(yyout, "║   JujutsuLang Compiler - Phase 2&3                     ║\n");
    fprintf(yyout, "║   Syntax Analysis & Execution                          ║\n");
    fprintf(yyout, "╚════════════════════════════════════════════════════════╝\n\n");
    fprintf(yyout, "[START] Parsing: %s\n\n", argv[1]);

    int parse_result = yyparse();

    write_ir_file("output.ir");
    write_c_code("output.c");
    write_symbol_table_file("symbol_table.txt");

        fprintf(yyout, "\n  ╔════════════════════════════════════════════════════════╗\n");
    if (parse_result == 0) {
        fprintf(yyout, "  ║   ✓ PARSING SUCCESSFUL                                 ║\n");
    } else {
        fprintf(yyout, "  ║   ✗ PARSING FAILED                                     ║\n");
    }
        fprintf(yyout, "  ╚════════════════════════════════════════════════════════╝\n");

    /* Print final variable state */
    if (!variables.empty()) {
        fprintf(yyout, "\n[FINAL STATE] Variables:\n");
        for (auto &var : variables) {
            fprintf(yyout, "  %s = %g\n", var.first.c_str(), var.second);
        }
    }

    if (!symbol_table.empty()) {
        fprintf(yyout, "\n[SYMBOL TABLE]\n");
        fprintf(yyout, "  %-20s %-8s %-12s %-12s\n", "Name", "Type", "Init", "Value");
        for (auto &entry : symbol_table) {
            fprintf(yyout, "  %-20s %-8s %-12s %-12g\n",
                entry.first.c_str(),
                type_to_string(entry.second.type).c_str(),
                entry.second.initialized ? "yes" : "no",
                entry.second.value);
        }
    }

    fprintf(yyout, "\n[IR] Written to output.ir\n");
    fprintf(yyout, "[TARGET-C] Written to output.c\n");
    fprintf(yyout, "[SYMTAB] Written to symbol_table.txt\n");

    if (yyin && yyin != stdin) fclose(yyin);

    return parse_result;
}

string type_to_string(int t)
{
    switch (t) {
        case 0: return "int";
        case 1: return "float";
        case 2: return "double";
        case 3: return "char";
        case 4: return "void";
        default: return "unknown";
    }
}

string format_num(double v)
{
    ostringstream oss;
    oss << std::setprecision(12) << v;
    return oss.str();
}

string new_temp()
{
    return "t" + to_string(temp_counter++);
}

void emit_ir(const string &op, const string &arg1, const string &arg2, const string &result)
{
    ir.push_back({op, arg1, arg2, result});
}

void write_ir_file(const string &path)
{
    ofstream out(path);
    if (!out.is_open()) return;

    out << "# Three-Address-like Intermediate Code\n";
    for (size_t i = 0; i < ir.size(); ++i) {
        out << setw(4) << i << ": ("
            << ir[i].op << ", "
            << ir[i].arg1 << ", "
            << ir[i].arg2 << ", "
            << ir[i].result << ")\n";
    }
}

void write_symbol_table_file(const string &path)
{
    ofstream out(path);
    if (!out.is_open()) return;

    out << "# Symbol Table\n";
    out << left << setw(20) << "Name"
        << setw(10) << "Type"
        << setw(8) << "Init"
        << setw(14) << "Value" << "\n";
    out << string(52, '-') << "\n";

    for (const auto &entry : symbol_table) {
        out << left << setw(20) << entry.first
            << setw(10) << type_to_string(entry.second.type)
            << setw(8) << (entry.second.initialized ? "yes" : "no")
            << setw(14) << entry.second.value
            << "\n";
    }
}

void write_c_code(const string &path)
{
    ofstream out(path);
    if (!out.is_open()) return;

    if (input_source_path.empty()) {
        out << "/* No input source path available */\n";
        out << "#include <stdio.h>\nint main(void){return 0;}\n";
        return;
    }

    ifstream in(input_source_path);
    if (!in.is_open()) {
        out << "/* Failed to open source for transpilation */\n";
        out << "#include <stdio.h>\nint main(void){return 0;}\n";
        return;
    }

    vector<string> lines;
    string line;
    while (getline(in, line)) lines.push_back(line);

    vector<pair<string,string>> type_map = {
        {"CursedEnergy","int"}, {"ReversedFlow","float"}, {"DomainPower","double"},
        {"SoulShard","char"}, {"NullVoid","void"}
    };
    vector<pair<string,string>> word_map = {
        {"TriggerCondition","if"}, {"CounterMove","else"}, {"BindingLoop","for"}, {"CursedCycle","while"},
        {"GuaranteedHit","do"}, {"ShikigamiSummon","switch"}, {"ShikigamiForm","case"},
        {"DomainShatter","break"}, {"FlowShift","continue"}, {"SukunaRelease","return"}
    };
    vector<pair<string,string>> op_map = {
        {"BelowEq","<="}, {"AboveEq",">="}, {"ShardMod","%"}, {"Amplify","*"}, {"Divide","/"},
        {"Match","=="}, {"Clash","!="}, {"Chain","&&"}, {"Boost","++"}, {"Drain","-"},
        {"Below","<"}, {"Above",">"}, {"Bind","="}, {"Link","||"}, {"Add","+"}, {"Neg","!"}
    };

    auto replace_words_outside_strings = [&](const string &src, const vector<pair<string,string>> &mapping) -> string {
        string res;
        size_t i = 0;
        while (i < src.size()) {
            if (src[i] == '"') {
                size_t j = i + 1;
                while (j < src.size()) {
                    if (src[j] == '\\' && j + 1 < src.size()) { j += 2; continue; }
                    if (src[j] == '"') break;
                    ++j;
                }
                if (j < src.size()) ++j;
                res += src.substr(i, j - i);
                i = j;
            } else {
                size_t j = i;
                while (j < src.size() && src[j] != '"') ++j;
                string part = src.substr(i, j - i);
                for (const auto &kv : mapping) {
                    part = regex_replace(part, regex("\\b" + kv.first + "\\b"), kv.second);
                }
                res += part;
                i = j;
            }
        }
        return res;
    };

    auto trim = [](string s) {
        size_t a = s.find_first_not_of(" \t\r\n");
        if (a == string::npos) return string("");
        size_t b = s.find_last_not_of(" \t\r\n");
        return s.substr(a, b - a + 1);
    };

    regex decl_re("^\\s*([A-Za-z_][A-Za-z0-9_]*)\\s+([A-Za-z_][A-Za-z0-9_]*)\\s*(.*);\\s*$");
    regex func_start_re("^\\s*(int|float|double|char|void)\\s+[A-Za-z_][A-Za-z0-9_]*\\s*\\([^;]*\\)\\s*\\{\\s*$");
    regex func_head_re("^\\s*(int|float|double|char|void)\\s+[A-Za-z_][A-Za-z0-9_]*\\s*\\([^;]*\\)\\s*$");
    regex print_re("^\\s*CursedPrint\\s*\\((.*)\\)\\s*;\\s*$");
    regex scan_fmt_re("^\\s*CursedScan\\s*\\(\\s*\"([^\"]*)\"\\s*,\\s*&\\s*([A-Za-z_][A-Za-z0-9_]*)\\s*\\)\\s*;\\s*$");
    regex scan_addr_re("^\\s*CursedScan\\s*\\(\\s*&\\s*([A-Za-z_][A-Za-z0-9_]*)\\s*\\)\\s*;\\s*$");
    regex scan_var_re("^\\s*CursedScan\\s*\\(\\s*([A-Za-z_][A-Za-z0-9_]*)\\s*\\)\\s*;\\s*$");

    unordered_map<string,string> var_types_local;
    set<string> prim = {"int","float","double","char"};

    for (const auto &ln : lines) {
        string cvt = replace_words_outside_strings(ln, type_map);
        smatch m;
        if (regex_match(cvt, m, decl_re)) {
            string t = m[1], n = m[2];
            if (prim.count(t)) var_types_local[n] = t;
        }
    }

    auto infer_fmt = [&](const string &ctype) -> string {
        if (ctype == "int") return "%d";
        if (ctype == "float") return "%f";
        if (ctype == "double") return "%lf";
        if (ctype == "char") return " %c";
        return "%d";
    };

    auto convert_line = [&](const string &raw) -> string {
        smatch m;
        if (regex_match(raw, m, print_re)) {
            string arg = trim(m[1]);
            arg = replace_words_outside_strings(arg, op_map);
            if (arg.size() >= 2 && arg.front() == '"' && arg.back() == '"') {
                return string("printf(\"%s\\n\", ") + arg + ");";
            }
            return string("printf(\"%g\\n\", (double)(") + arg + "));";
        }
        if (regex_match(raw, m, scan_fmt_re)) {
            return string("scanf(\"") + m[1].str() + "\", &" + m[2].str() + ");";
        }
        if (regex_match(raw, m, scan_addr_re) || regex_match(raw, m, scan_var_re)) {
            string var = m[1].str();
            string fmt = infer_fmt(var_types_local.count(var) ? var_types_local[var] : "int");
            return string("scanf(\"") + fmt + "\", &" + var + ");";
        }
        string s = replace_words_outside_strings(raw, type_map);
        s = replace_words_outside_strings(s, word_map);
        s = replace_words_outside_strings(s, op_map);
        return s;
    };

    vector<string> globals_lines, function_lines, main_lines;
    vector<pair<string,string>> global_symbols;
    for (size_t i = 0; i < lines.size();) {
        string conv = convert_line(lines[i]);
        string stripped = trim(conv);
        if (stripped.empty()) { ++i; continue; }

        smatch dm;
        if (regex_match(conv, dm, decl_re)) {
            string t = dm[1];
            if (prim.count(t) && conv.find('(') == string::npos) {
                globals_lines.push_back(conv);

                string decl_body = conv;
                if (!decl_body.empty() && decl_body.back() == ';') decl_body.pop_back();
                decl_body = regex_replace(decl_body, regex("^\\s*" + t + "\\s+"), "");

                size_t start = 0;
                while (start < decl_body.size()) {
                    size_t comma = decl_body.find(',', start);
                    string chunk = (comma == string::npos)
                        ? decl_body.substr(start)
                        : decl_body.substr(start, comma - start);
                    chunk = trim(chunk);
                    smatch vm;
                    if (regex_search(chunk, vm, regex("^([A-Za-z_][A-Za-z0-9_]*)"))) {
                        global_symbols.push_back({vm[1].str(), t});
                    }
                    if (comma == string::npos) break;
                    start = comma + 1;
                }

                ++i;
                continue;
            }
        }

        bool is_func_start = regex_match(conv, func_start_re);
        if (!is_func_start && regex_match(conv, func_head_re)) {
            size_t j = i + 1;
            while (j < lines.size() && trim(convert_line(lines[j])).empty()) ++j;
            if (j < lines.size() && trim(convert_line(lines[j])) == "{") {
                is_func_start = true;
            }
        }

        if (is_func_start) {
            int brace = 0;
            bool seen_open = false;
            while (i < lines.size()) {
                string c2 = convert_line(lines[i]);
                function_lines.push_back(c2);
                for (char ch : c2) {
                    if (ch == '{') { ++brace; seen_open = true; }
                    else if (ch == '}') --brace;
                }
                ++i;
                if (seen_open && brace == 0) break;
            }
            function_lines.push_back("");
            continue;
        }

        main_lines.push_back(conv);
        ++i;
    }

    out << "/* Parser-generated C from JujutsuLang source */\n";
    out << "#include <stdio.h>\n\n";
    for (const auto &g : globals_lines) out << g << "\n";
    if (!globals_lines.empty()) out << "\n";
    for (const auto &f : function_lines) out << f << "\n";

    out << "static void write_symbol_table_runtime(void) {\n";
    out << "    FILE *fp = fopen(\"symbol_table.txt\", \"w\");\n";
    out << "    if (!fp) return;\n";
    out << "    fprintf(fp, \"# Symbol Table\\n\");\n";
    out << "    fprintf(fp, \"%-20s %-10s %-8s %-14s\\n\", \"Name\", \"Type\", \"Init\", \"Value\");\n";
    out << "    fprintf(fp, \"----------------------------------------------------\\n\");\n";
    for (const auto &sym : global_symbols) {
        if (sym.second == "int") {
            out << "    fprintf(fp, \"%-20s %-10s %-8s %-14d\\n\", \"" << sym.first << "\", \"int\", \"yes\", " << sym.first << ");\n";
        } else if (sym.second == "char") {
            out << "    fprintf(fp, \"%-20s %-10s %-8s %-14d\\n\", \"" << sym.first << "\", \"char\", \"yes\", (int)" << sym.first << ");\n";
        } else if (sym.second == "float") {
            out << "    fprintf(fp, \"%-20s %-10s %-8s %-14g\\n\", \"" << sym.first << "\", \"float\", \"yes\", (double)" << sym.first << ");\n";
        } else if (sym.second == "double") {
            out << "    fprintf(fp, \"%-20s %-10s %-8s %-14g\\n\", \"" << sym.first << "\", \"double\", \"yes\", (double)" << sym.first << ");\n";
        }
    }
    out << "    fclose(fp);\n";
    out << "}\n\n";

    out << "int main(void) {\n";
    for (const auto &ml : main_lines) out << "    " << ml << "\n";
    out << "    write_symbol_table_runtime();\n";
    out << "    return 0;\n";
    out << "}\n";
}

void declare_symbol(const string &name, int type, double value, bool initialized)
{
    symbol_table[name] = {type, value, initialized};
}

bool symbol_exists(const string &name)
{
    return symbol_table.find(name) != symbol_table.end();
}

bool is_integer_value(double v)
{
    return std::fabs(v - std::round(v)) < 1e-9;
}

double coerce_to_type(int target_type, double value, const string &name, const string &context)
{
    switch (target_type) {
        case 0: /* int */ {
            if (!is_integer_value(value)) {
                fprintf(stderr,
                    "[TYPE WARNING] Implicit conversion in %s: '%s' value %g converted to int at line %d\n",
                    context.c_str(), name.c_str(), value, line_number);
            }
            return static_cast<int>(value);
        }
        case 1: /* float */
            return static_cast<float>(value);
        case 2: /* double */
            return value;
        case 3: /* char */ {
            if (!is_integer_value(value)) {
                fprintf(stderr,
                    "[TYPE WARNING] Implicit conversion in %s: '%s' value %g converted to char at line %d\n",
                    context.c_str(), name.c_str(), value, line_number);
            }
            int iv = static_cast<int>(value);
            if (iv < -128 || iv > 127) {
                fprintf(stderr,
                    "[TYPE WARNING] Char overflow in %s: '%s' value %d out of range; clamped at line %d\n",
                    context.c_str(), name.c_str(), iv, line_number);
                iv = std::max(-128, std::min(127, iv));
            }
            return static_cast<char>(iv);
        }
        default:
            return value;
    }
}

double assign_typed_value(const string &name, double raw_value, const string &context)
{
    if (!symbol_exists(name)) {
        fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", name.c_str(), line_number);
        return 0;
    }

    int target_type = symbol_table[name].type;
    double typed_value = coerce_to_type(target_type, raw_value, name, context);

    variables[name] = typed_value;
    symbol_table[name].value = typed_value;
    symbol_table[name].initialized = true;

    return typed_value;
}

bool try_read_scan_input(const string &name, double &input_value)
{
    const char *no_interactive = getenv("JUJUTSU_NO_INTERACTIVE_SCAN");
    if (no_interactive && strcmp(no_interactive, "1") == 0) {
        input_value = 0;
        return true;
    }

    fprintf(yyout, "[SCAN] Enter value for %s: ", name.c_str());
    fflush(yyout);

    if (!(cin >> input_value)) {
        cin.clear();
        cin.ignore(10000, '\n');
        fprintf(stderr, "[ERROR] Invalid input for %s at line %d\n", name.c_str(), line_number);
        input_value = 0;
        return false;
    }

    return true;
}

