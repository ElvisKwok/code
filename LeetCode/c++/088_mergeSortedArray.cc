// Source : https://leetcode.com/problems/merge-sorted-array/
// Author : Elvis Kwok
// Date   : 2015-10-18

/********************************************************************************** 
 * 
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one 
 * sorted array.
 * 
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) 
 * to hold additional elements from nums2. The number of elements initialized in nums1 
 * and nums2 are m and n respectively.
 *               
 *               
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator it = nums1.begin();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums2[j] <= *it)
                it = nums1.insert(it, nums2[j++]) + 1;
            else {
                ++it;
                ++i;
            }
        }
        while (j < n)
            it = nums1.insert(it, nums2[j++]) + 1;
            //nums1.push_back(num2[j++]);           // wrong, because space at the tail is allocated.
        nums1.resize(m+n);
    }

    // soulmachine solution: from end to begin. Simple and Clean!!
    // Not to worry about covering: always ia<i && ib<i.
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ia = m - 1, ib = n - 1, i = m + n - 1;
        while (ia >= 0 && ib >= 0)
            nums1[i--] = (nums1[ia] >= nums2[ib] ? nums1[ia--] : nums2[ib--]);
        while (ib >= 0)
            nums1[ia--] = nums2[ib--];
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
