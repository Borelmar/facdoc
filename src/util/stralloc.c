/* Erroneous rudiment */

#include <stdlib.h>

char *stralloc(size_t n)
{
    char *_ret = (char*)malloc(n+1); /* +1 for null byte */
    _ret[n] = '\0';
    return _ret;
}
