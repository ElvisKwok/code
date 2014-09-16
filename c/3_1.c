#include<stdio.h>

int binsearch(int x, int v[], int n)
{
    int  low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if ( x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int a[10], x;
    printf("input 10 numbers:\n");
    for ( int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("input a number you want to find:\n");
    scanf("%d", &x);
    printf("%d is in the %d place of array", x, binsearch(x, a, 10));
    return 0;
}
