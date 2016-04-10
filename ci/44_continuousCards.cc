#include <iostream>
using namespace std;

// file description:
// poker card, 1 ~ 13, 0 for king(could stand for every card)
// given 5 cards, check if they are continue

// =====================solution =====================
//
int compare(const void *arg1, const void *arg2);

bool isContinuous(int* numbers, int length) {
    if (numbers == NULL || length < 1)   
        return false;
    qsort(numbers, length, sizeof(int), compare);

    int numberOf0 = 0;
    int numberOfGap = 0;

    // count 0
    for (int i=0; i<length && numbers[i]==0; ++i) 
        ++numberOf0;

    int low = numberOf0;
    int high = low + 1;
    while (high < length) {
        // pair
        if (numbers[low] == numbers[high])
            return false;
        numberOfGap += numbers[high] - numbers[low] - 1;
        low = high;
        ++high;
    }
    return numberOfGap > numberOf0 ? false : true;
}

int compare(const void *arg1, const void *arg2) {
    return *(int*)arg1 - *(int*)arg2;
}


// =====================Test Code=====================
void Test(char* testName, int* numbers, int length, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(isContinuous(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int numbers[] = {1, 3, 2, 5, 4};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2()
{
    int numbers[] = {1, 3, 2, 6, 4};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3()
{
    int numbers[] = {0, 3, 2, 6, 4};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4()
{
    int numbers[] = {0, 3, 1, 6, 4};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5()
{
    int numbers[] = {1, 3, 0, 5, 0};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6()
{
    int numbers[] = {1, 3, 0, 7, 0};
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7()
{
    int numbers[] = {1, 0, 0, 5, 0};
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8()
{
    int numbers[] = {1, 0, 0, 7, 0};
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9()
{
    int numbers[] = {3, 0, 0, 0, 0};
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10()
{
    int numbers[] = {0, 0, 0, 0, 0};
    Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test11()
{
    int numbers[] = {1, 0, 0, 1, 0};
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test12()
{
    Test("Test12", NULL, 0, false);
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
    Test12();

    return 0;
}
