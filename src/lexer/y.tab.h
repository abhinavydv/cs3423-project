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

#ifndef YY_YY_SRC_LEXER_Y_TAB_H_INCLUDED
# define YY_YY_SRC_LEXER_Y_TAB_H_INCLUDED
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
    DATA_TYPE = 258,               /* DATA_TYPE  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    STRING = 260,                  /* STRING  */
    IN = 261,                      /* IN  */
    DOTS = 262,                    /* DOTS  */
    CHAR = 263,                    /* CHAR  */
    RETURN = 264,                  /* RETURN  */
    INTEGER = 265,                 /* INTEGER  */
    CURVE = 266,                   /* CURVE  */
    FOR = 267,                     /* FOR  */
    STRUCT = 268,                  /* STRUCT  */
    AUG_ASSIGN = 269,              /* AUG_ASSIGN  */
    DIFF = 270,                    /* DIFF  */
    VOID = 271,                    /* VOID  */
    ARROW = 272,                   /* ARROW  */
    COMPARE = 273,                 /* COMPARE  */
    AND = 274,                     /* AND  */
    OR = 275,                      /* OR  */
    SHIFT = 276,                   /* SHIFT  */
    DECREMENT = 277,               /* DECREMENT  */
    INCREMENT = 278,               /* INCREMENT  */
    REAL = 279,                    /* REAL  */
    NEWLINE = 280,                 /* NEWLINE  */
    IF = 281,                      /* IF  */
    ELSE = 282,                    /* ELSE  */
    REPEAT = 283,                  /* REPEAT  */
    UNTIL = 284,                   /* UNTIL  */
    BREAK = 285,                   /* BREAK  */
    CONTINUE = 286,                /* CONTINUE  */
    IMPORT = 287,                  /* IMPORT  */
    TRUE = 288,                    /* TRUE  */
    FALSE = 289,                   /* FALSE  */
    FUNC = 290                     /* FUNC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DATA_TYPE 258
#define IDENTIFIER 259
#define STRING 260
#define IN 261
#define DOTS 262
#define CHAR 263
#define RETURN 264
#define INTEGER 265
#define CURVE 266
#define FOR 267
#define STRUCT 268
#define AUG_ASSIGN 269
#define DIFF 270
#define VOID 271
#define ARROW 272
#define COMPARE 273
#define AND 274
#define OR 275
#define SHIFT 276
#define DECREMENT 277
#define INCREMENT 278
#define REAL 279
#define NEWLINE 280
#define IF 281
#define ELSE 282
#define REPEAT 283
#define UNTIL 284
#define BREAK 285
#define CONTINUE 286
#define IMPORT 287
#define TRUE 288
#define FALSE 289
#define FUNC 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_LEXER_Y_TAB_H_INCLUDED  */
