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
    // my version
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0;
        int vec_size = strs.size();
        int cnt = 1;
        string s;
        if (vec_size <= 0) return s;
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

    // soulmachine version 1: vertical comparison. Overhead: O(n1+n2...)
    string longestCommonPrefix2(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int idx = 0; idx < strs[0].size(); ++idx) {
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][idx] != strs[0][idx])
                    return strs[0].substr(0, idx);
            }
        }
        return strs[0];
    }

    // soulmachine version 2: horizontal comparison. Overhead: O(n1+n2...)
    string longestCommonPrefix3(vector<string>& strs) {
        if (strs.empty()) return "";
        int right_most = strs[0].size() - 1;
        for (size_t i = 1; i < strs.size(); ++i)
            for (int j = 0; j <= right_most; ++j)
                if (j<strs[i].size() || strs[i][j]!=strs[0][j])   // index j out of range?
                    right_most = j-1;
        return strs[0].substr(0, right_most+1);
    }

    // haoel version
    string longestCommonPrefix3(vector<string>& strs) {
        string word;
        if (strs.size() <= 0) return word;
        for (int i = 1; i <= strs[0].size(); ++i) {
            string w = strs[0].substr(0, i);    // substr range from 0 to i-1
            bool match = true;
            int j = 1;
            for (j = 1; j < strs.size(); ++j) {
                if (i>strs[j].size() || w!=strs[j].substr(0, i)) {
                    match = false;
                    break;
                }
            }
            if (!match)
                return word;
            word = w;   // already matched substr
        }
        return word;
    }
};

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;

    return 0;
}
