// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Elvis Kwok
// Date   : 2015-10-15

/********************************************************************************** 
 * 
 * Given a sorted array, remove the duplicates in place such that each element appear 
 * only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with 
 * constant memory.
 * 
 * For example,
 * Given input array nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums being 1 
 * and 2 respectively. It doesn't matter what you leave beyond the new length.
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[len] == nums[i])
                ++i;
            else
                nums[++len] = nums[i++];
        }
        nums.resize(len+1);     // not required?
        return len+1;
    }
    // haoel version & soulmachine version
    int removeDuplicates2(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int pos = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[pos] != nums[i])
                nums[++pos] = nums[i];
        }
        return pos+1;
    }
    // soulmachine version 2: using STL
    // distance(iter1, iter2)
    // unique(iter1, iter2) moves all unique element to front and return the iterator of the next of last unique element.
    int removeDuplicates3(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));

};

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;

    return 0;
}
