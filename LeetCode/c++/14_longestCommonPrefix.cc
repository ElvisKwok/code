// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : Elvis Kwok
// Date   : 2015-10-14

/********************************************************************************** 
 * 
 * Write a function to find the longest common prefix string amongst an array of 
 * strings.
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0;
        int vec_size = strs.size();
        int cnt = 1;
        string s;
        if (vec_size == 1) return strs[0];
        while (1) {
            for (int i = 0; i < vec_size-1; i++) {
                if (strs[i].empty())
                    return s;
                if ((j < strs[i].size()) && (strs[i][j] == strs[i+1][j])) // 注意j越界
                    cnt++;
                else
                    break;
            }
            if (cnt == vec_size) {
                s += strs[0][j++];
                cnt = 1;    
            }
            else
                break;
        }
        return s; 
    }
};

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;

    return 0;
}
