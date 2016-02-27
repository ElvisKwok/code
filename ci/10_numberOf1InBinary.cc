#include <iostream>
using namespace std;

// file description:
// input a int num, count how many 1 in its binary expression

int numberOf1_1(int n) {
    unsigned int flag = 1;
    int cnt = 0;
    while (flag) {
        if (n & flag)
            ++cnt;
        flag <<= 1;
    }
    return cnt;
}

int numberOf1_2(int n) {
    int cnt = 0;
    while (n) {
        n = n & (n-1);  // 每次把最右的1变成0
        ++cnt;
    }
    return cnt;
}


// =====================Test Code=====================
void test(int num, unsigned int expected) {
    int actual = numberOf1_1(num);
    if (actual == expected)
        cout << "solution1: test for " << num << " passed." << endl;
    else
        cout << "solution1: test for " << num << " failed." << endl;
    actual = numberOf1_2(num);
    if (actual == expected)
        cout << "solution2: test for " << num << " passed." << endl;
    else
        cout << "solution2: test for " << num << " failed." << endl;
    cout << endl;
}

int main() {
    test(0, 0);
    test(1, 1);
    test(10, 2);
    test(0x7FFFFFFF, 31);
    test(0xFFFFFFFF, 32);
    test(0x80000000, 1);

    return 0;
}
