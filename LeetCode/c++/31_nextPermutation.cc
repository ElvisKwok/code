// Source : https://leetcode.com/problems/next-permutation/
// Author : Elvis Kwok
// Date   : 2015-12-22

/********************************************************************************** 
 * 
 * Implement next permutation, which rearranges numbers into the lexicographically next 
 * greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible 
 * order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding 
 * outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 **********************************************************************************/

/********************************************************************************** 
 *
 * Example  6  8  7  4  3  2
 * Step1   [6] 8  7  4  3  2
 * Step2    6  8 <7> 4  3  2
 * Step3    7  8  6  4  3  2
 * Step4|-  7 [8  6  4  3  2]
 *      |-  7  2  3  4  6  8
 *
 * Algorithm:
 * 1. From RIGHT to LEFT, find the first digit[partitionNumber] while violate the
 *    increase trend, in this example, [6] will be be selected, PARTITION_INDEX=0.
 * 2. From RIGHT to LEFT, find the first digit<changeNumber>, which large than
 *    [partitionNumber]. Here <7> will be selected.
 * 3. Swap the [partitionNumber] and <changeNumber>.
 * 4. Reverse all the digit on the RIGHT of PARTITION_INDEX
 *
 * PS: The rest digits must be in decrease trend, so sort is also feasible
 *
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // soulmachine solution:
    void nextPermutation(vector<int>& nums) {
        vector<int>::reverse_iterator pivot, change;
        pivot = nums.rbegin()+1;
        while (pivot != nums.rend() && *pivot >= *(pivot-1))    // step 1
            ++pivot;
        if (pivot == nums.rend()) {   //rearrange to the first permutation
            reverse(nums.begin(), nums.end());
            return;
        }
        change = find_if(nums.rbegin(), pivot, bind1st(less<int>(), *pivot));   // step 2
        swap(*pivot, *change);      // step 3
        reverse(nums.rbegin(), pivot);   // step 4
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> nums;
    for (int i = 1; i < argc; ++i)
        nums.push_back(atoi(argv[i]));
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    cout << endl;
    if (argc < 2)
        return 0;

    return 0;
}
