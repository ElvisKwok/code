#include <stdio.h>
#include "getfloat.c"

int main()
{
    int i;
    double array[10];
    for (i = 0; i < 10 && getfloat(&array[i]) != EOF; i++)
        ;
    for (i = 0; i < 10; i++)
        printf("%f ", array[i]);
    printf("\n");
    return 0;
}
