/*
*	Find out and print the line of the given pattern
*/

#include<stdio.h>
#include"getline2.c"
#include"strindex.c"

#define MAXLINE 1000

char pattern[] = "ould";

int main()
{

    char line[MAXLINE];
    int found = 0;

    while (getline2(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}
