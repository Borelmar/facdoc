/* 
 * YACC parser for fcd format (author using bison as generator).
 * Copyright (C) 2023 Free Software Foundation, Inc.
 *
 * This file is part of facdoc.
 *
 * Facdoc is free software: you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Foobar. If not, see <https://www.gnu.org/licenses/>. 
*/

%{
#include <stdio.h>

#define YYDEBUG 1

int yylex();
int yyparse();
void yyerror(const char *s);

static const int HAVE_BEGIN_DOCUMENT = 0;
static const char *CURRENT_FILE_NAME = NULL;
static const size_t CURRENT_FILE_LINE = 0;

%}

// %define parse.error verbose

/* General blocks */
%token TEXT

%token BEGIN_DOCUMENT END_DOCUMENT
%token INCLUDE
%token BEGIN_SECTION END_SECTION

/* Section-in blocks */
%token LINK
%token IMAGE
%token BEGIN_TEXT END_TEXT
%token BEGIN_CODE END_CODE
//%token BEGIN_NOTE END_NOTE
%token BEGIN_TABLE END_TABLE

/* table-in blocks */
%token BEGIN_TABLE_ROW END_TABLE_ROW

/* row-in blocks */
%token BEGIN_TABLE_ROW_HEADER END_TABLE_ROW_HEADER
%token BEGIN_TABLE_ROW_CELL END_TABLE_ROW_CELL

/* text-in blocks */
%token BEGIN_BOLD_TEXT          END_BOLD_TEXT 
%token BEGIN_ITALIC_TEXT        END_ITALIC_TEXT 
%token BEGIN_UNDERLINE_TEXT     END_UNDERLINE_TEXT 
%token BEGIN_MARK_TEXT          END_MARK_TEXT 
%token BEGIN_SUPERSCRIPT_TEXT   END_SUPERSCRIPT_TEXT 
%token BEGIN_SUBSCRIPT_TEXT     END_SUBSCRIPT_TEXT 
%token BEGIN_DELETED_TEXT       END_DELETED_TEXT

%start document

%%

/* *** GENERAL *** */
document:
      /* empty */
    | '(' BEGIN_DOCUMENT '\'' TEXT '\'' ')' '(' END_DOCUMENT ')' { printf("\nOK\n"); }
    | '(' BEGIN_DOCUMENT '\'' TEXT '\'' ')' document_content '(' END_DOCUMENT ')' { printf("\nOK\n"); }
    ;

document_content:
      documentin_block
    | document_content documentin_block
    ;

documentin_block:
      '(' INCLUDE '\'' TEXT '\'' ')'
    | '(' BEGIN_SECTION '\'' TEXT '\'' ')' '(' END_SECTION ')'
    | '(' BEGIN_SECTION '\'' TEXT '\'' ')' section_content '(' END_SECTION ')'
    ;
/* *** END GENERAL *** */


/* *** SECTION *** */
section_content:
      sectionin_block
    | section_content sectionin_block 
    ;


sectionin_block:
      '(' IMAGE '\'' TEXT '\'' ')'
    | '(' LINK '\'' TEXT '\'' ')'

    /* | '(' BEGIN_NOTE ')' '(' END_NOTE ')'
    | '(' BEGIN_NOTE ')' note_content '(' END_NOTE ')' */

    | '(' BEGIN_TEXT ')' '(' END_TEXT ')'
    | '(' BEGIN_TEXT ')' text_content '(' END_TEXT ')'

    | '(' BEGIN_CODE ')' '(' END_CODE ')'
    | '(' BEGIN_CODE ')' code_content '(' END_CODE ')'

    | '(' BEGIN_TABLE '\'' TEXT '\'' ')' '(' END_TABLE ')'
    | '(' BEGIN_TABLE '\'' TEXT '\'' ')' table_content '(' END_TABLE ')'
    ;
/* *** END SECTION *** */

/* *** TEXT *** */
text_content:
      textin_block
    | text_content textin_block
    ;

textin_block:
      '(' BEGIN_BOLD_TEXT ')'           TEXT    '(' END_BOLD_TEXT ')'
    | '(' BEGIN_ITALIC_TEXT ')'         TEXT    '(' END_ITALIC_TEXT ')'
    | '(' BEGIN_UNDERLINE_TEXT ')'      TEXT    '(' END_UNDERLINE_TEXT ')'
    | '(' BEGIN_MARK_TEXT ')'           TEXT    '(' END_MARK_TEXT ')'
    | '(' BEGIN_SUPERSCRIPT_TEXT ')'    TEXT    '(' END_SUPERSCRIPT_TEXT ')'
    | '(' BEGIN_SUBSCRIPT_TEXT ')'      TEXT    '(' END_SUBSCRIPT_TEXT ')'
    | '(' BEGIN_DELETED_TEXT ')'        TEXT    '(' END_DELETED_TEXT ')'
    ;
/* *** END TEXT *** */

/* *** NOTE *** */
/* note_content:
      notein_block
    | text_content notein_block
    ;

notein_block:
      '(' BEGIN_BOLD_TEXT ')'           TEXT    '(' END_BOLD_TEXT ')'
    | '(' BEGIN_ITALIC_TEXT ')'         TEXT    '(' END_ITALIC_TEXT ')'
    | '(' BEGIN_UNDERLINE_TEXT ')'      TEXT    '(' END_UNDERLINE_TEXT ')'
    | '(' BEGIN_MARK_TEXT ')'           TEXT    '(' END_MARK_TEXT ')'
    | '(' BEGIN_SUPERSCRIPT_TEXT ')'    TEXT    '(' END_SUPERSCRIPT_TEXT ')'
    | '(' BEGIN_SUBSCRIPT_TEXT ')'      TEXT    '(' END_SUBSCRIPT_TEXT ')'
    | '(' BEGIN_DELETED_TEXT ')'        TEXT    '(' END_DELETED_TEXT ')'
    ;
*/
/* *** END NOTE *** */

/* *** CODE *** */
code_content:
      codein_block
    | code_content codein_block 
    ;

codein_block:
      '(' BEGIN_MARK_TEXT ')'           TEXT    '(' END_MARK_TEXT ')'
    ;
/* *** END CODE *** */

/* *** TABLE *** */
table_content:
      '('BEGIN_TABLE_ROW')' table_row_content '('END_TABLE_ROW')'
    | table_content '('BEGIN_TABLE_ROW')' table_row_content '('END_TABLE_ROW')' 
    ;

table_row_content:
      rowin_block
    | table_row_content rowin_block 
    ;

rowin_block:
      '('BEGIN_TABLE_ROW_HEADER')' TEXT '('END_TABLE_ROW_HEADER')'
    | '('BEGIN_TABLE_ROW_CELL')' TEXT '('END_TABLE_ROW_CELL')'
    ;
/* *** END TABLE *** */


%%

void yyerror(const char *s)
{
    fprintf(stderr, "Error: %s\n", s);
}
