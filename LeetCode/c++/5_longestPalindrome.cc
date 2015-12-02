// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Elvis Kwok
// Date   : 2015-12-02

/********************************************************************************** 
 * 
 * Given a string S, find the longest palindromic substring in S. You may assume that 
 * the maximum length of S is 1000, and there exists one unique longest palindromic 
 * substring.
 *               
 *               
 **********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // haoel sollution:
    // search both sides from center 
    string findPalindrome(string s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right <= n-1 && s[left] == s[right]) {
            --left;
            ++right;
        }
        return s.substr(left+1, right-left-1);
    }

    string longestPalindrome_recursive(string s) {
        int n = s.size();
        if (n <= 1) return s;

        string tmpStr, longestStr;
        for (int i = 0; i < n-1; ++i) {
            tmpStr = findPalindrome(s, i, i);
            if (tmpStr.size() > longestStr.size())
                longestStr = tmpStr;
            tmpStr = findPalindrome(s, i, i+1);
            if (tmpStr.size() > longestStr.size())
                longestStr = tmpStr;
        }
        return longestStr;
    }
    
    // haoel solution: Dynamic Programming
    // time: O(N^2), space: O(N^2)
    // Time Limit Exceeded in LeetCode
    string longestPalindrome_dp(string s) {
        int n = s.size();
        if (n <= 1) return s;

        string longestStr;
        // construct a matrix: matrix[i][j] indicates s[i] -> s[j] is palindrome or not.
        vector< vector<bool> > matrix(n, vector<bool>(n));
        
        // Dynamic Programming
        //   1) if i == j, then matrix[i][j] = true;
        //   2) if i != j, then matrix[i][j] = (s[i]==s[j] && matrix[i+1][j-1])
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                // The following "if" statement can be broken into:
                //   1) i == j, then matrix[i][j] = true
                //   2) the length from i to j is 2 or 3, then chenck s[i] == s[j]
                //   3) the length from i to j > 3, then check s[i][j] && matrix[i+1][j-1]
                if (i==j || (s[i]==s[j] && (j-i<2 || matrix[i+1][j-1]))) {
                    matrix[i][j] = true;
                    if (longestStr.size() < j-i+1) {
                        longestStr = s.substr(i, j-i+1);
                    }
                }
            }
        }

        return longestStr;
    }


    // LeetCode article solution: Dynamic Programming, explicitly.
    // time: O(N^2), space: O(N^2)
    // Time Limit Exceeded in LeetCode
    string longestPalindrome_dp_1(string s) {
        int n = s.length();
        int longestBegin = 0;
        int maxLen = 1;

        // construct a initial table
        vector< vector<bool> > table(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            table[i][i] = true;
        }
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                longestBegin = i;
                maxLen = 2;
            }
        }

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n-len+1; ++i) {
                int j = i+len-1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    longestBegin = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(longestBegin, maxLen);
    }


    // haoel solution: optimized DP, accepted by LeetCode
    string longestPalindrome_dp_opt(string s) { 
        int n = s.size();
        if (n <= 1) return s;

        bool **matrix = new bool* [n];
        int start=0, len=0;

        for (int i=0; i<n; ++i) {
            matrix[i] = new bool[i+1];
            memset(matrix[i], false, (i+1)*sizeof(bool));
            matrix[i][i] = true;
            // from j to i
            for (int j=0; j<i; j++) {
                if (i==j || (s[j]==s[i] && (i-j<2 || matrix[i-1][j+1]))) {
                    matrix[i][j] = true;
                    if (len < i-j+1) {
                        start = j;
                        len = i-j+1;
                    }
                }
            }
        }

        for (int i=0; i<n; i++) {
            delete [] matrix[i];    // release the memory pointed by pointer matrix[i]
        }
        delete [] matrix;       // release the memory pointed by pointer matrix

        return s.substr(start, len);
    }

    // Brute force solution, O(N^3): total of C(N, 2) substrings, each substring takes O(N) time to verify.
    // Time Limit Exceeded
    string longestPalindrome(string s) {
        int max = 0;
        string subStr;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i+1; j < s.size(); ++j) {
                if (isPalindrome(s.substr(i, j-i))) {
                    if (j-i > max) {
                        max = (j-i);
                        subStr = s.substr(i, j-i);
                    }
                }
            }
        }
        return subStr;    
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string longStr(10000, 'a');
    cout << s.longestPalindrome("abbacte") << endl;
    cout << s.longestPalindrome_recursive("abbacte") << endl;
//    cout << s.longestPalindrome(longStr) << endl;
//    cout << s.longestPalindrome_recursive(longStr) << endl;
    return 0;
}
