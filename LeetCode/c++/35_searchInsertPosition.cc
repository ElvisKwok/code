// Source : https://leetcode.com/problems/search-insert-position/
// Author : Elvis Kwok
// Date   : 2015-12-23

/********************************************************************************** 
 * 
 * Given a sorted array and a target value, return the index if the target is found. If 
 * not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
            return low;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    int a[] = {1, 3, 5, 6};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    cout << "[1,3,5,6], 5 → 2\t" << s.searchInsert(nums, 5) << endl;
    cout << "[1,3,5,6], 2 → 1\t" << s.searchInsert(nums, 2) << endl;
    cout << "[1,3,5,6], 7 → 4\t" << s.searchInsert(nums, 7) << endl;
    cout << "[1,3,5,6], 0 → 0\t" << s.searchInsert(nums, 0) << endl;

    if (argc < 2)
        return 0;

    return 0;
}
