#include <stdio.h>

int max3(int a, int b, int c)
{
    int tmp;
    tmp = a > b ? a : b;
    return c > tmp ? c : tmp;
}

static int maxSubSum(const int a[], int left, int right)
{
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center, i;

    if (left == right)      /* Base Case*/
        if (a[left] > 0)
            return a[left];
        else
            return 0;

    center = (left + right) / 2;
    maxLeftSum = maxSubSum(a, left, center);
    maxRightSum = maxSubSum(a, center+1, right);

    maxLeftBorderSum = 0;
    leftBorderSum = 0;
    for (i = center; i >= left; --i) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    maxRightBorderSum = 0;
    rightBorderSum = 0;
    for (i = center+1; i <= right; ++i) {
        rightBorderSum += a[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
}

int main()
{
    const int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
    printf("max sub sum: %d\n", maxSubSum(a, 0, 7));

    return 0;
}
