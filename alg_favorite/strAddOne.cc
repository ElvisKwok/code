#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// good
void strAddOne(string &str) {
    int len = str.size();
    int carry = 0;
    for (int i = len-1; i >= 0; --i) {
        int digit = str[i] - '0' + carry;
        if (i == len-1)
            ++digit;
        carry = digit / 10;
        str[i] = digit % 10 + '0';
        if (!carry)
            break;
    }
    if (carry)
        str.insert(str.begin(), carry+'0');
}

// bad
void strAddOne2(string &str) {
    int len = str.size();
    str[len-1] += 1;
    int carry = (str[len-1]-'0') / 10;
    str[len-1] = (str[len-1]-'0') % 10 + '0';
    for (int i = len-2; i >= 0; --i) {
        int digit = str[i] - '0' + carry;
        carry = digit / 10;
        str[i] = digit % 10 + '0';
    }
    if (carry)
        str.insert(str.begin(), carry+'0');
}

int main(int argc, char **argv) {
    string str("1");
    string str2("1000000000");
    //while (strcmp(str.c_str(), str2.c_str())) {
    while (str != str2) {
        cout << str << endl;
        strAddOne(str);
    }

    return 0;
}
