#include <stdio.h>

int binarySearch(int array[], int n, int v)
{
    // left<=right, right = middle-1;
    // left<right, right = middle; // 如目标在位置0，left=0,mid=1,若得到right=mid-1=0，则跳出while
    int left, right, middle;
    left = 0;
    right = n - 1;
//    while (left <= right) {
//        middle = (left + right) / 2;
//        if (v < array[middle])
//            right = middle - 1;
//        else if (v > array[middle])
//            left = middle + 1;
//        else
//            return middle;
//    }
    while (left < right) {
        middle = (left + right) / 2;
        if (v < array[middle])
            right = middle;
        else if (v > array[middle])
            left = middle;
        else
            return middle;
    }
    return -1;
}

int main()
{
    int a[] = {1, 3, 4, 6, 7, 34, 40};
    printf("%d\n", binarySearch(a, sizeof(a)/sizeof(a[0]), 7));
    printf("%d\n", binarySearch(a, sizeof(a)/sizeof(a[0]), 1));
    return 0;
}
