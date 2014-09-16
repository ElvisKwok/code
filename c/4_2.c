/*
 * sum up every single floating number of each line read immediately
 */

#include <stdio.h>
#include "atof.c"
#include "getline2.c"
#define MAXLINE 100

int main()
{
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (getline2(line, MAXLINE) > 0)
        printf("now:\t%g\n", sum += atof(line));
    return 0;
}
