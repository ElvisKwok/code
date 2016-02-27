#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// file description:
// 给定一个int数组，将数组所有元素拼接成一个数，输出拼接结果最小的那个
//

int compare(const void* strNum1, const void* strNum2);

const int g_MaxNumberLength = 10;
char* g_StrCombine1 = new char[g_MaxNumberLength*2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength*2 + 1];

void printMinNumber(int* nums, int length) {
    if (nums == NULL || length <= 0)
        return ;
    char** strNums = (char**)(new int[length]);
    for (int i = 0; i < length; ++i) {
        strNums[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNums[i], "%d", nums[i]);
    }

    qsort(strNums, length, sizeof(char*), compare);

    for (int i=0; i<length; ++i)
        cout << strNums[i];
    cout << endl;

    for (int i=0; i<length; ++i)
        delete[] strNums[i];
    delete[] strNums;
}

int compare(const void* strNum1, const void* strNum2) {
    // [strNum1][strNum2]
    strcpy(g_StrCombine1, *(const char**)strNum1);
    strcat(g_StrCombine1, *(const char**)strNum2);

    // [strNum2][strNum1]
    strcpy(g_StrCombine2, *(const char**)strNum2);
    strcat(g_StrCombine2, *(const char**)strNum1);

    return strcmp(g_StrCombine1, g_StrCombine2);
}

// =====================Test Code=====================
void Test(char* testName, int* numbers, int length, char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    if(expectedResult != NULL)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    printMinNumber(numbers, length);

    printf("\n");
}

void Test1()
{
    int numbers[] = {3, 5, 1, 4, 2};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int), "12345");
}

void Test2()
{
    int numbers[] = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int), "321323");
}

void Test3()
{
    int numbers[] = {3, 323, 32123};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int), "321233233");
}

void Test4()
{
    int numbers[] = {1, 11, 111};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int), "111111");
}

void Test5()
{
    int numbers[] = {321};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int), "321");
}

void Test6()
{
    Test("Test6", NULL, 0, "Don't print anything.");
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
