// Source : https://leetcode.com/problems/two-sum/
// Author : Elvis Kwok
// Date   : 2015-10-18

/********************************************************************************** 
 * 
 * Given an array of integers, find two numbers such that they add up to a specific 
 * target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up 
 * to the target, where index1 must be less than index2. Please note that your returned 
 * answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
using std::unordered_map;

/********************************************************************************** 
 * 
 * General solution: K-sum  O(max{nlogn, n^(k-1)})
 * 1) sort              
 * 2) k-2 for loops, starting point is next by next: a1, a2(next to a1), ..., ak-2
 * 3) 1 while loop, "while(index[ak-1] < index[ak])"
 * 4) ak-1 start from index[ak-2]+1, ak start from vector.size()-1
 * 5) two pointer(ak-1, ak) search from both sides to center
 *               
 **********************************************************************************/

class Solution {
public:
    // july solution: sort, two pointer from both sides to center.
    vector<int> twoSum(vector<int>& nums, int target) {
        int small = 0, big = 0, index1 = 0, index2 = 0, j=0;
        vector<int> nums_copy(nums);
        vector<int> result;
        sort(nums_copy.begin(), nums_copy.end());
        vector<int>::iterator first = nums_copy.begin(), last = nums_copy.end()-1;
        while (first != last) {
            if ((*first + *last) == target) {
                small = *first;
                big = *last;
                break;
            }
            else if ((*first + *last) < target)
                ++first;
            else 
                --last;
        }
        for (size_t i = 0; i < nums.size(); ++i){
            if (nums[i] == small){
                index1 = i+1;
                if (small == big)
                    j = i+1;
                break;
            }
        }
        for (; j < nums.size(); ++j)
            if (nums[j] == big)
                index2 = j+1;
        int a = index1 < index2 ? index1 : index2;
        int b = index1 > index2 ? index1 : index2;
        result.push_back(a);
        result.push_back(b);
        return result;
    }

    // haoel solution: map
    vector<int> twoSum2(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            // not found the second one
            if (m.find(numbers[i])==m.end() ) { 
                // store the first one poisition into the second one's key
                m[target - numbers[i]] = i; 
            }else { 
                // found the second one
                result.push_back(m[numbers[i]]+1);
                result.push_back(i+1);
                break;
            }
        }
        return result;
    }
};

int main()
{
    int target = -8;
    int ia[] = {-1, -2, -3, -4, -5};
    vector<int> ivec(ia, ia+5);
    Solution s;
    vector<int> result;
    result = s.twoSum(ivec, target);
    //cout << result[0] << " + " << result[1] << " = " << target<< endl;
    cout << "two index: " << result[0] << "\t" << result[1] << endl;
     
    return 0;
}
