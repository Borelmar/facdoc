/* Erroneous rudiment */

#include <stdlib.h>

void ** mallocn(size_t size, unsigned int n)
{
    return (void**)malloc( (size) * n);
}
