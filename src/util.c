#include <stdio.h>

int wildcard_compare(const char* wild, const char* string) 
{
    const char* cp = NULL, *mp = NULL;
    
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
