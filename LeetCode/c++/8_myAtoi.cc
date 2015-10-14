// Source : https://leetcode.com/problems/string-to-integer-atoi/
// Author : Elvis Kwok
// Date   : 2015-10-14

/********************************************************************************** 
 * 
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, please 
 * do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: 
 * It is intended for this problem to be specified vaguely (ie, no given input specs). 
 * You are responsible to gather all the input requirements up front. 
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function 
 * signature accepts a const char * argument, please click the reload button  to reset 
 * your code definition.
 * 
 * spoilers alert... click to show requirements for atoi.
 * 
 * Requirements for atoi:
 * 
 * The function first discards as many whitespace characters as necessary until the 
 * first non-whitespace character is found. Then, starting from this character, takes 
 * an optional initial plus or minus sign followed by as many numerical digits as 
 * possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral 
 * number, which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral 
 * number, or if no such sequence exists because either str is empty or it contains 
 * only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the correct 
 * value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN 
 * (-2147483648) is returned.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

/* my wrong answer occured:
 * "+", "-+1", "         010", "  -0012a42"(-12), 
 * INPUT:       " -1010023630o4"
 * OUTPUT:      -2147483648  
 * EXPECTED:    -1010023630
 */

#include <iostream>
#include <vector>
#include <climits>      // INT_MAX
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i=0, len=str.size(), base=0;
        int sign=1;
        while (i < len && str[i]==' ')
            ++i;
        if (str[i] == '-') {
            i++;
            sign = -1;
        } else if (str[i] == '+')
            i++;

        while (i < len) {
            if (str[i] < '0' || str[i] > '9')   // 非数字则跳出，base仍保存有效位("1t4"保存1)
                break;

            int digit = str[i] - '0';

            if ((base > INT_MAX/10) ||
                ((base == INT_MAX/10)&&(digit > INT_MAX%10)))   // digit(8~9)
                return sign==1 ? INT_MAX : INT_MIN;     // if input INT_MIN, digit=8

//            if (sign == 1){
//                if (base > (INT_MAX-digit)/10)  // overflow: digit(8~9) => 2147483647-(8~9)
//                    return INT_MAX;             
//            } else {
//                if (-base < (INT_MIN+digit)/10) // underflow: digit(9) => -2147483648+(9)
//                    return INT_MIN;             
//            }

            base = base * 10 + digit;
            ++i;
        }
        return sign * base;
    }
};


int main(int argc, char **argv)
{
    Solution s;
    if (argc < 2) return 0;
    cout << s.myAtoi(argv[1]) << endl;
    return 0;
}
