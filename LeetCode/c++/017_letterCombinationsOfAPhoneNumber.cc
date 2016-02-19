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
                for (int k=0; k<phone[digit].size(); ++k) {     // note: digit 1's size() is 0
                    string s = result[j] + phone[digit][k];
                    tmp.push_back(s);
                }
            }
            result = tmp;   // bug: if digits contain '1', then the inner for loop is ignored, the value of tmp still unassigned, so result reset to empty.
        }

        return result;
    }

    // bop solution: P218 3.2
    // iteratively
    // bug: digit 1
    vector<string> letterCombinations2(string digits) {
        string phone[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> pos(digits.size(), 0);       // pos[4]=0 means digits '4' now stands for 'j', pos[4]=1 means '4' now for 'h'
        vector<string> result;
        while (true) {
            string s;
            for (int i=0; i<digits.size(); ++i) {
                int digit = digits[i] - '0';
                if (digit!=1) {                 // pos[1] is overflow
                    s += phone[digit][pos[i]];
                }
            }
            result.push_back(s);
            int k = digits.size()-1;            // 枚举最后一位对应的字母，直到它的pos等于对应字母集的最后一个字母, k--, 枚举倒数第二位数字
            while (k >= 0) {
                int digit = digits[k] - '0';
                if (pos[k] < phone[digit].size() - 1) {
                    pos[k]++;
                    break;
                }
                else {
                    pos[k] = 0;     //
                    k--;            // 枚举第k-1个数字的字母, 由于pos[k]被置回0，所以对于每个选定的第k-1个数字字母, 第k个数字所有字母又要重新枚举一轮
                }
            }
            if (k < 0)
                break;
        }
        return result;
    }

    // bop solution: P218 3.2
    // recursively
    // bug: digit 1
    vector<string> letterCombinations3(string digits) {
        string phone[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> pos(digits.size(), 0);       // pos[4]=0 means digits '4' now stands for 'j', pos[4]=1 means '4' now for 'h'
        vector<string> result;
        recursiveSearch(phone, digits, result, pos, 0);
        return result;
    }
    void recursiveSearch(string phone[], string digits, vector<string> &result, vector<int> &pos, int i) {
        if (i == digits.size()) {   // not digits.size()-1
            string s;
            for (int j=0; j<digits.size(); ++j) 
                s += phone[digits[j]-'0'][pos[j]];
            result.push_back(s);
            return ;
        }
        for (pos[i]=0; pos[i]<phone[digits[i]-'0'].size(); ++pos[i])
            recursiveSearch(phone, digits, result, pos, i+1);
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

    vector<string> sv2 = s.letterCombinations2(str);
    print(sv2);

    vector<string> sv3 = s.letterCombinations3(str);
    print(sv3);

    return 0;
}
