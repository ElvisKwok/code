// Source : https://leetcode.com/problems/integer-to-roman/
// Author : Elvis Kwok
// Date   : 2015-12-02

/********************************************************************************** 
 * 
 * Given an integer, convert it to a roman numeral.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 *               
 **********************************************************************************/

/********************************************************************************** 
 * I = 1
 * V = 5
 * X = 10
 * L = 50
 * C = 100
 * D = 500
 * M = 1000
 * 
 * If a lower value symbol is before a higher value one, it is subtracted. 
 * Otherwise it is added.
 * Lower value symbol in the front only occurs once.(XXL is undefined)
 * So 'IV' is '4' and 'VI' is '6'.
 **********************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    inline int romanMap(const char c) {
        int d = 0;
        switch (c) {
            case 'I': d = 1;    break;
            case 'V': d = 5;    break;
            case 'X': d = 10;   break; 
            case 'L': d = 50;   break;
            case 'C': d = 100;  break;
            case 'D': d = 500;  break;
            case 'M': d = 1000; break;
            default :           break;
        }
        return d;
    }
 
    string intToRoman(int num) {
        string result;
        

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
