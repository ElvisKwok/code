#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];			/* buffer zone of ungetch() */
int bufp = 0;				/* next empty space of buf	*/

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
