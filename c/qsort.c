#include <stdio.h>

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right)
{
    int i, last;
    if (left >= right)							/* less than two element */
        return;
    swap(v, left, (left + right)/2);			/* choose the mid as pivot */
    last = left;								/* move pivot to v[0] */
    for (i = left + 1; i < right; i++)			/* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);						/* resume the pivot */

    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
