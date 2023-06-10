#include <stdlib.h>
#include <string.h>

char*
    chrmult(char chr, size_t factor)
{
    unsigned int len = factor + 1;
    char *ptr = (char*)malloc(len);
    ptr[len-1] = '\0';
    return memset(ptr, chr, factor);
}

void**
    mallocn(size_t size, unsigned int n)
{
    return (void**)malloc( (size) * n);
}
