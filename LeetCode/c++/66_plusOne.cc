// Source : https://leetcode.com/problems/plus-one/
// Author : Elvis Kwok
// Date   : 2015-10-18

/********************************************************************************** 
 * 
 * Given a non-negative number represented as an array of digits, plus one to the 
 * number.
 * 
 * The digits are stored such that the most significant digit is at the head of the 
 * list.
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
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, bit = 0;
        int i = digits.size()-1;
        while(i >= 0) {
            bit = digits[i]+carry;
            digits[i] = bit % 10;
            carry = bit / 10;
            --i;
        }
        if (carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
    // haoel solution
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> v;
        while (digits.size() > 0) {
            int x = digits.back();
            digits.pop_back();
            x += carry;
            v.insert(v.begin(), x%10);
            carry = x / 10;
        }
        if (carry > 0)
            v.insert(v.begin(), carry);
        return v;
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
