// Source : https://leetcode.com/problems/reverse-integer/
// Author : Elvis Kwok
// Date   : 2015-10-13

/********************************************************************************** 
 * 
 * Reverse digits of an integer.
 * 
 * Example1: x =  123, return  321
 * Example2: x = -123, return -321
 * 
 * click to show spoilers.
 * 
 * Have you thought about this?
 * 
 * Here are some good questions to ask before coding. Bonus points for you if you have 
 * already thought through this!
 * 
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 
 * 100.
 * 
 * Did you notice that the reversed integer might overflow? Assume the input is a 
 * 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such 
 * cases?
 * 
 * For the purpose of this problem, assume that your function returns 0 when the 
 * reversed integer overflows.
 * 
 * Update (2014-11-10):
 * Test cases had been added to test the overflow behavior.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

/* my wrong answer occured:
 * input:       1534236469
 * output:      1056389759
 * expected:    0
 */


#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        //int MAX_INT = (-1u)>>1, MIN_INT = (-MAX_INT-1);
        int MAX_INT = numeric_limits<int>::max(), MIN_INT = numeric_limits<int>::min();
        int base = 0;
        int bit;
        while (x != 0) {            // 这里x!=0兼容了正负情形
            bit = x % 10;
            x /= 10;
            if (base > MAX_INT/10 || base < MIN_INT/10)
                return 0;
            base = base*10 + bit;
        }
        return base;
    }
};


int main(int argc, char **argv)
{
    Solution s;
    cout << "max_int: " << ((-1u)>>1) << endl;
    cout << s.reverse(atoi(argv[1])) << endl; 
    return 0;
}
