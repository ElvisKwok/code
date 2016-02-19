// Source : https://leetcode.com/problems/add-binary/
// Author : Elvis Kwok
// Date   : 2015-10-18

/********************************************************************************** 
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int size_a = a.size(), size_b = b.size();
        int longer_size = size_a >= size_b ? size_a : size_b;
        string result(longer_size, '0');
        int i = size_a - 1, j = size_b - 1, k = longer_size - 1;
        int bit_a = 0, bit_b = 0, bit = 0, carry = 0;
        while (i >= 0 || j >= 0) {
            bit_a = (i < 0 ? 0 : a[i]-'0');
            bit_b = (j < 0 ? 0 : b[j]-'0');
            bit = (bit_a + bit_b + carry) % 2;          // or & 1
            carry = (bit_a + bit_b + carry) / 2;        // or > 1
            result[k--] = bit+'0';
            --i;
            --j;
        }
        if (carry)
            result.insert(result.begin(), '1');
        return result;
    }
    // haoel solution: using string function is better.
    string addBinary1(string a, string b) {
        int alen = a.size(), blen = b.size();
        bool carry = false;
        string result;
        while (alen > 0 || blen > 0) {
            int abit = alen <= 0 ? 0 : a[alen-1]-'0';
            int bbit = blen <= 0 ? 0 : b[blen-1]-'0';
            int cbit = carry ? 1 : 0;
            result.insert(result.begin(), '0' + ((abit+bbit+cbit) & 1) );
            carry = (abit+bbit+cbit > 1);
            alen--; blen--;
        }
        if (carry)
            result.insert(result.begin(), '1');
        } 
        return result;
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.addBinary("0", "0") << endl;
    if (argc < 2)
        return 0;

    return 0;
}
