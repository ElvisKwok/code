// Source : https://leetcode.com/problems/count-and-say/
// Author : Elvis Kwok
// Date   : 2015-10-23

/********************************************************************************** 
 * 
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return NULL;
        string prev("1"), cur(prev);
        int i, cnt;
        for (int i = 1; i < n; ++i) {
            char first = prev[0];
            cnt = 1;
            cur.erase(cur.begin(), cur.end());
            for (int j = 1; j < prev.size(); ++j) {
                char next = prev[j];
                if (next != first) {
                    cur.append(1, cnt+'0');
                    cur.append(1, first);
                    cnt = 1;
                    first = next;   // replace with first different char.
                }
                else {
                    ++cnt;
                }
            }
            cur.append(1, cnt+'0');    // remain string.
            cur.append(1, first);
            prev = cur;
        }
        return cur;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    for (int i = 1; i <= 5; ++i)
        cout << s.countAndSay(i) << endl;

    if (argc < 2)
        return 0;

    return 0;
}
