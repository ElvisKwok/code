#include <iostream>
using namespace std;

// file description:
// given a predicate(func), reorder the array to 
// 1st part s.t. predicate==false
// the other part s.t. predicate==true

void reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

void reorderOddEven(int *pData, unsigned int length) {
    reorder(pData, length, isEven);
}

void reorder(int *pData, unsigned int length, bool (*func)(int)) {
    if (pData == NULL || length == 0)
        return ;
    int *pBegin = pData;
    int *pEnd = pData+length-1;
    while (pBegin < pEnd) {
        while (pBegin < pEnd && !func(*pBegin))
            ++pBegin;
        while (pBegin < pEnd && func(*pEnd))
            --pEnd;
        if (pBegin < pEnd) {
            int tmp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = tmp;
        }
    }
}
            
bool isEven(int n) {
    return (n & 0x1) == 0;
}

// =====================Test Code=====================
void printArray(int nums[], int length) {
    if (length < 0)
        return;
    for (int i=0; i<length; ++i)
        cout << nums[i] << "\t";
    cout << endl;
}

void test(char* testName, int nums[], int length) {
    if (testName != NULL) 
        cout << testName << "begins: " << endl;
    cout << "test result: " << endl;
    printArray(nums, length);
    reorderOddEven(nums, length);
    printArray(nums, length);
}

void test1() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    test("test1", nums, sizeof(nums)/sizeof(int));
}

void test2() {
    int nums[] = {2, 4, 6, 1, 3, 5, 7};
    test("test2", nums, sizeof(nums)/sizeof(int));
}

void test3() {
    int nums[] = {1, 3, 5, 7, 2, 4, 6};
    test("test3", nums, sizeof(nums)/sizeof(int));
}

void test4() {
    int nums[] = {1};
    test("test4", nums, sizeof(nums)/sizeof(int));
}

void test5() {
    int nums[] = {2};
    test("test5", nums, sizeof(nums)/sizeof(int));
}

void test6() {
    test("test6", NULL, 0);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}
