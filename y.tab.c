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




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sql_parser.h"

extern int yylex();
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

void yyerror(const char* s);
ASTNode* create_node(NodeType type, const char* value);
void print_tree(ASTNode* node, int depth);

ASTNode* parse_tree[10];
int parse_tree_count =0;

extern int num_tables;
extern TABLE *tables;

#line 93 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 24 "parser.y"

    char* str;
    int num;
    struct ASTNode* node;

#line 290 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_STRING_LITERAL = 4,             /* STRING_LITERAL  */
  YYSYMBOL_OPERATOR = 5,                   /* OPERATOR  */
  YYSYMBOL_NUM = 6,                        /* NUM  */
  YYSYMBOL_SELECT = 7,                     /* SELECT  */
  YYSYMBOL_ALL = 8,                        /* ALL  */
  YYSYMBOL_DISTINCT = 9,                   /* DISTINCT  */
  YYSYMBOL_FROM = 10,                      /* FROM  */
  YYSYMBOL_WHERE = 11,                     /* WHERE  */
  YYSYMBOL_GROUP = 12,                     /* GROUP  */
  YYSYMBOL_BY = 13,                        /* BY  */
  YYSYMBOL_HAVING = 14,                    /* HAVING  */
  YYSYMBOL_ORDER = 15,                     /* ORDER  */
  YYSYMBOL_ASC = 16,                       /* ASC  */
  YYSYMBOL_DESC = 17,                      /* DESC  */
  YYSYMBOL_USING = 18,                     /* USING  */
  YYSYMBOL_NULLS = 19,                     /* NULLS  */
  YYSYMBOL_FIRST = 20,                     /* FIRST  */
  YYSYMBOL_LAST = 21,                      /* LAST  */
  YYSYMBOL_UNION = 22,                     /* UNION  */
  YYSYMBOL_INTERSECT = 23,                 /* INTERSECT  */
  YYSYMBOL_EXCEPT = 24,                    /* EXCEPT  */
  YYSYMBOL_INSERT = 25,                    /* INSERT  */
  YYSYMBOL_INTO = 26,                      /* INTO  */
  YYSYMBOL_VALUES = 27,                    /* VALUES  */
  YYSYMBOL_DEFAULT = 28,                   /* DEFAULT  */
  YYSYMBOL_WITH = 29,                      /* WITH  */
  YYSYMBOL_RECURSIVE = 30,                 /* RECURSIVE  */
  YYSYMBOL_AS = 31,                        /* AS  */
  YYSYMBOL_UPDATE = 32,                    /* UPDATE  */
  YYSYMBOL_ONLY = 33,                      /* ONLY  */
  YYSYMBOL_SET = 34,                       /* SET  */
  YYSYMBOL_ROW = 35,                       /* ROW  */
  YYSYMBOL_DELETE = 36,                    /* DELETE  */
  YYSYMBOL_EXISTS = 37,                    /* EXISTS  */
  YYSYMBOL_BETWEEN = 38,                   /* BETWEEN  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_IN = 41,                        /* IN  */
  YYSYMBOL_INNER = 42,                     /* INNER  */
  YYSYMBOL_NATURAL = 43,                   /* NATURAL  */
  YYSYMBOL_LEFT = 44,                      /* LEFT  */
  YYSYMBOL_RIGHT = 45,                     /* RIGHT  */
  YYSYMBOL_FULL = 46,                      /* FULL  */
  YYSYMBOL_CROSS = 47,                     /* CROSS  */
  YYSYMBOL_JOIN = 48,                      /* JOIN  */
  YYSYMBOL_ON = 49,                        /* ON  */
  YYSYMBOL_IS = 50,                        /* IS  */
  YYSYMBOL_NOT = 51,                       /* NOT  */
  YYSYMBOL_NULL_VAL = 52,                  /* NULL_VAL  */
  YYSYMBOL_SEMICOLON = 53,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 54,                     /* COMMA  */
  YYSYMBOL_DOT = 55,                       /* DOT  */
  YYSYMBOL_ASTERISK = 56,                  /* ASTERISK  */
  YYSYMBOL_LPAREN = 57,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 58,                    /* RPAREN  */
  YYSYMBOL_EQ = 59,                        /* EQ  */
  YYSYMBOL_NE = 60,                        /* NE  */
  YYSYMBOL_LT = 61,                        /* LT  */
  YYSYMBOL_GT = 62,                        /* GT  */
  YYSYMBOL_LE = 63,                        /* LE  */
  YYSYMBOL_GE = 64,                        /* GE  */
  YYSYMBOL_CONCAT = 65,                    /* CONCAT  */
  YYSYMBOL_PLUS = 66,                      /* PLUS  */
  YYSYMBOL_MINUS = 67,                     /* MINUS  */
  YYSYMBOL_DIV = 68,                       /* DIV  */
  YYSYMBOL_UMINUS = 69,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_statement_list = 72,            /* statement_list  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_query = 74,                     /* query  */
  YYSYMBOL_set_op = 75,                    /* set_op  */
  YYSYMBOL_select_stmt = 76,               /* select_stmt  */
  YYSYMBOL_with_clause_opt = 77,           /* with_clause_opt  */
  YYSYMBOL_with_clause = 78,               /* with_clause  */
  YYSYMBOL_recursive_opt = 79,             /* recursive_opt  */
  YYSYMBOL_with_query_list = 80,           /* with_query_list  */
  YYSYMBOL_with_query = 81,                /* with_query  */
  YYSYMBOL_select_opts = 82,               /* select_opts  */
  YYSYMBOL_column_list = 83,               /* column_list  */
  YYSYMBOL_column = 84,                    /* column  */
  YYSYMBOL_as_id_opt = 85,                 /* as_id_opt  */
  YYSYMBOL_modified_id = 86,               /* modified_id  */
  YYSYMBOL_from_clause = 87,               /* from_clause  */
  YYSYMBOL_from_item_list = 88,            /* from_item_list  */
  YYSYMBOL_from_item = 89,                 /* from_item  */
  YYSYMBOL_join_type = 90,                 /* join_type  */
  YYSYMBOL_where_clause = 91,              /* where_clause  */
  YYSYMBOL_group_clause = 92,              /* group_clause  */
  YYSYMBOL_group_item_list = 93,           /* group_item_list  */
  YYSYMBOL_having_clause = 94,             /* having_clause  */
  YYSYMBOL_order_clause = 95,              /* order_clause  */
  YYSYMBOL_order_item_list = 96,           /* order_item_list  */
  YYSYMBOL_order_item = 97,                /* order_item  */
  YYSYMBOL_order_option = 98,              /* order_option  */
  YYSYMBOL_nulls_option = 99,              /* nulls_option  */
  YYSYMBOL_insert_stmt = 100,              /* insert_stmt  */
  YYSYMBOL_column_list_opt = 101,          /* column_list_opt  */
  YYSYMBOL_column_name_list = 102,         /* column_name_list  */
  YYSYMBOL_insert_values = 103,            /* insert_values  */
  YYSYMBOL_insert_value_list = 104,        /* insert_value_list  */
  YYSYMBOL_insert_value_items = 105,       /* insert_value_items  */
  YYSYMBOL_insert_value = 106,             /* insert_value  */
  YYSYMBOL_update_stmt = 107,              /* update_stmt  */
  YYSYMBOL_only_opt = 108,                 /* only_opt  */
  YYSYMBOL_asterisk_opt = 109,             /* asterisk_opt  */
  YYSYMBOL_set_clause = 110,               /* set_clause  */
  YYSYMBOL_set_item_list = 111,            /* set_item_list  */
  YYSYMBOL_set_item = 112,                 /* set_item  */
  YYSYMBOL_set_value = 113,                /* set_value  */
  YYSYMBOL_column_name = 114,              /* column_name  */
  YYSYMBOL_delete_stmt = 115,              /* delete_stmt  */
  YYSYMBOL_using_clause_opt = 116,         /* using_clause_opt  */
  YYSYMBOL_expression = 117,               /* expression  */
  YYSYMBOL_and_condition = 118,            /* and_condition  */
  YYSYMBOL_condition = 119,                /* condition  */
  YYSYMBOL_not_opt = 120,                  /* not_opt  */
  YYSYMBOL_in_items = 121,                 /* in_items  */
  YYSYMBOL_comparison_op = 122,            /* comparison_op  */
  YYSYMBOL_operand = 123,                  /* operand  */
  YYSYMBOL_summand = 124,                  /* summand  */
  YYSYMBOL_factor = 125,                   /* factor  */
  YYSYMBOL_term = 126                      /* term  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

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
       0,    81,    81,    87,    90,    96,   115,   119,   123,   127,
     131,   145,   149,   153,   161,   224,   229,   235,   246,   251,
     257,   261,   271,   280,   284,   289,   295,   306,   319,   326,
     330,   339,   343,   348,   354,   358,   367,   372,   378,   382,
     386,   396,   407,   420,   440,   460,   464,   468,   472,   476,
     480,   484,   491,   497,   503,   509,   515,   519,   529,   535,
     541,   547,   553,   557,   567,   588,   592,   597,   603,   607,
     612,   619,   647,   652,   658,   662,   672,   676,   681,   688,
     692,   702,   706,   716,   720,   728,   764,   769,   775,   780,
     786,   794,   798,   808,   815,   822,   829,   839,   843,   847,
     854,   862,   888,   894,   901,   905,   915,   919,   929,   933,
     939,   946,   965,  1001,  1006,  1012,  1016,  1023,  1027,  1031,
    1035,  1039,  1043,  1050,  1054,  1064,  1068,  1075,  1085,  1089,
    1096,  1106,  1110,  1114,  1120
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRING_LITERAL",
  "OPERATOR", "NUM", "SELECT", "ALL", "DISTINCT", "FROM", "WHERE", "GROUP",
  "BY", "HAVING", "ORDER", "ASC", "DESC", "USING", "NULLS", "FIRST",
  "LAST", "UNION", "INTERSECT", "EXCEPT", "INSERT", "INTO", "VALUES",
  "DEFAULT", "WITH", "RECURSIVE", "AS", "UPDATE", "ONLY", "SET", "ROW",
  "DELETE", "EXISTS", "BETWEEN", "AND", "OR", "IN", "INNER", "NATURAL",
  "LEFT", "RIGHT", "FULL", "CROSS", "JOIN", "ON", "IS", "NOT", "NULL_VAL",
  "SEMICOLON", "COMMA", "DOT", "ASTERISK", "LPAREN", "RPAREN", "EQ", "NE",
  "LT", "GT", "LE", "GE", "CONCAT", "PLUS", "MINUS", "DIV", "UMINUS",
  "$accept", "program", "statement_list", "statement", "query", "set_op",
  "select_stmt", "with_clause_opt", "with_clause", "recursive_opt",
  "with_query_list", "with_query", "select_opts", "column_list", "column",
  "as_id_opt", "modified_id", "from_clause", "from_item_list", "from_item",
  "join_type", "where_clause", "group_clause", "group_item_list",
  "having_clause", "order_clause", "order_item_list", "order_item",
  "order_option", "nulls_option", "insert_stmt", "column_list_opt",
  "column_name_list", "insert_values", "insert_value_list",
  "insert_value_items", "insert_value", "update_stmt", "only_opt",
  "asterisk_opt", "set_clause", "set_item_list", "set_item", "set_value",
  "column_name", "delete_stmt", "using_clause_opt", "expression",
  "and_condition", "condition", "not_opt", "in_items", "comparison_op",
  "operand", "summand", "factor", "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-115)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,    -9,    29,    17,  -109,   -22,   159,    83,  -109,  -109,
    -109,  -109,  -109,    34,  -109,  -109,  -109,  -109,  -109,  -109,
     155,   155,    53,    60,    86,    82,    44,  -109,  -109,  -109,
     -15,    32,   106,  -109,   126,   134,    85,    34,  -109,   137,
      99,  -109,  -109,  -109,    61,    -5,    25,  -109,  -109,    25,
     123,   181,   -15,  -109,    20,   145,    46,   109,    -2,  -109,
       5,    71,   190,  -109,   206,  -109,   153,  -109,    25,     5,
     190,   154,  -109,  -109,   208,  -109,    61,    61,    61,    61,
      61,    57,    25,   160,   124,    25,    49,   201,  -109,   212,
     122,   182,   160,  -109,  -109,   109,    -2,    -2,  -109,  -109,
     161,    67,  -109,    21,   169,   170,   172,   173,   174,   176,
    -109,   220,  -109,    49,    49,   185,   187,  -109,   143,   214,
     215,  -109,    68,   171,   203,  -109,  -109,    24,   221,    25,
    -109,   -15,   124,  -109,  -109,  -109,  -109,  -109,  -109,    25,
    -109,    45,   127,    49,    49,   183,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,   191,    61,   212,    49,   218,   212,  -109,
      55,   184,  -109,   212,  -109,   186,  -109,   177,   190,  -109,
     188,  -109,   187,  -109,   189,   178,   179,  -109,   192,   185,
     226,  -109,  -109,  -109,    69,  -109,   179,   193,    76,    24,
       6,  -109,    49,  -109,    12,   212,    61,    55,  -109,    55,
     194,  -109,  -109,  -109,   185,    97,   185,  -109,   195,   196,
    -109,   197,  -109,    75,  -109,    77,    37,  -109,    61,  -109,
    -109,   223,  -109,   198,    16,  -109,   175,  -109,    55,   199,
      78,  -109,  -109,    87,  -109,  -109,  -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      16,    19,     0,    16,     3,     0,     6,     0,    15,     7,
       8,     9,    18,     0,     1,     4,     5,    11,    12,    13,
      25,    25,     0,    87,     0,     0,    17,    20,    23,    24,
      16,     0,     0,    86,     0,     0,     0,     0,    10,     0,
      34,   134,   133,    28,     0,    37,    33,   132,    29,    33,
      89,   103,    16,    21,     0,    34,     0,   123,   125,   128,
       0,     0,    53,    32,     0,    26,    73,    88,    33,     0,
      53,     0,    35,    30,     0,   131,     0,     0,     0,     0,
       0,    16,    33,    36,    39,    33,     0,    55,    31,     0,
      16,     0,   102,   101,    22,   124,   126,   127,   129,   130,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    27,     0,     0,    52,   104,   106,   114,     0,
      59,    74,     0,     0,     0,    78,    71,     0,    37,    33,
      38,    16,    40,    45,    51,    46,    47,    48,    49,    33,
     109,     0,   114,     0,     0,   114,   113,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,    61,     0,    72,
       0,    77,    76,     0,   100,    90,    91,     0,    53,    42,
      44,   108,   105,   107,     0,     0,   110,    56,    54,    58,
       0,    14,    75,    84,     0,    81,    83,     0,     0,     0,
       0,    85,     0,   111,    16,     0,     0,     0,    79,     0,
       0,    92,    99,    93,    98,    97,    43,   116,   115,     0,
      57,    60,    62,    67,    82,     0,     0,   112,     0,    65,
      66,    70,    80,     0,    16,    63,     0,    64,     0,     0,
       0,    68,    69,     0,    96,    94,    95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,   240,   -51,  -109,   217,   222,  -109,  -109,
    -109,   211,   224,    62,   200,   -42,   -56,   130,    36,   156,
    -109,   -67,  -109,  -109,  -109,  -109,  -109,    42,  -109,  -109,
    -109,  -109,   100,  -109,  -109,  -104,    65,  -109,  -109,  -109,
    -109,  -109,    79,  -109,  -109,  -109,  -109,  -108,   121,  -102,
     125,  -109,  -109,   -44,   202,   120,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    20,     6,     7,     8,    13,
      26,    27,    30,    45,    46,    65,    47,    62,    83,    84,
     111,    87,   120,   178,   157,   181,   211,   212,   221,   227,
       9,    90,   122,   126,   161,   184,   185,    10,    34,    68,
     128,   165,   166,   203,   167,    11,    70,   115,   116,   117,
     153,   209,   154,   118,    57,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    71,    48,    93,    82,    60,   141,    66,    55,    55,
      41,   140,    42,    82,     1,    40,    41,    -2,    42,    55,
      41,    12,    42,    72,    55,    82,    91,    55,    63,    14,
     100,    16,    48,   121,   202,    40,    41,    25,    42,   125,
     102,     1,   173,   112,   183,     1,     1,    82,   179,    61,
      98,    99,    55,    41,    79,    42,    64,   113,    55,    41,
      55,    42,    81,   114,    55,    41,    80,    42,    43,    44,
     142,   164,   223,    44,    40,    41,    73,    42,   131,    32,
     100,   163,   204,   183,   206,   143,     1,   169,    43,    44,
      21,   219,   220,    33,   224,   215,    35,   170,    37,   177,
     113,   191,   182,   171,    75,    92,   114,   121,    22,    49,
     176,    76,    44,    36,    81,    23,   186,   101,    44,    24,
     230,   103,   158,   197,   233,   130,   159,   198,    44,    50,
     158,   197,   197,   164,   200,   222,   235,    51,  -114,   210,
      76,   197,    52,   207,    21,   236,   205,   145,   146,   123,
     124,     1,   213,   186,    54,   186,   147,   148,   149,   150,
     151,   152,    76,    28,    29,    48,   104,   105,   106,   107,
     108,   109,   110,   229,   213,    77,    78,   145,   146,    67,
     186,    17,    18,    19,   186,    75,   147,   148,   149,   150,
     151,   152,    76,   145,   146,   231,   232,    96,    97,    69,
      74,    86,   147,   148,   149,   150,   151,   152,    76,    88,
      89,    72,    94,   119,   103,    55,   127,   133,   134,   129,
     135,   136,   137,   139,   138,   143,   144,   155,   160,   156,
     162,    60,   175,   180,   146,   194,   190,   192,   187,   196,
     189,   193,   226,    15,    76,    31,   195,    38,    53,    61,
     199,   218,    39,   216,   217,   228,   208,   234,   168,   132,
     225,    85,   214,   188,   172,     0,     0,     0,   201,     0,
     174,     0,     0,     0,     0,     0,     0,     0,    95
};

static const yytype_int16 yycheck[] =
{
      44,    52,    31,    70,    60,    10,   114,    49,     3,     3,
       4,   113,     6,    69,    29,     3,     4,     0,     6,     3,
       4,    30,     6,     3,     3,    81,    68,     3,     3,     0,
      81,    53,    61,    89,    28,     3,     4,     3,     6,    90,
      82,    29,   144,    85,    28,    29,    29,   103,   156,    54,
      79,    80,     3,     4,    56,     6,    31,    51,     3,     4,
       3,     6,    57,    57,     3,     4,    68,     6,    56,    57,
     114,   127,    35,    57,     3,     4,    56,     6,    57,    26,
     131,    57,   190,    28,   192,    40,    29,   129,    56,    57,
       7,    16,    17,    33,    57,   199,    10,   139,    54,   155,
      51,   168,   158,    58,    58,    69,    57,   163,    25,     3,
     154,    65,    57,    31,    57,    32,   160,    81,    57,    36,
     224,    54,    54,    54,   228,    58,    58,    58,    57,     3,
      54,    54,    54,   189,    58,    58,    58,     3,    41,   195,
      65,    54,    57,   194,     7,    58,   190,    50,    51,    27,
      28,    29,   196,   197,    55,   199,    59,    60,    61,    62,
      63,    64,    65,     8,     9,   194,    42,    43,    44,    45,
      46,    47,    48,   224,   218,    66,    67,    50,    51,    56,
     224,    22,    23,    24,   228,    58,    59,    60,    61,    62,
      63,    64,    65,    50,    51,    20,    21,    77,    78,    18,
      55,    11,    59,    60,    61,    62,    63,    64,    65,     3,
      57,     3,    58,    12,    54,     3,    34,    48,    48,    58,
      48,    48,    48,     3,    48,    40,    39,    13,    57,    14,
      27,    10,    41,    15,    51,    57,    59,    49,    54,    13,
      54,    52,    19,     3,    65,    21,    54,    30,    37,    54,
      57,    54,    30,    59,    58,    57,   194,    58,   128,   103,
     218,    61,   197,   163,   143,    -1,    -1,    -1,   189,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    71,    72,    73,    74,    76,    77,    78,   100,
     107,   115,    30,    79,     0,    73,    53,    22,    23,    24,
      75,     7,    25,    32,    36,     3,    80,    81,     8,     9,
      82,    82,    26,    33,   108,    10,    31,    54,    76,    77,
       3,     4,     6,    56,    57,    83,    84,    86,   126,     3,
       3,     3,    57,    81,    55,     3,   123,   124,   125,   126,
      10,    54,    87,     3,    31,    85,    85,    56,   109,    18,
     116,    74,     3,    56,    55,    58,    65,    66,    67,    56,
      68,    57,    86,    88,    89,    84,    11,    91,     3,    57,
     101,    85,    88,    91,    58,   124,   125,   125,   126,   126,
      74,    88,    85,    54,    42,    43,    44,    45,    46,    47,
      48,    90,    85,    51,    57,   117,   118,   119,   123,    12,
      92,    86,   102,    27,    28,    74,   103,    34,   110,    58,
      58,    57,    89,    48,    48,    48,    48,    48,    48,     3,
     119,   117,   123,    40,    39,    50,    51,    59,    60,    61,
      62,    63,    64,   120,   122,    13,    14,    94,    54,    58,
      57,   104,    27,    57,    86,   111,   112,   114,    87,    85,
      85,    58,   118,   119,   120,    41,   123,    86,    93,   117,
      15,    95,    86,    28,   105,   106,   123,    54,   102,    54,
      59,    91,    49,    52,    57,    54,    13,    54,    58,    57,
      58,   112,    28,   113,   117,   123,   117,    74,    83,   121,
      86,    96,    97,   123,   106,   105,    59,    58,    54,    16,
      17,    98,    58,    35,    57,    97,    19,    99,    57,    74,
     105,    20,    21,   105,    58,    58,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    74,    74,    74,    74,
      74,    75,    75,    75,    76,    77,    77,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    83,    83,    83,    84,
      84,    85,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    98,    98,    98,    99,    99,
      99,   100,   101,   101,   102,   102,   103,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   108,   108,   109,   109,
     110,   111,   111,   112,   112,   112,   112,   113,   113,   113,
     114,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   122,   123,   123,   124,   124,   124,   125,   125,
     125,   126,   126,   126,   126
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       4,     1,     1,     1,     9,     1,     0,     3,     1,     0,
       1,     3,     5,     1,     1,     0,     2,     4,     1,     1,
       3,     2,     1,     0,     1,     3,     2,     0,     3,     1,
       3,     2,     4,     6,     4,     2,     2,     2,     2,     2,
       1,     2,     2,     0,     3,     0,     1,     3,     2,     0,
       3,     0,     1,     3,     3,     1,     1,     0,     2,     2,
       0,     7,     3,     0,     1,     3,     2,     2,     1,     3,
       5,     1,     3,     1,     1,     9,     1,     0,     1,     0,
       2,     1,     3,     3,     7,     8,     7,     1,     1,     1,
       1,     6,     2,     0,     1,     3,     1,     3,     3,     2,
       3,     4,     6,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     1
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
  case 2: /* program: statement_list  */
#line 82 "parser.y"
    {
    }
#line 1581 "y.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 88 "parser.y"
    {
    }
#line 1588 "y.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 91 "parser.y"
    {
    }
#line 1595 "y.tab.c"
    break;

  case 5: /* statement: query SEMICOLON  */
#line 97 "parser.y"
    {
        (yyval.node) = create_node(RA_SCOPE,NULL);
        (yyval.node)->left = (yyvsp[-1].node);
        parse_tree[parse_tree_count] = (yyval.node);
        parse_tree_count++;
        printf("\nOriginal Relational Algebra Tree for sql statement %d:\n",parse_tree_count);
        print_tree((yyvsp[-1].node), 0);

        printf("Cost of actual tree: %lld\n",cost_estimation((yyvsp[-1].node)));
        
        ASTNode* transformed_both = apply_transformations(deep_copy_tree((yyval.node)));
        printf("\nTree after Transformations:\n");
        print_tree(transformed_both, 0);
        printf("Cost of transformed tree: %lld\n",cost_estimation(transformed_both));
    }
#line 1615 "y.tab.c"
    break;

  case 6: /* query: select_stmt  */
#line 116 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1623 "y.tab.c"
    break;

  case 7: /* query: insert_stmt  */
#line 120 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1631 "y.tab.c"
    break;

  case 8: /* query: update_stmt  */
#line 124 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1639 "y.tab.c"
    break;

  case 9: /* query: delete_stmt  */
#line 128 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1647 "y.tab.c"
    break;

  case 10: /* query: select_stmt set_op select_opts select_stmt  */
#line 132 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        (yyval.node)->left = (yyvsp[-3].node);
        (yyval.node)->right = (yyvsp[0].node);
        if((yyvsp[-1].node) && strcmp((yyvsp[-1].node)->value, "DISTINCT") == 0) {
            ASTNode* distinct = create_node(RA_DISTINCT, (yyvsp[-1].node)->value);
            distinct->left = (yyval.node);
            (yyval.node) = distinct;
        }
    }
#line 1662 "y.tab.c"
    break;

  case 11: /* set_op: UNION  */
#line 146 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "∪");  // Union symbol
    }
#line 1670 "y.tab.c"
    break;

  case 12: /* set_op: INTERSECT  */
#line 150 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "∩");  // Intersection symbol
    }
#line 1678 "y.tab.c"
    break;

  case 13: /* set_op: EXCEPT  */
#line 154 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "−");  // Minus symbol
    }
#line 1686 "y.tab.c"
    break;

  case 14: /* select_stmt: with_clause_opt SELECT select_opts column_list from_clause where_clause group_clause having_clause order_clause  */
#line 162 "parser.y"
    {
        // Start building the tree from the bottom up
        ASTNode* base_tree = (yyvsp[-4].node);  // FROM clause
        
        // Apply WITH clause
        if ((yyvsp[-8].node) && (yyvsp[-8].node)->type != RA_EMPTY) {
            base_tree->left = (yyvsp[-8].node);
        }

        // Apply WHERE clause (σ - selection)
        if ((yyvsp[-3].node) && (yyvsp[-3].node)->type != RA_EMPTY) {
            ASTNode* selection = (yyvsp[-3].node);
            // selection->left = $6->left;  // Condition
            // selection->args = $6;
            selection->left = base_tree;
            base_tree = selection;
        }
        
        // Apply GROUP BY (γ - grouping)
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->type != RA_EMPTY) {
            ASTNode* grouping = (yyvsp[-2].node);
            // grouping->left = $7->left;  // Grouping columns
            // grouping->args = $7;
            grouping->left = base_tree;
            base_tree = grouping;
        }
        
        // Apply HAVING (σ - selection after grouping)
        if ((yyvsp[-1].node) && (yyvsp[-1].node)->type != RA_EMPTY) {
            ASTNode* having = (yyvsp[-1].node);
            // having->left = $8->left;  // Condition
            // having->args = $8;
            having->left = base_tree;
            base_tree = having;
        }
        
        // Apply projection (π)
        ASTNode* projection = create_node(RA_PROJECTION, "");
        projection->args = (yyvsp[-5].node);  // SELECT columns
        projection->left = base_tree;

        // Apply DISTINCT if specified
        if ((yyvsp[-6].node) && strcmp((yyvsp[-6].node)->value, "DISTINCT") == 0) {
            ASTNode* distinct = create_node(RA_DISTINCT, "DISTINCT");
            distinct->left = projection;
            (yyval.node) = distinct;
        }
        else{
            (yyval.node) = projection;
        }
        
        // Apply ORDER BY
        if ((yyvsp[0].node) && (yyvsp[0].node)->type != RA_EMPTY) {
            ASTNode* order = create_node(RA_ORDERBY, "");
            order->left = (yyval.node);
            (yyval.node) = order;
        }
        
    }
#line 1750 "y.tab.c"
    break;

  case 15: /* with_clause_opt: with_clause  */
#line 225 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1758 "y.tab.c"
    break;

  case 16: /* with_clause_opt: %empty  */
#line 229 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1766 "y.tab.c"
    break;

  case 17: /* with_clause: WITH recursive_opt with_query_list  */
#line 236 "parser.y"
    {
        (yyval.node) = create_node(RA_WITH, "");
        if (strcmp((yyvsp[-1].node)->value, "RECURSIVE") == 0) {
            strcpy((yyval.node)->value,"RECURSIVE") ; // Mark as recursive
        }
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 1778 "y.tab.c"
    break;

  case 18: /* recursive_opt: RECURSIVE  */
#line 247 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "RECURSIVE");
    }
#line 1786 "y.tab.c"
    break;

  case 19: /* recursive_opt: %empty  */
#line 251 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1794 "y.tab.c"
    break;

  case 20: /* with_query_list: with_query  */
#line 258 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1802 "y.tab.c"
    break;

  case 21: /* with_query_list: with_query_list COMMA with_query  */
#line 262 "parser.y"
    {
        ASTNode* list = create_node(RA_WITH_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 1813 "y.tab.c"
    break;

  case 22: /* with_query: ID AS LPAREN query RPAREN  */
#line 272 "parser.y"
    {
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[-4].str));
        (yyval.node)->left = create_node(RA_SCOPE,NULL);
        (yyval.node)->left->left = (yyvsp[-1].node);
    }
#line 1823 "y.tab.c"
    break;

  case 23: /* select_opts: ALL  */
#line 281 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ALL");
    }
#line 1831 "y.tab.c"
    break;

  case 24: /* select_opts: DISTINCT  */
#line 285 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DISTINCT");
    }
#line 1839 "y.tab.c"
    break;

  case 25: /* select_opts: %empty  */
#line 289 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1847 "y.tab.c"
    break;

  case 26: /* column_list: column as_id_opt  */
#line 296 "parser.y"
    {
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle column alias
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            alias->args = (yyvsp[-1].node);
            (yyval.node) = alias;
        } else {
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 1862 "y.tab.c"
    break;

  case 27: /* column_list: column_list COMMA column as_id_opt  */
#line 307 "parser.y"
    {
        ASTNode* col;
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle column alias
            col = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            col->args = (yyvsp[-1].node);
        } else {
            col = (yyvsp[-1].node);
        }
        (yyval.node) = (yyvsp[-3].node);
        (yyval.node)->left=col;
    }
#line 1879 "y.tab.c"
    break;

  case 28: /* column_list: ASTERISK  */
#line 320 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "*");
    }
#line 1887 "y.tab.c"
    break;

  case 29: /* column: term  */
#line 327 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1895 "y.tab.c"
    break;

  case 30: /* column: ID DOT ASTERISK  */
#line 331 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        snprintf(value, sizeof(value), "%s.*", (yyvsp[-2].str));
        (yyval.node) = create_node(RA_ATTRIBUTE, value);
    }
#line 1905 "y.tab.c"
    break;

  case 31: /* as_id_opt: AS ID  */
#line 340 "parser.y"
    {
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[0].str));
    }
#line 1913 "y.tab.c"
    break;

  case 32: /* as_id_opt: ID  */
#line 344 "parser.y"
    {
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[0].str));
    }
#line 1921 "y.tab.c"
    break;

  case 33: /* as_id_opt: %empty  */
#line 348 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1929 "y.tab.c"
    break;

  case 34: /* modified_id: ID  */
#line 355 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, (yyvsp[0].str));
    }
#line 1937 "y.tab.c"
    break;

  case 35: /* modified_id: ID DOT ID  */
#line 359 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        snprintf(value, sizeof(value), "%s.%s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.node) = create_node(RA_ATTRIBUTE, value);
    }
#line 1947 "y.tab.c"
    break;

  case 36: /* from_clause: FROM from_item_list  */
#line 368 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1955 "y.tab.c"
    break;

  case 37: /* from_clause: %empty  */
#line 372 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1963 "y.tab.c"
    break;

  case 38: /* from_item_list: LPAREN from_item_list RPAREN  */
#line 379 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1971 "y.tab.c"
    break;

  case 39: /* from_item_list: from_item  */
#line 383 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1979 "y.tab.c"
    break;

  case 40: /* from_item_list: from_item_list COMMA from_item  */
#line 387 "parser.y"
    {
        ASTNode* cross_join = create_node(RA_JOIN, "x");  // Cross product
        cross_join->left = (yyvsp[-2].node);
        cross_join->right = (yyvsp[0].node);
        (yyval.node) = cross_join;
    }
#line 1990 "y.tab.c"
    break;

  case 41: /* from_item: modified_id as_id_opt  */
#line 397 "parser.y"
    {
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle table alias
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            alias->left = create_node(RA_RELATION, (yyvsp[-1].node)->value);
            (yyval.node) = alias;
        } else {
            (yyval.node) = create_node(RA_RELATION, (yyvsp[-1].node)->value);
        }
    }
#line 2005 "y.tab.c"
    break;

  case 42: /* from_item: LPAREN query RPAREN as_id_opt  */
#line 408 "parser.y"
    {
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle table alias
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            alias->left = create_node(RA_SCOPE, NULL);
            alias->left->left = (yyvsp[-2].node);
            (yyval.node) = alias;
        } else {
            (yyval.node) = create_node(RA_SCOPE, NULL);
            (yyval.node)->left = (yyvsp[-2].node);
        }
    }
#line 2022 "y.tab.c"
    break;

  case 43: /* from_item: from_item join_type ID as_id_opt ON expression  */
#line 421 "parser.y"
    {
        ASTNode* right_relation;
        if ((yyvsp[-2].node)->type != RA_EMPTY) {
            right_relation = create_node(RA_ALIAS, (yyvsp[-2].node)->value);
            right_relation->left = create_node(RA_RELATION, (yyvsp[-3].str));
        } else {
            right_relation = create_node(RA_RELATION, (yyvsp[-3].str));
        }
        
        ASTNode* join = create_node(RA_JOIN, (yyvsp[-4].node)->value);
        join->left = (yyvsp[-5].node);
        join->right = right_relation;
        
        // Add join condition
        join->condition = (yyvsp[0].node);
        
        (yyval.node) = join;
        free((yyvsp[-4].node));
    }
#line 2046 "y.tab.c"
    break;

  case 44: /* from_item: from_item join_type ID as_id_opt  */
#line 441 "parser.y"
    {
        ASTNode* right_relation;
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            right_relation = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            right_relation->left = create_node(RA_RELATION, (yyvsp[-1].str));
        } else {
            right_relation = create_node(RA_RELATION, (yyvsp[-1].str));
        }
        
        ASTNode* join = create_node(RA_JOIN, (yyvsp[-2].node)->value);
        join->left = (yyvsp[-3].node);
        join->right = right_relation;
        
        (yyval.node) = join;
        free((yyvsp[-2].node));
    }
#line 2067 "y.tab.c"
    break;

  case 45: /* join_type: INNER JOIN  */
#line 461 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈");  // Join symbol
    }
#line 2075 "y.tab.c"
    break;

  case 46: /* join_type: LEFT JOIN  */
#line 465 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟕");  // Left join symbol
    }
#line 2083 "y.tab.c"
    break;

  case 47: /* join_type: RIGHT JOIN  */
#line 469 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟖");  // Right join symbol
    }
#line 2091 "y.tab.c"
    break;

  case 48: /* join_type: FULL JOIN  */
#line 473 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟗");  // Full join symbol
    }
#line 2099 "y.tab.c"
    break;

  case 49: /* join_type: CROSS JOIN  */
#line 477 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "x");  // Cross join symbol
    }
#line 2107 "y.tab.c"
    break;

  case 50: /* join_type: JOIN  */
#line 481 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈");  // Join symbol
    }
#line 2115 "y.tab.c"
    break;

  case 51: /* join_type: NATURAL JOIN  */
#line 485 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈ᴺ");  // Natural join symbol
    }
#line 2123 "y.tab.c"
    break;

  case 52: /* where_clause: WHERE expression  */
#line 492 "parser.y"
    {
        (yyval.node) = create_node(RA_SELECTION, "WHERE");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2132 "y.tab.c"
    break;

  case 53: /* where_clause: %empty  */
#line 497 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2140 "y.tab.c"
    break;

  case 54: /* group_clause: GROUP BY group_item_list  */
#line 504 "parser.y"
    {
        (yyval.node) = create_node(RA_GROUPBY, "GROUP BY");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2149 "y.tab.c"
    break;

  case 55: /* group_clause: %empty  */
#line 509 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2157 "y.tab.c"
    break;

  case 56: /* group_item_list: modified_id  */
#line 516 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2165 "y.tab.c"
    break;

  case 57: /* group_item_list: group_item_list COMMA modified_id  */
#line 520 "parser.y"
    {
        ASTNode* list = create_node(RA_GROUP_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2176 "y.tab.c"
    break;

  case 58: /* having_clause: HAVING expression  */
#line 530 "parser.y"
    {
        (yyval.node) = create_node(RA_SELECTION, "HAVING");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2185 "y.tab.c"
    break;

  case 59: /* having_clause: %empty  */
#line 535 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2193 "y.tab.c"
    break;

  case 60: /* order_clause: ORDER BY order_item_list  */
#line 542 "parser.y"
    {
        (yyval.node) = create_node(RA_ORDERBY, "ORDER BY");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2202 "y.tab.c"
    break;

  case 61: /* order_clause: %empty  */
#line 547 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2210 "y.tab.c"
    break;

  case 62: /* order_item_list: order_item  */
#line 554 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2218 "y.tab.c"
    break;

  case 63: /* order_item_list: order_item_list COMMA order_item  */
#line 558 "parser.y"
    {
        ASTNode* list = create_node(RA_ORDER_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2229 "y.tab.c"
    break;

  case 64: /* order_item: operand order_option nulls_option  */
#line 568 "parser.y"
    {
        char direction[MAX_STRING_LENGTH] = "";
        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            strncpy(direction, (yyvsp[-1].node)->value, MAX_STRING_LENGTH - 1);
        }
        
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            if (direction[0] != '\0') {
                strncat(direction, ", ", MAX_STRING_LENGTH - strlen(direction) - 1);
            }
            strncat(direction, (yyvsp[0].node)->value, MAX_STRING_LENGTH - strlen(direction) - 1);
        }
        
        ASTNode* order_item = create_node(RA_ORDER_ITEM, direction);
        order_item->left = (yyvsp[-2].node);
        (yyval.node) = order_item;
    }
#line 2251 "y.tab.c"
    break;

  case 65: /* order_option: ASC  */
#line 589 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ASC");
    }
#line 2259 "y.tab.c"
    break;

  case 66: /* order_option: DESC  */
#line 593 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DESC");
    }
#line 2267 "y.tab.c"
    break;

  case 67: /* order_option: %empty  */
#line 597 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2275 "y.tab.c"
    break;

  case 68: /* nulls_option: NULLS FIRST  */
#line 604 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NULLS FIRST");
    }
#line 2283 "y.tab.c"
    break;

  case 69: /* nulls_option: NULLS LAST  */
#line 608 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NULLS LAST");
    }
#line 2291 "y.tab.c"
    break;

  case 70: /* nulls_option: %empty  */
#line 612 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2299 "y.tab.c"
    break;

  case 71: /* insert_stmt: with_clause_opt INSERT INTO ID as_id_opt column_list_opt insert_values  */
#line 620 "parser.y"
    {
        ASTNode* target = create_node(RA_RELATION, (yyvsp[-3].str));
        
        // Apply WITH clause
        if ((yyvsp[-6].node) && (yyvsp[-6].node)->type != RA_EMPTY) {
            target->left = (yyvsp[-6].node);
        }

        if ((yyvsp[-2].node)->type != RA_EMPTY) {
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[-2].node)->value);
            alias->left = target;
            target = alias;
        }
        
        ASTNode* insert = create_node(RA_INSERT, "INSERT");
        insert->left = target;
        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            insert->right = (yyvsp[-1].node);  // Columns
        }
        
        insert->args = (yyvsp[0].node);  // Values or subquery
        
        (yyval.node) = insert;
    }
#line 2328 "y.tab.c"
    break;

  case 72: /* column_list_opt: LPAREN column_name_list RPAREN  */
#line 648 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2336 "y.tab.c"
    break;

  case 73: /* column_list_opt: %empty  */
#line 652 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2344 "y.tab.c"
    break;

  case 74: /* column_name_list: modified_id  */
#line 659 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2352 "y.tab.c"
    break;

  case 75: /* column_name_list: column_name_list COMMA modified_id  */
#line 663 "parser.y"
    {
        ASTNode* list = create_node(RA_COLUMN_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2363 "y.tab.c"
    break;

  case 76: /* insert_values: DEFAULT VALUES  */
#line 673 "parser.y"
    {
        (yyval.node) = create_node(RA_VALUES, "DEFAULT");
    }
#line 2371 "y.tab.c"
    break;

  case 77: /* insert_values: VALUES insert_value_list  */
#line 677 "parser.y"
    {
        (yyval.node) = create_node(RA_VALUES, "");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2380 "y.tab.c"
    break;

  case 78: /* insert_values: query  */
#line 682 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);  // Subquery
    }
#line 2388 "y.tab.c"
    break;

  case 79: /* insert_value_list: LPAREN insert_value_items RPAREN  */
#line 689 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2396 "y.tab.c"
    break;

  case 80: /* insert_value_list: insert_value_list COMMA LPAREN insert_value_items RPAREN  */
#line 693 "parser.y"
    {
        ASTNode* list = create_node(RA_VALUE_LIST, "");
        list->left = (yyvsp[-4].node);
        list->right = (yyvsp[-1].node);
        (yyval.node) = list;
    }
#line 2407 "y.tab.c"
    break;

  case 81: /* insert_value_items: insert_value  */
#line 703 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2415 "y.tab.c"
    break;

  case 82: /* insert_value_items: insert_value_items COMMA insert_value  */
#line 707 "parser.y"
    {
        ASTNode* list = create_node(RA_VALUE_ITEMS, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2426 "y.tab.c"
    break;

  case 83: /* insert_value: operand  */
#line 717 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2434 "y.tab.c"
    break;

  case 84: /* insert_value: DEFAULT  */
#line 721 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DEFAULT");
    }
#line 2442 "y.tab.c"
    break;

  case 85: /* update_stmt: with_clause_opt UPDATE only_opt ID asterisk_opt as_id_opt set_clause from_clause where_clause  */
#line 729 "parser.y"
    {
        ASTNode* target = create_node(RA_RELATION, (yyvsp[-5].str));

        // Apply WITH clause
        if ((yyvsp[-8].node) && (yyvsp[-8].node)->type != RA_EMPTY) {
            target->left = (yyvsp[-8].node);
        }

        if ((yyvsp[-3].node)->type != RA_EMPTY) {
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[-3].node)->value);
            alias->left = target;
            target = alias;
        }
        
        ASTNode* update = create_node(RA_UPDATE, "");
        update->left = target;
        update->args = (yyvsp[-2].node);  // SET clause
        
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            update->right = (yyvsp[0].node);  // WHERE condition
        }

        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            if(update->right==NULL)update->right = (yyvsp[-1].node);
            else{
                update->right->left = (yyvsp[-1].node);
            }
        }
        
        
        (yyval.node) = update;
    }
#line 2479 "y.tab.c"
    break;

  case 86: /* only_opt: ONLY  */
#line 765 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ONLY");
    }
#line 2487 "y.tab.c"
    break;

  case 87: /* only_opt: %empty  */
#line 769 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2495 "y.tab.c"
    break;

  case 88: /* asterisk_opt: ASTERISK  */
#line 776 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "*");
    }
#line 2503 "y.tab.c"
    break;

  case 89: /* asterisk_opt: %empty  */
#line 780 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2511 "y.tab.c"
    break;

  case 90: /* set_clause: SET set_item_list  */
#line 787 "parser.y"
    {
        (yyval.node) = create_node(RA_SET, "");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2520 "y.tab.c"
    break;

  case 91: /* set_item_list: set_item  */
#line 795 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2528 "y.tab.c"
    break;

  case 92: /* set_item_list: set_item_list COMMA set_item  */
#line 799 "parser.y"
    {
        ASTNode* list = create_node(RA_SET_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2539 "y.tab.c"
    break;

  case 93: /* set_item: column_name EQ set_value  */
#line 809 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-2].node);
        assignment->right = (yyvsp[0].node);
        (yyval.node) = assignment;
    }
#line 2550 "y.tab.c"
    break;

  case 94: /* set_item: LPAREN column_name_list RPAREN EQ LPAREN insert_value_items RPAREN  */
#line 816 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-5].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2561 "y.tab.c"
    break;

  case 95: /* set_item: LPAREN column_name_list RPAREN EQ ROW LPAREN insert_value_items RPAREN  */
#line 823 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "= ROW");
        assignment->left = (yyvsp[-6].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2572 "y.tab.c"
    break;

  case 96: /* set_item: LPAREN column_name_list RPAREN EQ LPAREN query RPAREN  */
#line 830 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-5].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2583 "y.tab.c"
    break;

  case 97: /* set_value: operand  */
#line 840 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2591 "y.tab.c"
    break;

  case 98: /* set_value: expression  */
#line 844 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2599 "y.tab.c"
    break;

  case 99: /* set_value: DEFAULT  */
#line 848 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DEFAULT");
    }
#line 2607 "y.tab.c"
    break;

  case 100: /* column_name: modified_id  */
#line 855 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2615 "y.tab.c"
    break;

  case 101: /* delete_stmt: with_clause_opt DELETE FROM ID using_clause_opt where_clause  */
#line 863 "parser.y"
    {
        ASTNode* target = create_node(RA_RELATION, (yyvsp[-2].str));
        
        // Apply WITH clause
        if ((yyvsp[-5].node) && (yyvsp[-5].node)->type != RA_EMPTY) {
            target->left = (yyvsp[-5].node);
        }

        ASTNode* delete = create_node(RA_DELETE, "");
        delete->left = target;
        
        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            delete->right = (yyvsp[-1].node);  // USING clause
        }
        
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            if(delete->right)delete->right->left = (yyvsp[0].node);  // WHERE condition
            else delete->right = (yyvsp[0].node);
        }
        
        (yyval.node) = delete;
    }
#line 2642 "y.tab.c"
    break;

  case 102: /* using_clause_opt: USING from_item_list  */
#line 889 "parser.y"
    {
        (yyval.node) = create_node(RA_USING, "");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2651 "y.tab.c"
    break;

  case 103: /* using_clause_opt: %empty  */
#line 894 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2659 "y.tab.c"
    break;

  case 104: /* expression: and_condition  */
#line 902 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2667 "y.tab.c"
    break;

  case 105: /* expression: expression OR and_condition  */
#line 906 "parser.y"
    {
        ASTNode* or_node = create_node(RA_OR, "OR");
        or_node->left = (yyvsp[-2].node);
        or_node->right = (yyvsp[0].node);
        (yyval.node) = or_node;
    }
#line 2678 "y.tab.c"
    break;

  case 106: /* and_condition: condition  */
#line 916 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2686 "y.tab.c"
    break;

  case 107: /* and_condition: and_condition AND condition  */
#line 920 "parser.y"
    {
        ASTNode* and_node = create_node(RA_AND, "AND");
        and_node->left = (yyvsp[-2].node);
        and_node->right = (yyvsp[0].node);
        (yyval.node) = and_node;
    }
#line 2697 "y.tab.c"
    break;

  case 108: /* condition: LPAREN expression RPAREN  */
#line 930 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2705 "y.tab.c"
    break;

  case 109: /* condition: NOT condition  */
#line 934 "parser.y"
    {
        ASTNode* not_node = create_node(RA_NOT, "NOT");
        not_node->left = (yyvsp[0].node);
        (yyval.node) = not_node;
    }
#line 2715 "y.tab.c"
    break;

  case 110: /* condition: operand comparison_op operand  */
#line 940 "parser.y"
    {
        ASTNode* comp = create_node(RA_COMPARISON, (yyvsp[-1].node)->value);
        comp->left = (yyvsp[-2].node);
        comp->right = (yyvsp[0].node);
        (yyval.node) = comp;
    }
#line 2726 "y.tab.c"
    break;

  case 111: /* condition: operand IS not_opt NULL_VAL  */
#line 947 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            snprintf(value, sizeof(value), "IS NOT NULL");
        } else {
            snprintf(value, sizeof(value), "IS NULL");
        }
        
        ASTNode* null_check = create_node(RA_NULL_CHECK, value);
        null_check->left = (yyvsp[-3].node);
        (yyval.node) = null_check;
    }
#line 2743 "y.tab.c"
    break;

  case 112: /* condition: operand not_opt IN LPAREN in_items RPAREN  */
#line 966 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        if ((yyvsp[-4].node)->type != RA_EMPTY) {
            snprintf(value, sizeof(value), "NOT IN");
        } else {
            snprintf(value, sizeof(value), "IN");
        }
        
        ASTNode* in_check = create_node(RA_IN, value);
        in_check->left = (yyvsp[-5].node);
        in_check->right = (yyvsp[-1].node);
        (yyval.node) = in_check;
    }
#line 2761 "y.tab.c"
    break;

  case 113: /* not_opt: NOT  */
#line 1002 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NOT");
    }
#line 2769 "y.tab.c"
    break;

  case 114: /* not_opt: %empty  */
#line 1006 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2777 "y.tab.c"
    break;

  case 115: /* in_items: column_list  */
#line 1013 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2785 "y.tab.c"
    break;

  case 116: /* in_items: query  */
#line 1017 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2793 "y.tab.c"
    break;

  case 117: /* comparison_op: EQ  */
#line 1024 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "=");
    }
#line 2801 "y.tab.c"
    break;

  case 118: /* comparison_op: NE  */
#line 1028 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<>");
    }
#line 2809 "y.tab.c"
    break;

  case 119: /* comparison_op: LT  */
#line 1032 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<");
    }
#line 2817 "y.tab.c"
    break;

  case 120: /* comparison_op: GT  */
#line 1036 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, ">");
    }
#line 2825 "y.tab.c"
    break;

  case 121: /* comparison_op: LE  */
#line 1040 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<=");
    }
#line 2833 "y.tab.c"
    break;

  case 122: /* comparison_op: GE  */
#line 1044 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, ">=");
    }
#line 2841 "y.tab.c"
    break;

  case 123: /* operand: summand  */
#line 1051 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2849 "y.tab.c"
    break;

  case 124: /* operand: operand CONCAT summand  */
#line 1055 "parser.y"
    {
        ASTNode* concat = create_node(RA_CONCAT, "||");
        concat->left = (yyvsp[-2].node);
        concat->right = (yyvsp[0].node);
        (yyval.node) = concat;
    }
#line 2860 "y.tab.c"
    break;

  case 125: /* summand: factor  */
#line 1065 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2868 "y.tab.c"
    break;

  case 126: /* summand: summand PLUS factor  */
#line 1069 "parser.y"
    {
        ASTNode* add = create_node(RA_ARITHMETIC, "+");
        add->left = (yyvsp[-2].node);
        add->right = (yyvsp[0].node);
        (yyval.node) = add;
    }
#line 2879 "y.tab.c"
    break;

  case 127: /* summand: summand MINUS factor  */
#line 1076 "parser.y"
    {
        ASTNode* subtract = create_node(RA_ARITHMETIC, "-");
        subtract->left = (yyvsp[-2].node);
        subtract->right = (yyvsp[0].node);
        (yyval.node) = subtract;
    }
#line 2890 "y.tab.c"
    break;

  case 128: /* factor: term  */
#line 1086 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2898 "y.tab.c"
    break;

  case 129: /* factor: factor ASTERISK term  */
#line 1090 "parser.y"
    {
        ASTNode* multiply = create_node(RA_ARITHMETIC, "*");
        multiply->left = (yyvsp[-2].node);
        multiply->right = (yyvsp[0].node);
        (yyval.node) = multiply;
    }
#line 2909 "y.tab.c"
    break;

  case 130: /* factor: factor DIV term  */
#line 1097 "parser.y"
    {
        ASTNode* divide = create_node(RA_ARITHMETIC, "/");
        divide->left = (yyvsp[-2].node);
        divide->right = (yyvsp[0].node);
        (yyval.node) = divide;
    }
#line 2920 "y.tab.c"
    break;

  case 131: /* term: LPAREN operand RPAREN  */
#line 1107 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2928 "y.tab.c"
    break;

  case 132: /* term: modified_id  */
#line 1111 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2936 "y.tab.c"
    break;

  case 133: /* term: NUM  */
#line 1115 "parser.y"
    {
        char value[32];
        snprintf(value, sizeof(value), "%d", (yyvsp[0].num));
        (yyval.node) = create_node(RA_LITERAL, value);
    }
#line 2946 "y.tab.c"
    break;

  case 134: /* term: STRING_LITERAL  */
#line 1121 "parser.y"
    {
        (yyval.node) = create_node(RA_LITERAL, (yyvsp[0].str));
    }
#line 2954 "y.tab.c"
    break;


#line 2958 "y.tab.c"

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

#line 1126 "parser.y"




void yyerror(const char* s) {
    fprintf(stderr, "Parse error on line %d: %s at '%s'\n", yylineno, s, yytext);
    exit(1);
}

ASTNode* create_node(NodeType type, const char* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    node->type = type;
    if (value) {
        strncpy(node->value, value, MAX_STRING_LENGTH - 1);
        node->value[MAX_STRING_LENGTH - 1] = '\0';
    } else {
        node->value[0] = '\0';
    }
    
    node->left = NULL;
    node->right = NULL;
    node->condition = NULL;
    node->from = NULL;
    
    return node;
}

scope_attr* merge_scopes(scope_attr* left, scope_attr* right) {
    scope_attr* merged = NULL;
    scope_attr* tail = NULL;

    for (scope_attr* curr = left; curr; curr = curr->next) {
        scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
        sa->name = strdup(curr->name);
        sa->alias = strdup(curr->alias);
        sa->tablename = curr->tablename;
        sa->next = NULL;

        if (!merged) merged = tail = sa;
        else { tail->next = sa; tail = sa; }
    }

    for (scope_attr* curr = right; curr; curr = curr->next) {
        scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
        sa->name = strdup(curr->name);
        sa->alias = strdup(curr->alias);
        sa->tablename = curr->tablename;
        sa->next = NULL;

        if (!merged) merged = tail = sa;
        else { tail->next = sa; tail = sa; }
    }

    return merged;
}


scope_attr* build_scope(ASTNode* node) {
    if (!node) return NULL;

    switch (node->type) {
        case RA_RELATION:
        case RA_ALIAS: {
            const char* table_name = NULL;
            const char* alias = NULL;

            if (node->type == RA_ALIAS && node->left) {
                table_name = node->left->value;
                alias = node->value;
            } else {
                table_name = alias = node->value;
            }

            // Find table in global tables[]
            TABLE* table = NULL;
            for (int i = 0; i < num_tables; ++i) {
                if (strcmp(tables[i].TABLE_NAME, table_name) == 0) {
                    table = &tables[i];
                    break;
                }
            }

            if (!table) return NULL;

            // Build scope_attr list
            scope_attr* head = NULL;
            scope_attr* tail = NULL;

            for (int i = 0; i < table->num_attributes; ++i) {
                scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
                sa->name = strdup(table->attr_list[i].name);
                sa->alias = strdup(alias);
                sa->tablename = table;
                sa->next = NULL;

                if (!head) head = tail = sa;
                else { tail->next = sa; tail = sa; }
            }

            return head;
        }

        case RA_PROJECTION: {
            scope_attr* base_scope = build_scope(node->left); // 🔑 get full alias→table mapping

            scope_attr* head = NULL;
            scope_attr* tail = NULL;

            for (ASTNode* curr = node->args; curr; curr = curr->args) {
                if (curr->type == RA_ATTRIBUTE) {
                    char* dot = strchr(curr->value, '.');
                    char alias_buf[256], name_buf[256];

                    if (dot) {
                        int len = dot - curr->value;
                        strncpy(alias_buf, curr->value, len);
                        alias_buf[len] = '\0';
                        strcpy(name_buf, dot + 1);
                    } else {
                        strcpy(alias_buf, "");
                        strcpy(name_buf, curr->value);
                    }

                    // 🧠 Try to find the matching attribute in base scope
                    TABLE* matched_table = NULL;
                    for (scope_attr* s = base_scope; s; s = s->next) {
                        if ((strcmp(alias_buf, "") == 0 || strcmp(s->alias, alias_buf) == 0) &&
                            strcmp(s->name, name_buf) == 0) {
                            matched_table = s->tablename;
                            break;
                        }
                    }

                    scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
                    sa->alias = strdup(alias_buf);
                    sa->name = strdup(name_buf);
                    sa->tablename = matched_table; // ✅ copied from matched scope
                    sa->next = NULL;

                    if (!head) head = tail = sa;
                    else { tail->next = sa; tail = sa; }
                }
            }

            free_scope(base_scope); // clean up base scope after using
            return head;
        }


        case RA_SELECTION:
        case RA_DISTINCT:
        case RA_GROUPBY:
        case RA_ORDERBY:
            return build_scope(node->left);

        case RA_JOIN:
        case RA_JOIN_TYPE:{
            scope_attr* left = build_scope(node->left);
            scope_attr* right = build_scope(node->right);
            return merge_scopes(left, right);
        }

        default:
            return build_scope(node->left);
    }
}


void print_subtree(ASTNode* node, int depth) {
    if (!node) return;

    switch (node->type) {
        case RA_ATTRIBUTE:
            printf("%s, ",node->value);
            break;
        case RA_LITERAL:
            printf("%s, ",node->value);
            break;
        default:
    }
    print_subtree(node->left, depth + 1);
    print_subtree(node->right, depth + 1);
}

ASTNode* deep_copy_tree(ASTNode* original) {
    if (!original) return NULL;
    
    ASTNode* copy = create_node(original->type, original->value);
    copy->left = deep_copy_tree(original->left);
    copy->right = deep_copy_tree(original->right);
    copy->args = deep_copy_tree(original->args);
    copy->condition = deep_copy_tree(original->condition);
    return copy;
}

ASTNode* append_condition(ASTNode* root, ASTNode* cond) {
    if (!root) return deep_copy_tree(cond);

    ASTNode* new_node = create_node(RA_AND, "AND");
    new_node->left = root;
    new_node->right = deep_copy_tree(cond);
    return new_node;
}

int condition_involves_only(ASTNode* cond, scope_attr* scope) {
    if (!cond) return 1;
    if (cond->type == RA_ATTRIBUTE) {
        char alias[256], attr[256];
        char* dot = strchr(cond->value, '.');
        if (dot) {
            strncpy(alias, cond->value, dot - cond->value);
            alias[dot - cond->value] = '\0';
            strcpy(attr, dot + 1);
        } else {
            strcpy(alias, "");
            strcpy(attr, cond->value);
        }

        for (scope_attr* s = scope; s; s = s->next) {
            if (strcmp(s->alias, alias) == 0 && strcmp(s->name, attr) == 0) {
                return 1;
            }
        }
        return 0;
    }

    return condition_involves_only(cond->left, scope)
        && condition_involves_only(cond->right, scope)
        && condition_involves_only(cond->args, scope);
}

ASTNode* selection_pushdown(ASTNode* node) {
    if (!node) return NULL;

    int count = 0;
    ASTNode* conds[64]; // Assuming at most 64 AND conditions

    // Flatten condition tree (only handle AND chains here)
    void flatten_conditions(ASTNode* expr) {
        if (!expr) return;
        if (expr->type == RA_AND) {
            flatten_conditions(expr->left);
            flatten_conditions(expr->right);
        } else {
            conds[count++] = expr;
        }
    }

    // case: pushing the condition of join invloves only one side of the join as select node to reduce the join size
    if(node->type == RA_JOIN && node->condition){
        ASTNode* cond = node->condition;
        flatten_conditions(cond);

        scope_attr* left_scope = build_scope(node->left);
        scope_attr* right_scope = build_scope(node->right);

        // Step 1: Classify conditions
        ASTNode* left_conditions = NULL;
        ASTNode* right_conditions = NULL;

        for (int i = 0; i < count; i++) {
            ASTNode* c = conds[i];
            int in_left = condition_involves_only(c, left_scope);
            int in_right = condition_involves_only(c, right_scope);

            if (in_left) {
                left_conditions = append_condition(left_conditions, c);
            } else if (in_right) {
                right_conditions = append_condition(right_conditions, c);
            }
        }

        // Step 2: Push down to join children
        if (left_conditions) {
            ASTNode* sel = create_node(RA_SELECTION, "");
            sel->args = left_conditions;
            sel->left = node->left;
            node->left = selection_pushdown(sel);
        }

        if (right_conditions) {
            ASTNode* sel = create_node(RA_SELECTION, "");
            sel->args = right_conditions;
            sel->left = node->right;
            node->right = selection_pushdown(sel);
        }

        free_scope(left_scope);
        free_scope(right_scope);
    }

    // Case: σ(cond) over a join
    if (node->type == RA_SELECTION && node->left && node->left->type == RA_JOIN) {
        ASTNode* join_node = node->left;

        scope_attr* left_scope = build_scope(join_node->left);
        scope_attr* right_scope = build_scope(join_node->right);

        // Step 1: Break condition into ANDs
        ASTNode* cond = node->args;

        flatten_conditions(cond);

        // Step 2: Classify conditions
        ASTNode* left_conditions = NULL;
        ASTNode* right_conditions = NULL;
        ASTNode* join_conditions = NULL;

        for (int i = 0; i < count; i++) {
            ASTNode* c = conds[i];
            int in_left = condition_involves_only(c, left_scope);
            int in_right = condition_involves_only(c, right_scope);

            if (in_left) {
                left_conditions = append_condition(left_conditions, c);
            } else if (in_right) {
                right_conditions = append_condition(right_conditions, c);
            } else {
                join_conditions = append_condition(join_conditions, c);
            }
        }

        // Step 3: Push down to join children
        if (left_conditions) {
            ASTNode* sel = create_node(RA_SELECTION, "");
            sel->args = left_conditions;
            sel->left = join_node->left;
            join_node->left = selection_pushdown(sel);
        }

        if (right_conditions) {
            ASTNode* sel = create_node(RA_SELECTION, "");
            sel->args = right_conditions;
            sel->left = join_node->right;
            join_node->right = selection_pushdown(sel);
        }


        // Step 4: Keep remaining at the top if needed
        free_scope(left_scope);
        free_scope(right_scope);

        if (join_conditions) {
            if (join_node->condition) {
                // Merge existing join condition with new one using AND
                ASTNode* merged = create_node(RA_AND, "AND");
                merged->left = join_node->condition;
                merged->right = join_conditions;
                join_node->condition = merged;
            } else {
                join_node->condition = join_conditions;
            }
        }
        return join_node;
    }

    // Merge selects
    if (node->type == RA_SELECTION && node->left && node->left->type == RA_SELECTION) {
        // Merge conditions into one AND expression
        ASTNode* merged = create_node(RA_AND, "AND");
        merged->left = node->args;
        merged->right = node->left->args;

        node->args = merged;
        node->left = node->left->left;
    }


    node->left = selection_pushdown(node->left);
    node->right = selection_pushdown(node->right);
    return node;
}


int attribute_in_list(ASTNode* list, const char* attr) {
    for (ASTNode* curr = list; curr; curr = curr->args) {
        if (strcmp(curr->value, attr) == 0)
            return 1;
    }
    return 0;
}

ASTNode* merge_attribute_lists(ASTNode* list1, ASTNode* list2) {
    ASTNode* merged = NULL;
    ASTNode* tail = NULL;

    for (ASTNode* curr = list1; curr; curr = curr->args) {
        ASTNode* node = deep_copy_tree(curr);
        node->args = NULL;
        if (!merged) merged = tail = node;
        else { tail->args = node; tail = node; }
    }

    for (ASTNode* curr = list2; curr; curr = curr->args) {
        if (!attribute_in_list(merged, curr->value)) {
            ASTNode* node = deep_copy_tree(curr);
            node->args = NULL;
            if (!merged) merged = tail = node;
            else { tail->args = node; tail = node; }
        }
    }

    return merged;
}

ASTNode* extract_attributes_from_conditions(ASTNode* node) {
    if (!node) return NULL;

    ASTNode* result = NULL;

    if (node->type == RA_ATTRIBUTE) {
        ASTNode* copy = deep_copy_tree(node);
        copy->args = NULL;
        result = copy;
    } else {
        ASTNode* left_attrs = extract_attributes_from_conditions(node->left);
        ASTNode* right_attrs = extract_attributes_from_conditions(node->right);
        ASTNode* cond_attrs = extract_attributes_from_conditions(node->condition);
        ASTNode* args_attrs = extract_attributes_from_conditions(node->args);

        result = merge_attribute_lists(left_attrs, right_attrs);
        result = merge_attribute_lists(result, cond_attrs);
        result = merge_attribute_lists(result, args_attrs);
    }

    return result;
}

int is_projection_star_only(ASTNode *args) {
    for (ASTNode *curr = args; curr; curr = curr->args) {
        if (!(curr->type == RA_ATTRIBUTE && strcmp(curr->value, "*") == 0)) {
            return 0;
        }
    }
    return 1;
}

ASTNode *projection_pushdown(ASTNode *node) {
    if (!node) return NULL;

    if (node->type == RA_PROJECTION && is_projection_star_only(node->args)) {
        ASTNode *temp = node->left;
        free_tree(node->args);
        free(node);
        return projection_pushdown(temp);
    }

    node->left = projection_pushdown(node->left);
    node->right = projection_pushdown(node->right);
    node->args = projection_pushdown(node->args);
    node->condition = projection_pushdown(node->condition);
    node->from = projection_pushdown(node->from);

    // Case: π → σ
    if (node->type == RA_PROJECTION && node->left && node->left->type == RA_SELECTION) {
        ASTNode *select_node = node->left;

        // Step 1: Extract attributes used in the selection condition
        ASTNode *cond_attrs = extract_attributes_from_conditions(select_node->args);

        // Step 2: Merge selection condition attributes + original projection args
        ASTNode *merged_attrs = merge_attribute_lists(node->args, cond_attrs);

        // Step 3: Create new projection node below selection with merged attributes
        ASTNode *new_proj = create_node(RA_PROJECTION, "");
        new_proj->args = merged_attrs;
        new_proj->left = select_node->left;

        // Step 4: Replace selection's child with new projection
        select_node->left = new_proj;
        free_tree(cond_attrs);

        // Recurse downward to handle inner cases (π under joins etc.)
        return projection_pushdown(select_node);
    }

    // Case: π → JOIN(any join)
    if (node->type == RA_PROJECTION && node->left && (node->left->type == RA_JOIN || node->left->type == RA_JOIN_TYPE)) {
        ASTNode *join_node = node->left;

        ASTNode *proj_attrs = node->args;
        ASTNode *cond_attrs = extract_attributes_from_conditions(join_node->condition);
        ASTNode *combined_attrs = merge_attribute_lists(proj_attrs, cond_attrs);

        scope_attr *left_scope = build_scope(join_node->left);
        if (!left_scope) printf("Left scope is NULL\n");
        scope_attr *right_scope = build_scope(join_node->right);
        if (!right_scope) printf("Right scope is NULL\n");

        ASTNode *left_proj_attrs = NULL;
        ASTNode *right_proj_attrs = NULL;
        ASTNode *tail_left = NULL, *tail_right = NULL;

        for (ASTNode *curr = combined_attrs; curr; curr = curr->args) {
            char *attr_full = curr->value;
            char *dot = strchr(attr_full, '.');
            char alias[256], attr[256];

            if (dot) {
                int len = dot - attr_full;
                strncpy(alias, attr_full, len); alias[len] = '\0';
                strcpy(attr, dot + 1);
            } else {
                strcpy(alias, "");
                strcpy(attr, attr_full);
            }

            int found_in_left = 0, found_in_right = 0;

            for (scope_attr *s = left_scope; s; s = s->next) {
                if (strcmp(s->alias, alias) == 0 && strcmp(s->name, attr) == 0) {
                    found_in_left = 1;
                    break;
                }
            }

            for (scope_attr *s = right_scope; s; s = s->next) {
                if (strcmp(s->alias, alias) == 0 && strcmp(s->name, attr) == 0) {
                    found_in_right = 1;
                    break;
                }
            }
            

            ASTNode *copy = deep_copy_tree(curr);
            copy->args = NULL;

            if (found_in_left && !found_in_right) {
                if (!left_proj_attrs) left_proj_attrs = tail_left = copy;
                else { tail_left->args = copy; tail_left = copy; }
            } else if (found_in_right && !found_in_left) {
                if (!right_proj_attrs) right_proj_attrs = tail_right = copy;
                else { tail_right->args = copy; tail_right = copy; }
            }
        }

        // Step 6: Push down to left
        if (left_proj_attrs) {
            ASTNode *left_proj_node = create_node(RA_PROJECTION, "");
            left_proj_node->args = left_proj_attrs;
            left_proj_node->left = join_node->left;
            join_node->left = left_proj_node;
        }

        // Step 7: Push down to right
        if (right_proj_attrs) {
            ASTNode *right_proj_node = create_node(RA_PROJECTION, "");
            right_proj_node->args = right_proj_attrs;
            right_proj_node->left = join_node->right;
            join_node->right = right_proj_node;
        }

        // Step 8: Check if all projection attributes have been pushed
        int all_attrs_pushed = 1;
        for (ASTNode *curr = proj_attrs; curr; curr = curr->args) {
            if (!attribute_in_list(left_proj_attrs, curr->value) &&
                !attribute_in_list(right_proj_attrs, curr->value)) {
                all_attrs_pushed = 0;
                break;
            }
        }

        free_scope(left_scope);
        free_scope(right_scope);
        free_tree(combined_attrs);

        if (all_attrs_pushed) {
            return join_node;
        } else {
            node->left = join_node;
            return node;
        }
    }
    if (node->type == RA_PROJECTION && node->left && node->left->type == RA_PROJECTION) {
        // Keep only attributes from outer projection
        node->left = node->left->left; // remove inner projection
        return node;
    }


    return node;
}

ASTNode* apply_transformations(ASTNode* node) {
    if (!node) return NULL;
    int changed;
    do {
        changed = 0;
        ASTNode* original = deep_copy_tree(node);
        ASTNode* after_selection = selection_pushdown(node);
        if (after_selection != node) {
            node = after_selection;
            changed = 1;
        }

        ASTNode* after_projection = projection_pushdown(node);
        if (after_projection != node) {
            node = after_projection;
            changed = 1;
        }
    } while (changed);

    return node;
}


ASTNode* extract_attributes(ASTNode* attr_list, ASTNode* relation) {
    if (!attr_list || !relation) return NULL;

    const char* alias = relation->value;
    ASTNode* result = NULL;
    ASTNode* last = NULL;

    for (ASTNode* curr = attr_list; curr; curr = curr->args) {
        if (curr->type == RA_ATTRIBUTE) {
            char* dot = strchr(curr->value, '.');

            int include = 0;

            if (dot) {
                // Qualified attribute: alias.attr
                char prefix[256];
                strncpy(prefix, curr->value, dot - curr->value);
                prefix[dot - curr->value] = '\0';

                // Match alias (or table name if you track it)
                if (strcmp(prefix, alias) == 0) {
                    include = 1;
                }
            } else {
                // Unqualified attribute: attr
                // Include just to be safe (or enhance this with schema-based resolution)
                include = 1;
            }

            if (include) {
                ASTNode* new_attr = deep_copy_tree(curr);
                new_attr->args = NULL;

                if (!result) {
                    result = last = new_attr;
                } else {
                    last->args = new_attr;
                    last = new_attr;
                }
            }
        }
    }

    return result;
}


void print_tree(ASTNode* node, int depth) {
    if (!node) return;
    
    // Print indentation
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    if (node->type == RA_TRANSFORMED) {
        printf("[%s Transformation]\n", node->value);
        print_tree(node->left, depth + 1);
        return;
    }

    // Print node information
    switch (node->type) {
        case RA_EMPTY:
            printf("EMPTY\n");
            break;
        case RA_PROJECTION:
            printf("π-Project (%s)\n", node->value);
            break;
        case RA_SELECTION:
            printf("σ-Select[%s]\n", node->value);
            break;
        case RA_GROUPBY:
            printf("γ-Group by [%s]\n", node->value);
            break;
        case RA_ORDERBY:
            printf("τ-order by [%s]\n", node->value);
            break;
        case RA_JOIN:
            printf("%s-join\n", node->value);
            if (node->condition) {
                for (int i = 0; i < depth + 1; i++) printf("  ");
                printf("Condition:\n");
                print_tree(node->condition, depth + 2);
            }
            break;
        case RA_SET_OP:
            printf("%s-set_op\n", node->value);
            break;
        case RA_WITH:
            printf("WITH %s\n", node->value);
            break;
        case RA_WITH_LIST:
            printf("WITH LIST %s\n", node->value);
            break;
        case RA_WITH_QUERY:
            printf("WITH QUERY %s\n", node->value);
            break;
        case RA_RELATION:
            printf("Relation: %s\n", node->value);
            break;
        case RA_ATTRIBUTE:
            printf("Attribute: %s\n", node->value);
            break;
        case RA_ALIAS:
            printf("AS %s\n", node->value);
            break;
        case RA_LITERAL:
            printf("Literal: %s\n", node->value);
            break;
        case RA_COMPARISON:
            printf("Comparison: %s\n", node->value);
            break;
        case RA_ARITHMETIC:
            printf("Arithmetic: %s\n", node->value);
            break;
        case RA_DISTINCT:
            printf("δ (%s)\n", node->value);
            break;
        case RA_INSERT:
            printf("Insert: %s\n", node->value);
            break;
        case RA_UPDATE:
            printf("Update: %s\n", node->value);
            break;
        case RA_DELETE:
            printf("Delete: %s\n", node->value);
            break;
        case RA_VALUES:
            printf("Values: %s\n", node->value);
            break;
        case RA_VALUE_LIST:
            printf("Value List: %s\n", node->value);
            break;
        case RA_VALUE_ITEMS:
            printf("Value Items: %s(", node->value);
            print_subtree(node->left,depth);
            if(node->right)printf("%s)\n",node->right->value);
            else printf(")\n");
            return;
        case RA_COLUMN_LIST:
            printf("Column List: %s(", node->value);
            print_subtree(node->left,depth);
            if(node->right)printf("%s)\n",node->right->value);
            else printf(")\n");
            return;
        case RA_SET:
            printf("Set\n");
            break;
        case RA_SET_LIST:
            printf("Set List: %s\n", node->value);
            break;
        case RA_ASSIGNMENT:
            printf("Assignment: %s\n", node->value);
            break;
        case RA_USING:
            printf("Using: %s\n", node->value);
            break;
        case RA_FROM:
            printf("From: %s\n", node->value);
            break;
        case RA_JOIN_TYPE:
            printf("Join Type: %s\n", node->value);
            break;
        case RA_OR:
            printf("Or: %s\n", node->value);
            break;
        case RA_AND:
            printf("And: %s\n", node->value);
            break;
        case RA_NOT:
            printf("Not: %s\n", node->value);
            break;
        case RA_NULL_CHECK:
            printf("Null Check: %s\n", node->value);
            break;
        case RA_IN:
            printf("In: %s\n", node->value);
            break;
        case RA_RANGE:
            printf("Range: %s\n", node->value);
            break;
        case RA_CONCAT:
            printf("Concat: %s\n", node->value);
            break;
        default:
            printf("Node: %d (%s)\n", node->type, node->value);
            break;
    }
    
    // Recursively print children
    print_tree(node->args,depth+1);
    print_tree(node->left, depth + 1);
    print_tree(node->right, depth + 1);
}
