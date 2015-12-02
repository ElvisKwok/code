// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Elvis Kwok
// Date   : 2015-10-13

/********************************************************************************** 
 * 
 * Given a string, find the length of the longest substring without repeating 
 * characters. For example, the longest substring without repeating letters for 
 * "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is 
 * "b", with the length of 1.
 *               
 *               
 * 
 *               
 **********************************************************************************/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using std::unordered_map;

class Solution {
public:
    // O(N) solution: using (i - lastRepeatPos) to check if it's max
    // haoel solution using map:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m; // <char, last_pos>
        int max = 0;
        int lastRepeatPos = -1;     // 0 - lastRepeatPos = 1
        for (int i = 0; i < s.size(); ++i) {
            if ((m.find(s[i]) != m.end()) && lastRepeatPos < m[s[i]])
                lastRepeatPos = m[s[i]];
            if (i - lastRepeatPos > max)
                max = i - lastRepeatPos;
            m[s[i]] = i;
        }
        return max;
    }
    // haoel solution without using map:
    int lengthOfLongestSubstring1(string s) {
        const int MAX_CHARS = 256;
        int m[MAX_CHARS];
        memset(m, -1, sizeof(m));
        int max = 0;
        int lastRepeatPos = -1;
        for (int i = 0; i < s.size(); ++i) {
            if ((m[s[i]] != -1) && lastRepeatPos < m[s[i]])
                lastRepeatPos = m[s[i]];
            if (i - lastRepeatPos > max)
                max = i - lastRepeatPos;
            m[s[i]] = i;
        }
        return max;
    }

    // time limit exceeded
    int lengthOfLongestSubstring_bad(string s) {
        unordered_map<char, int> m;
        int max = 0;
        for (int i = 0; i < s.size(); ++i) {
            int j = i;
            while ((j < s.size()) && (m.find(s[j]) == m.end())) {
                m[s[j]] = j;
                ++j;
            }
            max = (j-i) > max ? (j-i) : max;
            if (i < m[s[j]])
                i = m[s[j]] + 1;
            m.clear();
        }
        return max;
    }
};


int main()
{
    Solution s;
    string str = "abcabcbb";
    cout << str << ": " << s.lengthOfLongestSubstring(str) << endl;
    str = "bbbbbb";
    cout << str << ": " << s.lengthOfLongestSubstring(str) << endl;
    str = "abcdabcdbb";
    cout << str << ": " << s.lengthOfLongestSubstring(str) << endl;
    
    return 0;
}
