// Source : https://leetcode.com/problems/sqrtx/
// Author : Elvis Kwok
// Date   : 2016-01-16

/********************************************************************************** 
 * 
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // TLE
    int mySqrt(int x) {
        if (x<=0) return 0;
        int i;
        for (i=1; i*i<=x; i*=2);
        i /= 2;
        for (; i*i<=x; ++i);    // TLE
        return --i;
    }

    // soulmachine & haoel solution: binary search
    int mySqrt1(int x) {
        if (x<=1) return x;

        int left=1, right=x/2+1, mid, last_mid;   // the sqrt <= x/2+1, (x/2+1)^2=(x^2)/4+x > x
        while (left <= right) {
            mid = left + (right-left)/2;    // (left+right)/2 may be overflow if left>INT_MAX/2
            if (x/mid > mid) {  // x > (mid*mid) may be overflow
                left = mid+1;
                last_mid = mid;
            } 
            else if (x/mid < mid)
                right = mid-1;
            else
                return mid;
        }
        return last_mid;
    }

    // haoel solution: Newton's method
    // find 'x' s.t. f(x) = x^2 - n = 0, f'(x) = 2*x
    // Newtwon's method: x[k+1] = x[k] - (f(x[k])/f'(x[k])) = (x[k]+n/x[k]) / 2
    int mySqrt2(int x) {
        if (x==0) return 0;
        double last=0, res=1;
        while (res != last) {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};

int main(int argc, char **argv)
{
    Solution s;
    //cout << s.mySqrt(atoi(argv[1])) << endl;
    cout << s.mySqrt1(atoi(argv[1])) << endl;

    if (argc < 2)
        return 0;

    return 0;
}
