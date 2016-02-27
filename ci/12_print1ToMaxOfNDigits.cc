#include <iostream>
#include <cstring>  // memset
using namespace std;

// file description:
// print 1, 2, 3, 4, ...,  (9............9)
//                          |--n digits--|

bool increment(char* num);
void printNum(char* num);

void print1ToMaxOfNDigits(int n) {
    if (n<=0)
        return;
    char* num = new char[n+1];
    memset(num, '0', n);
    num[n] = '\0';
    while (!increment(num))
        printNum(num);
    delete []num;
}

bool increment(char* num) {
    bool isOverflow = false;
    int carry = 0;
    int len = strlen(num);
    for (int i=len-1; i>=0; --i) {
        int digit = num[i] - '0' + carry;
        if (i == len-1)
            ++digit;
        carry = digit / 10;
        if (carry) {
            if (i == 0)
                isOverflow = true;
            else
                num[i] = digit % 10 + '0';
        }
        else {
            num[i] = digit + '0';
            break;
        }
    }
    return isOverflow;
}

void printNum(char* num) {
    bool isStart0 = true;
    int len = strlen(num);
    for (int i=0; i<len; ++i) { 
        if (isStart0 && num[i]!='0')
            isStart0 = false;
        if (isStart0 == false)
            cout << num[i];
    }
    cout << "\t";
}

// ============== recursively ============== 
void recursive(char* num, int length, int index);

void print1ToMaxOfNDigits_2(int n) {
    if (n <= 0)
        return;
    char* num = new char[n+1];
    memset(num, '0', n);
    num[n] = '\0';
    for (int i=0; i<10; ++i) {
        num[0] = i + '0';
        recursive(num, n, 0);
    }
    delete []num;
}

void recursive(char* num, int length, int index) {
    if (index == length-1) {
        printNum(num);
        return;
    }
    for (int i=0; i<10; ++i) {
        num[index+1] = i + '0';
        recursive(num, length, index+1);
    }
}

// =====================Test Code=====================
void test(int n) {
    cout << "test for " << n << " begins:" << endl;
    print1ToMaxOfNDigits(n);
    cout << endl;
    print1ToMaxOfNDigits_2(n);
    cout << endl;
    cout << "test for " << n << " ends." << endl;
}

int main() {
    test(1);
    test(2);
    test(3);
    test(0);
    test(-1);

    return 0;
}
