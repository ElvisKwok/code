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



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x1)
            return find_kth(A, m, B, n, total / 2 + 1);
        else
            return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
}
private:
    static int find_kth(int A[], int m, int B[], int n, int k) {
        //always assume that m is equal or smaller than n
        if (m > n) return find_kth(B, n, A, m, k);
        if (m == 0) return B[k - 1];
        if (k == 1) return min(A[0], B[0]);
        //divide k into two parts
        int ia = min(k / 2, m), ib = k - ia;
        if (A[ia - 1] < B[ib - 1])
            return find_kth(A + ia, m - ia, B, n, k - ia);
        else if (A[ia - 1] > B[ib - 1])
            return find_kth(A, m, B + ib, n - ib, k - ib);
        else
            return A[ia - 1];
    }
};


int main()
{
    Solution s;
     
    return 0;
}
