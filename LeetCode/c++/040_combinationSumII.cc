// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : Elvis Kwok
// Date   : 2015-12-31

/********************************************************************************** 
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find all unique 
 * combinations in C where the candidate numbers sums to T.
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 
 * ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * 
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine&haoel solution: backtracking(dfs)
    // O(N!), O(N)
    // soulmachine version with bug: duplicates.
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> intermediate;   // intermediate result;
        dfs(candidates, target, 0, intermediate, result);
        return result;
    }
    void dfs(vector<int>& candidates, int gap, int start, vector<int>& intermediate, 
             vector<vector<int> >& result) {
        if (gap == 0) {     // find a solution
            result.push_back(intermediate);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i>start && candidates[i] == candidates[i-1])    // skip duplicates(haoel)
                continue;
            if (gap < candidates[i])    // pruning strategy
                return;
            intermediate.push_back(candidates[i]);
            dfs(candidates, gap-candidates[i], i+1, intermediate, result);
            intermediate.pop_back();    // undo/revocation
        }
    }
};

void printMatrix(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void printVector(vector<int> &v) {
    cout << "{ ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "}" << endl;
}

int main(int argc, char **argv)
{
    Solution s;
    int a[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates(a, a+sizeof(a)/sizeof(int));
    int target = 8;
    cout << "Array = ";
    printVector(candidates);
    cout << "target = " << target << endl;
    vector<vector<int> > result = s.combinationSum2(candidates, target);
    printMatrix(result);

    if (argc < 2)
        return 0;

    return 0;
}
