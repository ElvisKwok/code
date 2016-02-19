// Source : https://leetcode.com/problems/anagrams/
// Author : Elvis Kwok
// Date   : 2016-01-07

/********************************************************************************** 
 * 
 * Given an array of strings, group anagrams together.
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 *   ["ate", "eat", "tea"],
 *   ["nat", "tan"],
 *   ["bat"]
 * ]
 * 
 * Note:
 * 
 * For the return value, each inner list's elements must follow the lexicographic order.
 * All inputs will be in lower-case.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
using std::unordered_map;

class Solution {
public:
    // soulmachine solution
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > group;
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            string key = *it;
            sort(key.begin(), key.end());
            group[key].push_back(*it);
        }
        vector<vector<string> > result;
        for (auto it = group.begin(); it != group.end(); ++it) {
            sort(it->second.begin(), it->second.end());     // do not use cbegin(const) in the above for statement
            vector<string> svec(it->second.begin(), it->second.end());
            result.push_back(svec);
        }
        return result;
    }
};

void printStrings(vector<vector<string> >& vv) {
    cout << "[" << endl;
    for (int i = 0; i < vv.size(); ++i) {
        cout << "    [";
        for (int j = 0; j < vv[i].size(); ++j) {
            if (j < vv[i].size()-1)
                cout << "\"" <<vv[i][j] << "\", ";
            else
                cout << "\"" <<vv[i][j] << "\"";
        }
        if (i < vv.size()-1)
            cout << "]," << endl;
        else
            cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main(int argc, char **argv)
{
    Solution s;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > result = s.groupAnagrams(strs);
    printStrings(result);
    if (argc < 2)
        return 0;

    return 0;
}
