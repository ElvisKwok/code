#include <iostream>
using namespace std;

// file description:
// 连续子数组的最大和
// 注意：要能处理全负数的情况，下一个值设为nums[i]

bool g_InvalidInput = false;

int findGreatestSumOfSubArray(int nums[], int length) {
    if (nums == NULL || length <= 0) {
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;
    //int curSum = 0;
    //int maxSum = INT_MIN;
    int curSum = nums[0];
    int maxSum = nums[0];
    //for (int i=0; i < length; ++i) {
    for (int i=1; i < length; ++i) {
        if (curSum <= 0)
            curSum = nums[i];
        else
            curSum += nums[i];
        if (curSum > maxSum)
            maxSum = curSum;
    }
    return maxSum;
}

// =====================Test Code=====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    int result = findGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

void Test4()
{
    Test("Test4", NULL, 0, 0, true);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
