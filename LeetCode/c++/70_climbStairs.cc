// Source : https://leetcode.com/problems/climbing-stairs/
// Author : Elvis Kwok
// Date   : 2015-10-18

/********************************************************************************** 
 * 
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb 
 * to the top?
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    // in fact, it is a fibonacci array.
    // O(N)
    int climbStairs(int n) {
        if (n <= 3 ) return n;
        int prev = 2, cur= 3, tmp;
        for (int i = 4; i <= n; ++i) {
            tmp = prev;
            prev = cur;
            cur += tmp;
        }
        return cur;
    }
    // soulmachine solution: 
    int climbStairs1(int n) {
        const double s = sqrt(5);
        return floor( (pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5 );
    }
   
    // recursive is expensive because redudant computation, like f(n-2) running twice, f(n-3) three times.
    // NOT RECOMMENDED!!!
    int climbStairs2(int n) {
        if (n <= 3) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

int main(int argc, char **argv)
{
    Solution s;
    //cout << s.climbStairs(44) << endl;

    if (argc < 2)
        return 0;

    cout << s.climbStairs1(atoi(argv[1])) << endl;

    return 0;
}
