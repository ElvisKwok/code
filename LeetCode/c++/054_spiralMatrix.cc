// Source : https://leetcode.com/problems/spiral-matrix/
// Author : Elvis Kwok
// Date   : 2016-01-12

/********************************************************************************** 
 * 
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the 
 * matrix in spiral order.
 * 
 * For example,
 * Given the following matrix:
 * 
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution: O(N^2)
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int beginX = 0, endX = matrix[0].size()-1;
        int beginY = 0, endY = matrix.size()-1;

        while (true) {
            // left -> right: [1, 2, 3], [5]
            for (int j = beginX; j <= endX; ++j)     result.push_back(matrix[beginY][j]);
            if (++beginY > endY)    break;
            // top -> bottom:  [6, 9]
            for (int i = beginY; i <= endY; ++i)     result.push_back(matrix[i][endX]);
            if (beginX > --endX)    break;
            // right -> left: [8, 7]
            for (int j = endX; j >= beginX; --j)     result.push_back(matrix[endY][j]);
            if (beginY > --endY)    break;
            // bottom -> top: [4]
            for (int i = endY; i >= beginY; --i)     result.push_back(matrix[i][beginX]);
            if (++beginX > endX)    break;
        }

        return result;
    }

    // haoel solution:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector <int> v;
        int row = matrix.size();
        if (row<=0) return v;
        int col = matrix[0].size();
        if (col<=0) return v;
        int r, c;
        for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
            //top [1, 2, 3], [5]
            for(int i=c; i<col-c; i++){
                v.push_back(matrix[r][i]);
            }
            //right [6, 9]
            for(int i=r+1; i<row-r; i++){
                v.push_back(matrix[i][col-c-1]);
            }
            //bottom [8, 7]
            for(int i=col-c-2; row-r-1>r && i>=c; i--){
                v.push_back(matrix[row-r-1][i]);
            }
            //left [4]
            for(int i=row-r-2; col-c-1>c && i>r; i--){
                v.push_back(matrix[i][c]);
            }
        }
        return v;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
