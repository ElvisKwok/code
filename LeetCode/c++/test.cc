// Source : https://leetcode.com/problems/roman-to-integer/
// Author : Elvis Kwok
// Date   : 2015-10-14

/********************************************************************************** 
 * 
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 *               
 *               
 * 
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
//    inline int romanMap(const char c) {
//        int d = 0;
//        switch (c) {
//            case 'I': d = 1;    break;
//            case 'V': d = 5;    break;
//            case 'X': d = 10;   break; 
//            case 'L': d = 50;   break;
//            case 'C': d = 100;  break;
//            case 'D': d = 500;  break;
//            case 'M': d = 1000; break;
//            default :           break;
//        }
//        return d;
//    }
    int romanToInt(string s) {
        unordered_map<char, int> romanMap;      // slower than switch
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;

        int len = s.size();
        int prev = 0, result = 0;

        for (int i = 0; i < len; ++i) {
            int curr = romanMap[s[i]];
            result += (curr > prev) ? (curr - 2 * prev) : curr;
            prev = curr;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;
    cout << s.romanToInt(argv[1]) << endl;

    return 0;
}
