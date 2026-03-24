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
    OP_ADD = 288,                  /* OP_ADD  */
    OP_DRAIN = 289,                /* OP_DRAIN  */
    OP_MUL = 290,                  /* OP_MUL  */
    OP_DIV = 291,                  /* OP_DIV  */
    OP_MOD = 292,                  /* OP_MOD  */
    OP_ASSIGN = 293,               /* OP_ASSIGN  */
    OP_EQ = 294,                   /* OP_EQ  */
    OP_NEQ = 295,                  /* OP_NEQ  */
    OP_LT = 296,                   /* OP_LT  */
    OP_GT = 297,                   /* OP_GT  */
    OP_LTE = 298,                  /* OP_LTE  */
    OP_GTE = 299,                  /* OP_GTE  */
    OP_AND = 300,                  /* OP_AND  */
    OP_OR = 301,                   /* OP_OR  */
    OP_NOT = 302,                  /* OP_NOT  */
    OP_INC = 303,                  /* OP_INC  */
    LIT_INT = 304,                 /* LIT_INT  */
    LIT_FLOAT = 305,               /* LIT_FLOAT  */
    LIT_CHAR = 306,                /* LIT_CHAR  */
    LIT_STRING = 307,              /* LIT_STRING  */
    IDENTIFIER = 308,              /* IDENTIFIER  */
    LPAREN = 309,                  /* LPAREN  */
    RPAREN = 310,                  /* RPAREN  */
    LBRACE = 311,                  /* LBRACE  */
    RBRACE = 312,                  /* RBRACE  */
    LBRACKET = 313,                /* LBRACKET  */
    RBRACKET = 314,                /* RBRACKET  */
    SEMICOLON = 315,               /* SEMICOLON  */
    COMMA = 316,                   /* COMMA  */
    DOT = 317,                     /* DOT  */
    COLON = 318,                   /* COLON  */
    ARROW = 319,                   /* ARROW  */
    AMPERSAND = 320,               /* AMPERSAND  */
    HASH = 321                     /* HASH  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 63 "jujutsu.y"

    int ival;
    double fval;
    char cval;
    char *sval;

#line 137 "jujutsu.tab.h"

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

#line 159 "jujutsu.tab.h"

#endif /* !YY_YY_JUJUTSU_TAB_H_INCLUDED  */
