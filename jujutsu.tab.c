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
#line 11 "jujutsu.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

#line 74 "jujutsu.tab.c"



/* First part of user prologue.  */
#line 24 "jujutsu.y"

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


#line 114 "jujutsu.tab.c"

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
  YYSYMBOL_OP_ADD = 33,                    /* OP_ADD  */
  YYSYMBOL_OP_DRAIN = 34,                  /* OP_DRAIN  */
  YYSYMBOL_OP_MUL = 35,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 36,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 37,                    /* OP_MOD  */
  YYSYMBOL_OP_ASSIGN = 38,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_EQ = 39,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 40,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 41,                     /* OP_LT  */
  YYSYMBOL_OP_GT = 42,                     /* OP_GT  */
  YYSYMBOL_OP_LTE = 43,                    /* OP_LTE  */
  YYSYMBOL_OP_GTE = 44,                    /* OP_GTE  */
  YYSYMBOL_OP_AND = 45,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 46,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 47,                    /* OP_NOT  */
  YYSYMBOL_OP_INC = 48,                    /* OP_INC  */
  YYSYMBOL_LIT_INT = 49,                   /* LIT_INT  */
  YYSYMBOL_LIT_FLOAT = 50,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_CHAR = 51,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 52,                /* LIT_STRING  */
  YYSYMBOL_IDENTIFIER = 53,                /* IDENTIFIER  */
  YYSYMBOL_LPAREN = 54,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 55,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 56,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 57,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 58,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 59,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 60,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 61,                     /* COMMA  */
  YYSYMBOL_DOT = 62,                       /* DOT  */
  YYSYMBOL_COLON = 63,                     /* COLON  */
  YYSYMBOL_ARROW = 64,                     /* ARROW  */
  YYSYMBOL_AMPERSAND = 65,                 /* AMPERSAND  */
  YYSYMBOL_HASH = 66,                      /* HASH  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_program = 68,                   /* program  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_declaration_list = 70,          /* declaration_list  */
  YYSYMBOL_type = 71,                      /* type  */
  YYSYMBOL_statement = 72,                 /* statement  */
  YYSYMBOL_expression_statement = 73,      /* expression_statement  */
  YYSYMBOL_compound_statement = 74,        /* compound_statement  */
  YYSYMBOL_statement_list = 75,            /* statement_list  */
  YYSYMBOL_if_statement = 76,              /* if_statement  */
  YYSYMBOL_loop_statement = 77,            /* loop_statement  */
  YYSYMBOL_return_statement = 78,          /* return_statement  */
  YYSYMBOL_break_statement = 79,           /* break_statement  */
  YYSYMBOL_continue_statement = 80,        /* continue_statement  */
  YYSYMBOL_switch_statement = 81,          /* switch_statement  */
  YYSYMBOL_case_list = 82,                 /* case_list  */
  YYSYMBOL_case_item = 83,                 /* case_item  */
  YYSYMBOL_expression = 84,                /* expression  */
  YYSYMBOL_assignment_expr = 85,           /* assignment_expr  */
  YYSYMBOL_logical_or_expr = 86,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 87,          /* logical_and_expr  */
  YYSYMBOL_equality_expr = 88,             /* equality_expr  */
  YYSYMBOL_relational_expr = 89,           /* relational_expr  */
  YYSYMBOL_additive_expr = 90,             /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 91,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 92,                /* unary_expr  */
  YYSYMBOL_postfix_expr = 93,              /* postfix_expr  */
  YYSYMBOL_argument_list = 94,             /* argument_list  */
  YYSYMBOL_primary_expr = 95,              /* primary_expr  */
  YYSYMBOL_function_def = 96,              /* function_def  */
  YYSYMBOL_parameter_list = 97             /* parameter_list  */
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
#define YYLAST   260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


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
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   120,   121,   122,   127,   132,   137,   144,
     145,   149,   150,   151,   152,   153,   158,   159,   160,   161,
     162,   163,   164,   165,   169,   170,   174,   180,   182,   183,
     187,   195,   206,   210,   214,   221,   227,   236,   244,   252,
     259,   260,   264,   272,   279,   283,   297,   301,   309,   313,
     321,   325,   330,   338,   342,   347,   352,   357,   365,   369,
     374,   382,   386,   391,   401,   414,   418,   423,   428,   442,
     446,   457,   466,   478,   479,   483,   493,   498,   503,   512,
     520,   527,   531
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
  "KW_BREAKPOINT", "OP_ADD", "OP_DRAIN", "OP_MUL", "OP_DIV", "OP_MOD",
  "OP_ASSIGN", "OP_EQ", "OP_NEQ", "OP_LT", "OP_GT", "OP_LTE", "OP_GTE",
  "OP_AND", "OP_OR", "OP_NOT", "OP_INC", "LIT_INT", "LIT_FLOAT",
  "LIT_CHAR", "LIT_STRING", "IDENTIFIER", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "DOT", "COLON",
  "ARROW", "AMPERSAND", "HASH", "$accept", "program", "declaration",
  "declaration_list", "type", "statement", "expression_statement",
  "compound_statement", "statement_list", "if_statement", "loop_statement",
  "return_statement", "break_statement", "continue_statement",
  "switch_statement", "case_list", "case_item", "expression",
  "assignment_expr", "logical_or_expr", "logical_and_expr",
  "equality_expr", "relational_expr", "additive_expr",
  "multiplicative_expr", "unary_expr", "postfix_expr", "argument_list",
  "primary_expr", "function_def", "parameter_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -62,    10,   -62,   -62,   -62,   -62,   -62,   -62,   -46,   -42,
     -35,   -33,   200,    -7,    -4,    28,    49,    90,    90,    51,
     -62,   -62,    35,   189,   -62,   -62,   -62,    65,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,    12,   -62,    44,
      68,    60,    53,    74,    75,   -62,   -62,   -62,   -62,   189,
     189,   189,   189,   115,   -62,   -62,   -62,    96,   110,     7,
     -62,   -62,   -62,   189,   -62,    72,   112,   147,    33,   -62,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,   113,   114,   111,   117,   116,   -62,    36,
     -62,   -62,   -62,    19,   -62,   -62,   -62,   120,   -62,   189,
      43,   -62,    68,    60,    53,    53,    74,    74,    74,    74,
      75,    75,   -62,   -62,   -62,   200,   118,   189,   200,   189,
     -62,    27,   -62,   189,   -31,   123,   135,   139,    31,   184,
     187,   145,   -62,   144,   149,   -62,   -62,   -62,   -62,   -62,
     135,   142,   200,   189,    -5,   -62,   189,   151,   -62,   -62,
     165,   -62,   161,   -62,   -62,   174,   -62,   -62,   -62,   200,
     172,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    75,     0,    27,    25,     3,     0,     4,    16,
      17,    18,    20,    21,    22,    23,    19,     0,    43,    44,
      46,    48,    50,    53,    58,    61,    65,    69,     5,     0,
       0,     0,     0,     0,    37,    38,    35,     0,     0,    75,
      67,    66,    68,     0,    70,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
      45,    71,    73,     0,    78,    26,    29,     0,    28,     0,
       0,     6,    47,    49,    51,    52,    54,    55,    56,    57,
      59,    60,    62,    63,    64,     0,     0,     0,     0,     0,
       9,     0,    72,     0,     0,     0,     0,     0,     0,    30,
       0,     0,    33,     0,     0,    10,    74,     7,    79,    81,
       0,     0,     0,     0,     0,    40,     0,     0,     8,    80,
       0,    31,     0,    39,    41,     0,    34,    82,    27,     0,
      42,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,     2,   -62,     1,    -1,   -62,   -61,    69,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,    86,   -14,   168,   -62,
     132,   162,    58,    59,    37,   -13,   -62,   -62,   -62,   -62,
     -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    96,   121,    97,    98,    29,    30,    67,    31,
      32,    33,    34,    35,    36,   144,   145,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    93,    47,    48,
     128
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    57,    27,    26,    60,    61,   143,    99,    49,    66,
       2,    53,    50,     3,     4,     5,     6,     7,     8,    51,
       9,    52,    10,    11,    12,    13,    14,    15,    16,   101,
       3,     4,     5,     6,     7,    83,    84,    85,    86,     3,
       4,     5,     6,     7,    17,    16,     3,     4,     5,     6,
       7,    92,   153,    54,    16,    64,    55,    18,    19,    20,
      21,    65,    17,    22,    23,   138,    24,   112,   113,   114,
      25,    99,    69,    63,   122,    18,    19,    20,    21,   149,
     123,    22,    23,    64,   134,   125,   140,   100,    56,    65,
      70,   120,   141,   101,    74,    75,    76,    77,   126,    72,
      73,   127,    58,   131,    62,   133,    17,    78,    79,   136,
      80,    81,    82,    71,   129,   110,   111,   132,    68,    18,
      19,    20,    21,   135,    17,    22,    23,    91,    87,   152,
     104,   105,   155,   106,   107,   108,   109,    18,    19,    20,
      21,   151,   150,    59,    23,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,     8,    88,     9,   161,    10,
      11,    12,    13,    14,    15,    16,    89,    94,   115,   116,
     119,   117,   118,   124,   130,     3,     4,     5,     6,     7,
       8,    17,     9,   137,    10,    11,    12,    13,    14,    15,
      16,    24,   139,   142,    18,    19,    20,    21,   143,   147,
      22,    23,   102,    24,    95,   146,    17,    25,     8,   148,
       9,   156,    10,    11,    12,    13,    14,    15,   157,    18,
      19,    20,    21,    17,   158,    22,    23,   160,    24,   159,
     154,    90,    25,   103,    17,     0,    18,    19,    20,    21,
       0,     0,    22,    23,     0,     0,     0,    18,    19,    20,
      21,     0,     0,    22,    23,     0,    24,     0,     0,     0,
      25
};

static const yytype_int16 yycheck[] =
{
       1,    15,     1,     1,    17,    18,    11,    38,    54,    23,
       0,    12,    54,     3,     4,     5,     6,     7,     8,    54,
      10,    54,    12,    13,    14,    15,    16,    17,    18,    60,
       3,     4,     5,     6,     7,    49,    50,    51,    52,     3,
       4,     5,     6,     7,    34,    18,     3,     4,     5,     6,
       7,    65,    57,    60,    18,    48,    60,    47,    48,    49,
      50,    54,    34,    53,    54,   126,    56,    80,    81,    82,
      60,    38,    60,    38,    55,    47,    48,    49,    50,   140,
      61,    53,    54,    48,    57,    99,    55,    54,    60,    54,
      46,    89,    61,    60,    41,    42,    43,    44,    55,    39,
      40,   100,    53,   117,    53,   119,    34,    33,    34,   123,
      35,    36,    37,    45,   115,    78,    79,   118,    53,    47,
      48,    49,    50,   121,    34,    53,    54,    55,    13,   143,
      72,    73,   146,    74,    75,    76,    77,    47,    48,    49,
      50,   142,   141,    53,    54,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,     8,    60,    10,   159,    12,
      13,    14,    15,    16,    17,    18,    56,    55,    55,    55,
      54,    60,    55,    53,    56,     3,     4,     5,     6,     7,
       8,    34,    10,    60,    12,    13,    14,    15,    16,    17,
      18,    56,    53,     9,    47,    48,    49,    50,    11,    55,
      53,    54,    70,    56,    57,    60,    34,    60,     8,    60,
      10,    60,    12,    13,    14,    15,    16,    17,    53,    47,
      48,    49,    50,    34,    63,    53,    54,   158,    56,    55,
     144,    63,    60,    71,    34,    -1,    47,    48,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    56,    -1,    -1,    -1,
      60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,     0,     3,     4,     5,     6,     7,     8,    10,
      12,    13,    14,    15,    16,    17,    18,    34,    47,    48,
      49,    50,    53,    54,    56,    60,    69,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    95,    96,    54,
      54,    54,    54,    72,    60,    60,    60,    84,    53,    53,
      92,    92,    53,    38,    48,    54,    84,    75,    53,    60,
      46,    45,    39,    40,    41,    42,    43,    44,    33,    34,
      35,    36,    37,    84,    84,    84,    84,    13,    60,    56,
      85,    55,    84,    94,    55,    57,    69,    71,    72,    38,
      54,    60,    87,    88,    89,    89,    90,    90,    90,    90,
      91,    91,    92,    92,    92,    55,    55,    60,    55,    54,
      69,    70,    55,    61,    53,    84,    55,    71,    97,    72,
      56,    84,    72,    84,    57,    69,    84,    60,    74,    53,
      55,    61,     9,    11,    82,    83,    60,    55,    60,    74,
      71,    72,    84,    57,    83,    84,    60,    53,    63,    55,
      75,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    75,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    79,    80,    81,
      82,    82,    83,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    89,    89,    89,    90,    90,
      90,    91,    91,    91,    91,    92,    92,    92,    92,    93,
      93,    93,    93,    94,    94,    95,    95,    95,    95,    96,
      96,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     3,     5,     6,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     0,     2,     2,
       5,     7,     9,     5,     7,     2,     3,     2,     2,     7,
       1,     2,     4,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     1,
       2,     3,     4,     1,     3,     1,     1,     1,     3,     5,
       6,     2,     4
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
  case 6: /* declaration: type IDENTIFIER SEMICOLON  */
#line 128 "jujutsu.y"
    {
        variables[(yyvsp[-1].sval)] = 0;
        fprintf(yyout, "[DECL] Variable '%s' declared (initial value: 0)\n", (yyvsp[-1].sval));
    }
#line 1342 "jujutsu.tab.c"
    break;

  case 7: /* declaration: type IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 133 "jujutsu.y"
    {
        variables[(yyvsp[-3].sval)] = (yyvsp[-1].fval);
        fprintf(yyout, "[DECL] Variable '%s' declared with initial value: %g\n", (yyvsp[-3].sval), (yyvsp[-1].fval));
    }
#line 1351 "jujutsu.tab.c"
    break;

  case 8: /* declaration: KW_STRUCT IDENTIFIER LBRACE declaration_list RBRACE SEMICOLON  */
#line 138 "jujutsu.y"
    {
        fprintf(yyout, "[DECL] Struct declared: %s\n", (yyvsp[-4].sval));
    }
#line 1359 "jujutsu.tab.c"
    break;

  case 26: /* compound_statement: LBRACE statement_list RBRACE  */
#line 175 "jujutsu.y"
    {
        fprintf(yyout, "[BLOCK] Compound statement executed\n");
    }
#line 1367 "jujutsu.tab.c"
    break;

  case 30: /* if_statement: KW_IF LPAREN expression RPAREN statement  */
#line 188 "jujutsu.y"
    {
        if ((yyvsp[-2].fval)) {
            fprintf(yyout, "[IF] Condition true at line %d\n", line_number);
        } else {
            fprintf(yyout, "[IF] Condition false at line %d\n", line_number);
        }
    }
#line 1379 "jujutsu.tab.c"
    break;

  case 31: /* if_statement: KW_IF LPAREN expression RPAREN statement KW_ELSE statement  */
#line 196 "jujutsu.y"
    {
        if ((yyvsp[-4].fval)) {
            fprintf(yyout, "[IF-ELSE] Executed then block (condition true)\n");
        } else {
            fprintf(yyout, "[IF-ELSE] Executed else block (condition false)\n");
        }
    }
#line 1391 "jujutsu.tab.c"
    break;

  case 32: /* loop_statement: KW_FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement  */
#line 207 "jujutsu.y"
    {
        fprintf(yyout, "[LOOP] For loop executed\n");
    }
#line 1399 "jujutsu.tab.c"
    break;

  case 33: /* loop_statement: KW_WHILE LPAREN expression RPAREN statement  */
#line 211 "jujutsu.y"
    {
        fprintf(yyout, "[LOOP] While loop executed\n");
    }
#line 1407 "jujutsu.tab.c"
    break;

  case 34: /* loop_statement: KW_DO statement KW_WHILE LPAREN expression RPAREN SEMICOLON  */
#line 215 "jujutsu.y"
    {
        fprintf(yyout, "[LOOP] Do-while loop executed\n");
    }
#line 1415 "jujutsu.tab.c"
    break;

  case 35: /* return_statement: KW_RETURN SEMICOLON  */
#line 222 "jujutsu.y"
    {
        return_flag = true;
        return_value = 0;
        fprintf(yyout, "[RETURN] Return (no value)\n");
    }
#line 1425 "jujutsu.tab.c"
    break;

  case 36: /* return_statement: KW_RETURN expression SEMICOLON  */
#line 228 "jujutsu.y"
    {
        return_flag = true;
        return_value = (yyvsp[-1].fval);
        fprintf(yyout, "[RETURN] Return value: %g\n", (yyvsp[-1].fval));
    }
#line 1435 "jujutsu.tab.c"
    break;

  case 37: /* break_statement: KW_BREAK SEMICOLON  */
#line 237 "jujutsu.y"
    {
        break_flag = true;
        fprintf(yyout, "[BREAK] Break statement\n");
    }
#line 1444 "jujutsu.tab.c"
    break;

  case 38: /* continue_statement: KW_CONTINUE SEMICOLON  */
#line 245 "jujutsu.y"
    {
        continue_flag = true;
        fprintf(yyout, "[CONTINUE] Continue statement\n");
    }
#line 1453 "jujutsu.tab.c"
    break;

  case 39: /* switch_statement: KW_SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE  */
#line 253 "jujutsu.y"
    {
        fprintf(yyout, "[SWITCH] Switch statement executed\n");
    }
#line 1461 "jujutsu.tab.c"
    break;

  case 42: /* case_item: KW_CASE expression COLON statement_list  */
#line 265 "jujutsu.y"
    {
        fprintf(yyout, "[CASE] Case %g executed\n", (yyvsp[-2].fval));
    }
#line 1469 "jujutsu.tab.c"
    break;

  case 43: /* expression: assignment_expr  */
#line 273 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1477 "jujutsu.tab.c"
    break;

  case 44: /* assignment_expr: logical_or_expr  */
#line 280 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1485 "jujutsu.tab.c"
    break;

  case 45: /* assignment_expr: IDENTIFIER OP_ASSIGN assignment_expr  */
#line 284 "jujutsu.y"
    {
        if (variables.find((yyvsp[-2].sval)) == variables.end()) {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", (yyvsp[-2].sval), line_number);
            (yyval.fval) = 0;
        } else {
            variables[(yyvsp[-2].sval)] = (yyvsp[0].fval);
            (yyval.fval) = (yyvsp[0].fval);
            fprintf(yyout, "[ASSIGN] %s = %g\n", (yyvsp[-2].sval), (yyvsp[0].fval));
        }
    }
#line 1500 "jujutsu.tab.c"
    break;

  case 46: /* logical_or_expr: logical_and_expr  */
#line 298 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1508 "jujutsu.tab.c"
    break;

  case 47: /* logical_or_expr: logical_or_expr OP_OR logical_and_expr  */
#line 302 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[-2].fval) || (yyvsp[0].fval)) ? 1 : 0;
        fprintf(yyout, "[OP] %g || %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1517 "jujutsu.tab.c"
    break;

  case 48: /* logical_and_expr: equality_expr  */
#line 310 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1525 "jujutsu.tab.c"
    break;

  case 49: /* logical_and_expr: logical_and_expr OP_AND equality_expr  */
#line 314 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[-2].fval) && (yyvsp[0].fval)) ? 1 : 0;
        fprintf(yyout, "[OP] %g && %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1534 "jujutsu.tab.c"
    break;

  case 50: /* equality_expr: relational_expr  */
#line 322 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1542 "jujutsu.tab.c"
    break;

  case 51: /* equality_expr: equality_expr OP_EQ relational_expr  */
#line 326 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[-2].fval) == (yyvsp[0].fval)) ? 1 : 0;
        fprintf(yyout, "[OP] %g == %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1551 "jujutsu.tab.c"
    break;

  case 52: /* equality_expr: equality_expr OP_NEQ relational_expr  */
#line 331 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[-2].fval) != (yyvsp[0].fval)) ? 1 : 0;
        fprintf(yyout, "[OP] %g != %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1560 "jujutsu.tab.c"
    break;

  case 53: /* relational_expr: additive_expr  */
#line 339 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1568 "jujutsu.tab.c"
    break;

  case 54: /* relational_expr: relational_expr OP_LT additive_expr  */
#line 343 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[-2].fval) < (yyvsp[0].fval)) ? 1 : 0;
        fprintf(yyout, "[OP] %g < %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1577 "jujutsu.tab.c"
    break;

  case 55: /* relational_expr: relational_expr OP_GT additive_expr  */
#line 348 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[-2].fval) > (yyvsp[0].fval)) ? 1 : 0;
        fprintf(yyout, "[OP] %g > %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1586 "jujutsu.tab.c"
    break;

  case 56: /* relational_expr: relational_expr OP_LTE additive_expr  */
#line 353 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[-2].fval) <= (yyvsp[0].fval)) ? 1 : 0;
        fprintf(yyout, "[OP] %g <= %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1595 "jujutsu.tab.c"
    break;

  case 57: /* relational_expr: relational_expr OP_GTE additive_expr  */
#line 358 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[-2].fval) >= (yyvsp[0].fval)) ? 1 : 0;
        fprintf(yyout, "[OP] %g >= %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1604 "jujutsu.tab.c"
    break;

  case 58: /* additive_expr: multiplicative_expr  */
#line 366 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1612 "jujutsu.tab.c"
    break;

  case 59: /* additive_expr: additive_expr OP_ADD multiplicative_expr  */
#line 370 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[-2].fval) + (yyvsp[0].fval);
        fprintf(yyout, "[OP] %g + %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1621 "jujutsu.tab.c"
    break;

  case 60: /* additive_expr: additive_expr OP_DRAIN multiplicative_expr  */
#line 375 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[-2].fval) - (yyvsp[0].fval);
        fprintf(yyout, "[OP] %g - %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1630 "jujutsu.tab.c"
    break;

  case 61: /* multiplicative_expr: unary_expr  */
#line 383 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1638 "jujutsu.tab.c"
    break;

  case 62: /* multiplicative_expr: multiplicative_expr OP_MUL unary_expr  */
#line 387 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[-2].fval) * (yyvsp[0].fval);
        fprintf(yyout, "[OP] %g * %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
    }
#line 1647 "jujutsu.tab.c"
    break;

  case 63: /* multiplicative_expr: multiplicative_expr OP_DIV unary_expr  */
#line 392 "jujutsu.y"
    {
        if ((yyvsp[0].fval) != 0) {
            (yyval.fval) = (yyvsp[-2].fval) / (yyvsp[0].fval);
            fprintf(yyout, "[OP] %g / %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Division by zero at line %d\n", line_number);
            (yyval.fval) = 0;
        }
    }
#line 1661 "jujutsu.tab.c"
    break;

  case 64: /* multiplicative_expr: multiplicative_expr OP_MOD unary_expr  */
#line 402 "jujutsu.y"
    {
        if ((yyvsp[0].fval) != 0) {
            (yyval.fval) = (int)(yyvsp[-2].fval) % (int)(yyvsp[0].fval);
            fprintf(yyout, "[OP] %g %% %g = %g\n", (yyvsp[-2].fval), (yyvsp[0].fval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Modulo by zero at line %d\n", line_number);
            (yyval.fval) = 0;
        }
    }
#line 1675 "jujutsu.tab.c"
    break;

  case 65: /* unary_expr: postfix_expr  */
#line 415 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1683 "jujutsu.tab.c"
    break;

  case 66: /* unary_expr: OP_NOT unary_expr  */
#line 419 "jujutsu.y"
    {
        (yyval.fval) = ((yyvsp[0].fval) != 0) ? 0 : 1;
        fprintf(yyout, "[OP] !%g = %g\n", (yyvsp[0].fval), (yyval.fval));
    }
#line 1692 "jujutsu.tab.c"
    break;

  case 67: /* unary_expr: OP_DRAIN unary_expr  */
#line 424 "jujutsu.y"
    {
        (yyval.fval) = -(yyvsp[0].fval);
        fprintf(yyout, "[OP] -%g = %g\n", (yyvsp[0].fval), (yyval.fval));
    }
#line 1701 "jujutsu.tab.c"
    break;

  case 68: /* unary_expr: OP_INC IDENTIFIER  */
#line 429 "jujutsu.y"
    {
        if (variables.find((yyvsp[0].sval)) != variables.end()) {
            variables[(yyvsp[0].sval)]++;
            (yyval.fval) = variables[(yyvsp[0].sval)];
            fprintf(yyout, "[OP] ++%s = %g\n", (yyvsp[0].sval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s\n", (yyvsp[0].sval));
            (yyval.fval) = 0;
        }
    }
#line 1716 "jujutsu.tab.c"
    break;

  case 69: /* postfix_expr: primary_expr  */
#line 443 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
    }
#line 1724 "jujutsu.tab.c"
    break;

  case 70: /* postfix_expr: IDENTIFIER OP_INC  */
#line 447 "jujutsu.y"
    {
        if (variables.find((yyvsp[-1].sval)) != variables.end()) {
            (yyval.fval) = variables[(yyvsp[-1].sval)];
            variables[(yyvsp[-1].sval)]++;
            fprintf(yyout, "[OP] %s++ = %g (post-increment)\n", (yyvsp[-1].sval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s\n", (yyvsp[-1].sval));
            (yyval.fval) = 0;
        }
    }
#line 1739 "jujutsu.tab.c"
    break;

  case 71: /* postfix_expr: IDENTIFIER LPAREN RPAREN  */
#line 458 "jujutsu.y"
    {
        if (functions.find((yyvsp[-2].sval)) != functions.end()) {
            fprintf(yyout, "[CALL] Function: %s()\n", (yyvsp[-2].sval));
        } else {
            fprintf(stderr, "[ERROR] Undefined function: %s\n", (yyvsp[-2].sval));
        }
        (yyval.fval) = 0;
    }
#line 1752 "jujutsu.tab.c"
    break;

  case 72: /* postfix_expr: IDENTIFIER LPAREN argument_list RPAREN  */
#line 467 "jujutsu.y"
    {
        if (functions.find((yyvsp[-3].sval)) != functions.end()) {
            fprintf(yyout, "[CALL] Function: %s(...)\n", (yyvsp[-3].sval));
        } else {
            fprintf(stderr, "[ERROR] Undefined function: %s\n", (yyvsp[-3].sval));
        }
        (yyval.fval) = 0;
    }
#line 1765 "jujutsu.tab.c"
    break;

  case 75: /* primary_expr: IDENTIFIER  */
#line 484 "jujutsu.y"
    {
        if (variables.find((yyvsp[0].sval)) != variables.end()) {
            (yyval.fval) = variables[(yyvsp[0].sval)];
            fprintf(yyout, "[REF] Variable reference: %s = %g\n", (yyvsp[0].sval), (yyval.fval));
        } else {
            fprintf(stderr, "[ERROR] Undefined variable: %s at line %d\n", (yyvsp[0].sval), line_number);
            (yyval.fval) = 0;
        }
    }
#line 1779 "jujutsu.tab.c"
    break;

  case 76: /* primary_expr: LIT_INT  */
#line 494 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].ival);
        fprintf(yyout, "[LIT] Integer literal: %d\n", (int)(yyvsp[0].ival));
    }
#line 1788 "jujutsu.tab.c"
    break;

  case 77: /* primary_expr: LIT_FLOAT  */
#line 499 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[0].fval);
        fprintf(yyout, "[LIT] Float literal: %f\n", (yyvsp[0].fval));
    }
#line 1797 "jujutsu.tab.c"
    break;

  case 78: /* primary_expr: LPAREN expression RPAREN  */
#line 504 "jujutsu.y"
    {
        (yyval.fval) = (yyvsp[-1].fval);
        fprintf(yyout, "[EXPR] Parenthesized expression: %g\n", (yyval.fval));
    }
#line 1806 "jujutsu.tab.c"
    break;

  case 79: /* function_def: type IDENTIFIER LPAREN RPAREN compound_statement  */
#line 513 "jujutsu.y"
    {
        FunctionDef fdef;
        fdef.params.clear();
        fdef.body_line = line_number;
        functions[(yyvsp[-3].sval)] = fdef;
        fprintf(yyout, "[FUNC] Function '%s' defined (no parameters)\n", (yyvsp[-3].sval));
    }
#line 1818 "jujutsu.tab.c"
    break;

  case 80: /* function_def: type IDENTIFIER LPAREN parameter_list RPAREN compound_statement  */
#line 521 "jujutsu.y"
    {
        fprintf(yyout, "[FUNC] Function '%s' defined (with parameters)\n", (yyvsp[-4].sval));
    }
#line 1826 "jujutsu.tab.c"
    break;

  case 81: /* parameter_list: type IDENTIFIER  */
#line 528 "jujutsu.y"
    {
        fprintf(yyout, "[PARAM] Parameter: %s\n", (yyvsp[0].sval));
    }
#line 1834 "jujutsu.tab.c"
    break;

  case 82: /* parameter_list: parameter_list COMMA type IDENTIFIER  */
#line 532 "jujutsu.y"
    {
        fprintf(yyout, "[PARAM] Parameter: %s\n", (yyvsp[0].sval));
    }
#line 1842 "jujutsu.tab.c"
    break;


#line 1846 "jujutsu.tab.c"

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

#line 549 "jujutsu.y"


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

