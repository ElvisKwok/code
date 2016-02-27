// Source : https://leetcode.com/problems/powx-n/
// Author : Elvis Kwok
// Date   : 2016-01-10

/********************************************************************************** 
 * 
 * Implement pow(x, n).
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // time limit exceed
    // O(N)
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (fabs(x-0.0) < 0.0000001) return 0.0;
        int sign = (n>0 ? 1 : -1);
        n = abs(n);
        int odd = n % 2;
        double result = x, last = 1.0;
        while ((n--)>1)
           result *= x;
        return sign==1 ? result : 1/result;
    }
    // soulmachine solution: divide-and-conquer
    // O(logN)
    double myPow2(double x, int n) {
        return (n>0 ? power(x, n) : 1/power(x, -n));
    }
    double power(double x, int n) {
        if (fabs(x-0.0) < 0.0000001) return 0.0;
        if (n == 0) return 1.0;     
        //double v = power(x, n/2);
        double v = power(x, n<<1);     // store the value to avoid unneccesary computation, faster than just return power()*power()
        //if (n%2)
        if (n & 0x1 == 1)
            return v * v * x;
        else
            return v * v;
    }

    // haoel solution:  use x = x*x to reduce the 'n' more quickly
    // in each iteration, if exp is even, do 'x *= x' and 'exp >>= 1'; else do extra 'result *= x'
    // O(logN)
    double myPow3(double x, int n) {
        if (fabs(x-0.0) < 0.0000001) return 0.0;
        unsigned int exp = abs(n);
        double result = 1.0;
        while (exp) {
            if (exp & 1)    // odd number, also the last iteration stop here
                result *= x;
            exp >>= 1;
            x *= x;
       }
       return n < 0 ? 1/result : result;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.myPow2(atof(argv[1]), atof(argv[2])) << endl;
    cout << s.myPow3(atof(argv[1]), atof(argv[2])) << endl;
    cout << "correct answer: " << pow(atof(argv[1]), atof(argv[2])) << endl;

    if (argc < 2)
        return 0;

    return 0;
}
