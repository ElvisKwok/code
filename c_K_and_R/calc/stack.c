#include <stdio.h>
#include "calc.h"

#define MAXVAL	100			/* largest depth of stack val */

int sp = 0;					/* next empty space of stack */
double val[MAXVAL];			/* the stack of value		*/

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
