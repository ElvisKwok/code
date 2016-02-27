// Source : https://leetcode.com/problems/subsets/
// Author : Elvis Kwok
// Date   : 2016-02-19

/********************************************************************************** 
 * 
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 * Note:
 * 
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> bits(nums.size());
        vector<vector<int> > result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        
        while(!allOne(bits)) {
            getSubset(result, nums, bits);
            addBit(bits);
        }
        getSubset(result, nums, bits);
        return result;
    }
    void getSubset(vector<vector<int> >& result, vector<int>& nums, vector<int> &bits) {
        vector<int> one;
        for (int i=0; i<bits.size(); ++i) {
            if (bits[i]==1) 
                one.push_back(nums[i]);
        }
        result.push_back(one);
    }
    bool allOne(vector<int>& bits) {
        for (int i=0; i<bits.size(); ++i) {
            if (bits[i]==0)
                return false;
        }
        return true;
    }
    void addBit(vector<int>& bits) {
        int n = bits.size();
        int carry = (bits[n-1] + 1) / 2;
        bits[n-1] = (bits[n-1] + 1) % 2;
        for (int i=n-2; i>=0; --i) {
            int tmp = carry;
            carry = (bits[i] + tmp) / 2;
            bits[i] = (bits[i] + tmp) % 2;
        }
    }        

    // soulmachine solution 1: 增量构造法dfs，每个元素都有两种选择：选、不选
    // O(2^N) O(N)
    vector<vector<int> > subsets2(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(result, path, 0, nums);
        return result;
    }
    void dfs(vector<vector<int> > &result, vector<int> &path, int step, vector<int> &nums) {
        if (step == nums.size()) {
            result.push_back(path);
            return ;
        }
        // 不选
        dfs(result, path, step+1, nums);

        // 选
        path.push_back(nums[step]);
        dfs(result, path, step+1, nums);
        path.pop_back();
    }
    // soulmachine solution 2: 位向量法dfs，每个元素都有两种选择：选、不选
    // O(2^N) O(N)
    vector<vector<int> > subsets3(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        vector<bool> selected(nums.size(), false);
        dfs(result, selected, 0, nums);
        return result;
    }
    void dfs(vector<vector<int> > &result, vector<bool> &selected, int step, vector<int> &nums) {
        if (step == nums.size()) {
            vector<int> path;
            for (int i=0; i<nums.size(); ++i) {
                if (selected[i])
                    path.push_back(nums[i]);
            }
            result.push_back(path);
            return ;
        }
        // 不选
        selected[step] = false;
        dfs(result, selected, step+1, nums);
        // 选 
        selected[step] = true;
        dfs(result, selected, step+1, nums);
    }
    // soulmachine solution 3: 二进制法, nums={A,B,C,D} 0110=6表示子集{B,C}
    // O(2^N) O(1)
    vector<vector<int> > subsets4(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        const size_t n = nums.size();
        for (size_t i=0; i<(1<<n); ++i) {
            vector<int> subset;
            for (size_t j=0; j<n; ++j) {
                if (i & (1<<j))     // 判断第j位是否为1
                    subset.push_back(nums[j]);
            }
            result.push_back(subset);
        }
        return result;
    }

    // haoel solution: 改用上一题的combination算法 
    vector<vector<int> > subsets5(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<=nums.size(); ++i) {
            vector<vector<int> > tmp = combine(nums, i);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        return result;
    }
    vector<vector<int> > combine(vector<int> &nums, int k) {
        vector<vector<int> > result;
        if (k>nums.size()) return result;
        vector<int> path;
        dfs(result, path, nums, 0, k);
        return result;
    }
    // start: start index 
    void dfs(vector<vector<int> > &result, vector<int> &path, vector<int> &nums, int start, int k) {
        if (path.size() == k) {
            result.push_back(path);
            return ;
        }
        for (int i=start; i<nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(result, path, nums, i+1, k);
            path.pop_back();
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

int main(int argc, char **argv)
{
    Solution s;
    int a[] = {1, 2, 3};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    vector<vector<int> > result = s.subsets(nums);
    printMatrix(result);
    cout << endl;
    vector<vector<int> > result2 = s.subsets2(nums);
    printMatrix(result2);
    cout << endl;
    vector<vector<int> > result3 = s.subsets3(nums);
    printMatrix(result3);
    cout << endl;
    vector<vector<int> > result4 = s.subsets4(nums);
    printMatrix(result4);
    cout << endl;
    vector<vector<int> > result5 = s.subsets5(nums);
    printMatrix(result5);

    if (argc < 2)
        return 0;

    return 0;
}
