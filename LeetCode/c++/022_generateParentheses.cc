// Source : https://leetcode.com/problems/generate-parentheses/
// Author : Elvis Kwok
// Date   : 2015-12-19

/********************************************************************************** 
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of 
 * well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 * 
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    // soulmachine solution 1: recursive
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n > 0)  generate(n, "", 0, 0, result);
        return result;
    }
    // l: left '(' occured times, r: right ')' occured times.
    void generate(int n, string s, int l, int r, vector<string>& result) {
        if (l == n) {
            result.push_back(s.append(n-r, ')'));
            return;
        }
        generate(n, s+"(", l+1, r, result);     // if (l<n)
        if (l > r) generate(n, s+")", l, r+1, result); // trace back to the status of recursive return, if (l<n && l>r)
    }

    // soulmachine & haoel solution: recursive
    vector<string> generateParenthesis2(int n) {
        vector<string> result;
        if (n > 0)  generate2(n, "", 0, 0, result);
        return result;
    }
    // l: left '(' occured times, r: right ')' occured times.
    void generate2(int n, string s, int l, int r, vector<string>& result) {
        if (l == n && r == n) {
            result.push_back(s);
            return;
        }
        if (l < n) 
            generate2(n, s+"(", l+1, r, result);
        if (l > r && r < n) 
            generate2(n, s+")", l, r+1, result); // trace back to the status of recursive return
    }

    // soulmachine solution 3: recursive, still confused
    vector<string> generateParenthesis3(int n) {
        if (n == 0) return vector<string>(1, "");
        if (n == 1) return vector<string>(1, "()");
        vector<string> result;

        for (int i=0; i<n; ++i)
            for (auto inner: generateParenthesis3(i))
                for (auto outer: generateParenthesis3(n-1-i))
                    result.push_back("(" + inner + ")" + outer);

        return result;
    }
};

void printVector(vector<string> svec) {
    for (int i=0; i<svec.size()-1; ++i)
        cout << svec[i] << ", ";
    cout << svec[svec.size()-1] << endl;
}

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;
    printVector(s.generateParenthesis(atoi(argv[1])));
    printVector(s.generateParenthesis2(atoi(argv[1])));
    printVector(s.generateParenthesis3(atoi(argv[1])));

    return 0;
}
