/* 
 * LEX lexer for fcd format (author using flex as generator).
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
#include "parser.h"
%}

%option noyywrap
%option yylineno
%option debug

%x COMMENT
%x TEXT_S
%x ARG

l_end       (end(_)?)
r_end       ((_)?end)
document    (doc(ument)?)
e_document  ({l_end}{document})|({document}{r_end})
include     (include)
section     (sec(tion)?)
e_section   ({l_end}{section})|({section}{r_end})

link        (link)
image       (img|image)
shell       (sh|shell|cmd|command)

text        (t(e)?xt)
e_text      ({l_end}{text})|({text}{r_end})
code        (code)
e_code      ({l_end}{code})|({code}{r_end})
table       (table)
e_table     ({l_end}{table})|({table}{r_end})
list        (list)
e_list      ({l_end}{list})|({list}{r_end})
csv_table   (csv_table)

row         (row)
e_row       ({l_end}{row})|({row}{r_end})

cell        (cell|cl)
e_cell      ({l_end}{cell})|({cell}{r_end})
header      (header|head|hd)
e_header    ({l_end}{header})|({header}{r_end})

bold            (bold|b)
e_bold          ({l_end}{bold})|({bold}{r_end})
italic          (italic|i)
e_italic        ({l_end}{italic})|({italic}{r_end})
underline       (underline|uline|u)
e_underline     ({l_end}{underline})|({underline}{r_end})
mark            (mark|m)
e_mark          ({l_end}{mark})|({mark}{r_end})
superscript     (superscript|sup)
e_superscript   ({l_end}{superscript})|({superscript}{r_end})
subscript       (subscript|sub)
e_subscript     ({l_end}{subscript})|({subscript}{r_end})
delete          (delete|del|d)
e_delete        ({l_end}{delete})|({delete}{r_end})

%%


<TEXT_S>(?:(?!\(endtext\))(.|\n))*  {}
<ARG>\'.*\'                         { yylval.string_val = strdup(yytext); return TEXT; }

"("         { return '('; }
")"         { return ')'; }


{document}          { return BEGIN_DOCUMENT; }
{e_document}        { return END_DOCUMENT; }
{include}           { return INCLUDE; }
{section}           { return BEGIN_SECTION;  }
{e_section}         { return END_SECTION;  }

                        /* section-in blocks */
{link}                  { return LINK; }
{image}                 { return IMAGE; }
{text}                  { BEGIN(TEXT_S) ; return BEGIN_TEXT; }
<TEXT_S>{e_text}        { BEGIN(INITIAL) ; return END_TEXT; }
{code}                  { return BEGIN_CODE; }
{e_code}                { return END_CODE; }
{table}                 { return BEGIN_TABLE; }
{e_table}               { return END_TABLE; }

                /* table-in blocks */
{row}           { return BEGIN_TABLE_ROW; }
{e_row}         { return BEGIN_TABLE_ROW; }

                /* row-in blocks*/
{cell}          { return BEGIN_TABLE_ROW_CELL; }
{e_cell}        { return END_TABLE_ROW_CELL; }
{header}        { return BEGIN_TABLE_ROW_HEADER; }
{e_header}      { return END_TABLE_ROW_HEADER; }

                    /* text-in blocks */
{bold}              { return BEGIN_BOLD_TEXT; }
{e_bold}            { return END_BOLD_TEXT; }
{italic}            { return BEGIN_ITALIC_TEXT; }
{e_italic}          { return END_ITALIC_TEXT; }
{underline}         { return BEGIN_UNDERLINE_TEXT; }
{e_underline}       { return END_UNDERLINE_TEXT; }
{mark}              { return BEGIN_MARK_TEXT; }
{e_mark}            { return END_MARK_TEXT; }
{superscript}       { return BEGIN_SUPERSCRIPT_TEXT; }
{e_superscript}     { return END_SUPERSCRIPT_TEXT; }
{subscript}         { return BEGIN_SUBSCRIPT_TEXT; }
{e_subscript}       { return END_SUBSCRIPT_TEXT; }
{delete}            { return BEGIN_DELETED_TEXT; }
{e_delete}          { return END_DELETED_TEXT; }


"/*"            { BEGIN(COMMENT); }
<COMMENT>"*/"   { BEGIN(INITIAL); }
<COMMENT>.|\n   { }

[\t\n ]     { /* whitespaces */ }

.                   {
                        printf("Error at line %d: unrecognized symbol \"%s\"\n",
                            yylloc.first_line, yytext);
                        exit(0);
                    }

%%
