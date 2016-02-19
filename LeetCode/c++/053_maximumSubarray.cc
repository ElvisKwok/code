// Source : https://leetcode.com/problems/maximum-subarray/
// Author : Elvis Kwok
// Date   : 2016-01-10

/********************************************************************************** 
 * 
 * Find the contiguous subarray within an array (containing at least one number) which 
 * has the largest sum.
 * 
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution using the 
 * divide and conquer approach, which is more subtle.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums[0], sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            m = max(m, sum);
            if (sum < 0)
                sum = 0;
        }
        return m;
    }
    // dynamic programming:
    // extra space
    int maxSubArray1(vector<int>& nums) {
        int m = INT_MIN;
        int *sum = new int[nums.size()];
        sum[0] = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            sum[i] = max(sum[i-1]+nums[i], nums[i]);
            m = max(m, sum[i]);
        }
        delete[] sum;
        return m;
    }

    // divide and conquer
    int maxSubArray2(vector<int>& nums) {
        int i, maxElem = INT_MIN;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            maxElem = max(nums[i], maxElem);
        }
        if (i == nums.size()) return maxElem;  // all negative
        return maxSubSum(nums, 0, nums.size()-1);
    }
    int maxSubSum(vector<int>& nums, int left, int right) {
        int maxLeftSum, maxRightSum;
        int maxLeftBorderSum, maxRightBorderSum;
        int leftBorderSum, rightBorderSum;
        int center, i;
        
        if (left == right) {     // base case
            if (nums[left]>0)
                return nums[left];
            else
                return 0;
        }

        center = (left + right) / 2;
        maxLeftSum = maxSubSum(nums, left, center);
        maxRightSum = maxSubSum(nums, center+1, right);

        maxLeftBorderSum = 0;
        leftBorderSum = 0;
        for (i = center; i >= left; --i) {
            leftBorderSum += nums[i];
            if (leftBorderSum > maxLeftBorderSum)
                maxLeftBorderSum = leftBorderSum;
        }

        maxRightBorderSum = 0;
        rightBorderSum = 0;
        for (i = center+1; i <= right; ++i) {
            rightBorderSum += nums[i];
            if (rightBorderSum > maxRightBorderSum)
                maxRightBorderSum = rightBorderSum;
        }
        
        return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }
    int max3(int a, int b, int c) {
        int tmp = a > b ? a : b;
        return c > tmp ? c : tmp;
    }
};

int main() {
    //const int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
    const int a[] = {1, 2, -1, -2, 2, 1, -2, 1};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    Solution s;
    cout <<  s.maxSubArray(nums) << endl;
    cout <<  s.maxSubArray1(nums) << endl;
    cout <<  s.maxSubArray2(nums) << endl;
    return 0;
}
