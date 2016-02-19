// Source : https://leetcode.com/problems/jump-game/
// Author : Elvis Kwok
// Date   : 2016-01-12

/********************************************************************************** 
 * 
 * Given an array of non-negative integers, you are initially positioned at the first 
 * index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position. 
 * 
 * Determine if you are able to reach the last index.
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * A = [3,2,1,0,4], return false.
 * 
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // note: each elem is the "max" length can go
    // soulmachine & haoel solution: greed, from left to right;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return false;
        int reachPos = 0;       // how far we could reach currently
        for (int i = 0; i <= reachPos && i < n; ++i) {
            reachPos = max(reachPos, nums[i]+i);
            if (reachPos >= n-1)
                return true;
        }
        return false;
    }

    // soulmachine solution 2: greed, from right to left;
    bool canJump2(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return false;
        int left_most = n-1;
        for (int i = n-2; i >= 0; --i) {
            if (nums[i]+i >= left_most)
                left_most = i;
        }
        return left_most == 0;
    }

    // soulmachine solution 3: dynamic programmming
    bool canJump2(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return false;
        vector<int> f(n, 0);
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i-1], nums[i-1]) - 1;  // f[i] means in pos i, how many steps can jump
            if (f[i] < 0)
                return false;
        }
        return f[n-1] >= 0;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
