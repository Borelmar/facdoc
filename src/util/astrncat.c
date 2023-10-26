/* 
 * Allocated STRing conCATentation up to N-bytes (astnrcat)
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


char *astrncat(const char *dest, const char *src, size_t size)
{
    char *ret = malloc(strlen(dest) + size + 1);
    strcpy(ret, dest);
    strncat(ret, src, size);
    return ret;
}
