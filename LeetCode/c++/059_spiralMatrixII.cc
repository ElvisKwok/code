// Source : https://leetcode.com/problems/spiral-matrix-ii/
// Author : Elvis Kwok
// Date   : 2016-01-12

/********************************************************************************** 
 * 
 * Given an integer n, generate a square matrix filled with elements from 1 to n^2 in 
 * spiral order.
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * 
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        if (n == 0) return result;
        int beginX = 0, endX = n-1;
        int beginY = 0, endY = n-1;
        int num = 1;
        while (true) {
            for (int j = beginX; j <= endX; ++j)    result[beginY][j] = num++;
            if (++beginY > endY)    break;
            for (int i = beginY; i <= endY; ++i)    result[i][endX] = num++;
            if (beginX > --endX)    break;
            for (int j = endX; j >= beginX; --j)    result[endY][j] = num++;
            if (beginY > --endY)    break;
            for (int i = endY; i >= beginY; --i)    result[i][beginX] = num++;
            if (++beginX > endX)    break;
        }
        return result;
    }

    // soulmachine solution 2
    vector<vector<int> > generateMatrix2(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        if (n == 0) return result;
        int begin = 0, end = n-1;
        int num = 1;
        while (begin < end) {
            for (int j = begin; j < end; ++j)  result[begin][j] = num++;
            for (int i = begin; i < end; ++i)  result[i][end] = num++;
            for (int j = end; j > begin; --j)  result[end][j] = num++;
            for (int i = end; i > begin; --i)  result[i][begin] = num++;
            // move forward to inner circle
            ++begin;
            --end;
        }
        if (begin == end)
            result[begin][begin] = num;
        return result;
    }

    // haoel solution: n row, m column
    vector<vector<int> > generateMatrix3(int n) {
        int m = n;
        vector< vector <int> > matrix(n);
        if (n<=0) return matrix;
        for(int i=0; i<n; i++){
            vector<int> v(m);
            matrix[i] = v;
        }
    
        int row=n, col=m;
        int r, c;
        int cnt=1;
        for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
            //top
            for(int i=c; i<col-c; i++){
                matrix[r][i] = cnt++;
            }
            //right
            for(int i=r+1; i<row-r; i++){
                matrix[i][col-c-1] = cnt++;
            }
            //bottom
            for(int i=col-c-2; row-r-1>r && i>=c; i--){
                matrix[row-r-1][i] = cnt++;
            }
            //left
            for(int i=row-r-2; col-c-1>c && i>r; i--){
                matrix[i][c] = cnt++;
            }
            
        }
        return matrix;
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
    vector<vector<int> > result = s.generateMatrix(atoi(argv[1]));
    printMatrix(result);
    cout << endl;
    vector<vector<int> > result2 = s.generateMatrix2(atoi(argv[1]));
    printMatrix(result2);
    cout << endl;
    vector<vector<int> > result3 = s.generateMatrix3(atoi(argv[1]));
    printMatrix(result3);

    if (argc < 2)
        return 0;

    return 0;
}
