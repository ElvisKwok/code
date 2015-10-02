#include <stdio.h>
#include <time.h>

int main()
{
    struct tm *tm_ptr;
    unsigned int u=0;
    time_t biggest =  u-1, now, diff;
    now = time(NULL);
    diff = difftime(biggest, now);
    tm_ptr = gmtime(&diff);
    printf("biggest = %s", asctime(gmtime(&biggest)));
    printf("now = %s", ctime(&now));
    printf("diff = %f\n", difftime(biggest, now));
    printf("%2d/%2d/%2d, %2d:%2d:%2d\n", tm_ptr->tm_year, tm_ptr->tm_mon, tm_ptr->tm_mday, tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec); 
    return 0;
}
