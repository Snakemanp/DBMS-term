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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,                      /* ID  */
    STRING_LITERAL = 259,          /* STRING_LITERAL  */
    OPERATOR = 260,                /* OPERATOR  */
    NUM = 261,                     /* NUM  */
    SELECT = 262,                  /* SELECT  */
    ALL = 263,                     /* ALL  */
    DISTINCT = 264,                /* DISTINCT  */
    FROM = 265,                    /* FROM  */
    WHERE = 266,                   /* WHERE  */
    GROUP = 267,                   /* GROUP  */
    BY = 268,                      /* BY  */
    HAVING = 269,                  /* HAVING  */
    ORDER = 270,                   /* ORDER  */
    ASC = 271,                     /* ASC  */
    DESC = 272,                    /* DESC  */
    USING = 273,                   /* USING  */
    NULLS = 274,                   /* NULLS  */
    FIRST = 275,                   /* FIRST  */
    LAST = 276,                    /* LAST  */
    UNION = 277,                   /* UNION  */
    INTERSECT = 278,               /* INTERSECT  */
    EXCEPT = 279,                  /* EXCEPT  */
    INSERT = 280,                  /* INSERT  */
    INTO = 281,                    /* INTO  */
    VALUES = 282,                  /* VALUES  */
    DEFAULT = 283,                 /* DEFAULT  */
    WITH = 284,                    /* WITH  */
    RECURSIVE = 285,               /* RECURSIVE  */
    AS = 286,                      /* AS  */
    UPDATE = 287,                  /* UPDATE  */
    ONLY = 288,                    /* ONLY  */
    SET = 289,                     /* SET  */
    ROW = 290,                     /* ROW  */
    DELETE = 291,                  /* DELETE  */
    EXISTS = 292,                  /* EXISTS  */
    BETWEEN = 293,                 /* BETWEEN  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    IN = 296,                      /* IN  */
    INNER = 297,                   /* INNER  */
    NATURAL = 298,                 /* NATURAL  */
    LEFT = 299,                    /* LEFT  */
    RIGHT = 300,                   /* RIGHT  */
    FULL = 301,                    /* FULL  */
    CROSS = 302,                   /* CROSS  */
    JOIN = 303,                    /* JOIN  */
    ON = 304,                      /* ON  */
    IS = 305,                      /* IS  */
    NOT = 306,                     /* NOT  */
    NULL_VAL = 307,                /* NULL_VAL  */
    SEMICOLON = 308,               /* SEMICOLON  */
    COMMA = 309,                   /* COMMA  */
    DOT = 310,                     /* DOT  */
    ASTERISK = 311,                /* ASTERISK  */
    LPAREN = 312,                  /* LPAREN  */
    RPAREN = 313,                  /* RPAREN  */
    EQ = 314,                      /* EQ  */
    NE = 315,                      /* NE  */
    LT = 316,                      /* LT  */
    GT = 317,                      /* GT  */
    LE = 318,                      /* LE  */
    GE = 319,                      /* GE  */
    CONCAT = 320,                  /* CONCAT  */
    PLUS = 321,                    /* PLUS  */
    MINUS = 322,                   /* MINUS  */
    DIV = 323,                     /* DIV  */
    UMINUS = 324                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define STRING_LITERAL 259
#define OPERATOR 260
#define NUM 261
#define SELECT 262
#define ALL 263
#define DISTINCT 264
#define FROM 265
#define WHERE 266
#define GROUP 267
#define BY 268
#define HAVING 269
#define ORDER 270
#define ASC 271
#define DESC 272
#define USING 273
#define NULLS 274
#define FIRST 275
#define LAST 276
#define UNION 277
#define INTERSECT 278
#define EXCEPT 279
#define INSERT 280
#define INTO 281
#define VALUES 282
#define DEFAULT 283
#define WITH 284
#define RECURSIVE 285
#define AS 286
#define UPDATE 287
#define ONLY 288
#define SET 289
#define ROW 290
#define DELETE 291
#define EXISTS 292
#define BETWEEN 293
#define AND 294
#define OR 295
#define IN 296
#define INNER 297
#define NATURAL 298
#define LEFT 299
#define RIGHT 300
#define FULL 301
#define CROSS 302
#define JOIN 303
#define ON 304
#define IS 305
#define NOT 306
#define NULL_VAL 307
#define SEMICOLON 308
#define COMMA 309
#define DOT 310
#define ASTERISK 311
#define LPAREN 312
#define RPAREN 313
#define EQ 314
#define NE 315
#define LT 316
#define GT 317
#define LE 318
#define GE 319
#define CONCAT 320
#define PLUS 321
#define MINUS 322
#define DIV 323
#define UMINUS 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

    char* str;
    int num;
    struct ASTNode* node;

#line 211 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
