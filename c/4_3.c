#include <stdio.h>
#include <stdlib.h>			/* in order to use standard atof() */
#include <ctype.h>

#define MAXOP	100			/* max length of number or  operator */
#define NUMBER	'0'			/* tag for finding out a number */
#define MAXVAL	100			/* largest depth of stack val */
#define BUFSIZE 100

int sp = 0;					/* next empty space of stack */
double val[MAXVAL];			/* the stack of value		*/
char buf[BUFSIZE];			/* buffer zone of ungetch() */
int bufp = 0;				/* next empty space of buf	*/

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/*	 逆波兰计算器	*/
int main()
{
	int type;
	double op2;		/* The second operator, used for operation like '-' or '/' */
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
    return 0;
}

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

int getch(void)			/* fetch a character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* return back the character to input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
