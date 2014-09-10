#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* get the next operator */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;			/* not a number, may be a operator or illegal character */
	i = 0;
	if (isdigit(c))			/* collect the integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')			/* collect the fractional part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
