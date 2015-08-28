#include <stdio.h>

static int maxSubSum(const int a[], int n) 
{
    int maxSum=0, thisSum=0, i;
    for (i = 0; i < n; i++) {
        thisSum += a[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

int main()
{
    const int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
    printf("max sub sum: %d\n", maxSubSum(a, 8));

    return 0;
}
