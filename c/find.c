/*
 * find.exe to print the line match with given pattern 
 */

#include <stdio.h>
#include <string.h>

#include "getline2.c"

#define MAXLINE 1000

int getline2(char *line, int max);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage: ./find.exe pattern\n");
	else
		while (getline2(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
	return found;
}
