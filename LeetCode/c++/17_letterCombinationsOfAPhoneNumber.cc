// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Elvis Kwok
// Date   : 2015-12-15

/********************************************************************************** 
 * 
 * Given a digit string, return all possible letter combinations that the number could 
 * represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any 
 * order you want.
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // haoel solution
    vector<string> letterCombinations(string digits) {
        string phone[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (digits.size() <= 0)
            return result;

        for (int i=0; i<digits.size(); ++i) {
            if (!isdigit(digits[i])) {
                vector<string> err;
                return err;
            }
            int digit = digits[i] - '0';
            if (result.size()<=0) {
                for (int j=0; j<phone[digit].size(); ++j) {
                    string s;
                    s += phone[digit][j];
                    result.push_back(s);
                }
                continue;       // !!! skip the following for_loop
            }
            vector<string> tmp;
            for (int j=0; j<result.size(); ++j) {
                for (int k=0; k<phone[digit].size(); ++k) {
                    string s = result[j] + phone[digit][k];
                    tmp.push_back(s);
                }
            }
            result = tmp;
        }

        return result;
    }
};

void print(vector<string>& sv) {
    for (int i=0; i<sv.size(); i++) {
        if (i>0) cout << ", ";
        cout << sv[i];
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    Solution s;
    string str = "23";

    if (argc > 1)
        str = argv[1];
    vector<string> sv = s.letterCombinations(str);
    print(sv);

    return 0;
}
