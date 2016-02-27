// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Elvis Kwok
// Date   : 2016-02-23

/********************************************************************************** 
 * 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its index, 
 * otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int low = 0;
        int high = n-1;
        int mid = 0;
        // find min
        while (nums[low] >= nums[high] && low < high) { // low < high in case of only one element
            mid = low + (high-low)/2;
            if (low+1 == high)
                break;
            if (nums[mid] >= nums[low])
                low = mid;
            if (nums[mid] <= nums[high])
                high = mid;
            if (nums[mid] == target)
                return true;
        }
        int minPos = high;
        if (target >= nums[minPos] && target <= nums[n-1]) {
            low = minPos;
            high = n-1;
        }
        else if (target <= nums[minPos-1] && target >= nums[0]) {
            low = 0;
            high = minPos-1;
        }
        else
            return false;
        // binary search
        while (low <= high) {
            mid = low + (high-low)/2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }

    // soulmachine solution
    bool search1(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int low = 0;
        int high = n-1;
        while (low <= high) {
            //if ((nums[low] <= nums[high]) && (target < nums[low] || target > nums[high]))
            //    return false;
            int mid = low + (high-low)/2;
            if (target == nums[mid])
                return true;
            if (nums[mid] >= nums[low]) { // 区间[low, mid]递增
                if (target >= nums[low] && target < nums[mid]) // 在递增区间[low, mid]
                    high = mid-1;
                else                // 不在递增区间[low, mid], 下一轮看[mid+1, high]区间
                    low = mid+1;
            }
            else {  // 区间[mid, high]递增 
                if (target > nums[mid] && target <= nums[high]) // 在递增区间[mid, high]
                    low = mid+1;
                else               // 不在递增区间[mid, high], 下一轮看[low, mid-1]区间
                    high = mid-1;
            }
        }
        return false;
    }
};

void test(vector<int>& nums, int target, int expected) {
    Solution s;
    if (s.search1(nums, target) == expected)
        cout << "passed." << endl;
    else
        cout << "failed." << endl;
}

int main(int argc, char **argv)
{
    int a[] = {4, 5, 10, 20, 0, 1, 2};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    test(nums, 4, 0);
    test(nums, 5, 1);
    test(nums, 10, 2);
    test(nums, 20, 3);
    test(nums, 0, 4);
    test(nums, 1, 5);
    test(nums, 2, 6);
    test(nums, 100, -1);
    test(nums, 6, -1);
    test(nums, 14, -1);

    return 0;
}
