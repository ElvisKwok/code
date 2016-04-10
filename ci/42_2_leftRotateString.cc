#include <iostream>
#include <cstring>
using namespace std;

// file description:
// abc123xyz
// |-t-|
// 3xyzabc12
// 3次翻手

void reverse(char* pStr, int low, int high);

char* leftRotateString(char* pStr, int t) {
    if (pStr != NULL) {
        int len = strlen(pStr);
        if (len > 0 && t > 0 && t < len) {
            reverse(pStr, 0, t-1);
            reverse(pStr, t, len-1);
            reverse(pStr, 0, len-1);
        }
    }
    return pStr;
}

void reverse(char* pStr, int low, int high) {
    while (low < high) {
        char tmp = pStr[low];
        pStr[low] = pStr[high];
        pStr[high] = tmp;
        ++low;
        --high;
    }
}

// =====================Test Code=====================
void Test(char* testName, char* input, int num, char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    char* result = leftRotateString(input, num);

    if((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

void Test4()
{
    Test("Test4", NULL, 6, NULL);
}

void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
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
