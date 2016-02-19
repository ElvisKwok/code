// Source : https://leetcode.com/problems/3sum/
// Author : Elvis Kwok
// Date   : 2015-12-02

/********************************************************************************** 
 * 
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c 
 * = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * 
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * 
 *     For example, given array S = {-1 0 1 2 -1 -4},
 * 
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector <int> > threeSum(vector<int>& nums) {
        vector<vector <int> > result;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i=0; i < n-2; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;    // skip the duplication
            int a = nums[i];
            int low = i+1;
            int high = n-1;
            while (low < high) {    // for current a
                int b = nums[low];
                int c = nums[high];
                if (a+b+c == 0) {
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    result.push_back(v);
                    // skip the duplication
                    while (low<n && nums[low]==nums[low+1]) ++low;
                    while (high>0 && nums[high]==nums[high-1]) --high;
                    // continue search for next b and c for current a.
                    ++low;
                    --high;
                } else if (a+b+c > 0) {
                    while (high>0 && nums[high]==nums[high-1]) --high;    // skip
                    --high;
                } else {
                    while (low<n && nums[low]==nums[low+1]) ++low;        // skip
                    ++low;
                }
            } // end while, next a
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
    //int a[] = {-1, 0, 1, 2, -1, -4};
    int a[] = {0, 0, 0, 0};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    vector<vector <int> > result = s.threeSum(nums);
    printMatrix(result);

    return 0;
}
