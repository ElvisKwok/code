// Source : https://leetcode.com/problems/valid-parentheses/
// Author : Elvis Kwok
// Date   : 2015-10-14

/********************************************************************************** 
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but 
 * "(]" and "([)]" are not.
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
    bool isValid(string s) {
        vector<char> stack;
        int i = 0, j=-1;
        char test_char;
        while (i < s.size()) {  
            if (s[i]=='{' || s[i]=='[' || s[i]=='(') {
                stack.push_back(s[i]);
                ++j;
            }
            else if (s[i]=='}' || s[i]==']' || s[i]==')') {
                if (s[i] == '}') test_char = '{';
                else if (s[i] == ']') test_char = '[';
                else test_char = '(';

                if (!stack.empty()) {
                    if (stack[j] == test_char) {
                        stack.pop_back();
                        --j;
                    }
                    else
                        return false;
                }
                else return false;  // stack empty;
            } // else if
            else return false;      // undefined char
            ++i;
        } // while
        return stack.empty();       // return false if e.g: "(({"
    }
    // soulmachine version
    bool isValid(string s) {
        string left  = "([{";
        string rignt = ")]}";
        stack<char> stk;
        for (auto c : s) {
            if (left.find(c) != string::npos)
                stk.push(c);
            else {
                if (stk.empty() || stk.top()!=left[right.find(c)])
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;

    return 0;
}
