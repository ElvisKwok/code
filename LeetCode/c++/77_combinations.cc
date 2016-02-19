// Source : https://leetcode.com/problems/combinations/
// Author : Elvis Kwok
// Date   : 2016-01-29

/********************************************************************************** 
 * 
 * Given two integers n and k, return all possible combinations of k numbers out of 1 
 * ... n.
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    // just for k=2
//    vector<vector<int> > combine(int n, int k) {
//        vector<vector<int> > result;
//        for (int i=0; i<k; ++i) {
//            for (int j=1; j<=n; ++j) {
//                for (int t = j+1; t<=n; ++t) {
//                    vector<int> v;
//                    v.push_back(j);
//                    v.push_back(t);
//                    result.push_back(v);
//                }
//            }
//        }
//        sort(result.begin(), result.end());
//        unique(result.begin(), result.end());
//
//        return result;
//
//    }

    // soulmachine solution: recursively
    // O(n!)
    vector<vector<int> > combine1(int n, int k) {
        vector<vector<int> > result;
        if (k>n) return result;
        vector<int> path;
        dfs(result, path, 1, k, n);
        return result;
    }
    // start: start num
    void dfs(vector<vector<int> > &result, vector<int> &path, int start, int k, int n) {
        if (path.size() == k) {
            result.push_back(path);
            return ;
        }
        for (int i=start; i<=n; ++i) {
            path.push_back(i);
            dfs(result, path, i+1, k, n);
            path.pop_back();
        }
    }

    // soulmachine solution: iteratively
    // O((n-k)!)
    vector<vector<int> > combine2(int n, int k) {
        vector<vector<int> > result;
        if (k>n) return result;
        vector<int> values(n);
        iota(values.begin(), values.end(), 1);   // 1,2,3,...,n
        vector<bool> select(n, false);
        fill_n(select.end()-k, k, true); // not return false untill next_permutation(1,1,...,0,0) 
        //fill_n(select.begin(), k, true); // prev_permutation(0,0,...,1,1) return false
        do {
            vector<int> one(k);
            for (int i=0, index=0; i<n; ++i) {
                if (select[i])
                    one[index++] = values[i];
            }
            result.push_back(one);
        } while (next_permutation(select.begin(), select.end()));
        //} while (prev_permutation(select.begin(), select.end()));
        return result;
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

int main(int argc, char **argv)
{
    Solution s;
    vector<vector<int> > result1 = s.combine1(atoi(argv[1]), atoi(argv[2]));
    printMatrix(result1);
    cout << endl;
    vector<vector<int> > result2 = s.combine2(atoi(argv[1]), atoi(argv[2]));
    printMatrix(result2);
    

    if (argc < 2)
        return 0;

    return 0;
}
