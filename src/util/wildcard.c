/* 
 * wildcard() - wildcard implementation for facdoc.
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

int wildcard_compare(const char* wild, const char* string) 
{
    const char* cp = 0, *mp = 0;
    
    while ((*string) && (*wild != '*')) 
    {
        if ((*wild != *string) && (*wild != '?')) 
        {
            return 0;
        }
        wild++;
        string++;
    }
        
    while (*string) 
    {
        if (*wild == '*') 
        {
            if (!*++wild) 
            {
                return 1;
            }
            mp = wild;
            cp = string+1;
        } 
        else if ((*wild == *string) || (*wild == '?')) 
        {
            wild++;
            string++;
        } 
        else 
        {
            wild = mp;
            string = cp++;
        }
    }
        
    while (*wild == '*') 
    {
        wild++;
    }
    return !*wild;
}

