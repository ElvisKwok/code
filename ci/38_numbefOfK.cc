#include <iostream>
using namespace std;

// file description:
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

// =====================Test Code=====================
void Test(char* testName, int data[], int length, int k, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result = getNumberOfK(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

void Test11()
{
    Test("Test11", NULL, 0, 0, 0);
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
    Test9();
    Test10();
    Test11();

    return 0;
}
