/* 
 * strarrcat() - strings in array concatinate.
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
#include <string.h>

extern size_t strarr_data_size(const char **arr, size_t n);
extern char *stralloc(size_t n);

char *strarrcat(const char **array, size_t n)
{
    size_t dsize = strarr_data_size(array, n);
    char *_ret = stralloc(dsize);
    char *_curr = _ret;

    for (size_t i = 0; i < n; i++)
    {
        size_t _size = strlen(array[i]);
        memcpy(_curr, array[i], _size);
        _curr += _size;
    }
    return _ret;
}

/*
int main(void)
{
    char **arr = (char**)malloc(2*sizeof(char*));
    arr[0] = (char*)malloc(10);
    arr[1] = (char*)malloc(10);
    arr[2] = (char*)malloc(10);
    arr[3] = (char*)malloc(10);
    strcpy(arr[0], "0 ");
    strcpy(arr[1], "1 ");
    strcpy(arr[2], "2 ");
    strcpy(arr[3], "3 ");

    char *out = strarrcat(arr, 4);
    puts(out);
    free(out);
    free(arr[0]);
    free(arr[1]);
    free(arr[2]);
    free(arr[3]);
    free(arr);
    return 0;
}
*/

