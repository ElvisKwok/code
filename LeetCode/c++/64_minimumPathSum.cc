// Source : https://leetcode.com/problems/minimum-path-sum/
// Author : Elvis Kwok
// Date   : 2016-01-15

/********************************************************************************** 
 * 
 * Given a m x n grid filled with non-negative numbers, find a path from top left to 
 * bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // run time error: may be space exceed for a single array len=m*n
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> f(m*n, 0);
        f[0] = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j>0)
                    f[i*n+j] = f[i*n+j-1] + grid[i][j];
                else if (i>0 && j==0)
                    f[i*n+j] = f[(i-1)*n+j] + grid[i][j];
                else    // i>0 && j>0
                    f[i*n+j] = min(f[(i-1)*n+j], f[i*n+j-1]) + grid[i][j];
            }
        }
        return f[m*n-1];
    }

    // pass
    int minPathSum1(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > f(m, vector<int>(n, 0));
        f[0][0] = grid[0][0];
        for (int i=1; i<m; ++i)
            f[i][0] = f[i-1][0] + grid[i][0];
        for (int j=1; j<n; ++j)
            f[0][j] = f[0][j-1] + grid[0][j];
        for (int i=1; i<m; ++i) 
            for (int j=1; j<n; ++j) 
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
        return f[m-1][n-1];
    }

    // pass!!
    int minPathSum2(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> f(n, 0);
        f[0] = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j>0)
                    f[j] = f[j-1] + grid[i][j];
                else if (i>0 && j==0)
                    f[j] = f[j] + grid[i][j];   // f[j] in the right is the last f[i-1][j]
                else    // i>0 && j>0
                    f[j] = min(f[j], f[j-1]) + grid[i][j];
            }
        }
        return f[n-1];
    }
    
    // haoel solution: O(1) space!!!
    int minPathSum3(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int top = i-1<0 ? INT_MAX : grid[i-1][j];
                int left = j-1<0 ? INT_MAX : grid[i][j-1];
                if (top==INT_MAX && left==INT_MAX)
                    continue;
                grid[i][j] += min(top, left);
            }
        }
        return grid[m-1][n-1];
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
