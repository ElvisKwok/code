// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Elvis Kwok
// Date   : 2015-10-13

/********************************************************************************** 
 * 
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the 
 * median of the two sorted arrays. The overall run time complexity should be O(log 
 * (m+n)).
 *               
 **********************************************************************************/

// bug: [1,2], [1,2] output 1.000000 expect 1.500000


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left1 = 0, mid1, right1 = nums1.size()-1, left2 = 0, mid2, right2 = nums2.size()-1;
        if (nums1.size()==0) {
            int tmp = left2+right2;
            return (tmp%2==0) ? (double)nums2[tmp/2] : ((double)nums2[tmp/2]+(double)nums2[tmp/2+1])/2;
        }
        if (nums2.size()==0) {
            int tmp = left1+right1;
            return (tmp%2==0) ? (double)nums1[tmp/2] : ((double)nums1[tmp/2]+(double)nums1[tmp/2+1])/2;
        }
        while (left1 < right1 && left2 < right2) {
            mid1 = (left1 + right1) / 2;
            mid2 = (left2 + right2) / 2;
            if (left1+1==right1 && left2+1==right2) { // [1,2], [1,2]
                int mid_value1 = nums1[left1] <= nums2[left2] ? nums2[left2]: nums1[left1];
                int mid_value2 = nums1[right1] <= nums2[right2] ? nums1[right1]: nums2[right2];
                return (mid_value1 + mid_value2)/2.0;
            }
            if (nums1[mid1] == nums2[mid2])
                return (double)nums1[mid1];
            else if (nums1[mid1] > nums2[mid2]) {
                if ((left1+right1)%2 == 0) {    // 序列1有奇数个元素
                    left1 = mid1;
                    right2 = mid2;
                } else {                        // 序列1有偶数个元素
                    left1 = mid1+1;
                    right2 = mid2;
                }
            } 
            else {
                if ((left1+right1)%2 == 0) {    // 序列1有奇数个元素
                    right1 = mid1;
                    left2 = mid2;
                } else {                        // 序列1有偶数个元素
                    right1 = mid1;
                    left2 = mid2+1;
                }
            } // else
        } // while
        return (nums1[left1] + nums2[left2]) / 2.0;
    }
};


int main()
{
    Solution s;
    int b1[] = {1,2};
    int b2[] = {1,2};
    int n1 = sizeof(b1)/sizeof(b1[0]);
    int n2 = sizeof(b2)/sizeof(b2[0]);
    vector<int> nums1(b1, b1+n1), nums2(b2, b2+n2);
    cout << "Median is 2.5 = " << s.findMedianSortedArrays(nums1, nums2) << endl;  
    return 0;
}
