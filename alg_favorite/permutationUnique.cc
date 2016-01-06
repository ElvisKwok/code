/********************************************************************************** 
 * 
 * Given a collection of numbers that might contain duplicates, return all possible 
 * unique permutations.
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        perm_recursive(result, nums, 0, nums.size()-1);
        return unique(result);
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
    // INVALID IN THIS PROBLEM
    //vector<vector<int> > permuteUnique1(vector<int>& nums) {
    //    sort(nums.begin(), nums.end());
    //    vector<vector<int> > result;
    //    vector<int> path;   // tmp
    //    dfs(nums, path, result);
    //    return unique(result);
    //}
    //void dfs(const vector<int>& nums, vector<int> &path, vector<vector<int> > &result) {
    //    if (path.size() == nums.size()) {
    //        result.push_back(path);
    //        return;
    //    }
    //    for (vector<int>::const_iterator it=nums.begin(); it != nums.end(); ++it) {
    //        vector<int>::const_iterator pos = find(path.begin(), path.end(), *it);
    //        if (pos == path.end()) {
    //            path.push_back(*it);
    //            dfs(nums, path, result);
    //            path.pop_back();
    //        }
    //    }
    //}

    // soulmachine solution2: using std::next_permutation()
    vector<vector<int> > permuteUnique2(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return unique(result);
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
    // To deal with the duplication number, we need do those modification:
    //    1) sort the array [pos..n].
    //    2) skip the same number.
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
    vector<vector<int> > permuteUnique4(vector<int>& nums) {
        vector<vector<int> > vv;
        vv.push_back(nums);
       
        if (nums.size() <2){
            return vv;
        }
            
        int pos=0;
        while(pos<nums.size()-1){
            int size = vv.size();
            for(int i=0; i<size; i++){
                sort(vv[i].begin()+pos, vv[i].end());   // sort the array, then same num will be consecutive
                //take each number to the first place
                for (int j=pos+1; j<vv[i].size(); j++) {
                    vector<int> v = vv[i];
                    if (j>0 && v[j] == v[j-1])
                        continue;       // skip the same num
                    swap(v[j], v[pos]);
                    vv.push_back(v);
                }
            }
            pos++;
        }
        return vv;
    }
    
    // Time Limit Exceed if just applying this method to previous algorithm
    vector<vector<int> > unique(vector<vector<int> > &vv) {
        set<vector<int> > vset(vv.begin(), vv.end());
        vector<vector<int> > result(vset.begin(), vset.end());
        return result;
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
    int a[] = {1, 1, 2};
    //int a[] = {3, 3, 0, 0, 2, 3, 2};
    vector<int> ivec(a, a+sizeof(a)/sizeof(int));
    vector<vector<int> > result = s.permuteUnique4(ivec);
    cout << "permuation of ";
    printVector(ivec); 
    cout << " is: " << endl;
    printMatrix(result);

    if (argc < 2)
        return 0;

    return 0;
}
