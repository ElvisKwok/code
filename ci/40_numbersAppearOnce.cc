#include <iostream>
using namespace std;

// file description:
// two of nums in array appear once, find them out

unsigned int findFirstBitIs1(int num);
bool isBit1(int num, unsigned int indexBit);

void findNumsAppearOnce(int data[], int length, int* num1, int* num2) {
    if (data == NULL || length < 2)
        return ;
    int resultExclusiveOR = 0;
    for (int i = 0; i < length; ++i)
        resultExclusiveOR ^= data[i];
    unsigned int indexOf1 = findFirstBitIs1(resultExclusiveOR);
    *num1 = *num2 = 0;
    for (int j = 0; j < length; ++j) {
        if (isBit1(data[j], indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}

unsigned int findFirstBitIs1(int num) {
    int indexBit = 0;
    while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
        num >>= 1;
        ++indexBit;
    }
    return indexBit;    
}

bool isBit1(int num, unsigned int indexBit) {
    return (num >> indexBit) & 1;
}


// =====================Test Code=====================
void Test(char* testName, int data[], int length, int expected1, int expected2)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result1, result2;
    findNumsAppearOnce(data, length, &result1, &result2);

    if((expected1 == result1 && expected2 == result2) ||
        (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1()
{
    int data[] = {2, 4, 3, 6, 3, 2, 5, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
    int data[] = {4, 6};
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
    int data[] = {4, 6, 1, 1, 1, 1};
    Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main()
{
    Test1();
    Test2();
    Test3();

    return 0;
}
