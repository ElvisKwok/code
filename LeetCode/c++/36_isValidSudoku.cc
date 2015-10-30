// Source : https://leetcode.com/problems/valid-sudoku/
// Author : Elvis Kwok
// Date   : 2015-10-15

/********************************************************************************** 
 * 
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled with the 
 * character '.'.
 * 
 * A partially filled sudoku which is valid.
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled 
 * cells need to be validated.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution
class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {
        bool used[9];
        
        for (int i = 0; i < 9; ++i) {
            fill(used, used + 9, false); 
            for (int j = 0; j < 9; ++j)         // check row
                if (!check(board[i][j], used))
                    return false;

            fill(used, used + 9, false); 
            for (int j = 0; j < 9; ++j)
                if (!check(board[j][i], used))  // check column
                    return false;
        }
        
        // check area
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c) {
                fill(used, used + 9, false);
                for (int i = r*3; i < r*3+3; ++i) 
                    for (int j = c*3; j < c*3+3; ++j)
                        if (!check(board[i][j], used))
                            return false;
            }
        return true;
    }

    bool check(char c, bool used[9]) {
        if (c == '.') return true;
        if (used[c-'1']) return false; // sudoku num range from 1 to 9;
        return used[c-'1'] = true;
    }

    // haoel solution:
    bool isValidSudoku(vector< vector<char> >& board) {
        const int cnt = 9;
        bool row_mask[cnt][cnt] = {false};
        bool col_mask[cnt][cnt] = {false};
        bool area_mask[cnt][cnt] = {false};
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                if (!isdigit(board[r][c])) continue;
                int idx = board[r][c] - '0' - 1;
                // check rows
                if (row_mask[r][idx] == true)  return false;
                row_mask[r][idx] = true;

                // check cols   // note: poor locality
                if (col_mask[c][idx] == true)  return false;
                col_mask[c][idx] = true;

                // check areas
                int area= (r/3) * 3 + (c/3);    
                if (area_mask[area][idx] == true)  return false;
                area_mask[area][idx] = true;
           }
        }
        return true;
    }
};

 
int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;

    return 0;
}
