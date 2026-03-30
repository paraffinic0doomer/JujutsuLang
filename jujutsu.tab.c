/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 11 "/home/saif/Desktop/JujutsuLang/jujutsu.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

#line 74 "jujutsu.tab.c"



/* First part of user prologue.  */
#line 24 "/home/saif/Desktop/JujutsuLang/jujutsu.y"

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


#line 170 "jujutsu.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "jujutsu.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_INT = 3,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 4,                   /* KW_FLOAT  */
  YYSYMBOL_KW_DOUBLE = 5,                  /* KW_DOUBLE  */
  YYSYMBOL_KW_CHAR = 6,                    /* KW_CHAR  */
  YYSYMBOL_KW_VOID = 7,                    /* KW_VOID  */
  YYSYMBOL_KW_IF = 8,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 9,                    /* KW_ELSE  */
  YYSYMBOL_KW_SWITCH = 10,                 /* KW_SWITCH  */
  YYSYMBOL_KW_CASE = 11,                   /* KW_CASE  */
  YYSYMBOL_KW_FOR = 12,                    /* KW_FOR  */
  YYSYMBOL_KW_WHILE = 13,                  /* KW_WHILE  */
  YYSYMBOL_KW_DO = 14,                     /* KW_DO  */
  YYSYMBOL_KW_BREAK = 15,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONTINUE = 16,               /* KW_CONTINUE  */
  YYSYMBOL_KW_RETURN = 17,                 /* KW_RETURN  */
  YYSYMBOL_KW_STRUCT = 18,                 /* KW_STRUCT  */
  YYSYMBOL_KW_TYPEDEF = 19,                /* KW_TYPEDEF  */
  YYSYMBOL_KW_ENUM = 20,                   /* KW_ENUM  */
  YYSYMBOL_KW_CONST = 21,                  /* KW_CONST  */
  YYSYMBOL_KW_STATIC = 22,                 /* KW_STATIC  */
  YYSYMBOL_KW_EXTERN = 23,                 /* KW_EXTERN  */
  YYSYMBOL_KW_SIZEOF = 24,                 /* KW_SIZEOF  */
  YYSYMBOL_KW_GOTO = 25,                   /* KW_GOTO  */
  YYSYMBOL_KW_MAIN = 26,                   /* KW_MAIN  */
  YYSYMBOL_KW_UNION = 27,                  /* KW_UNION  */
  YYSYMBOL_KW_VOLATILE = 28,               /* KW_VOLATILE  */
  YYSYMBOL_KW_REGISTER = 29,               /* KW_REGISTER  */
  YYSYMBOL_KW_SIGNED = 30,                 /* KW_SIGNED  */
  YYSYMBOL_KW_UNSIGNED = 31,               /* KW_UNSIGNED  */
  YYSYMBOL_KW_BREAKPOINT = 32,             /* KW_BREAKPOINT  */
  YYSYMBOL_KW_PRINTF = 33,                 /* KW_PRINTF  */
  YYSYMBOL_KW_SCANF = 34,                  /* KW_SCANF  */
  YYSYMBOL_OP_ADD = 35,                    /* OP_ADD  */
  YYSYMBOL_OP_DRAIN = 36,                  /* OP_DRAIN  */
  YYSYMBOL_OP_MUL = 37,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 38,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 39,                    /* OP_MOD  */
  YYSYMBOL_OP_ASSIGN = 40,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_EQ = 41,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 42,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 43,                     /* OP_LT  */
  YYSYMBOL_OP_GT = 44,                     /* OP_GT  */
  YYSYMBOL_OP_LTE = 45,                    /* OP_LTE  */
  YYSYMBOL_OP_GTE = 46,                    /* OP_GTE  */
  YYSYMBOL_OP_AND = 47,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 48,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 49,                    /* OP_NOT  */
  YYSYMBOL_OP_INC = 50,                    /* OP_INC  */
  YYSYMBOL_LIT_INT = 51,                   /* LIT_INT  */
  YYSYMBOL_LIT_FLOAT = 52,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_CHAR = 53,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 54,                /* LIT_STRING  */
  YYSYMBOL_IDENTIFIER = 55,                /* IDENTIFIER  */
  YYSYMBOL_LPAREN = 56,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 57,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 58,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 59,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 60,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 61,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 62,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 63,                     /* COMMA  */
  YYSYMBOL_DOT = 64,                       /* DOT  */
  YYSYMBOL_COLON = 65,                     /* COLON  */
  YYSYMBOL_ARROW = 66,                     /* ARROW  */
  YYSYMBOL_AMPERSAND = 67,                 /* AMPERSAND  */
  YYSYMBOL_HASH = 68,                      /* HASH  */
  YYSYMBOL_LOWER_THAN_ELSE = 69,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_declaration = 72,               /* declaration  */
  YYSYMBOL_declarator_list = 73,           /* declarator_list  */
  YYSYMBOL_declarator = 74,                /* declarator  */
  YYSYMBOL_declaration_list = 75,          /* declaration_list  */
  YYSYMBOL_type = 76,                      /* type  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_io_statement = 78,              /* io_statement  */
  YYSYMBOL_expression_statement = 79,      /* expression_statement  */
  YYSYMBOL_compound_statement = 80,        /* compound_statement  */
  YYSYMBOL_statement_list = 81,            /* statement_list  */
  YYSYMBOL_if_statement = 82,              /* if_statement  */
  YYSYMBOL_83_1 = 83,                      /* $@1  */
  YYSYMBOL_if_else_part = 84,              /* if_else_part  */
  YYSYMBOL_85_2 = 85,                      /* $@2  */
  YYSYMBOL_loop_statement = 86,            /* loop_statement  */
  YYSYMBOL_87_3 = 87,                      /* $@3  */
  YYSYMBOL_88_4 = 88,                      /* $@4  */
  YYSYMBOL_return_statement = 89,          /* return_statement  */
  YYSYMBOL_break_statement = 90,           /* break_statement  */
  YYSYMBOL_continue_statement = 91,        /* continue_statement  */
  YYSYMBOL_switch_statement = 92,          /* switch_statement  */
  YYSYMBOL_case_list = 93,                 /* case_list  */
  YYSYMBOL_case_item = 94,                 /* case_item  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_assignment_expr = 96,           /* assignment_expr  */
  YYSYMBOL_logical_or_expr = 97,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 98,          /* logical_and_expr  */
  YYSYMBOL_equality_expr = 99,             /* equality_expr  */
  YYSYMBOL_relational_expr = 100,          /* relational_expr  */
  YYSYMBOL_additive_expr = 101,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 102,      /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 103,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 104,             /* postfix_expr  */
  YYSYMBOL_argument_list = 105,            /* argument_list  */
  YYSYMBOL_primary_expr = 106,             /* primary_expr  */
  YYSYMBOL_function_def = 107,             /* function_def  */
  YYSYMBOL_108_5 = 108,                    /* $@5  */
  YYSYMBOL_109_6 = 109,                    /* $@6  */
  YYSYMBOL_parameter_list = 110            /* parameter_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   180,   180,   182,   183,   184,   189,   190,   197,   198,
     202,   214,   231,   232,   236,   237,   238,   239,   240,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   257,   264,
     275,   282,   297,   312,   330,   331,   335,   341,   343,   344,
     349,   348,   385,   389,   388,   402,   401,   419,   418,   434,
     444,   455,   469,   480,   491,   501,   502,   506,   517,   524,
     528,   544,   548,   561,   565,   578,   582,   592,   605,   609,
     619,   629,   639,   652,   656,   666,   679,   683,   693,   706,
     722,   726,   736,   746,   764,   768,   783,   797,   814,   815,
     819,   832,   842,   852,   862,   861,   911,   910,   960,   967
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_INT", "KW_FLOAT",
  "KW_DOUBLE", "KW_CHAR", "KW_VOID", "KW_IF", "KW_ELSE", "KW_SWITCH",
  "KW_CASE", "KW_FOR", "KW_WHILE", "KW_DO", "KW_BREAK", "KW_CONTINUE",
  "KW_RETURN", "KW_STRUCT", "KW_TYPEDEF", "KW_ENUM", "KW_CONST",
  "KW_STATIC", "KW_EXTERN", "KW_SIZEOF", "KW_GOTO", "KW_MAIN", "KW_UNION",
  "KW_VOLATILE", "KW_REGISTER", "KW_SIGNED", "KW_UNSIGNED",
  "KW_BREAKPOINT", "KW_PRINTF", "KW_SCANF", "OP_ADD", "OP_DRAIN", "OP_MUL",
  "OP_DIV", "OP_MOD", "OP_ASSIGN", "OP_EQ", "OP_NEQ", "OP_LT", "OP_GT",
  "OP_LTE", "OP_GTE", "OP_AND", "OP_OR", "OP_NOT", "OP_INC", "LIT_INT",
  "LIT_FLOAT", "LIT_CHAR", "LIT_STRING", "IDENTIFIER", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "DOT",
  "COLON", "ARROW", "AMPERSAND", "HASH", "LOWER_THAN_ELSE", "$accept",
  "program", "declaration", "declarator_list", "declarator",
  "declaration_list", "type", "statement", "io_statement",
  "expression_statement", "compound_statement", "statement_list",
  "if_statement", "$@1", "if_else_part", "$@2", "loop_statement", "$@3",
  "$@4", "return_statement", "break_statement", "continue_statement",
  "switch_statement", "case_list", "case_item", "expression",
  "assignment_expr", "logical_or_expr", "logical_and_expr",
  "equality_expr", "relational_expr", "additive_expr",
  "multiplicative_expr", "unary_expr", "postfix_expr", "argument_list",
  "primary_expr", "function_def", "$@5", "$@6", "parameter_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -112,    76,  -112,  -112,  -112,  -112,  -112,  -112,   -36,    15,
      29,    41,   258,    13,    49,    -4,     1,    63,    73,   159,
     159,     4,  -112,  -112,   -12,   204,  -112,  -112,  -112,    78,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
      83,  -112,    98,   100,    28,    71,    42,    26,  -112,  -112,
    -112,  -112,   204,   204,   204,   204,   135,  -112,  -112,  -112,
      88,    93,   108,   -24,   -23,  -112,  -112,  -112,   204,  -112,
      51,    96,   171,    -6,    33,  -112,  -112,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
      97,   104,   103,   109,    99,  -112,    19,   111,   -21,   112,
     107,   114,   117,  -112,  -112,  -112,    -3,  -112,  -112,  -112,
     125,  -112,   204,    10,  -112,   125,   100,    28,    71,    71,
      42,    42,    42,    42,    26,    26,  -112,  -112,  -112,  -112,
     124,   204,  -112,   204,  -112,     3,   129,   130,   131,   127,
     137,   140,  -112,   204,   158,  -112,  -112,   145,    -2,  -112,
     258,   190,  -112,   258,   146,   144,  -112,  -112,  -112,  -112,
     147,  -112,   150,  -112,   155,  -112,  -112,   136,   207,   204,
       7,  -112,   156,  -112,   157,  -112,   160,  -112,  -112,   155,
     169,  -112,  -112,   163,  -112,  -112,   204,  -112,   170,  -112,
    -112,   258,  -112,   168,  -112,  -112,   231,   258,  -112
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    90,     0,    37,    35,     3,     0,
       4,    21,    19,    20,    22,    24,    25,    26,    27,    23,
       0,    58,    59,    61,    63,    65,    68,    73,    76,    80,
      84,     5,     0,     0,     0,     0,     0,    52,    53,    50,
       0,     0,     0,     0,    90,    82,    81,    83,     0,    85,
       0,     0,     0,    10,     0,     8,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    90,     0,
       0,     0,     0,    60,    86,    88,     0,    93,    36,    39,
       0,    38,     0,     0,     6,     0,    62,    64,    66,    67,
      69,    70,    71,    72,    74,    75,    77,    78,    79,    40,
       0,     0,    47,     0,    12,     0,     0,     0,     0,     0,
       0,     0,    87,     0,    10,    11,    94,     0,     0,     9,
       0,     0,    45,     0,     0,     0,    13,    28,    29,    30,
       0,    32,     0,    89,     0,    98,    96,     0,    42,     0,
       0,    55,     0,    48,     0,     7,     0,    33,    95,     0,
       0,    43,    41,     0,    54,    56,     0,    49,     0,    97,
      99,     0,    37,     0,    31,    44,    57,     0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,     2,  -112,   116,  -112,     0,    -1,  -112,  -112,
    -111,    58,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,    72,   -13,   183,  -112,   175,   179,
      25,    40,    50,   -15,  -112,  -112,  -112,  -112,  -112,  -112,
    -112
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,   109,    74,    75,   135,   110,   111,    31,    32,
      33,    72,    34,   150,   182,   191,    35,   172,   153,    36,
      37,    38,    39,   170,   171,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,   106,    50,    51,   164,   179,
     148
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    29,    60,    28,    65,    66,     3,     4,     5,     6,
       7,    56,    71,     3,     4,     5,     6,     7,   169,    68,
      52,    16,     3,     4,     5,     6,     7,    69,    68,    69,
     100,   101,    19,    70,   112,    70,   137,    16,    69,    90,
      91,    92,    93,   102,    70,    20,    21,    22,    23,    99,
     113,    24,    25,   178,   142,   166,    61,   105,    59,    67,
     143,   167,   155,    87,    88,    89,   184,   146,   189,    79,
      80,    53,   126,   127,   128,    57,     2,    85,    86,     3,
       4,     5,     6,     7,     8,    54,     9,    19,    10,    11,
      12,    13,    14,    15,    16,   114,   115,    55,   134,   145,
      20,    21,    22,    23,   118,   119,    24,    25,   104,    17,
      18,    58,    19,   147,    81,    82,    83,    84,   152,    62,
     154,   120,   121,   122,   123,    20,    21,    22,    23,    63,
     163,    24,    25,    73,    26,   124,   125,   156,    27,     3,
       4,     5,     6,     7,    19,    76,    77,    78,    94,   168,
      95,    96,   173,   107,   129,   133,   183,    20,    21,    22,
      23,   130,    97,    98,    25,   131,   132,   180,   136,   138,
     139,   140,   141,   193,     3,     4,     5,     6,     7,     8,
     144,     9,   151,    10,    11,    12,    13,    14,    15,    16,
     195,   157,   158,   159,   160,    19,   198,   162,   112,   161,
     165,   169,   176,   174,    17,    18,   175,    19,    20,    21,
      22,    23,   177,    26,    64,    25,   181,   188,   186,   187,
      20,    21,    22,    23,   190,   197,    24,    25,   192,    26,
     108,   149,   194,    27,     3,     4,     5,     6,     7,     8,
      19,     9,   185,    10,    11,    12,    13,    14,    15,    16,
     196,   103,   116,    20,    21,    22,    23,   117,     0,    24,
      25,     0,     0,     0,    17,    18,     8,    19,     9,     0,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
      20,    21,    22,    23,     0,     0,    24,    25,     0,    26,
       0,    17,    18,    27,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,    22,
      23,     0,     0,    24,    25,     0,    26,     0,     0,     0,
      27
};

static const yytype_int16 yycheck[] =
{
       1,     1,    15,     1,    19,    20,     3,     4,     5,     6,
       7,    12,    25,     3,     4,     5,     6,     7,    11,    40,
      56,    18,     3,     4,     5,     6,     7,    50,    40,    50,
      54,    55,    36,    56,    40,    56,    57,    18,    50,    52,
      53,    54,    55,    67,    56,    49,    50,    51,    52,    62,
      56,    55,    56,   164,    57,    57,    55,    70,    62,    55,
      63,    63,    59,    37,    38,    39,    59,    57,   179,    41,
      42,    56,    87,    88,    89,    62,     0,    35,    36,     3,
       4,     5,     6,     7,     8,    56,    10,    36,    12,    13,
      14,    15,    16,    17,    18,    62,    63,    56,    96,   112,
      49,    50,    51,    52,    79,    80,    55,    56,    57,    33,
      34,    62,    36,   113,    43,    44,    45,    46,   131,    56,
     133,    81,    82,    83,    84,    49,    50,    51,    52,    56,
     143,    55,    56,    55,    58,    85,    86,   135,    62,     3,
       4,     5,     6,     7,    36,    62,    48,    47,    13,   150,
      62,    58,   153,    57,    57,    56,   169,    49,    50,    51,
      52,    57,    54,    55,    56,    62,    57,   167,    57,    57,
      63,    57,    55,   186,     3,     4,     5,     6,     7,     8,
      55,    10,    58,    12,    13,    14,    15,    16,    17,    18,
     191,    62,    62,    62,    67,    36,   197,    57,    40,    62,
      55,    11,    55,    57,    33,    34,    62,    36,    49,    50,
      51,    52,    62,    58,    55,    56,     9,    57,    62,    62,
      49,    50,    51,    52,    55,    57,    55,    56,    65,    58,
      59,   115,    62,    62,     3,     4,     5,     6,     7,     8,
      36,    10,   170,    12,    13,    14,    15,    16,    17,    18,
     192,    68,    77,    49,    50,    51,    52,    78,    -1,    55,
      56,    -1,    -1,    -1,    33,    34,     8,    36,    10,    -1,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    55,    56,    -1,    58,
      -1,    33,    34,    62,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    55,    56,    -1,    58,    -1,    -1,    -1,
      62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    71,     0,     3,     4,     5,     6,     7,     8,    10,
      12,    13,    14,    15,    16,    17,    18,    33,    34,    36,
      49,    50,    51,    52,    55,    56,    58,    62,    72,    76,
      77,    78,    79,    80,    82,    86,    89,    90,    91,    92,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     106,   107,    56,    56,    56,    56,    77,    62,    62,    62,
      95,    55,    56,    56,    55,   103,   103,    55,    40,    50,
      56,    95,    81,    55,    73,    74,    62,    48,    47,    41,
      42,    43,    44,    45,    46,    35,    36,    37,    38,    39,
      95,    95,    95,    95,    13,    62,    58,    54,    55,    95,
      54,    55,    67,    96,    57,    95,   105,    57,    59,    72,
      76,    77,    40,    56,    62,    63,    98,    99,   100,   100,
     101,   101,   101,   101,   102,   102,   103,   103,   103,    57,
      57,    62,    57,    56,    72,    75,    57,    57,    57,    63,
      57,    55,    57,    63,    55,    95,    57,    76,   110,    74,
      83,    58,    95,    88,    95,    59,    72,    62,    62,    62,
      67,    62,    57,    95,   108,    55,    57,    63,    77,    11,
      93,    94,    87,    77,    57,    62,    55,    62,    80,   109,
      76,     9,    84,    95,    59,    94,    62,    62,    57,    80,
      55,    85,    65,    95,    62,    77,    81,    57,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    81,    81,    81,
      83,    82,    84,    85,    84,    87,    86,    88,    86,    86,
      89,    89,    90,    91,    92,    93,    93,    94,    95,    96,
      96,    97,    97,    98,    98,    99,    99,    99,   100,   100,
     100,   100,   100,   101,   101,   101,   102,   102,   102,   102,
     103,   103,   103,   103,   104,   104,   104,   104,   105,   105,
     106,   106,   106,   106,   108,   107,   109,   107,   110,   110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     3,     6,     1,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     8,     5,     6,     2,     1,     3,     0,     2,     2,
       0,     7,     0,     0,     3,     0,    10,     0,     6,     7,
       2,     3,     2,     2,     7,     1,     2,     4,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     1,     2,     3,     4,     1,     3,
       1,     1,     1,     3,     0,     6,     0,     7,     2,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7: /* declaration: KW_STRUCT IDENTIFIER LBRACE declaration_list RBRACE SEMICOLON  */
#line 191 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        fprintf(yyout, "[DECL] Struct declared: %s\n", (yyvsp[-4].sval));
    }
#line 1438 "jujutsu.tab.c"
    break;

  case 10: /* declarator: IDENTIFIER  */
#line 203 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (current_decl_type == 4) {
            fprintf(stderr, "[SEMANTIC ERROR] Variable '%s' cannot have type void at line %d\n", (yyvsp[0].sval), line_number);
        } else if (execution_enabled) {
            variables[(yyvsp[0].sval)] = 0;
            var_types[(yyvsp[0].sval)] = current_decl_type;
            declare_symbol((yyvsp[0].sval), current_decl_type, 0, false);
            emit_ir("DECL", type_to_string(current_decl_type), "", (yyvsp[0].sval));
            fprintf(yyout, "[DECL] Variable '%s' declared (initial value: 0)\n", (yyvsp[0].sval));
        }
    }
#line 1454 "jujutsu.tab.c"
    break;

  case 11: /* declarator: IDENTIFIER OP_ASSIGN expression  */
#line 215 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (current_decl_type == 4) {
            fprintf(stderr, "[SEMANTIC ERROR] Variable '%s' cannot have type void at line %d\n", (yyvsp[-2].sval), line_number);
        } else if (execution_enabled) {
            double typed_value = coerce_to_type(current_decl_type, (yyvsp[0].fval), (yyvsp[-2].sval), "declaration");
            variables[(yyvsp[-2].sval)] = typed_value;
            var_types[(yyvsp[-2].sval)] = current_decl_type;
            declare_symbol((yyvsp[-2].sval), current_decl_type, typed_value, true);
            emit_ir("DECL", type_to_string(current_decl_type), "", (yyvsp[-2].sval));
            emit_ir("ASSIGN", format_num(typed_value), "", (yyvsp[-2].sval));
            fprintf(yyout, "[DECL] Variable '%s' declared with initial value: %g\n", (yyvsp[-2].sval), typed_value);
        }
    }
#line 1472 "jujutsu.tab.c"
    break;

  case 14: /* type: KW_INT  */
#line 236 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
                 { (yyval.ival) = 0; current_decl_type = (yyval.ival); }
#line 1478 "jujutsu.tab.c"
    break;

  case 15: /* type: KW_FLOAT  */
#line 237 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
                 { (yyval.ival) = 1; current_decl_type = (yyval.ival); }
#line 1484 "jujutsu.tab.c"
    break;

  case 16: /* type: KW_DOUBLE  */
#line 238 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
                 { (yyval.ival) = 2; current_decl_type = (yyval.ival); }
#line 1490 "jujutsu.tab.c"
    break;

  case 17: /* type: KW_CHAR  */
#line 239 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
                 { (yyval.ival) = 3; current_decl_type = (yyval.ival); }
#line 1496 "jujutsu.tab.c"
    break;

  case 18: /* type: KW_VOID  */
#line 240 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
                 { (yyval.ival) = 4; current_decl_type = (yyval.ival); }
#line 1502 "jujutsu.tab.c"
    break;

  case 28: /* io_statement: KW_PRINTF LPAREN LIT_STRING RPAREN SEMICOLON  */
#line 258 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
            emit_ir("PRINT_STR", (yyvsp[-2].sval), "", "");
            fprintf(yyout, "[PRINT] %s\n", (yyvsp[-2].sval));
        }
    }
#line 1513 "jujutsu.tab.c"
    break;

  case 29: /* io_statement: KW_PRINTF LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 265 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
            if (!symbol_exists((yyvsp[-2].sval))) {
                fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", (yyvsp[-2].sval), line_number);
            } else {
                emit_ir("PRINT_VAR", (yyvsp[-2].sval), "", "");
                fprintf(yyout, "[PRINT] %g\n", variables[(yyvsp[-2].sval)]);
            }
        }
    }
#line 1528 "jujutsu.tab.c"
    break;

  case 30: /* io_statement: KW_PRINTF LPAREN expression RPAREN SEMICOLON  */
#line 276 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
            emit_ir("PRINT_NUM", format_num((yyvsp[-2].fval)), "", "");
            fprintf(yyout, "[PRINT] %g\n", (yyvsp[-2].fval));
        }
    }
#line 1539 "jujutsu.tab.c"
    break;

  case 31: /* io_statement: KW_SCANF LPAREN LIT_STRING COMMA AMPERSAND IDENTIFIER RPAREN SEMICOLON  */
#line 283 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
        double input_value = 0;
        try_read_scan_input((yyvsp[-2].sval), input_value);

        if (!symbol_exists((yyvsp[-2].sval))) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", (yyvsp[-2].sval), line_number);
        } else {
            assign_typed_value((yyvsp[-2].sval), input_value, "scanf");
            emit_ir("SCAN", "", "", (yyvsp[-2].sval));
            fprintf(yyout, "[SCAN] %s = %g\n", (yyvsp[-2].sval), variables[(yyvsp[-2].sval)]);
        }
        }
    }
#line 1558 "jujutsu.tab.c"
    break;

  case 32: /* io_statement: KW_SCANF LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 298 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
        double input_value = 0;
        try_read_scan_input((yyvsp[-2].sval), input_value);

        if (!symbol_exists((yyvsp[-2].sval))) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", (yyvsp[-2].sval), line_number);
        } else {
            assign_typed_value((yyvsp[-2].sval), input_value, "scanf");
            emit_ir("SCAN", "", "", (yyvsp[-2].sval));
            fprintf(yyout, "[SCAN] %s = %g\n", (yyvsp[-2].sval), variables[(yyvsp[-2].sval)]);
        }
        }
    }
#line 1577 "jujutsu.tab.c"
    break;

  case 33: /* io_statement: KW_SCANF LPAREN AMPERSAND IDENTIFIER RPAREN SEMICOLON  */
#line 313 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
        double input_value = 0;
        try_read_scan_input((yyvsp[-2].sval), input_value);

        if (!symbol_exists((yyvsp[-2].sval))) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", (yyvsp[-2].sval), line_number);
        } else {
            assign_typed_value((yyvsp[-2].sval), input_value, "scanf");
            emit_ir("SCAN", "", "", (yyvsp[-2].sval));
            fprintf(yyout, "[SCAN] %s = %g\n", (yyvsp[-2].sval), variables[(yyvsp[-2].sval)]);
        }
        }
    }
#line 1596 "jujutsu.tab.c"
    break;

  case 36: /* compound_statement: LBRACE statement_list RBRACE  */
#line 336 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        fprintf(yyout, "[BLOCK] Compound statement executed\n");
    }
#line 1604 "jujutsu.tab.c"
    break;

  case 40: /* $@1: %empty  */
#line 349 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        exec_stack.push_back(execution_enabled);
        if_cond_stack.push_back((yyvsp[-1].fval) != 0);
        execution_enabled = execution_enabled && ((yyvsp[-1].fval) != 0);
    }
#line 1614 "jujutsu.tab.c"
    break;

  case 41: /* if_statement: KW_IF LPAREN expression RPAREN $@1 statement if_else_part  */
#line 356 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        int parent_exec = exec_stack.back();
        int cond_true = if_cond_stack.back();
        exec_stack.pop_back();
        if_cond_stack.pop_back();
        execution_enabled = parent_exec;

        if (parent_exec) {
            if ((yyvsp[0].ival)) {
                emit_ir("IF_ELSE", format_num((yyvsp[-4].fval)), "", "(then/else)");
                if ((yyvsp[-4].fval)) {
                    fprintf(yyout, "[IF-ELSE] Executed then block (condition true)\n");
                } else {
                    fprintf(yyout, "[IF-ELSE] Executed else block (condition false)\n");
                }
            } else {
                emit_ir("IF", format_num((yyvsp[-4].fval)), "", "(then)");
                if (cond_true) {
                    fprintf(yyout, "[IF] Condition true at line %d\n", line_number);
                } else {
                    fprintf(yyout, "[IF] Condition false at line %d\n", line_number);
                }
            }
        }
    }
#line 1644 "jujutsu.tab.c"
    break;

  case 42: /* if_else_part: %empty  */
#line 385 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.ival) = 0;
    }
#line 1652 "jujutsu.tab.c"
    break;

  case 43: /* $@2: %empty  */
#line 389 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        int parent_exec = exec_stack.back();
        int cond_true = if_cond_stack.back();
        execution_enabled = parent_exec && !cond_true;
    }
#line 1662 "jujutsu.tab.c"
    break;

  case 44: /* if_else_part: KW_ELSE $@2 statement  */
#line 395 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.ival) = 1;
    }
#line 1670 "jujutsu.tab.c"
    break;

  case 45: /* $@3: %empty  */
#line 402 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        exec_stack.push_back(execution_enabled);
        execution_enabled = execution_enabled && ((yyvsp[0].fval) != 0);
    }
#line 1679 "jujutsu.tab.c"
    break;

  case 46: /* loop_statement: KW_FOR LPAREN expression SEMICOLON expression $@3 SEMICOLON expression RPAREN statement  */
#line 408 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        int parent_exec = exec_stack.back();
        exec_stack.pop_back();
        execution_enabled = parent_exec;

        if (parent_exec) {
            emit_ir("FOR", format_num((yyvsp[-7].fval)), format_num((yyvsp[-5].fval)), format_num((yyvsp[-2].fval)));
            fprintf(yyout, "[LOOP] For loop condition = %g\n", (yyvsp[-5].fval));
        }
    }
#line 1694 "jujutsu.tab.c"
    break;

  case 47: /* $@4: %empty  */
#line 419 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        exec_stack.push_back(execution_enabled);
        execution_enabled = execution_enabled && ((yyvsp[-1].fval) != 0);
    }
#line 1703 "jujutsu.tab.c"
    break;

  case 48: /* loop_statement: KW_WHILE LPAREN expression RPAREN $@4 statement  */
#line 424 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        int parent_exec = exec_stack.back();
        exec_stack.pop_back();
        execution_enabled = parent_exec;

        if (parent_exec) {
            emit_ir("WHILE", format_num((yyvsp[-3].fval)), "", "");
            fprintf(yyout, "[LOOP] While condition = %g\n", (yyvsp[-3].fval));
        }
    }
#line 1718 "jujutsu.tab.c"
    break;

  case 49: /* loop_statement: KW_DO statement KW_WHILE LPAREN expression RPAREN SEMICOLON  */
#line 435 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
            emit_ir("DO_WHILE", format_num((yyvsp[-2].fval)), "", "");
            fprintf(yyout, "[LOOP] Do-while loop executed (single-pass parser execution model)\n");
        }
    }
#line 1729 "jujutsu.tab.c"
    break;

  case 50: /* return_statement: KW_RETURN SEMICOLON  */
#line 445 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
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
#line 1744 "jujutsu.tab.c"
    break;

  case 51: /* return_statement: KW_RETURN expression SEMICOLON  */
#line 456 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (function_depth <= 0) {
            fprintf(stderr, "[SEMANTIC ERROR] 'SukunaRelease' is only valid inside a function (line %d)\n", line_number);
        } else if (execution_enabled) {
            return_flag = true;
            return_value = (yyvsp[-1].fval);
            emit_ir("RETURN", format_num((yyvsp[-1].fval)), "", "");
            fprintf(yyout, "[RETURN] Return value: %g\n", (yyvsp[-1].fval));
        }
    }
#line 1759 "jujutsu.tab.c"
    break;

  case 52: /* break_statement: KW_BREAK SEMICOLON  */
#line 470 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
            break_flag = true;
            emit_ir("BREAK", "", "", "");
            fprintf(yyout, "[BREAK] Break statement\n");
        }
    }
#line 1771 "jujutsu.tab.c"
    break;

  case 53: /* continue_statement: KW_CONTINUE SEMICOLON  */
#line 481 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
            continue_flag = true;
            emit_ir("CONTINUE", "", "", "");
            fprintf(yyout, "[CONTINUE] Continue statement\n");
        }
    }
#line 1783 "jujutsu.tab.c"
    break;

  case 54: /* switch_statement: KW_SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE  */
#line 492 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
            emit_ir("SWITCH", format_num((yyvsp[-4].fval)), "", "");
            fprintf(yyout, "[SWITCH] Switch statement executed\n");
        }
    }
#line 1794 "jujutsu.tab.c"
    break;

  case 57: /* case_item: KW_CASE expression COLON statement_list  */
#line 507 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (execution_enabled) {
            emit_ir("CASE", format_num((yyvsp[-2].fval)), "", "");
            fprintf(yyout, "[CASE] Case %g executed\n", (yyvsp[-2].fval));
        }
    }
#line 1805 "jujutsu.tab.c"
    break;

  case 58: /* expression: assignment_expr  */
#line 518 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1813 "jujutsu.tab.c"
    break;

  case 59: /* assignment_expr: logical_or_expr  */
#line 525 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1821 "jujutsu.tab.c"
    break;

  case 60: /* assignment_expr: IDENTIFIER OP_ASSIGN assignment_expr  */
#line 529 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = (yyvsp[0].fval);
        } else if (!symbol_exists((yyvsp[-2].sval))) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", (yyvsp[-2].sval), line_number);
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = assign_typed_value((yyvsp[-2].sval), (yyvsp[0].fval), "assignment");
            emit_ir("ASSIGN", format_num((yyval.fval)), "", (yyvsp[-2].sval));
            fprintf(yyout, "[ASSIGN] %s = %g\n", (yyvsp[-2].sval), (yyval.fval));
        }
    }
#line 1838 "jujutsu.tab.c"
    break;

  case 61: /* logical_or_expr: logical_and_expr  */
#line 545 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1846 "jujutsu.tab.c"
    break;

  case 62: /* logical_or_expr: logical_or_expr OP_OR logical_and_expr  */
#line 549 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[-2].fval) || (yyvsp[0].fval)) ? 1 : 0;
            emit_ir("OR", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g || %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 1860 "jujutsu.tab.c"
    break;

  case 63: /* logical_and_expr: equality_expr  */
#line 562 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1868 "jujutsu.tab.c"
    break;

  case 64: /* logical_and_expr: logical_and_expr OP_AND equality_expr  */
#line 566 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[-2].fval) && (yyvsp[0].fval)) ? 1 : 0;
            emit_ir("AND", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g && %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 1882 "jujutsu.tab.c"
    break;

  case 65: /* equality_expr: relational_expr  */
#line 579 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1890 "jujutsu.tab.c"
    break;

  case 66: /* equality_expr: equality_expr OP_EQ relational_expr  */
#line 583 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[-2].fval) == (yyvsp[0].fval)) ? 1 : 0;
            emit_ir("EQ", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g == %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 1904 "jujutsu.tab.c"
    break;

  case 67: /* equality_expr: equality_expr OP_NEQ relational_expr  */
#line 593 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[-2].fval) != (yyvsp[0].fval)) ? 1 : 0;
            emit_ir("NEQ", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g != %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 1918 "jujutsu.tab.c"
    break;

  case 68: /* relational_expr: additive_expr  */
#line 606 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1926 "jujutsu.tab.c"
    break;

  case 69: /* relational_expr: relational_expr OP_LT additive_expr  */
#line 610 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[-2].fval) < (yyvsp[0].fval)) ? 1 : 0;
            emit_ir("LT", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g < %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 1940 "jujutsu.tab.c"
    break;

  case 70: /* relational_expr: relational_expr OP_GT additive_expr  */
#line 620 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[-2].fval) > (yyvsp[0].fval)) ? 1 : 0;
            emit_ir("GT", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g > %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 1954 "jujutsu.tab.c"
    break;

  case 71: /* relational_expr: relational_expr OP_LTE additive_expr  */
#line 630 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[-2].fval) <= (yyvsp[0].fval)) ? 1 : 0;
            emit_ir("LTE", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g <= %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 1968 "jujutsu.tab.c"
    break;

  case 72: /* relational_expr: relational_expr OP_GTE additive_expr  */
#line 640 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[-2].fval) >= (yyvsp[0].fval)) ? 1 : 0;
            emit_ir("GTE", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g >= %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 1982 "jujutsu.tab.c"
    break;

  case 73: /* additive_expr: multiplicative_expr  */
#line 653 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1990 "jujutsu.tab.c"
    break;

  case 74: /* additive_expr: additive_expr OP_ADD multiplicative_expr  */
#line 657 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = (yyvsp[-2].fval) + (yyvsp[0].fval);
            emit_ir("ADD", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g + %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 2004 "jujutsu.tab.c"
    break;

  case 75: /* additive_expr: additive_expr OP_DRAIN multiplicative_expr  */
#line 667 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = (yyvsp[-2].fval) - (yyvsp[0].fval);
            emit_ir("SUB", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g - %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 2018 "jujutsu.tab.c"
    break;

  case 76: /* multiplicative_expr: unary_expr  */
#line 680 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 2026 "jujutsu.tab.c"
    break;

  case 77: /* multiplicative_expr: multiplicative_expr OP_MUL unary_expr  */
#line 684 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = (yyvsp[-2].fval) * (yyvsp[0].fval);
            emit_ir("MUL", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g * %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 2040 "jujutsu.tab.c"
    break;

  case 78: /* multiplicative_expr: multiplicative_expr OP_DIV unary_expr  */
#line 694 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else if ((yyvsp[0].fval) != 0) {
            (yyval.fval) = (yyvsp[-2].fval) / (yyvsp[0].fval);
            emit_ir("DIV", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g / %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Division by zero at line %d\n", line_number);
            (yyval.fval) = 0;
        }
    }
#line 2057 "jujutsu.tab.c"
    break;

  case 79: /* multiplicative_expr: multiplicative_expr OP_MOD unary_expr  */
#line 707 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else if ((yyvsp[0].fval) != 0) {
            (yyval.fval) = (int)(yyvsp[-2].fval) % (int)(yyvsp[0].fval);
            emit_ir("MOD", format_num((yyvsp[-2].fval)), format_num((yyvsp[0].fval)), new_temp());
            fprintf(yyout, "[OP] %g %% %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Modulo by zero at line %d\n", line_number);
            (yyval.fval) = 0;
        }
    }
#line 2074 "jujutsu.tab.c"
    break;

  case 80: /* unary_expr: postfix_expr  */
#line 723 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 2082 "jujutsu.tab.c"
    break;

  case 81: /* unary_expr: OP_NOT unary_expr  */
#line 727 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = ((yyvsp[0].fval) != 0) ? 0 : 1;
            emit_ir("NOT", format_num((yyvsp[0].fval)), "", new_temp());
            fprintf(yyout, "[OP] !%g = %g\n", (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 2096 "jujutsu.tab.c"
    break;

  case 82: /* unary_expr: OP_DRAIN unary_expr  */
#line 737 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = -(yyvsp[0].fval);
            emit_ir("NEG", format_num((yyvsp[0].fval)), "", new_temp());
            fprintf(yyout, "[OP] -%g = %g\n", (yyvsp[0].fval), (yyval.fval));
        }
    }
#line 2110 "jujutsu.tab.c"
    break;

  case 83: /* unary_expr: OP_INC IDENTIFIER  */
#line 747 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else if (symbol_exists((yyvsp[0].sval))) {
            variables[(yyvsp[0].sval)]++;
            symbol_table[(yyvsp[0].sval)].value = variables[(yyvsp[0].sval)];
            (yyval.fval) = variables[(yyvsp[0].sval)];
            emit_ir("INC_PRE", (yyvsp[0].sval), "", (yyvsp[0].sval));
            fprintf(yyout, "[OP] ++%s = %g\n", (yyvsp[0].sval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s\n", (yyvsp[0].sval));
            (yyval.fval) = 0;
        }
    }
#line 2129 "jujutsu.tab.c"
    break;

  case 84: /* postfix_expr: primary_expr  */
#line 765 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 2137 "jujutsu.tab.c"
    break;

  case 85: /* postfix_expr: IDENTIFIER OP_INC  */
#line 769 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else if (symbol_exists((yyvsp[-1].sval))) {
            (yyval.fval) = variables[(yyvsp[-1].sval)];
            variables[(yyvsp[-1].sval)]++;
            symbol_table[(yyvsp[-1].sval)].value = variables[(yyvsp[-1].sval)];
            emit_ir("INC_POST", (yyvsp[-1].sval), "", (yyvsp[-1].sval));
            fprintf(yyout, "[OP] %s++ = %g (post-increment)\n", (yyvsp[-1].sval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s\n", (yyvsp[-1].sval));
            (yyval.fval) = 0;
        }
    }
#line 2156 "jujutsu.tab.c"
    break;

  case 86: /* postfix_expr: IDENTIFIER LPAREN RPAREN  */
#line 784 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else if (functions.find((yyvsp[-2].sval)) != functions.end()) {
            FunctionDef &fdef = functions[(yyvsp[-2].sval)];
            (yyval.fval) = fdef.has_return ? fdef.return_value : 0;
            emit_ir("CALL", (yyvsp[-2].sval), "", new_temp());
            fprintf(yyout, "[CALL] Function: %s() => %g\n", (yyvsp[-2].sval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Undefined function: %s\n", (yyvsp[-2].sval));
            (yyval.fval) = 0;
        }
    }
#line 2174 "jujutsu.tab.c"
    break;

  case 87: /* postfix_expr: IDENTIFIER LPAREN argument_list RPAREN  */
#line 798 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else if (functions.find((yyvsp[-3].sval)) != functions.end()) {
            FunctionDef &fdef = functions[(yyvsp[-3].sval)];
            (yyval.fval) = fdef.has_return ? fdef.return_value : 0;
            emit_ir("CALL", (yyvsp[-3].sval), "", new_temp());
            fprintf(yyout, "[CALL] Function: %s(...) => %g\n", (yyvsp[-3].sval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Undefined function: %s\n", (yyvsp[-3].sval));
            (yyval.fval) = 0;
        }
    }
#line 2192 "jujutsu.tab.c"
    break;

  case 90: /* primary_expr: IDENTIFIER  */
#line 820 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else if (symbol_exists((yyvsp[0].sval))) {
            (yyval.fval) = variables[(yyvsp[0].sval)];
            emit_ir("LOAD", (yyvsp[0].sval), "", new_temp());
            fprintf(yyout, "[REF] Variable reference: %s = %g\n", (yyvsp[0].sval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", (yyvsp[0].sval), line_number);
            (yyval.fval) = 0;
        }
    }
#line 2209 "jujutsu.tab.c"
    break;

  case 91: /* primary_expr: LIT_INT  */
#line 833 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = (yyvsp[0].ival);
            emit_ir("CONST", format_num((yyvsp[0].ival)), "", new_temp());
            fprintf(yyout, "[LIT] Integer literal: %d\n", (int)(yyvsp[0].ival));
        }
    }
#line 2223 "jujutsu.tab.c"
    break;

  case 92: /* primary_expr: LIT_FLOAT  */
#line 843 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!execution_enabled) {
            (yyval.fval) = 0;
        } else {
            (yyval.fval) = (yyvsp[0].fval);
            emit_ir("CONST", format_num((yyvsp[0].fval)), "", new_temp());
            fprintf(yyout, "[LIT] Float literal: %f\n", (yyvsp[0].fval));
        }
    }
#line 2237 "jujutsu.tab.c"
    break;

  case 93: /* primary_expr: LPAREN expression RPAREN  */
#line 853 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        (yyval.fval) = (yyvsp[-1].fval);
        fprintf(yyout, "[EXPR] Parenthesized expression: %g\n", (yyval.fval));
    }
#line 2246 "jujutsu.tab.c"
    break;

  case 94: /* $@5: %empty  */
#line 862 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
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
#line 2268 "jujutsu.tab.c"
    break;

  case 95: /* function_def: type IDENTIFIER LPAREN RPAREN $@5 compound_statement  */
#line 880 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        int parent_exec = exec_stack.back();
        exec_stack.pop_back();

        FunctionDef fdef;
        fdef.params.clear();
        fdef.body_line = line_number;
        fdef.has_return = return_flag;
        fdef.return_value = return_value;
        functions[(yyvsp[-4].sval)] = fdef;

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

        fprintf(yyout, "[FUNC] Function '%s' defined (no parameters)\n", (yyvsp[-4].sval));
    }
#line 2303 "jujutsu.tab.c"
    break;

  case 96: /* $@6: %empty  */
#line 911 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
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
#line 2325 "jujutsu.tab.c"
    break;

  case 97: /* function_def: type IDENTIFIER LPAREN parameter_list RPAREN $@6 compound_statement  */
#line 929 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        int parent_exec = exec_stack.back();
        exec_stack.pop_back();

        FunctionDef &fdef = functions[(yyvsp[-5].sval)];
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

        fprintf(yyout, "[FUNC] Function '%s' defined (with parameters)\n", (yyvsp[-5].sval));
    }
#line 2358 "jujutsu.tab.c"
    break;

  case 98: /* parameter_list: type IDENTIFIER  */
#line 961 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        if (!functions.empty()) {
            // no-op placeholder: parameters are displayed; functional arg binding is outside this educational scope
        }
        fprintf(yyout, "[PARAM] Parameter: %s\n", (yyvsp[0].sval));
    }
#line 2369 "jujutsu.tab.c"
    break;

  case 99: /* parameter_list: parameter_list COMMA type IDENTIFIER  */
#line 968 "/home/saif/Desktop/JujutsuLang/jujutsu.y"
    {
        fprintf(yyout, "[PARAM] Parameter: %s\n", (yyvsp[0].sval));
    }
#line 2377 "jujutsu.tab.c"
    break;


#line 2381 "jujutsu.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 973 "/home/saif/Desktop/JujutsuLang/jujutsu.y"


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

