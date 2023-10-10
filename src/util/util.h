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

#ifndef BIGGER_C_INT_T
#   define BIGGER_C_INT_T unsigned long long int
#endif


/* Calculate the data size with strlen(3)
 * in the array with (unsigned int size) size
 */
extern unsigned int
    strarr_data_size(char **array, unsigned int size);


extern unsigned long long int bstrlen(char *str);


/* Concatinate a strings on array with size (unsigned int size) */
extern char *strarrcat(char **array, unsigned int size);

/* Secure free (wrapper) */
extern void sfree(void *ptr);

/* Alloc mem for str with null byte (using malloc(3) ) */
extern char *stralloc(size_t size);

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
    unsigned int prev_line_num,

    char *line,
    unsigned int line_num,

    char *next_line,
    unsigned int next_line_num,

    int error_code,
    unsigned int symbol_in_line,
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


#ifndef HAVE_ASPRINTF
extern int asprintf (char **str, const char *fmt, ...);
extern int vasprintf (char **str, const char *fmt, va_list args);
#endif


extern char *astrncat(char *dest, char *src, unsigned int size);
extern char *astrcat(char *dest, char *src);


#endif /* _UTIL_H */

