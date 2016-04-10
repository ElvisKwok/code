#include <stdio.h>

// 任意i, 使得a[i] == v
int binarySearch(int a[], int n, int v)
{
    // low<=high, high = mid-1;
    // low<high, high = mid; // 如目标在位置0，low=0,mid=1,若得到high=mid-1=0，则跳出while
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + (high-low)/2; // avoid overflow!!!!
        if (v < a[mid])
            high = mid - 1;
        else if (v > a[mid])
            low = mid + 1;
        else
            return mid;
    }
//    while (low < high) {
//        mid = low + (high-low)/2; // avoid overflow!!!!
//        if (v < a[mid])
//            high = mid;
//        else if (v > a[mid])
//            low = mid;
//        else
//            return mid;
//    }
     
    return -1;      // can't find it
}


// bop 提供的方法：最大的i使得a[i]==v
int binarySearch_maxEqual(int a[], int n, int v) {
    int low = 0, high = n-1, mid;
    while (low < high-1) {
        mid = low + (high-low)/2;
        if (a[mid] <= v)        // 如果找到, 保证low的位置指向v的前提下，尝试通过high==low+1退出while循环得到的high，看是否满足要求(note: low会向最大的i靠拢,循环退出时,结果要么是low,要么是low+1(high))
            low = mid;
        else
            high = mid;
    }
    if (a[high] == v)
        return high;
    else if (a[low] == v)
        return low;
    else
        return -1;
}

// 最小的i使得a[i] == v
int binarySearch_minEqual(int a[], int n, int v) {
    int low = 0, high = n-1, mid;
    while (low < high-1) {
        mid = low + (high-low)/2;
        if (a[mid] < v)     // 改为<
            low = mid;
        else                // 如果找到, 至少是high已经指向v，那么尝试low(note: high会向最小的i靠拢)
            high = mid;
    }
    if (a[low] == v)
        return low;
    else if (a[high] == v)
        return high;
    else
        return -1;
}

// lower_bound
// 最大的i使得a[i] < v
int binarySearch_maxLess(int a[], int n, int v) {
    int low = 0, high = n-1, mid;
    while (low < high-1) {
        mid = low + (high-low)/2;
        if (a[mid] < v)     // 改为<，如果有<v的，那么至少保证被low指向，然后尝试high(note: low会向最大的i靠拢)
            low = mid;
        else    
            high = mid;
    }
    if (a[high] < v)        // 改为<
        return high;
    else if (a[low] < v)
        return low;
    else
        return -1;
}

// upper_bound
// 最小的i使得a[i] > v
int binarySearch_minLarge(int a[], int n, int v) {
    int low = 0, high = n-1, mid;
    while (low < high-1) {
        mid = low + (high-low)/2;
        if (a[mid] <= v)    // <=
            low = mid;
        else                // 如果有>v的，那么至少保证被high指向，然后尝试low(note: high会向最小的i靠拢)
            high = mid;
    }
    if (a[low] > v)         // 改为>
        return low;
    else if (a[high] > v)
        return high;
    else
        return -1;
}

// ======================================================================
// count the times number of K exist in array data[]
// O(logN)
int getFirstK(int* data, int length, int k, int low, int high);
int getLastK(int* data, int length, int k, int low, int high);

int getNumberOfK(int* data, int length, int k) {
    int number = 0;
    if (data != NULL || length > 0) {
        int first = getFirstK(data, length, k, 0, length-1);
        int last = getLastK(data, length, k, 0, length-1);
        if (first > -1 && last > -1)
            number = last - first + 1;
    }
    return number;
}

int getFirstK(int* data, int length, int k, int low, int high) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (data[mid] == k) {
        if ((mid > 0 && data[mid-1] != k)
            || mid == 0) {
            return mid;
        }
        else {
            high = mid - 1;
        }
    }
    else if (data[mid] > k) {
        high = mid - 1;
    }
    else {
        low = mid + 1;
    }
    return getFirstK(data, length, k, low, high);
}

int getLastK(int* data, int length, int k, int low, int high) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (data[mid] == k) {
        if ((mid < length-1 && data[mid+1] != k)
            || mid == length-1) {
            return mid;
        }
        else {
            low = mid + 1;
        }
    }
    else if (data[mid] > k) {
        high = mid - 1;
    }
    else {
        low = mid + 1;
    }
    return getLastK(data, length, k, low, high);
}

int main()
{
    int a[] = {1, 3, 4, 6, 6, 6, 7, 7, 7, 7, 34, 34, 34, 40};
    int n = sizeof(a)/sizeof(a[0]);
    int v = 7;
    printf("index: \t");
    for (int i=0; i<n; ++i) 
        printf("%d\t", i);
    printf("\narray: \t");
    for (int i=0; i<n; ++i) 
        printf("[%d]\t", a[i]);
    printf("\ntarget: %d\n", v);
    printf("\n-------------result--------------\n");
    printf("classic: \t%d\n", binarySearch(a, n, v));
    printf("maxEqual: \t%d\n", binarySearch_maxEqual(a, n, v));
    printf("minEqual: \t%d\n", binarySearch_minEqual(a, n, v));
    printf("maxLess: \t%d\n", binarySearch_maxLess(a, n, v));
    printf("minLarge: \t%d\n", binarySearch_minLarge(a, n, v));
    printf("numberOfK: \t%d\n", getNumberOfK(a, n, v));
    return 0;
}
