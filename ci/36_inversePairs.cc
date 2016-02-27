#include <iostream>
using namespace std;

// file description:
// 给定数组，输出数组元素的逆序对个数
// 参考mergeSort思想

int inversePairsCore(int* data, int* copy, int low, int high);

int inversePairs(int* data, int length) {
    if (data == NULL || length <= 0)
        return 0;
    int* copy = new int[length];
    for (int i=0; i<length; ++i)
        copy[i] = data[i];

    int cnt = inversePairsCore(data, copy, 0, length-1);

    delete[] copy;
    return cnt;
}

int inversePairsCore(int* data, int* copy, int low, int high) {
    if (low == high) {
        copy[low] = data[low];
        return 0;
    }
    int mid = low + (high-low)/2;
    int leftCnt = inversePairsCore(copy, data, low, mid);
    int rightCnt = inversePairsCore(copy, data, mid+1, high);

    int curCnt = 0;
    int i = mid;
    int j = high;
    int indexCopy = high;
    while (i >= low && j >= mid+1) {
        if (data[i] > data[j]) {
            copy[indexCopy--] = data[i--];
            curCnt += (j - mid);
        }
        else
            copy[indexCopy--] = data[j--];
    }
    while (i >= low)
        copy[indexCopy--] = data[i--];
    while (j >= mid+1)
        copy[indexCopy--] = data[j--];

    return leftCnt + rightCnt + curCnt;
}

// =====================Test Code=====================
void Test(char* testName, int* data, int length, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(inversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = {1, 2, 3, 4, 7, 6, 5};
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

void Test2()
{
    int data[] = {6, 5, 4, 3, 2, 1};
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

void Test3()
{
    int data[] = {1, 2, 3, 4, 5, 6};
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

void Test4()
{
    int data[] = {1};
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


void Test5()
{
    int data[] = {1, 2};
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

void Test6()
{
    int data[] = {2, 1};
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

void Test7()
{
    int data[] = {1, 2, 1, 2, 1};
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", NULL, 0, expected);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}
