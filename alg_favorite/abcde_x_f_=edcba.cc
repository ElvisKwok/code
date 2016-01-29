// abcde * f = edcba
// each digit is different
#include <iostream>
using namespace std;

void palindrome() {
    bool flag;
    bool isUsed[10];
    int num, numRevert, tmp, digit;
    for (num = 10000; num <= 98765; ++num) {
        flag = true;
        memset(isUsed, 0, sizeof(isUsed));
        tmp = num;
        numRevert = 0;
        for (int i=0; i<5; ++i) {
            digit = tmp%10;
            numRevert = numRevert*10 + digit;
            tmp /= 10;
            if (isUsed[digit])
                flag = false;
            else
                isUsed[digit] = 1;
        }
        if (flag && (numRevert % num == 0)) {
            digit = numRevert / num;
            if (digit<10 && !isUsed[digit])
                cout << num << " * " << digit << " = " << numRevert << endl;
        }
    }
}

int main() {
    palindrome();
    return 0;
}
