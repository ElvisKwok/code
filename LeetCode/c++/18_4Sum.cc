// Source : https://leetcode.com/problems/4sum/
// Author : Elvis Kwok
// Date   : 2015-12-15

/********************************************************************************** 
 * 
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + 
 * b + c + d = target? Find all unique quadruplets in the array which gives the sum of 
 * target.
 * 
 * Note:
 * 
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ 
 * c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * 
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 * 
 * 
 **********************************************************************************/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i=0; i<n-3; ++i) {
            if (i>0 && nums[i-1]==nums[i]) continue;
            int a = nums[i];
            for (int j=i+1; j<n-2; ++j) {
                if (j>0 && nums[j-1]==nums[j]) continue;
                int b = nums[j];
                int low = j+1;
                int high = n-1;
                while (low < high) {
                    int c = nums[low];
                    int d = nums[high];
                    if (a+b+c+d == target) {
                        vector<int> v;
                        v.push_back(a);
                        v.push_back(b);
                        v.push_back(c);
                        v.push_back(d);
                        result.push_back(v);
                        while (low<n && nums[low]==nums[low+1]) ++low;
                        while (high>0 && nums[high]==nums[high-1]) --high;
                        ++low;
                        --high;
                    } else if (a+b+c+d < target) {
                        while (low<n && nums[low]==nums[low+1]) ++low;
                        ++low;
                    } else {
                        while (high>0 && nums[high]==nums[high-1]) --high;
                        --high;
                    }
                }
            }
        }

        return result;
    }
};

void printMatrix(vector<vector <int> > &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << "]" << endl;
    }
    cout << endl;
}


int main(int argc, char **argv)
{
    Solution s;
    //int a[] = {1, 0, -1, 2, 0, -2}, target = 0;
    int a[] = {0, 0, 0, 0}, target = 0;
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    vector<vector <int> > result = s.fourSum(nums, target);
    printMatrix(result);

    return 0;
}
