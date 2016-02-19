// Source : https://leetcode.com/problems/remove-element/
// Author : Elvis Kwok
// Date   : 2015-10-15

/********************************************************************************** 
 * 
 * Given an array and a value, remove all instances of that value in place and return 
 * the new length.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the 
 * new length.
 * 
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
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int pos = 0;
        for (int i = 0; i < n; ++i)
            if (nums[i] != val)
                nums[pos++] = nums[i];
        return pos;
    }
};

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;

    return 0;
}
