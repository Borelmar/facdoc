/* 
 * Char multiply into string.
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

#include <stdlib.h>
#include <string.h>

char *chrmult(char chr, size_t factor)
{
    if(factor != 0)
    {
        unsigned int len = factor + 1;
        char *ptr = (char*)malloc(len);
        ptr[len-1] = '\0';
        return memset(ptr, chr, factor);
    }
    else
    {
        return NULL;
    }
}
