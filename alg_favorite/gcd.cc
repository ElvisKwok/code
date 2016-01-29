#include <iostream>
using namespace std;

/********************************************************
 *
 * 辗转相除法: f(x, y) = f(y, x%y)
 * x = k*y + b
 * 若x，y能被t整除，则y，b也能被t整除；
 * 相反，若y，b能被t整除，则x，y也能被t整除
 *
 *******************************************************/
int gcd(int x, int y) {
    return (!y) ? x : gcd(y, x%y);
}

int gcd1(int x, int y) {
    int tmp;
    while (y!=0) {
        tmp = x%y;
        x = y;
        y = tmp;
    }
    return x;
}

/********************************************************
 * 
 * 考虑到大整数使用%运算开销大（用到除法），另一种解法
 * f(x, y) = f(x-y, y)
 * 瓶颈: f(BigInt, 1) 迭代次数多
 *
 *******************************************************/
int gcd2(int x, int y) {
    if (x < y)
        return gcd2(y, x);
    if (y == 0)
        return x;
    else 
        return gcd2(x-y, y);
}

/********************************************************
 * 
 * 结合解法一、二
 * 左移避免除法（一），减少减法迭代次数（二）log2
 * 1) 如果y=k*y', x=k*x', 则f(x, y) = k*f(x', y')
 * 2) 如果x=p*x', y!=p*y'，则f(x, y) = f(x', y)
 * 这里p是素数，取p=2
 * 1) x, y is even, 则f(x, y) = 2*f(x>>1, y>>1)
 * 2) x is even, y is odd, 则f(x, y) = f(x>>1, y)
 *    x is odd, y is even, 则f(x, y) = f(x, y>>1)
 * 3) x, y is odd, 则f(x, y) = f(x-y, y),
 *    after that, x-y is even, then jump to 1) or 2)
 * 
 * O(log(max(x,y))
 *
 *******************************************************/
int gcd3(int x, int y) {
    if (x < y)
        return gcd3(y, x);
    if (y == 0)
        return x;
    else {
        if ((x & 1) == 0) {         // x&1==0 is wrong, which means x&(1==0)
            if ((y & 1) == 0) {
                return 2 * gcd3(x>>1, y>>1);
            }
            else {
                return gcd3(x>>1, y);
            }
        }
        else {
            if ((y & 1) == 0) {
                return gcd3(x, y>>1);
            }
            else {
                return gcd3(x-y, y);
            }
        }
    }
}

int main(int argc, char **argv) {
    cout << gcd(atoi(argv[1]), atoi(argv[2])) << endl;
    cout << gcd2(atoi(argv[1]), atoi(argv[2])) << endl;
    cout << gcd3(atoi(argv[1]), atoi(argv[2])) << endl;
    return 0;
}
