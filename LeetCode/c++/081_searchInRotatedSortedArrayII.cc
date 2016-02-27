// Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : Elvis Kwok
// Date   : 2016-02-23

/********************************************************************************** 
 * 
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * 
 * Would this affect the run-time complexity? How and why?
 * 
 * Write a function to determine if a given target is in the array.
 *               
 **********************************************************************************/

// relate problem:
// 033_searchInRotatedSortedArray.cc
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution
    // {1, 3, 1, 1, 1}
    // nums[mid] >= nums[low] 有两种情况
    // 1. nums[mid] > nums[low] 区间[low, mid]一定递增
    // 2. nums[mid] == nums[low] 不确定，忽略相同元素++low
    // O(N)
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int low = 0;
        int high = n-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (target == nums[mid])
                return true;
            if (nums[mid] > nums[low]) { // 区间[low, mid]递增
                if (target >= nums[low] && target < nums[mid]) // 在递增区间[low, mid]
                    high = mid-1;
                else                // 不在递增区间[low, mid], 下一轮看[mid+1, high]区间
                    low = mid+1;
            }
            else if (nums[mid] < nums[low]) {  // 区间[mid, high]递增 
                if (target > nums[mid] && target <= nums[high]) // 在递增区间[mid, high]
                    low = mid+1;
                else               // 不在递增区间[mid, high], 下一轮看[low, mid-1]区间
                    high = mid-1;
            }
            else  // nums[mid] == nums[low], skip the duplicate one: nums[low]
                ++low; // 由于nums[low] != target 顺序查看下一个index
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
