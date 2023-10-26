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

#ifndef YY_YY_SRC_FCD_PARSER_H_INCLUDED
# define YY_YY_SRC_FCD_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    TEXT = 258,                    /* TEXT  */
    BEGIN_DOCUMENT = 259,          /* BEGIN_DOCUMENT  */
    END_DOCUMENT = 260,            /* END_DOCUMENT  */
    INCLUDE = 261,                 /* INCLUDE  */
    BEGIN_SECTION = 262,           /* BEGIN_SECTION  */
    END_SECTION = 263,             /* END_SECTION  */
    LINK = 264,                    /* LINK  */
    IMAGE = 265,                   /* IMAGE  */
    BEGIN_TEXT = 266,              /* BEGIN_TEXT  */
    END_TEXT = 267,                /* END_TEXT  */
    BEGIN_CODE = 268,              /* BEGIN_CODE  */
    END_CODE = 269,                /* END_CODE  */
    BEGIN_TABLE = 270,             /* BEGIN_TABLE  */
    END_TABLE = 271,               /* END_TABLE  */
    BEGIN_TABLE_ROW = 272,         /* BEGIN_TABLE_ROW  */
    END_TABLE_ROW = 273,           /* END_TABLE_ROW  */
    BEGIN_TABLE_ROW_HEADER = 274,  /* BEGIN_TABLE_ROW_HEADER  */
    END_TABLE_ROW_HEADER = 275,    /* END_TABLE_ROW_HEADER  */
    BEGIN_TABLE_ROW_CELL = 276,    /* BEGIN_TABLE_ROW_CELL  */
    END_TABLE_ROW_CELL = 277,      /* END_TABLE_ROW_CELL  */
    BEGIN_BOLD_TEXT = 278,         /* BEGIN_BOLD_TEXT  */
    END_BOLD_TEXT = 279,           /* END_BOLD_TEXT  */
    BEGIN_ITALIC_TEXT = 280,       /* BEGIN_ITALIC_TEXT  */
    END_ITALIC_TEXT = 281,         /* END_ITALIC_TEXT  */
    BEGIN_UNDERLINE_TEXT = 282,    /* BEGIN_UNDERLINE_TEXT  */
    END_UNDERLINE_TEXT = 283,      /* END_UNDERLINE_TEXT  */
    BEGIN_MARK_TEXT = 284,         /* BEGIN_MARK_TEXT  */
    END_MARK_TEXT = 285,           /* END_MARK_TEXT  */
    BEGIN_SUPERSCRIPT_TEXT = 286,  /* BEGIN_SUPERSCRIPT_TEXT  */
    END_SUPERSCRIPT_TEXT = 287,    /* END_SUPERSCRIPT_TEXT  */
    BEGIN_SUBSCRIPT_TEXT = 288,    /* BEGIN_SUBSCRIPT_TEXT  */
    END_SUBSCRIPT_TEXT = 289,      /* END_SUBSCRIPT_TEXT  */
    BEGIN_DELETED_TEXT = 290,      /* BEGIN_DELETED_TEXT  */
    END_DELETED_TEXT = 291         /* END_DELETED_TEXT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TEXT 258
#define BEGIN_DOCUMENT 259
#define END_DOCUMENT 260
#define INCLUDE 261
#define BEGIN_SECTION 262
#define END_SECTION 263
#define LINK 264
#define IMAGE 265
#define BEGIN_TEXT 266
#define END_TEXT 267
#define BEGIN_CODE 268
#define END_CODE 269
#define BEGIN_TABLE 270
#define END_TABLE 271
#define BEGIN_TABLE_ROW 272
#define END_TABLE_ROW 273
#define BEGIN_TABLE_ROW_HEADER 274
#define END_TABLE_ROW_HEADER 275
#define BEGIN_TABLE_ROW_CELL 276
#define END_TABLE_ROW_CELL 277
#define BEGIN_BOLD_TEXT 278
#define END_BOLD_TEXT 279
#define BEGIN_ITALIC_TEXT 280
#define END_ITALIC_TEXT 281
#define BEGIN_UNDERLINE_TEXT 282
#define END_UNDERLINE_TEXT 283
#define BEGIN_MARK_TEXT 284
#define END_MARK_TEXT 285
#define BEGIN_SUPERSCRIPT_TEXT 286
#define END_SUPERSCRIPT_TEXT 287
#define BEGIN_SUBSCRIPT_TEXT 288
#define END_SUBSCRIPT_TEXT 289
#define BEGIN_DELETED_TEXT 290
#define END_DELETED_TEXT 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "../src/fcd/parser.y"

    char *string_val;

#line 143 "src/fcd/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_SRC_FCD_PARSER_H_INCLUDED  */
