// Source : https://leetcode.com/problems/3sum-closest/
// Author : Elvis Kwok
// Date   : 2015-12-02

/********************************************************************************** 
 * 
 * Given an array S of n integers, find three integers in S such that the sum is 
 * closest to a given number, target. Return the sum of the three integers. You may 
 * assume that each input would have exactly one solution.
 * 
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int distance = INT_MAX;
        int closestSum;
        int n = nums.size();
        for (int i=0; i < n; ++i) {
            if (i>0 && nums[i-1]==nums[i]) continue;    // skip
            int a = nums[i];
            int low = i+1;
            int high = n-1;
            // convert the 3sum to 2sum problem
            while (low < high) {
                int b = nums[low];
                int c = nums[high];
                int sum = a+b+c;
                if (distance > abs(sum-target)) {
                    distance = abs(sum-target);
                    closestSum = sum;
                }
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    while (low<n && nums[low]==nums[low+1]) ++low;  // skip
                    ++low;
                } else {
                    while (high>0 && nums[high]==nums[high-1]) --high;  // skip
                    --high;
                }
            }
        }
        return closestSum;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    cout << s.threeSumClosest(nums, -3) << endl;
    cout << s.threeSumClosest(nums, 10) << endl;

    return 0;
}
