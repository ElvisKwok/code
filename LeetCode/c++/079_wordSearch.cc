// Source : https://leetcode.com/problems/word-search/
// Author : Elvis Kwok
// Date   : 2016-02-23

/********************************************************************************** 
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell, where 
 * "adjacent" cells are those horizontally or vertically neighboring. The same letter 
 * cell may not be used more than once.
 * 
 * For example,
 * Given board = 
 * 
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * 
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution: dfs + backtracking
    // O(m*n*m*n)
    bool exist(vector<vector<char> >& board, string word) {
        const int row = board.size();
        const int col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for (int i=0; i<row; ++i) {
            for (int j=0; j<col; ++j) {
                if (dfs(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }
    bool dfs(const vector<vector<char> >& board, const string word, int index, int row, int col, vector<vector<bool> >& visited) {
        if (index == word.size())   
            return true;        // 收敛条件
        if (row<0 || col<0 || row>=board.size() || col>=board[0].size())    
            return false;       // 越界，终止条件
        if (visited[row][col])      
            return false;       // 已经访问过，剪枝
        if (board[row][col] != word[index])
            return false;       // 不相等，剪枝
        visited[row][col] = true;
        bool ret = dfs(board, word, index+1, row-1, col, visited) ||        // up
                   dfs(board, word, index+1, row+1, col, visited) ||        // down
                   dfs(board, word, index+1, row, col-1, visited) ||        // left
                   dfs(board, word, index+1, row, col+1, visited);          // right
        visited[row][col] = false;      // backtracking
        return ret;
   }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
