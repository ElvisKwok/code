// Source : https://leetcode.com/problems/divide-two-integers/
// Author : Elvis Kwok
// Date   : 2015-12-21

/********************************************************************************** 
 * 
 * Divide two integers without using multiplication, division and mod operator.
 * 
 * If it is overflow, return MAX_INT.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)

class Solution {
public:
    // Note: operations without *, / and %, only remain +, - and bit operations.

    // time limit exceed:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (abs(divisor)==1) {
            if (dividend == INT_MIN)
                return divisor==1 ? INT_MIN : INT_MAX;
            else return divisor==1 ? dividend : -dividend;
        }
        if (divisor == INT_MIN) return (dividend == INT_MIN ? 1 : 0);
        if (dividend == INT_MIN) dividend++;
        int cnt = 0, sign = 1;
        if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
            sign = -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor) {
            dividend -= divisor;
            ++cnt;
        }
        return sign==1 ? cnt : -cnt;
    }

    // soulmachine solution1: 
    // O(logN)
    int divide1(int dividend, int divisor) {
        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;
        long long result = 0;
        while (a >= b) {
            long long bb = b;
            for (int i = 0; a >= bb; ++i, bb <<= 1) {
                a -= bb;
                result += (1 << i);
            }
        }
        
        const bool sign_neg = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
        if (result > INT_MAX && !sign_neg)  return INT_MAX;  // overflow: dividend=INT_MIN, divisor=-1;
        return sign_neg ? -result : result;
        //return ((dividend^divisor) >> 31) ? -result : result;
    }

    // soulmachine solution2: Loop dividend-divisor, optimation: double divisor to speed up.
    // O(logN)
    int divide2(int dividend, int divisor) {
        int result = 0;
        // const bool sign_neg = (dividend^divisor) >> 31; 
        const bool sign_neg = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
        // while dividend = INT_MIN, -dividend is overflow, so use unsigned int
        unsigned int a = dividend >= 0 ? dividend : -dividend;
        unsigned int b = divisor >= 0 ? divisor : -divisor;
        
        while (a >= b) {
            int multi = 1;
            unsigned int bb = b;
            while (a >= bb) {
                a -= bb;
                result += multi;
                if (bb < (INT_MAX >> 1)) {  // overflow
                    bb += bb;   // bb <= 1
                    multi += multi;
                }
            }
        }
        if (result > INT_MAX && !sign_neg)  return INT_MAX;
        return sign_neg ? -result : result;
    }

    // haoel solution: bit operation
    // a/b can be illustrated as follow:
    // a = (a%b) + (a/b)*b
    // a = (a%b) + sum_of_one_subset{1, 2 , 4 , ... , (2^i)} * b
    // according to bit representation, every number can be represent as binary bits like 6=(110)
    // then a/b = sum_of_chosen_subset, like a/b = 2^0 + 2^3 + ...
    // e.g., 20/3 = 6, 20%3 = 2 
    // 20 = (2) + (2 + 4)*3, so 20/3 = 2+4 = 6
    // In this algorithm, only using ">>" and "-" to implement "/"
    int divide3(int dividend, int divisor) {
        int sign = (float)dividend / divisor > 0 ? 1 : -1;
        unsigned int a = dividend >= 0 ? dividend : -dividend;
        unsigned int b = divisor >= 0 ? divisor : -divisor;
        
        unsigned int bit_num[32];   // store: b, b*2, b*4, b*8, ... b*(2^i) 
        unsigned int i = 0;
        long long bb = b;
        bit_num[i] = bb;
        while (a >= bb) {
            bit_num[++i] = bb = bb << 1;
        }
        i--;

        unsigned int result = 0;
        while (a >= b) {
            if (a >= bit_num[i]) {  // chosen subset element.
                a -= bit_num[i];    // a -= (b*(2^i))
                result += (1<<i);   // result += (2^i)
            } else {                // ignore unchosen subset element.
                i--;
            }
        }

        if (result > INT_MAX && sign > 0)
            return INT_MAX;
        return sign == 1 ? (int)result : -(int)result;
    }

};

int main(int argc, char **argv)
{
    Solution s;

    cout << "0/2=" << s.divide3(0, 2) << endl;
    cout << "10/2=" << s.divide3(10, 2) << endl;
    cout << "10/3=" << s.divide3(10, 3) << endl;
    cout << "10/5=" << s.divide3(10, 5) << endl;
    cout << "10/7=" << s.divide3(10, 7) << endl;
    cout << "10/10=" << s.divide3(10, 10) << endl;
    cout << "10/11=" << s.divide3(10, 11) << endl;
    cout << "-1/1=" << s.divide3(1, -1) << endl;
    cout << "1/-1=" << s.divide3(1, -1) << endl;
    cout << "-1/-1=" << s.divide3(-1, -1) << endl;
    cout << "2147483647/1=" << s.divide3(2147483647, 1) << endl;
    cout << "-2147483647/1=" << s.divide3(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << s.divide3(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << s.divide3(-2147483647, -1) << endl;
    cout << "2147483647/2=" << s.divide3(2147483647, 2) << endl;
    cout << "2147483647/10=" << s.divide3(2147483647, 10) << endl;
    cout << "-2147483648/1=" << s.divide3(-2147483648, 1) << endl;
    cout << "-2147483648/-1=" << s.divide3(-2147483648, -1) << endl;

    cout << "0/2=" << s.divide1(0, 2) << endl;
    cout << "10/2=" << s.divide1(10, 2) << endl;
    cout << "10/3=" << s.divide1(10, 3) << endl;
    cout << "10/5=" << s.divide1(10, 5) << endl;
    cout << "10/7=" << s.divide1(10, 7) << endl;
    cout << "10/10=" << s.divide1(10, 10) << endl;
    cout << "10/11=" << s.divide1(10, 11) << endl;
    cout << "-1/1=" << s.divide1(1, -1) << endl;
    cout << "1/-1=" << s.divide1(1, -1) << endl;
    cout << "-1/-1=" << s.divide1(-1, -1) << endl;
    cout << "2147483647/1=" << s.divide1(2147483647, 1) << endl;
    cout << "-2147483647/1=" << s.divide1(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << s.divide1(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << s.divide1(-2147483647, -1) << endl;
    cout << "2147483647/2=" << s.divide1(2147483647, 2) << endl;
    cout << "2147483647/10=" << s.divide1(2147483647, 10) << endl;
    cout << "-2147483648/1=" << s.divide1(-2147483648, 1) << endl;
    cout << "-2147483648/-1=" << s.divide1(-2147483648, -1) << endl;

    cout << "0/2=" << s.divide2(0, 2) << endl;
    cout << "10/2=" << s.divide2(10, 2) << endl;
    cout << "10/3=" << s.divide2(10, 3) << endl;
    cout << "10/5=" << s.divide2(10, 5) << endl;
    cout << "10/7=" << s.divide2(10, 7) << endl;
    cout << "10/10=" << s.divide2(10, 10) << endl;
    cout << "10/11=" << s.divide2(10, 11) << endl;
    cout << "-1/1=" << s.divide2(1, -1) << endl;
    cout << "1/-1=" << s.divide2(1, -1) << endl;
    cout << "-1/-1=" << s.divide2(-1, -1) << endl;
    cout << "2147483647/1=" << s.divide2(2147483647, 1) << endl;
    cout << "-2147483647/1=" << s.divide2(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << s.divide2(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << s.divide2(-2147483647, -1) << endl;
    cout << "2147483647/2=" << s.divide2(2147483647, 2) << endl;
    cout << "2147483647/10=" << s.divide2(2147483647, 10) << endl;
    cout << "-2147483648/1=" << s.divide2(-2147483648, 1) << endl;
    cout << "-2147483648/-1=" << s.divide2(-2147483648, -1) << endl;
    if (argc < 2)
        return 0;

    return 0;
}
