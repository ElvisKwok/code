#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
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
