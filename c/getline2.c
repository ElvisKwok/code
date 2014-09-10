/*
 * The function getline2() saves the current line to array s, and return the length of the line 
 */
#include<stdio.h>

int getline2(char s[], int lim)
{
	int c, i;
	i = 0;
	while ( --lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
