#include <stdio.h>

#define MAX_PATT_LEN 12
#define PATCOUNT 26

char blocks_patterns_array[][MAX_PATT_LEN] = { "/block '*'/", "\\block\\", "/title/", "\\title\\", "/text/", "\\text\\", "/img '*'/", "\\img\\", "/link '*'/", "\\link\\", "/code/", "\\code\\", "/b/", "\\b\\", "/m/", "\\m\\", "/i/", "\\i\\", "/d/", "\\d\\", "/u/", "\\u\\", "/sub/", "\\sub\\", "/sup/", "\\sup\\"};

/*
int main(void)
{
    for(int i = 0; i < 26; i++){
        printf("%s\n", blocks_patterns_array[i]);
    }
}
*/
