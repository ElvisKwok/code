#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
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
    cout << s.longestPalindrome("abbacte") << endl;
    return 0;
}
