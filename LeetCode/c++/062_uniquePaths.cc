// Source : https://leetcode.com/problems/unique-paths/
// Author : Elvis Kwok
// Date   : 2016-01-13

/********************************************************************************** 
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the 
 * diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is 
 * trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram 
 * below).
 * 
 * How many possible unique paths are there?
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // NOTE: move limits to down and right

    // soulmachine solution: dfs, TLE when N is large
    // O(N^4) O(N)
    int uniquePaths(int m, int n) {
        if (m<1 || n<1) return 0;   // terminate condition
        if (m==1 && n==1) return 1; // base case
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
    // soulmachine solution2: dfs + memo
    // Slower than dynamic programming
    // O(M*N) O(M*N)
    int uniquePaths1(int m, int n) {
        this->f = vector<vector<int> >(m+1, vector<int>(n+1, 0));
        return dfs(m, n);
    }
    // soulmachine solution3: dp + 滚动数组(sliding window)
    // 使用滚动数组把空间由m*n节省为n
    // best!
    int uniquePaths2(int m, int n) {
        vector<int> f(n, 0);
        f[0] = 1;
        for (int i=0; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                // 左边的f[j]相当于f[i][j];
                // 中间的f[j-1]相当于f[i][j-1];
                // 右边的f[j]相当于f[i-1][j]; 在i-1轮迭代中，原f[j]保存着f[i-1][j]且未受改动
                f[j] = f[j-1] + f[j];
            }
        }
        return f[n-1];
    }
    // soulmachine solution4: math method
    // from (1,1) to (m,n) always takes m+n-2 steps (m-1 down and n-1 right)
    // thus, the problem can be tranformed to choosing m-1 numbers from m+n-2 numbers
    // the result is the combination number: C(m-1, m+n-2)
    typedef long long int64;
    // calculate n*(n-1)*...*start, set default value of start as 1
    int64 rangeFactor(int n, int start=1) {
        int64 result = 1;
        for (int i=start; i<=n; ++i) 
            result *= i;
        return result;
    }
    int64 combination(int n, int k) {
        if (k==0) return 1;
        if (k==1) return n;
        int64 result = rangeFactor(n, n-k+1) / rangeFactor(k);
        return result;
    } 
    int uniquePaths3(int m, int n) {
        // max to minimize the gap between n and k
        // so as to avoid overflow in combination()
        return combination(m+n-2, max(m-1, n-1)); 
    }


    // haoel solution: dynamic programming
    // O(M*N) O(M*N)
    int uniquePaths4(int m, int n) {
        vector<int> f(m*n);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 || j==0)
                    f[i*n+j] = 1;
                else
                    f[i*n+j] = f[i*n+j-1] + f[(i-1)*n+j];
            }
        }
        //printMatrix(f, m, n);
        return f[m*n-1];
    }
private:
    vector<vector<int> > f;         // memo
    int dfs(int m, int n) {
        if (m<1 || n<1) return 0;   // terminate condition
        if (m==1 && n==1) return 1; // base case
        return getOrUpdate(m-1, n) + getOrUpdate(m, n-1);
    }
    int getOrUpdate(int m, int n) {
        if (f[m][n] > 0) return f[m][n]; // checking recorded memo instead of computing it many times
        else return f[m][n] = dfs(m, n);
    }


    void printMatrix(vector<int> v, int m, int n) {
        for (int i = 0; i < m; ++i) {
            cout << "[ ";
            for (int j = 0; j < n; ++j) {
                cout << v[i*n+j] << " ";
            }
            cout << "]" << endl;
        }
    }
};

int main(int argc, char **argv)
{
    Solution s;
    //cout << s.uniquePaths(atoi(argv[1]), atoi(argv[2])) << endl;
    //cout << s.uniquePaths1(atoi(argv[1]), atoi(argv[2])) << endl;
    cout << s.uniquePaths3(atoi(argv[1]), atoi(argv[2])) << endl;
    cout << s.uniquePaths4(atoi(argv[1]), atoi(argv[2])) << endl;

    if (argc < 2)
        return 0;

    return 0;
}
