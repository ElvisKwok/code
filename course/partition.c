#include <stdio.h>
#include <stdlib.h>

int *a;

/* print one result stored in global array a[] */
void display(int m)
{
    int i;
    for (i = 0; i < m-1; i++)
        printf("%d+", a[i]);
    printf("%d\n", a[i]);
}


/* partition of n, parameter 'm' means m numbers sum up to n */
void partition(int n, int m)
{
    int i;
    if (n == 0)
        display(m);					/* n reduce to 0, finish one result */
    else
        for (i = n; i >= 1; i--)
            if (m == 0 || i <= a[m-1]) {
                a[m] = i;
                partition(n-i, m+1);
            }
}

int main(int argc, char *argv[])
{
    int n, i, m = 0;
    printf("input n: ");
    scanf("%d", &n);
    a = (int *)malloc(n*sizeof(int));
    partition(n, m);
    return 0;
}

