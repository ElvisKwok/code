#include <stdio.h>

#define ALLOCSIZE	10000			/*	available size */

char allocbuf[ALLOCSIZE];	/*	buffer */
char *allocp = allocbuf;		/*	next available position */

char *alloc(int n)					/* request for space of size n */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {	/* enough space */
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

void afree(char *p) /* release the buf from the position p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
