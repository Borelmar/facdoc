/* 
 * Digits count in integer.
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

#include <math.h>
/* #include <stdio.h> */

/* On my machine error with compile math.h,
 * its temporarily implementation of
 *    unsigned int dicount(unsinged int x) { }
 */
/*
unsigned int dicount(unsigned int x)
{
    unsigned int _ret;
    char buf[11];
    snprintf(buf, 11, "%d", x)
    unsigned int len = strlen(buf);
    return _ret;
}
*/

/* Its implementation with log10() (not working on my machine) */
unsigned int dicount(unsigned int x)
{
    return (unsigned int)log10(((double)x)) + 1;
}

