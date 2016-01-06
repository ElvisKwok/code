// Source : https://leetcode.com/problems/rotate-image/
// Author : Elvis Kwok
// Date   : 2016-01-06

/********************************************************************************** 
 * 
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 *               
 **********************************************************************************/


/********************************************************************************** 
 *
 * |1 2 3|  transpose(i<->j)  |1 4 7|   reverse column  |7 4 1|
 * |4 5 6|      ==>           |2 5 8|        ==>        |8 5 2|
 * |7 8 9|                    |3 6 9|                   |9 6 3|
 *
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();

        // transpose
        for (int i=0; i<n; ++i) 
            for (int j=0; j<i; ++j) 
                swap(matrix[i][j], matrix[j][i]);

        // reverse column
        for (int i=0; i<n; ++i)
            for (int j=0; j<n/2; ++j)
                swap(matrix[i][j], matrix[i][n-j-1]);
    }
    // haoel solution: rotate each circle from outter to inner
    void rotate2(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for (int i=0; i<n/2; i++) {
            int low=i, high=n-i-1;
            for (int j=low, j<high; j++) {
                int tmp = matrix[i][j];
                // left to top
                matrix[i][j] = matrix[n-j-1][i];
                // bottom to left
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                // right to bottom
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1]
                // top to right
                matrix[j][n-i-1] = tmp;
            }
        }
};

void printMatrix(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << "\t";
        }
        cout << "]" << endl;
    }
}

int main(int argc, char **argv)
{
    Solution s;
    int n = atoi(argv[1]);
    vector<vector<int> > vv;
    for (int i=0; i<n; ++i) {
        vector<int> v;
        for (int j=1; j<=n; ++j)
            v.push_back(i*n+j);
        vv.push_back(v);
    }
    printMatrix(vv);
    cout << endl;
    s.rotate(vv);
    printMatrix(vv);
    cout << endl;
    
    if (argc < 2)
        return 0;

    return 0;
}
