/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_FCD_PARSER_H_INCLUDED
# define YY_YY_SRC_FCD_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TEXT = 258,
    BEGIN_DOCUMENT = 259,
    END_DOCUMENT = 260,
    INCLUDE = 261,
    BEGIN_SECTION = 262,
    END_SECTION = 263,
    LINK = 264,
    IMAGE = 265,
    BEGIN_TEXT = 266,
    END_TEXT = 267,
    BEGIN_CODE = 268,
    END_CODE = 269,
    BEGIN_TABLE = 270,
    END_TABLE = 271,
    BEGIN_TABLE_ROW = 272,
    END_TABLE_ROW = 273,
    BEGIN_TABLE_ROW_HEADER = 274,
    END_TABLE_ROW_HEADER = 275,
    BEGIN_TABLE_ROW_CELL = 276,
    END_TABLE_ROW_CELL = 277,
    BEGIN_BOLD_TEXT = 278,
    END_BOLD_TEXT = 279,
    BEGIN_ITALIC_TEXT = 280,
    END_ITALIC_TEXT = 281,
    BEGIN_UNDERLINE_TEXT = 282,
    END_UNDERLINE_TEXT = 283,
    BEGIN_MARK_TEXT = 284,
    END_MARK_TEXT = 285,
    BEGIN_SUPERSCRIPT_TEXT = 286,
    END_SUPERSCRIPT_TEXT = 287,
    BEGIN_SUBSCRIPT_TEXT = 288,
    END_SUBSCRIPT_TEXT = 289,
    BEGIN_DELETED_TEXT = 290,
    END_DELETED_TEXT = 291
  };
#endif
/* Tokens.  */
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
#line 42 "../src/fcd/parser.y" /* yacc.c:1921  */

    char *string_val;

#line 134 "src/fcd/parser.h" /* yacc.c:1921  */
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
