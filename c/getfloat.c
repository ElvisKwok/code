/*
 * getint(): assign the next integer from input to *pn
 */

#include <ctype.h>
#include "getch.c"

int getch(void);
void ungetch(int);

int getfloat(double *pn)
{
	int c, sign;
	double power;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c!= '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}
	*pn = (*pn * sign) / power;
	if (c != EOF)
		ungetch(c);
	return c;
}
