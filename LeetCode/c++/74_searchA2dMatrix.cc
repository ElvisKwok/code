// Source : https://leetcode.com/problems/search-a-2d-matrix/
// Author : Elvis Kwok
// Date   : 2016-01-20

/********************************************************************************** 
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. This 
 * matrix has the following properties:
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * 
 * Given target = 3, return true.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int begin=0, end=m-1, mid;
        while (begin <= end) {
            mid = begin + (end-begin)/2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                begin = mid+1;
            else
                end = mid-1;
        }
        if (end<0)  return false;

        int row = end;
        begin=0;
        end=n-1;
        while (begin <= end) {
            mid = begin + (end-begin)/2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                begin = mid+1;
            else
                end = mid-1;
        }

        return false;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<vector<int> > matrix{{1}};
    int target = 0;
    cout << s.searchMatrix(matrix, target) << endl;

    if (argc < 2)
        return 0;

    return 0;
}
