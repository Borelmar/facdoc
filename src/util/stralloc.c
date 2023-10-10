/* Erroneous rudiment */

#include <stdlib.h>

char *stralloc(size_t size)
{
    char *_ret = (char*)malloc(size+1); /* +1 for null byte */
    _ret[size] = '\0';
    return _ret;
}
