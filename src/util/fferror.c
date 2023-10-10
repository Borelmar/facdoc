/* 
 * Print error in file with gcc style.
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


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern char *chrmult(char chr, size_t factor);

extern char *uint2str(unsigned int num);

extern unsigned int maxofa(unsigned int *array,
        unsigned int elements_count);

/*
 *
 * format ->
 * Error: No such terminate text block at line 34
 *     33 | /section 'Chapter 1'/
 *     34 |     /text/
 *        |           ^
 *     35 |      This is the big text
 * Code: 0x521
*/

void fferror (
    char *prev_line,
    unsigned int prev_line_num,

    char *line,
    unsigned int line_num,

    char *next_line,
    unsigned int next_line_num,

    int error_code,
    unsigned int symbol_in_line,
    char *error_message)
{
    char *format = "\
Error: \033[91m%s\033[0m at line %d\n\
    \033[2m%d%s | %s\033[0m\n\
    \033[0m%d%s | %s\033[0m\n\
   %s | %s\033[91m^\033[0m\n\
    \033[2m%d%s | %s\033[0m\n\
Code: 0x%08x\n";

    /* need spaces count bettwen line num and separator */
    unsigned int spofn1 = 0;
    unsigned int spofn2 = 0;
    unsigned int spofn3 = 0;

    /* count digits on prev_line_num, line_num, next_line_num*/
    unsigned int digits_count_l1 = 1;
    unsigned int digits_count_l2 = 1;
    unsigned int digits_count_l3 = 1;

    /* spaces bettwen line num and separator */
    char *spaces_l1 = "";
    char *spaces_l2 = "";
    char *spaces_l3 = "";
    
    /* nflN - need free line spaces at N line */
    unsigned int nfls1 = 1;
    unsigned int nfls2 = 1;
    unsigned int nfls3 = 1;
    unsigned int nfls_ep = 1; /* for error pointer */

    char *spaces_str_ep = NULL;


    /* calculate digits count of lines nums */
    /* 1 --> convert int to str */
    char *prev_line_num_str = uint2str(prev_line_num);
    char *line_num_str  = uint2str(line_num);
    char *next_line_num_str = uint2str(next_line_num);

    /* calculate */
    digits_count_l1 = strlen(prev_line_num_str);
    digits_count_l2 = strlen(line_num_str);
    digits_count_l3 = strlen(next_line_num_str);

    free(prev_line_num_str);
    prev_line_num_str = NULL;

    free(line_num_str);
    line_num_str = NULL;

    free(next_line_num_str);
    next_line_num_str = NULL;

    /* get max len of lines nums lens */
    unsigned int lines_nums_lens[] = {
        digits_count_l1,
        digits_count_l2,
        digits_count_l3
    };

    unsigned int maxl = maxofa(lines_nums_lens, 3);

    /* calculate spaces offset count */
    spofn1 = maxl - digits_count_l1;
    spofn2 = maxl - digits_count_l2;
    spofn3 = maxl - digits_count_l3;

    /* make spaces */
    spaces_l1 = chrmult(' ', spofn1);
    spaces_l2 = chrmult(' ', spofn2);
    spaces_l3 = chrmult(' ', spofn3);

    int NEED_FREE_spaces_l1 = 1;
    int NEED_FREE_spaces_l2 = 1;
    int NEED_FREE_spaces_l3 = 1;

    if(spaces_l1 == NULL)
    {
        NEED_FREE_spaces_l1 = 0;
        spaces_l1 = "";
    }
    if(spaces_l2 == NULL)
    {
        NEED_FREE_spaces_l2 = 0;
        spaces_l2 = "";
    }
    if(spaces_l3 == NULL)
    {
        NEED_FREE_spaces_l3 = 0;
        spaces_l3 = "";
    }

    int NEED_FREE_spaces_str;
    char *spaces_str = NULL;
    spaces_str = chrmult(' ', symbol_in_line);

    char *spaces_ep = chrmult(' ', maxl+1);

    if (spaces_str == NULL)
    {
        NEED_FREE_spaces_str = 0;
        spaces_str = "";
    }

    fprintf(stderr, format,
    error_message,
    line_num,
    prev_line_num,
    spaces_l1,
    prev_line,
    line_num,
    spaces_l2,
    line,
    spaces_ep,
    spaces_str,
    next_line_num,
    spaces_l3,
    next_line,
    error_code);

    if(NEED_FREE_spaces_str == 1)
    {
        free(spaces_str);
        spaces_str = NULL;
    }
    if(NEED_FREE_spaces_l1 == 1)
    {
        free(spaces_l1);
    }
    if(NEED_FREE_spaces_l2 == 1)
    {
        free(spaces_l2);
    }
    if(NEED_FREE_spaces_l3 == 1)
    {
        free(spaces_l3);
    }
    free(spaces_ep);
}


/*
int main(void)
{
    pfferror(
            "",
            5,
            "int main(vaid) {",
            6,
            "\treturn 0; }",
            7,
            1337,
            0,
            "undefined operator"
            );
    return 0;
}
*/
