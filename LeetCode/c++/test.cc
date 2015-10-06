#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using std::tr1::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) == m.end())
                m[target-nums[i]] = i;
            else {
                result.push_back(m[nums[i]]+1);
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
