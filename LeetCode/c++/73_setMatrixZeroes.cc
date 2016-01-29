// Source : https://leetcode.com/problems/set-matrix-zeroes/
// Author : Elvis Kwok
// Date   : 2016-01-19

/********************************************************************************** 
 * 
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it 
 * in place.
 * 
 * click to show follow up.
 * 
 * Follow up:
 * 
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // O(M*N), O(M*N)
    void setZeroes(vector<vector<int> >& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > vv(matrix);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (vv[i][j]==0) {
                    setRow(matrix, i);
                    setColumn(matrix, j);
                }
            }
        }
    }
    void setRow(vector<vector<int> >& matrix, int row) {
        int n = matrix[0].size();
        for (int j=0; j<n; ++j)
            matrix[row][j] = 0;
    }
    void setColumn(vector<vector<int> >& matrix, int column) {
        int m = matrix.size();
        for (int i=0; i<m; ++i)
            matrix[i][column] = 0;
    }

    // soulmachine & haoel solution:
    // O(M*N), O(M+N)
    void setZeroes2(vector<vector<int> >& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m, false);     // row[i]==true iff exist 0 in row[i]
        vector<bool> column(n, false);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==0) 
                    row[i]=column[j]=true;
            }
        }
        //for (int i=0; i<m; ++i) {
        //    if (row[i])
        //        fill(&matrix[i][0], &matrix[i][0]+n, 0);
        //}
        //for (int j=0; j<n; ++j) {
        //    if (column[j])
        //        for (int i=0; i<m; ++i)
        //            matrix[i][j]=0;
        //}
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (row[i] || column[j]) 
                    matrix[i][j]=0;
            }
        }
    }

    // soulmachine & haoel solution2: using 1st row and col to indicate final row and col to zero
    // O(M*N), O(1)
    void setZeroes3(vector<vector<int> >& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        bool zeroInFirstRow=false, zeroInFirstCol=false; // flag whether to finally zero the 1st row and col
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==0) {
                    if (i==0) zeroInFirstRow = true;
                    if (j==0) zeroInFirstCol = true;
                    matrix[0][j] = matrix[i][0] = 0;    // using 1st row and col as indicators
                }
            }
        }
        for (int i=1; i<m; ++i) {       // start from i=1, j=1;
            for (int j=1; j<n; ++j) {
                if (matrix[0][j]==0 || matrix[i][0]==0) // reference to indicators
                    matrix[i][j] = 0;
            }
        }
        if (zeroInFirstRow) {
            for (int j=0; j<n; ++j)
                matrix[0][j] = 0;
        }
        if (zeroInFirstCol) {
            for (int i=0; i<m; ++i)
                matrix[i][0] = 0;
        }
    }

};

void printMatrix(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main(int argc, char **argv)
{
    Solution s;
    vector<vector<int> > matrix{{1,2,3},{0,5,6},{7,0,9}};
    cout << "before: " << endl;
    printMatrix(matrix);
    cout << "after: " << endl;
    s.setZeroes2(matrix);
    printMatrix(matrix);

    if (argc < 2)
        return 0;

    return 0;
}
