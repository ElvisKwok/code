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
#include <sstream>
#include <algorithm>
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
                    //cur.append(1, cnt+'0');
                    //cur.append(1, first);
                    cur += intToStr(cnt);
                    cur += first;
                    //if (i == n-1) cout << intToStr(cnt) << "个" << first << ", ";
                    cnt = 1;
                    first = next;   // replace with first different char.
                }
                else {
                    ++cnt;
                }
            }
            cur.append(1, cnt+'0');    // remain string.
            cur.append(1, first);
            //if (i == n-1) cout << intToStr(cnt) << "个" << first << endl;
            prev = cur;
        }
        return cur;
    }
    // soulmachine solution: STL, include <sstream> and <algorithm> for find_if
    string countAndSay0(int n) {
        string s("1");
        while (--n)
            s = getNext(s);
        return s;
    }
    string getNext(const string &s) {
        stringstream ss;
        for (auto i = s.begin(); i != s.end(); ) {
            //auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));    // bind1st is a binder(function adapter)
            auto j = find_if(i, s.end(), bind2nd(not_equal_to<char>(), *i));    // bind2nd is a binder(function adapter), bind *i as the 2nd parameter for function "not_equal_to()"
            ss << distance(i, j) << *i;
            i = j;
        }
        return ss.str();
    }
private:
    string intToStr(int n) {
        string str;
        while (n != 0) {
            char bit = (n % 10) + '0';
            n /= 10;
            str = bit + str;
        } 
        return (n >= 0 ? str : '-'+str);
    }
};

int main(int argc, char **argv)
{
    Solution s;
    for (int i = 5; i <= 8; ++i) {
        cout << s.countAndSay(i) << "\n" << endl;
        cout << s.countAndSay0(i) << "\n" << endl;
    }

    if (argc < 2)
        return 0;

    return 0;
}
