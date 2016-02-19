// Source : https://leetcode.com/problems/permutations/
// Author : Elvis Kwok
// Date   : 2016-01-06

/********************************************************************************** 
 * 
 * Given a collection of distinct numbers, return all possible permutations.
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        perm_recursive(result, nums, 0, nums.size()-1);
        return result;
    }
    void perm_recursive(vector<vector<int> > &result, vector<int>& nums, int begin, int end) {
        if (begin == end)
            result.push_back(nums);
        else {
            for (int i=begin; i<=end; ++i) {
                swap(nums[i], nums[begin]);
                perm_recursive(result, nums, begin+1, end);
                swap(nums[i], nums[begin]);
            }
        }
    }
    // soulmachine solution1: dfs, 增量构造法
    vector<vector<int> > permute1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> path;   // tmp
        dfs(nums, path, result);
        return result;
    }
    void dfs(const vector<int>& nums, vector<int> &path, vector<vector<int> > &result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (vector<int>::const_iterator it=nums.begin(); it != nums.end(); ++it) {
            vector<int>::const_iterator pos = find(path.begin(), path.end(), *it);
            if (pos == path.end()) {
                path.push_back(*it);
                dfs(nums, path, result);
                path.pop_back();
            }
        }
    }

    // soulmachine solution2: using std::next_permutation()
    vector<vector<int> > permute2(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }

    // soulmachine solution3: implement next_permutation()
    void nextPermutation(vector<int>& nums) {
        vector<int>::reverse_iterator pivot, change;
        pivot = nums.rbegin()+1;
        while (pivot != nums.rend() && *pivot >= *(pivot-1))    // step 1
            ++pivot;
        if (pivot == nums.rend()) {   //rearrange to the first permutation
            reverse(nums.begin(), nums.end());
            return;
        }
        change = find_if(nums.rbegin(), pivot, bind1st(less<int>(), *pivot));   // step 2
        swap(*pivot, *change);      // step 3
        reverse(nums.rbegin(), pivot);   // step 4
    }

    // haoel solution:
    /*
     *    The algroithm - Take each element in array to the first place.
     *
     *    For example: 
     *    
     *         0) initalization 
     * 
     *             [1, 2, 3]   
     *
     *         1) take each element into the first place, 
     *
     *             pos = 0, then j = 1, 2
     *             [1, 2, 3]  ==>  [ [2, 1, 3] => [3, 1, 2] ] 
     *              |--|              |-----|
     *                 j=1                  j=2
     *
     *             then we have total 3 answers
     *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2] 
     *            
     *         2) take each element into the "first place" -- pos 
     *            (base on the result of step 1))
     *
     *             pos = 1, then j = 2
     *             [1, 2, 3]  ==>  [1, 3, 2]
     *                 |--| 
     *             [2, 1, 3]  ==>  [2, 3, 1]
     *                 |--| 
     *             [3, 1, 2]  ==>  [3, 2, 1] 
     *                 |--| 
     *
     *             then we have total 6 answers
     *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2], [1, 3, 2], [2, 3, 1], [3, 2, 1]
     *
     *          3) pos = 2 which reach the end of array, return.
     */
    vector<vector<int> > permute4(vector<int> &nums) {
        vector<vector<int> > vv;
        vv.push_back(nums);
       
        if (nums.size() <2){
            return vv;
        }
            
        int pos=0;
        while(pos<nums.size()-1){
            int size = vv.size();
            for(int i=0; i<size; i++){
                //take each number to the first place
                for (int j=pos+1; j<vv[i].size(); j++) {
                    vector<int> v = vv[i];
                    swap(v[j], v[pos]);
                    vv.push_back(v);
                }
            }
            pos++;
        }
        return vv;
    }


};

void printVector(vector<int> &v) {
    cout << "{ ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "}";
}

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
    int a[] = {1, 2, 3};
    vector<int> ivec(a, a+sizeof(a)/sizeof(int));
    vector<vector<int> > result = s.permute4(ivec);
    cout << "permuation of ";
    printVector(ivec); 
    cout << " is: " << endl;
    printMatrix(result);

    if (argc < 2)
        return 0;

    return 0;
}
