#include <iostream>
using namespace std;

// file description:
// 给定N, 求1~N中所有数字的十进制表示含有1的个数的总和
//

typedef unsigned long long ULONGLONG;
// solution 1:
// O(N*logN)
ULONGLONG count1(ULONGLONG n) {
    ULONGLONG cnt = 0;
    while (n != 0) {
        cnt += ((n % 10) == 1 ? 1 : 0);
        n /= 10;
    }
    return cnt;
}

ULONGLONG numberOf1_1(ULONGLONG n) {
    ULONGLONG cnt = 0;
    for (ULONGLONG i = 1; i <= n; ++i) 
        cnt += count1(i);
    return cnt;
}
        
// solution2: BOP page135
// n = abddfdsfdfgddgddsfdsfdsjd
//     ~~~~~~~~~~~~~|~~~~~~~~~~~
//     higherNum curNum lowerNum
// 每一个factor对应于curNum那一位
// O(N)
ULONGLONG numberOf1_2(ULONGLONG n) {
    ULONGLONG cnt = 0;
    ULONGLONG factor = 1;
    ULONGLONG lowerNum = 0;
    ULONGLONG curNum = 0;
    ULONGLONG higherNum = 0;
    while (n / factor != 0) {
        lowerNum = n % factor;
        curNum = (n/factor) % 10;
        higherNum = n / (factor * 10);
        switch (curNum) {
            case 0:
                cnt += higherNum * factor;
                break;
            case 1:
                cnt += higherNum * factor + lowerNum+1;
                break;
            default: // (2~9)
                cnt += (higherNum+1) * factor;
                break;
        }
        factor *= 10;
    }
    return cnt;
}

// =====================Test Code=====================
void test(char* testName, ULONGLONG n, ULONGLONG expected) {
    if (testName != NULL) 
        cout << testName << " begins: " << endl;
   // if (numberOf1_1(n) == expected)
   //     cout << "solution1 passed." << endl;
   // else
   //     cout << "solution1 failed." << endl;
    if (numberOf1_2(n) == expected)
        cout << "solution2 passed." << endl;
    else
        cout << "solution2 failed." << endl;
    cout << endl;
}

int main() {
    test("test1", 1, 1); 
    test("test2", 5, 1); 
    test("test3", 10, 2); 
    test("test4", 55, 16); 
    test("test5", 99, 20); 
    test("test6", 10000, 4001); 
    test("test7", 21345, 18821); 
    test("test8", 0, 0); 
    test("test9", 1111111110, 1111111110); 

    return 0;
}
