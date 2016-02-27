#include <iostream>
#include <string>
using namespace std;

// add two string
// note: 
// corner case: negative string!!

string strMinus(string &str1, string &str2);

// work when 正+正 or 负+负
string strAdd(string &str1, string &str2) {
    string result;
    int len1 = str1.size();
    int len2 = str2.size();
    bool flag1 = (str1[0]=='-');     // flag = 0 or 1
    bool flag2 = (str2[0]=='-');
    int carry = 0;
    if (flag1 + flag2 == 1)     // 一正一负
        return strMinus(str1, str2);
    for (int i=len1-1, j=len2-1; (i>=0+flag1 || j>=0+flag2); ) {
        int digit1 = (i>=0+flag1) ? str1[i]-'0' : 0;
        int digit2 = (j>=0+flag2) ? str2[j]-'0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        result.insert(result.begin(), sum+'0');
        --i;
        --j;
    }
    if (carry)
        result.insert(result.begin(), carry+'0');
    if (flag1 && flag2)
        result.insert(result.begin(), '-');
    return result;

}

string strMinus(string &str1, string &str2) {
    string result;
    bool flag1 = (str1[0]=='-');     // flag = 0 or 1
    bool flag2 = (str2[0]=='-');
    bool flag = true;
    string absStr1(str1.begin()+flag1, str1.end());
    string absStr2(str2.begin()+flag2, str2.end());
    int len1 = absStr1.size();
    int len2 = absStr2.size();
    if (len1 < len2 || 
        (len1 == len2 && absStr1 < absStr2)) // absStr1 < absStr2
    {
        swap(absStr1, absStr2);
        swap(len1, len2);
        if (flag1)
            flag = false;           // 结果为正
    }
    else {  // absStr1 >= absStr2
        if (flag2)
            flag = false;
    }
    
    int carry = 0;
    for (int i=len1-1, j=len2-1; (i>=0 || j>=0); ) {
        int digit1 = (i>=0) ? absStr1[i]-'0' : 0;
        int digit2 = (j>=0) ? absStr2[j]-'0' : 0;
        int diff = digit1 - digit2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        }
        else
            carry = 0;
        result.insert(result.begin(), diff+'0');
        --i;
        --j;
    }
    if (flag)
        result.insert(result.begin(), '-');
    return result;
}

int main(int argc, char **argv) {
    string str1(argv[1]);
    string str2(argv[2]);
    cout << strAdd(str1, str2) << endl;

    return 0;
}
