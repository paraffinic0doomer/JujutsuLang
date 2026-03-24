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
#include <cstdlib>
#include <cmath>
using namespace std;

/* ---- Symbol Table for Variables ---- */
map<string, double> variables;
map<string, int> var_types;  // 0=int, 1=float, 2=double, 3=char, 4=void

/* ---- Function Table ---- */
struct FunctionDef {
    vector<pair<string, int>> params;  // (name, type)
    int body_line;  // Line where function body starts
};
map<string, FunctionDef> functions;

/* ---- Execution Control Flow ---- */
bool break_flag = false;
bool continue_flag = false;
double return_value = 0;
bool return_flag = false;

/* ---- Forward Declarations ---- */
void yyerror(const char *s);
double eval_expression(int type, double value);

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
%right OP_NOT OP_INC
%right OP_ASSIGN

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
    type IDENTIFIER SEMICOLON
    {
        variables[$2] = 0;
        fprintf(yyout, "[DECL] Variable '%s' declared (initial value: 0)\n", $2);
    }
    | type IDENTIFIER OP_ASSIGN expression SEMICOLON
    {
        variables[$2] = $4;
        fprintf(yyout, "[DECL] Variable '%s' declared with initial value: %g\n", $2, $4);
    }
    | KW_STRUCT IDENTIFIER LBRACE declaration_list RBRACE SEMICOLON
    {
        fprintf(yyout, "[DECL] Struct declared: %s\n", $2);
    }
    ;

declaration_list:
    declaration
    | declaration_list declaration
    ;

type:
    KW_INT
    | KW_FLOAT
    | KW_DOUBLE
    | KW_CHAR
    | KW_VOID
    ;

/* ---- Statements ---- */
statement:
    expression_statement
    | compound_statement
    | if_statement
    | switch_statement
    | loop_statement
    | return_statement
    | break_statement
    | continue_statement
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
    KW_IF LPAREN expression RPAREN statement
    {
        if ($3) {
            fprintf(yyout, "[IF] Condition true at line %d\n", line_number);
        } else {
            fprintf(yyout, "[IF] Condition false at line %d\n", line_number);
        }
    }
    | KW_IF LPAREN expression RPAREN statement KW_ELSE statement
    {
        if ($3) {
            fprintf(yyout, "[IF-ELSE] Executed then block (condition true)\n");
        } else {
            fprintf(yyout, "[IF-ELSE] Executed else block (condition false)\n");
        }
    }
    ;

loop_statement:
    KW_FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement
    {
        fprintf(yyout, "[LOOP] For loop executed\n");
    }
    | KW_WHILE LPAREN expression RPAREN statement
    {
        fprintf(yyout, "[LOOP] While loop executed\n");
    }
    | KW_DO statement KW_WHILE LPAREN expression RPAREN SEMICOLON
    {
        fprintf(yyout, "[LOOP] Do-while loop executed\n");
    }
    ;

return_statement:
    KW_RETURN SEMICOLON
    {
        return_flag = true;
        return_value = 0;
        fprintf(yyout, "[RETURN] Return (no value)\n");
    }
    | KW_RETURN expression SEMICOLON
    {
        return_flag = true;
        return_value = $2;
        fprintf(yyout, "[RETURN] Return value: %g\n", $2);
    }
    ;

break_statement:
    KW_BREAK SEMICOLON
    {
        break_flag = true;
        fprintf(yyout, "[BREAK] Break statement\n");
    }
    ;

continue_statement:
    KW_CONTINUE SEMICOLON
    {
        continue_flag = true;
        fprintf(yyout, "[CONTINUE] Continue statement\n");
    }
    ;

switch_statement:
    KW_SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE
    {
        fprintf(yyout, "[SWITCH] Switch statement executed\n");
    }
    ;

case_list:
    case_item
    | case_list case_item
    ;

case_item:
    KW_CASE expression COLON statement_list
    {
        fprintf(yyout, "[CASE] Case %g executed\n", $2);
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
        if (variables.find($1) == variables.end()) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", $1, line_number);
            $$ = 0;
        } else {
            variables[$1] = $3;
            $$ = $3;
            fprintf(yyout, "[ASSIGN] %s = %g\n", $1, $3);
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
        $$ = ($1 || $3) ? 1 : 0;
        fprintf(yyout, "[OP] %g || %g = %g\n", $1, $3, $$);
    }
    ;

logical_and_expr:
    equality_expr
    {
        $$ = $1;
    }
    | logical_and_expr OP_AND equality_expr
    {
        $$ = ($1 && $3) ? 1 : 0;
        fprintf(yyout, "[OP] %g && %g = %g\n", $1, $3, $$);
    }
    ;

equality_expr:
    relational_expr
    {
        $$ = $1;
    }
    | equality_expr OP_EQ relational_expr
    {
        $$ = ($1 == $3) ? 1 : 0;
        fprintf(yyout, "[OP] %g == %g = %g\n", $1, $3, $$);
    }
    | equality_expr OP_NEQ relational_expr
    {
        $$ = ($1 != $3) ? 1 : 0;
        fprintf(yyout, "[OP] %g != %g = %g\n", $1, $3, $$);
    }
    ;

relational_expr:
    additive_expr
    {
        $$ = $1;
    }
    | relational_expr OP_LT additive_expr
    {
        $$ = ($1 < $3) ? 1 : 0;
        fprintf(yyout, "[OP] %g < %g = %g\n", $1, $3, $$);
    }
    | relational_expr OP_GT additive_expr
    {
        $$ = ($1 > $3) ? 1 : 0;
        fprintf(yyout, "[OP] %g > %g = %g\n", $1, $3, $$);
    }
    | relational_expr OP_LTE additive_expr
    {
        $$ = ($1 <= $3) ? 1 : 0;
        fprintf(yyout, "[OP] %g <= %g = %g\n", $1, $3, $$);
    }
    | relational_expr OP_GTE additive_expr
    {
        $$ = ($1 >= $3) ? 1 : 0;
        fprintf(yyout, "[OP] %g >= %g = %g\n", $1, $3, $$);
    }
    ;

additive_expr:
    multiplicative_expr
    {
        $$ = $1;
    }
    | additive_expr OP_ADD multiplicative_expr
    {
        $$ = $1 + $3;
        fprintf(yyout, "[OP] %g + %g = %g\n", $1, $3, $$);
    }
    | additive_expr OP_DRAIN multiplicative_expr
    {
        $$ = $1 - $3;
        fprintf(yyout, "[OP] %g - %g = %g\n", $1, $3, $$);
    }
    ;

multiplicative_expr:
    unary_expr
    {
        $$ = $1;
    }
    | multiplicative_expr OP_MUL unary_expr
    {
        $$ = $1 * $3;
        fprintf(yyout, "[OP] %g * %g = %g\n", $1, $3, $$);
    }
    | multiplicative_expr OP_DIV unary_expr
    {
        if ($3 != 0) {
            $$ = $1 / $3;
            fprintf(yyout, "[OP] %g / %g = %g\n", $1, $3, $$);
        } else {
            fprintf(stderr, "[ERROR] Division by zero at line %d\n", line_number);
            $$ = 0;
        }
    }
    | multiplicative_expr OP_MOD unary_expr
    {
        if ($3 != 0) {
            $$ = (int)$1 % (int)$3;
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
        $$ = ($2 != 0) ? 0 : 1;
        fprintf(yyout, "[OP] !%g = %g\n", $2, $$);
    }
    | OP_DRAIN unary_expr
    {
        $$ = -$2;
        fprintf(yyout, "[OP] -%g = %g\n", $2, $$);
    }
    | OP_INC IDENTIFIER
    {
        if (variables.find($2) != variables.end()) {
            variables[$2]++;
            $$ = variables[$2];
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
        if (variables.find($1) != variables.end()) {
            $$ = variables[$1];
            variables[$1]++;
            fprintf(yyout, "[OP] %s++ = %g (post-increment)\n", $1, $$);
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s\n", $1);
            $$ = 0;
        }
    }
    | IDENTIFIER LPAREN RPAREN
    {
        if (functions.find($1) != functions.end()) {
            fprintf(yyout, "[CALL] Function: %s()\n", $1);
        } else {
            fprintf(stderr, "[ERROR] Undefined function: %s\n", $1);
        }
        $$ = 0;
    }
    | IDENTIFIER LPAREN argument_list RPAREN
    {
        if (functions.find($1) != functions.end()) {
            fprintf(yyout, "[CALL] Function: %s(...)\n", $1);
        } else {
            fprintf(stderr, "[ERROR] Undefined function: %s\n", $1);
        }
        $$ = 0;
    }
    ;

argument_list:
    expression
    | argument_list COMMA expression
    ;

primary_expr:
    IDENTIFIER
    {
        if (variables.find($1) != variables.end()) {
            $$ = variables[$1];
            fprintf(yyout, "[REF] Variable reference: %s = %g\n", $1, $$);
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", $1, line_number);
            $$ = 0;
        }
    }
    | LIT_INT
    {
        $$ = $1;
        fprintf(yyout, "[LIT] Integer literal: %d\n", (int)$1);
    }
    | LIT_FLOAT
    {
        $$ = $1;
        fprintf(yyout, "[LIT] Float literal: %f\n", $1);
    }
    | LPAREN expression RPAREN
    {
        $$ = $2;
        fprintf(yyout, "[EXPR] Parenthesized expression: %g\n", $$);
    }
    ;

/* ---- Function Definitions ---- */
function_def:
    type IDENTIFIER LPAREN RPAREN compound_statement
    {
        FunctionDef fdef;
        fdef.params.clear();
        fdef.body_line = line_number;
        functions[$2] = fdef;
        fprintf(yyout, "[FUNC] Function '%s' defined (no parameters)\n", $2);
    }
    | type IDENTIFIER LPAREN parameter_list RPAREN compound_statement
    {
        fprintf(yyout, "[FUNC] Function '%s' defined (with parameters)\n", $2);
    }
    ;

parameter_list:
    type IDENTIFIER
    {
        fprintf(yyout, "[PARAM] Parameter: %s\n", $2);
    }
    | parameter_list COMMA type IDENTIFIER
    {
        fprintf(yyout, "[PARAM] Parameter: %s\n", $4);
    }
    ;

/* ---- Main Entry Point ---- */
main_func:
    type KW_MAIN LPAREN RPAREN compound_statement
    {
        fprintf(yyout, "Main function executed\n");
    }
    | KW_MAIN LPAREN RPAREN compound_statement
    {
        fprintf(yyout, "Main function executed\n");
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

    fprintf(yyout, "╔════════════════════════════════════════════════════════╗\n");
    fprintf(yyout, "║   JujutsuLang Compiler - Phase 2&3                    ║\n");
    fprintf(yyout, "║   Syntax Analysis & Execution                         ║\n");
    fprintf(yyout, "╚════════════════════════════════════════════════════════╝\n\n");
    fprintf(yyout, "[START] Parsing: %s\n\n", argv[1]);

    int parse_result = yyparse();

    fprintf(yyout, "\n╔════════════════════════════════════════════════════════╗\n");
    if (parse_result == 0) {
        fprintf(yyout, "║   ✓ PARSING SUCCESSFUL                               ║\n");
    } else {
        fprintf(yyout, "║   ✗ PARSING FAILED                                   ║\n");
    }
    fprintf(yyout, "╚════════════════════════════════════════════════════════╝\n");

    /* Print final variable state */
    if (!variables.empty()) {
        fprintf(yyout, "\n[FINAL STATE] Variables:\n");
        for (auto &var : variables) {
            fprintf(yyout, "  %s = %g\n", var.first.c_str(), var.second);
        }
    }

    if (yyin && yyin != stdin) fclose(yyin);

    return parse_result;
}

