/* 
 * This file store the css formats for fcd2html translator.
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

#ifndef __CSS__H__
#define __CSS__H__

char *BASE_CSS = "\
body\
{\
#background-color: #e6e6e6;\
font-family: serif;\
font-size: 18px;\
margin: 20px;\
background-color: white;\
}\
table, th, td\
{\
font-family: serif;\
font-size: 16px;\
border-collapse: collapse;\
border: 2px ridge black;\
padding: 5px;\
}\
.block\
{\
border-top: 3px ridge #145a6e;\
padding-left: 10px;\
}\
.note\
{\
background-color: #f1d5e1;\
margin-bottom: 3px;\
}\
.title\
{\
margin-bottom: 3px;\
margin-top: 3px;\
}\
.code\
{\
font-family: monospace;\
font-size: 14px;\
background-color: #f0f0f0;\
padding: 2px;\
white-space: pre-wrap;\
border-radius: 4px;\
border: 2px ridge gray;\
margin-bottom: 3px;\
}\
.text\
{\
font-family: serif;\
font-size: 16px;\
margin-bottom: 3px;\
}\
footer\
{\
background-color: #145a6e;\
padding: 2px;\
}";

unsigned int BASE_CSS_SIZE = sizeof(BASE_CSS);

#endif /* __CSS__H__ */
