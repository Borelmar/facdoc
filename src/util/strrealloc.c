#include <stdlib.h>

char *strrealloc(char *ptr, size_t size)
{
    char *_ret = realloc(ptr, size);
    _ret[size] = '\0';
    return _ret;
}
