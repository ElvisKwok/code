// Source : https://leetcode.com/problems/unique-paths-ii/
// Author : Elvis Kwok
// Date   : 2016-01-14

/********************************************************************************** 
 * 
 * Follow up for "Unique Paths":
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths would 
 * there be?
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * 
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * 
 * The total number of unique paths is 2.
 * 
 * Note: m and n will be at most 100.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // haoel solution: DP
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        vector<int> f(m*n, 0);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (obstacleGrid[i][j]==1) {
                    f[i*n+j] = 0;
                } else {
                    if (i<1 && j<1)         // &&
                        f[i*n+j]=1;
                    else {
                        int a = i>0 ? f[(i-1)*n+j] : 0; // because i-1 overflow when i==0
                        int b = j>0 ? f[i*n+j-1] : 0;
                        f[i*n+j] = a + b;
                    }
                }
            }
        }
        printMatrix(f, m, n);
        return f[m*n-1];
    }

    // soulmachine solution: dfs+memo
    int uniquePathsWithObstacles2(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        this->f = vector<vector<int> >(m+1, vector<int>(n+1, 0));
        return dfs(obstacleGrid, m, n);
    }
    void print() {
        printMatrix(f);
    }
    
    // soulmachine solution2: dp + 滚动数组(sliding window)
    // 使用滚动数组把空间由m*n节省为n
    // 特别注意第一列的obstacle 
    // 上一问题第一列全1，这里有所改动：如果第一列某一行出现obstacle，则后面的行全为0
    // 如f[i][0] = 0 + f[i-1][0], 使得i行及后续的行的第一列与f[i-1][0]一致
    int uniquePathsWithObstacles3(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        vector<int> f(n, 0);
        f[0] = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {   // difference: start from j=0
                // 左边的f[j]相当于f[i][j];
                // 中间的f[j-1]相当于f[i][j-1];
                // 右边的f[j]相当于f[i-1][j]; 在i-1轮迭代中，原f[j]保存着f[i-1][j]且未受改动
                f[j] = obstacleGrid[i][j] ? 0 : (j==0 ? 0 : f[j-1]) + f[j];
            }
        }
        return f[n-1];
    }

private:
    vector<vector<int> > f;         // memo
    int dfs(vector<vector<int> > &obstacleGrid, int m, int n) {
        if (m<1 || n<1) return 0;   // terminate condition
        if (obstacleGrid[m-1][n-1]) return 0;
        if (m==1 && n==1) return 1; // base case
        return getOrUpdate(obstacleGrid, m-1, n) + getOrUpdate(obstacleGrid, m, n-1);
    }
    int getOrUpdate(vector<vector<int> > &obstacleGrid, int m, int n) {
        if (f[m][n] > 0) return f[m][n]; // checking recorded memo instead of computing it many times
        else return f[m][n] = dfs(obstacleGrid, m, n);
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
    void printMatrix(vector<vector<int> >& vv) {
        for (int i = 0; i < vv.size(); ++i) {
            cout << "[ ";
            for (int j = 0; j < vv[i].size(); ++j) {
                cout << vv[i][j] << " ";
            }
            cout << "]" << endl;
        }
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<vector<int> > vv{{0,0,0}, {0,1,0}, {0,0,0}};
    if (atoi(argv[1]) == 1)
        cout << s.uniquePathsWithObstacles(vv) << endl;
    else {
        cout << s.uniquePathsWithObstacles2(vv) << endl;
        s.print();
    }


    if (argc < 2)
        return 0;

    return 0;
}
