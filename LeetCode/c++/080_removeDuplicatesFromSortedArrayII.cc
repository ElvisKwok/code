// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : Elvis Kwok
// Date   : 2016-02-23

/********************************************************************************** 
 * 
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * 
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, with the first five elements of nums being 
 * 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 *               
 **********************************************************************************/
// relate problem:
// 026_removeDuplicates.cc

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int len = 0;
        int cnt = 1;
        for (int i=1; i<n; ++i) {
            if (nums[len] != nums[i]) {
                cnt = 1;
                nums[++len] = nums[i];
            }
            else if (cnt == 1) {        // 相等, 且旧cnt==1(不是2)
                ++cnt;
                nums[++len] = nums[i];
            }
            //else { 
            //    ++cnt;
            //    if (cnt == 2) {
            //        nums[++len] = nums[i];
            //    }
            //}
        }
        return len+1;   
    }
    // soulmachine solution:
    int removeDuplicates2(vector<int>& nums) {
        const int n = nums.size();
        int len = 0;
        for (int i=0; i<n; ++i) {
            if (i>=1 && i<=n-2 && nums[i]==nums[i-1] && nums[i]==nums[i+1])
                continue;
            nums[len++] = nums[i];
        }
        return len;
    }
};

void printVector(vector<int> &v, int n) {
    cout << "{ ";
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "}" << endl;
}

void test(vector<int> v) {
    Solution s;
    printVector(v, v.size());
    int n = s.removeDuplicates(v);
    printVector(v, n);
    cout << "==============================" << endl;
}
    
int main(int argc, char **argv)
{
    int a0[] = {1, 2, 3, 4, 5};
    vector<int> v0(a0, a0+sizeof(a0)/sizeof(int));
    test(v0);

    int a1[] = {1, 1, 1};
    vector<int> v1(a1, a1+sizeof(a1)/sizeof(int));
    test(v1);

    int a2[] = {1, 2, 2};
    vector<int> v2(a2, a2+sizeof(a2)/sizeof(int));
    test(v2);

    int a3[] = {1, 1, 1, 1};
    vector<int> v3(a3, a3+sizeof(a3)/sizeof(int));
    test(v3);

    int a4[] = {1, 1, 1, 2};
    vector<int> v4(a4, a4+sizeof(a4)/sizeof(int));
    test(v4);

    int a5[] = {1, 2, 2, 2, 3, 3};
    vector<int> v5(a5, a5+sizeof(a5)/sizeof(int));
    test(v5);

    int a6[] = {1, 1, 1, 2, 2, 2};
    vector<int> v6(a6, a6+sizeof(a6)/sizeof(int));
    test(v6);

    return 0;
}
