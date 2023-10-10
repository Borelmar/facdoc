/* 
 * Sum of strlen's, of string array.
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

unsigned int strarr_data_size(char **array, unsigned int size)
{
    unsigned int data_size = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        data_size += strlen(array[i]);
    }
    return data_size;
}
