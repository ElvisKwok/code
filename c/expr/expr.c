#include <stdio.h>
#include <stdlib.h>
#include "calc2.h"


int main(int argc, char *argv[])
{
	double op2;		/* The second operator, used for operation like '-' or '/' */

	while (--argc > 0) {
		switch((*++argv)[0]) {
		case '+':
			push2(pop2() + pop2());
			break;
		case '*':
			push2(pop2() * pop2());
			break;
		case '-':
			op2 = pop2();
			push2(pop2() - op2);
			break;
		case '/':
			op2 = pop2();
			if (op2 != 0.0)
				push2(pop2() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop2();
			if (op2 != 0.0)
				push2((int)pop2() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;

		default:
			push2(atof(argv[0]));
			break;
		}
	}

	printf("%.8g\n", pop2());
    return 0;
}
