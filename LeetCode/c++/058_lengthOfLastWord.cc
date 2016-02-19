// Source : https://leetcode.com/problems/length-of-last-word/
// Author : Elvis Kwok
// Date   : 2015-10-16

/********************************************************************************** 
 * 
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' 
 * ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters 
 * only.
 * 
 * For example, 
 * Given s = "Hello World",
 * return 5.
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())  return 0;
        int size = s.size();
        int first, last = size-1;
        for ( ; last >= 0 && s[last] == ' '; --last);
        if (last < 0)   return 0;
        if (last<size-1) ++last;
        for (first = last; first >= 0 && s[first] != ' '; --first);
        ++first;
        return last-first+1;
    }
    // soulmachine sollution: sequence scan 
    int lengthOfLastWord1(string s) {
        int i = 0, len = 0;
        while (i < s.size()) {
            if (s[i++] != ' ')      // skip empty space, count alphabets.
                ++len;
            else if (i < s.size() && s[i] != ' ')   // next word appears. NOTE: i has been i++ before;
                len = 0;
            cout << "(i, len) = (" << i << " , " << len << ")" << endl;
        }
        return len;
    }
    // haoel sollution: sequence scan
    int lengthOfLastWord2(string s) {
        if (s.empty())  return 0;
        int i = 0, wordLen = 0, cnt = 0;
        for (; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                cnt++;
            }
            if (!isalpha(s[i])) {
                if (cnt > 0) {
                    wordLen = cnt;
                }
                cnt = 0;
            }
        }
        return cnt > 0 ? cnt : wordLen;     // cnt=0 means s end with empty space, else end with alpha
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.lengthOfLastWord1("    abc   ab") << endl;
    if (argc < 2)
        return 0;
    cout << s.lengthOfLastWord1(argv[1]) << endl;

    return 0;
}
