/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_JUJUTSU_TAB_H_INCLUDED
# define YY_YY_JUJUTSU_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_INT = 258,                  /* KW_INT  */
    KW_FLOAT = 259,                /* KW_FLOAT  */
    KW_DOUBLE = 260,               /* KW_DOUBLE  */
    KW_CHAR = 261,                 /* KW_CHAR  */
    KW_VOID = 262,                 /* KW_VOID  */
    KW_IF = 263,                   /* KW_IF  */
    KW_ELSE = 264,                 /* KW_ELSE  */
    KW_SWITCH = 265,               /* KW_SWITCH  */
    KW_CASE = 266,                 /* KW_CASE  */
    KW_FOR = 267,                  /* KW_FOR  */
    KW_WHILE = 268,                /* KW_WHILE  */
    KW_DO = 269,                   /* KW_DO  */
    KW_BREAK = 270,                /* KW_BREAK  */
    KW_CONTINUE = 271,             /* KW_CONTINUE  */
    KW_RETURN = 272,               /* KW_RETURN  */
    KW_STRUCT = 273,               /* KW_STRUCT  */
    KW_TYPEDEF = 274,              /* KW_TYPEDEF  */
    KW_ENUM = 275,                 /* KW_ENUM  */
    KW_CONST = 276,                /* KW_CONST  */
    KW_STATIC = 277,               /* KW_STATIC  */
    KW_EXTERN = 278,               /* KW_EXTERN  */
    KW_SIZEOF = 279,               /* KW_SIZEOF  */
    KW_GOTO = 280,                 /* KW_GOTO  */
    KW_MAIN = 281,                 /* KW_MAIN  */
    KW_UNION = 282,                /* KW_UNION  */
    KW_VOLATILE = 283,             /* KW_VOLATILE  */
    KW_REGISTER = 284,             /* KW_REGISTER  */
    KW_SIGNED = 285,               /* KW_SIGNED  */
    KW_UNSIGNED = 286,             /* KW_UNSIGNED  */
    KW_BREAKPOINT = 287,           /* KW_BREAKPOINT  */
    KW_PRINTF = 288,               /* KW_PRINTF  */
    KW_SCANF = 289,                /* KW_SCANF  */
    OP_ADD = 290,                  /* OP_ADD  */
    OP_DRAIN = 291,                /* OP_DRAIN  */
    OP_MUL = 292,                  /* OP_MUL  */
    OP_DIV = 293,                  /* OP_DIV  */
    OP_MOD = 294,                  /* OP_MOD  */
    OP_ASSIGN = 295,               /* OP_ASSIGN  */
    OP_EQ = 296,                   /* OP_EQ  */
    OP_NEQ = 297,                  /* OP_NEQ  */
    OP_LT = 298,                   /* OP_LT  */
    OP_GT = 299,                   /* OP_GT  */
    OP_LTE = 300,                  /* OP_LTE  */
    OP_GTE = 301,                  /* OP_GTE  */
    OP_AND = 302,                  /* OP_AND  */
    OP_OR = 303,                   /* OP_OR  */
    OP_NOT = 304,                  /* OP_NOT  */
    OP_INC = 305,                  /* OP_INC  */
    LIT_INT = 306,                 /* LIT_INT  */
    LIT_FLOAT = 307,               /* LIT_FLOAT  */
    LIT_CHAR = 308,                /* LIT_CHAR  */
    LIT_STRING = 309,              /* LIT_STRING  */
    IDENTIFIER = 310,              /* IDENTIFIER  */
    LPAREN = 311,                  /* LPAREN  */
    RPAREN = 312,                  /* RPAREN  */
    LBRACE = 313,                  /* LBRACE  */
    RBRACE = 314,                  /* RBRACE  */
    LBRACKET = 315,                /* LBRACKET  */
    RBRACKET = 316,                /* RBRACKET  */
    SEMICOLON = 317,               /* SEMICOLON  */
    COMMA = 318,                   /* COMMA  */
    DOT = 319,                     /* DOT  */
    COLON = 320,                   /* COLON  */
    ARROW = 321,                   /* ARROW  */
    AMPERSAND = 322,               /* AMPERSAND  */
    HASH = 323,                    /* HASH  */
    LOWER_THAN_ELSE = 324          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 119 "jujutsu.y"

    int ival;
    double fval;
    char cval;
    char *sval;

#line 140 "jujutsu.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);

/* "%code provides" blocks.  */
#line 17 "jujutsu.y"

    #define YY_DECL int yylex(void)
    extern int yylex(void);
    extern FILE *yyout;
    extern int line_number;

#line 162 "jujutsu.tab.h"

#endif /* !YY_YY_JUJUTSU_TAB_H_INCLUDED  */
