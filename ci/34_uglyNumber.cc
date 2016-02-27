#include <iostream>
using namespace std;

// file description:
// 输出第k个丑数(仅能被2，3，5整除的数)
// 第1个丑数为1

// =====================solution 1=====================
// bad: each num is processed 
bool isUgly(int num) {
    while (num % 2 == 0)
        num /= 2;
    while (num % 3 == 0)
        num /= 3;
    while (num % 5 == 0)
        num /= 5;
    return (num==1);
}

int getUglyNumber_1(int index) {
    if (index <= 0)
        return 0;
    int cnt = 0;
    int num = 0;
    while (cnt < index) {
        ++num;
        if (isUgly(num))
            ++cnt;
    }
    return num;
}

// =====================solution 2=====================
// only ugly num is processed
int min3(int a, int b, int c);

int getUglyNumber_2(int index) {
    if (index <= 0)
        return 0;

    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;
    
    int* pMultiply2 = pUglyNumbers;
    int* pMultiply3 = pUglyNumbers;
    int* pMultiply5 = pUglyNumbers;
    
    while (nextUglyIndex < index) {
        int minVal = min3(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        pUglyNumbers[nextUglyIndex] = minVal;
        
        while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply2;
        while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply3;
        while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply5;

        ++nextUglyIndex;
    }
    int ugly = pUglyNumbers[index-1];
    delete[] pUglyNumbers;
    return ugly;
}

int min3(int a, int b, int c) {
    int min2 = min(a, b);
    return min(min2, c);
}

// =====================Test Code=====================
void test(int index, int expected) {
    if (getUglyNumber_1(index) == expected)
        cout << "solution1 passed." << endl;
    else
        cout << "solution1 failed." << endl;
    if (getUglyNumber_2(index) == expected)
        cout << "solution2 passed." << endl;
    else
        cout << "solution2 failed." << endl;
}

int main() {
    test(1, 1);
    test(2, 2);
    test(3, 3);
    test(4, 4);
    test(5, 5);
    test(6, 6);
    test(7, 8);
    test(8, 9);
    test(9, 10);
    test(10, 12);
    test(11, 15);

    test(1500, 859963392);

    test(0, 0);

    return 0;
}
