// 求数组主元素
// 出现次数*超过*一半
// 若无则输出-1
// 主元素也是排序后的中位数，也就是第k大的数，k=n/2，可用求第k大的算法

// solution1: 排序，mid即是
// O(NlogN)

// solution2: 随机快速排序的partition函数
// 平均O(N)
// low = 0, high = n-1, mid = n>>1;
// index = partition(nums, n, low, high)
// while (index != mid) {
//     if (index > mid) {
//         high = mid-1;
//         index = partition(nums, n, low, high);
//     }
//     else {
//         low = mid+1;
//         index = partition(nums, n, low, high);
//     }
// }
// result = nums[mid];
// 验证result: 可设置全局变量bool g_bInputValid判断非法输入

// solution3: 候选主元素candidate, cnt
// 主元素的出现次数比其他元素出现次数的总数还要多

#include <iostream>
#include <vector>
#include "partition.h"
using namespace std;

bool g_bInputInvalid = false;
bool checkInvalidArray(int nums[], int length) {
    g_bInputInvalid = false;
    if (nums==NULL || length<=0)
        g_bInputInvalid = true;
    return g_bInputInvalid;
}

bool checkMoreThanHalf(int nums[], int length, int val) {
    int cnt = 0;
    for (int i = 0; i < length; ++i) {
        if (nums[i] == val)
            ++cnt;
    }
    bool isMoreThanHalf = true;
    if (cnt * 2 <= length) {
        isMoreThanHalf = false;
        g_bInputInvalid = true;
    }
    return isMoreThanHalf;
}

// =====================solution 1=====================
int moreThanHalfNum_1(int nums[], int length) {
    if (checkInvalidArray(nums, length))
        return 0;
    int mid = length >> 1;
    int low = 0;
    int high = length - 1;
    int index = partition(nums, length, low, high);
    while (index != mid) {
        if (index > mid) {
            high = index - 1;
            index = partition(nums, length, low, high);
        }
        else {
            low = index + 1;
            index = partition(nums, length, low, high);
        }
    }
    int result = nums[mid];
    if (!checkMoreThanHalf(nums, length, result))
        result = 0;
    return result;
} 

// =====================solution 2=====================
//int moreThanHalfNum_2(int nums[], int length) {
//    if (checkInvalidArray(nums, length))
//        return 0;
//    int candidate = nums[0];
//    int cnt = 1;
//    for (int i = 1; i < length; ++i) {
//        if (candidate == nums[i]) {
//            ++cnt;
//        }
//        else {
//            if (cnt > 0) {
//                --cnt;
//            }
//            else {
//                candidate = nums[i];
//                cnt = 1;
//            }
//        }
//    }
//    if (!checkMoreThanHalf(nums, length candidate))
//        candidate = 0;
//    return candidate;
//}
int moreThanHalfNum_2(int nums[], int length) {
    if (checkInvalidArray(nums, length))
        return 0;
    int candidate = nums[0];
    int cnt = 1;
    for (int i = 1; i < length; ++i) {
        if (cnt == 0) {
            candidate = nums[i];
            cnt = 1;
        }
        else if (candidate == nums[i])
            ++cnt;
        else
            --cnt;
    }

    if (!checkMoreThanHalf(nums, length, candidate))
        candidate = 0;
    return candidate;
}

// =====================Test Code=====================
void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = moreThanHalfNum_1(numbers, length);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    result = moreThanHalfNum_2(copy, length);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

void Test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

void Test2()
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

void Test3()
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

void Test4()
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

void Test5()
{
   int numbers[] = {1};
   Test("Test5", numbers, 1, 1, false);
}

void Test6()
{
    Test("Test6", NULL, 0, 0, true);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
