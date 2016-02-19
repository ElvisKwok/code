// Source : https://leetcode.com/problems/multiply-strings/
// Author : Elvis Kwok
// Date   : 2015-12-31

/********************************************************************************** 
 * 
 * Given two numbers represented as strings, return multiplication of the numbers as a 
 * string.
 * 
 * Note: The numbers can be arbitrarily large and are non-negative.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution: string to int array, correspond to each char.
    // O(M*N), O(M+N)
    // store in reverse order.
    vector<int> toIntArray(string const &repr) {
        vector<int> ivec;
        for (int i=0; i<repr.size(); ) 
            ivec.insert(ivec.begin(), repr[i++]-'0');
        return ivec;
    }
    string toString(vector<int> const &ivec) {
        string str;
        for (int i=0; i<ivec.size(); )
            str.insert(str.begin(), ivec[i++]+'0');
        return str;
    }
    vector<int> bitMultiply(vector<int> const &x, vector<int> const &y) {
        vector<int> z(x.size()+y.size());
        for (size_t i=0; i<x.size(); ++i) {
            for (size_t j=0; j<y.size(); ++j) {
                z[i+j] += x[i] * y[j];
                z[i+j+1] += z[i+j]/10;
                z[i+j] %= 10;
            }
        }
        // return 12*2 = 024 ??
        // note: "024" store in array as [4 2 0]
        for (size_t i=z.size()-1; i>=1; --i) {
            if (z[i] == 0)
                z.pop_back();
            else 
                break;
        }

        return z;
    }
    string multiply(string num1, string num2) {
        return toString(bitMultiply(toIntArray(num1), toIntArray(num2)));
    }

    // haoel solution
    string multiplyOneBit(string &num, char ch) {
        int n = ch - '0';
        int carry = 0;
        int x;
        string s;
        for (int i=num.size()-1; i>=0; --i) {
            x = (num[i]-'0') * n + carry;
            carry = x/10;
            s.insert(s.begin(), x%10+'0');
        }
        if (carry > 0)
            s.insert(s.begin(), carry+'0');
        return s;
    }
    string strPlus(string &num1, string &num2) {
        string s;
        int carry = 0;
        int n1 = num1.size();
        int n2 = num2.size();
        for (int i=n1-1, j=n2-1; i>=0 || j>=0; --i, --j) {
            int x1 = (i>=0 ? num1[i]-'0' : 0);
            int x2 = (j>=0 ? num2[j]-'0' : 0);
            int x = x1 + x2 + carry;
            carry = x/10;
            s.insert(s.begin(), x%10+'0');
        }
        if (carry > 0)
            s.insert(s.begin(), carry+'0');
        return s;
    }
    string multiply2(string num1, string num2) {
        if (num1.size()<=0 || num2.size()<=0) return "";
        int shift = 0;
        string result="0";
        for (int i=num1.size()-1; i>=0; --i) {
            string s = multiplyOneBit(num2, num1[i]);
            for (int j=0; j<shift; ++j)
                s.push_back('0');
            result = strPlus(result, s);
            shift++;
        }
        // check if it is zero
        if (result[0]=='0') return "0";
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.multiply("0", "0") << endl;
    if (argc < 2)
        return 0;

    return 0;
}
