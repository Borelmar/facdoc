#include <stdio.h>
#include <time.h>
 
int main(void)
{
    time_t mytime = time(NULL);
    struct tm *now = localtime(&mytime);
    char str[20];
    strftime(str, sizeof(str), "%d.%m.%Y", now);
    printf("Time: %s\n", str);
    return 0;
}
