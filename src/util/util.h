/* 
 * It file store externs for util func for facdoc project.
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

#ifndef _UTIL_H__
#define _UTIL_H__


/* Calculate the data size with strlen(3)
 * in the array with (unsigned int size) size
 */
extern size_t
    strarr_data_size(char **array, size_t size);


/* Concatinate a strings on array with n elements */
extern char *strarrcat(const char **array, size_t n);

/* Alloc mem for str with null byte (using malloc(3) ) */
extern char *stralloc(size_t n);

/* Imlementation of UNIX wildcards */
extern int
    wildcard(const char* wild, const char* string);


/* Get size of file */
extern size_t
    fgetsize(FILE *file);


/* Mult char on integer (aka x * 'c' ) */
extern char*
    chrmult(char chr, size_t factor);


/* Print error in file with gcc style
 */
extern void fferror (
    char *prev_line,
    size_t prev_line_num,

    char *line,
    size_t line_num,

    char *next_line,
    size_t next_line_num,

    int error_code,
    size_t symbol_in_line,
    char *error_message);


extern
unsigned char *b64decode(const char *data,
                             size_t input_length,
                             size_t *output_length);


extern
char *b64encode(const unsigned char *data,
                    size_t input_length,
                    size_t *output_length);


extern unsigned int dicount(unsigned int x);




extern char *astrncat(char *dest, char *src, unsigned int size);
extern char *astrcat(char *dest, char *src);


#endif /* _UTIL_H */

