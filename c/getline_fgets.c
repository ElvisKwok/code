/*
 * The function getline() saves the current line to array s
 * and return the length of the line
 * this program is simplified by using fgets()
 */
#include<stdio.h>

int getline(char *line, int max)
{
    if(fgets(line, max, stdin) == NULL)
        return 0;
    else return strlen(line);
}
