// Source : https://leetcode.com/problems/palindrome-number/
// Author : Elvis Kwok
// Date   : 2015-10-14

/********************************************************************************** 
 * 
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the restriction of 
 * using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the problem 
 * "Reverse Integer", you know that the reversed integer might overflow. How would you 
 * handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 *               
 *               
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
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int n = 1, tmp = x,base;      // x has n bits
        int high, low;
        while (tmp/10 >0) {
            tmp /= 10;
            n++;
        }

        while (n > 1) {
            base = (int)pow(10, n-1);
            high = x / base;
            low = x % 10;
            if (high != low)
                return false;
            x = (x % base) / 10;
            n -= 2;
        }    
        
        return true;
    }

    bool isPalindrome2(int x) {     // good
        if (x<0) return false;
        
        int divisor=1;
        for (divisor=1; (x/divisor) >= 10; divisor*=10 );
        
        while (x != 0 ) {
            int left = x / divisor;
            int right = x % 10;
            if(left!=right) return false;
            x = (x%divisor) / 10;
            divisor /= 100;
        }
        return true;
    }
 
    bool isPalindrome3(int x) {
        return (x >= 0 && x==reverse(x));
    }
private:
    int reverse(int x) {
        int y=0, bit;
        while (x != 0) {
            bit = x % 10;
            y = y*10 + bit;
            x /= 10;
        }
        return y;
    }
};

int main(int argc, char **argv)
{
    Solution s;
//    cout << s.isPalindrome(1234) << endl;
    if (argc < 2)
        return 0;
    cout << s.isPalindrome(atoi(argv[1])) << endl;
    cout << s.isPalindrome2(atoi(argv[1])) << endl;

    return 0;
}
