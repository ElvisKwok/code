#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single=nums[0];
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it)
            single = single ^ *it;
        return single;
    }
};

int main()
{
    Solution s;
    int a[9] = {1, 2, 3, 4, 5, 4, 2, 3, 1};
    vector<int> ivec(a, a+9);
    cout << s.singleNumber(ivec) << endl;
     
    return 0;
}
