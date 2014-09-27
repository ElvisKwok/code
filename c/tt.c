#include <stdio.h>
#include <stdlib.h>

#define Length 10

typedef struct Point {
    int distance;    
    int x1,x2;
} Pair;

Pair Cpair(int a[], int left, int right);

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(int argc, char *argvp[])
{
    int a[Length], i;
    Pair d;

    for(i = 0; i < Length; i++)
        a[i] = rand()%100;
    qsort(a, Length, sizeof(a[0]), cmp);

    for(i = 0; i < Length; i++)
        printf("%d ", a[i]);
    printf("\n");

    d=Cpair(a, 0, 4);
    printf("pair:<%d,%d>, distance:%d\n", d.x1, d.x2, d.distance);
    return 0;
}


Pair Cpair(int a[], int left, int right)
{
    Pair min_d = {99999,0,0}, d1, d2;
    int p, q;

    if(right-left<1) return min_d;

    int m1=a[left],m2=a[right];
    int m=(m1+m2)/2;
    int j,i;
    for(i=left; i < right; i++)
        if(a[i]<=m&&a[i+1]>m)
        {
            j=i;
            break;
        }

    d1=Cpair(a,left,j);
    d2=Cpair(a,j+1,right);

    p=a[j],q=a[j+1];

    if(d1.distance<d2.distance)
    {
        if((q-p)<d1.distance)
        {
            min_d.distance=(q-p);
            min_d.x1 = p;
            min_d.x2 = q;
            return min_d;
        }
        else return d1;
    }
    else
    {
        if((q-p)<d2.distance)
        {
            min_d.distance=(q-p);
            min_d.x1 = p;
            min_d.x2 = q;
            return min_d;
        }
        else return d2;
    }
}
