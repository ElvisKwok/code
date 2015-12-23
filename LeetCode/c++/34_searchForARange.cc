// Source : https://leetcode.com/problems/search-for-a-range/
// Author : Elvis Kwok
// Date   : 2015-12-23

/********************************************************************************** 
 * 
 * Given a sorted array of integers, find the starting and ending position of a given 
 * target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution1: STL
    vector<int> searchRange1(vector<int>& nums, int target) {
        // distance of 0 and 2 in [0, 1, 2] is 2.
        // lower_bound: return an iterator pointing to the first element >= target
        // upper_bound: return an iterator pointing to the first element > target
        // the target is in range of [lower_bound, upperbound) if exist.
        const int lower = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        const int upper = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
        if (nums[lower] != target)
            return vector<int> {-1, -1};
        else
            return vector<int> {lower, upper};
    }

    //// soulmachine solution2: implement upper_bound and lower_bound
    //vector<int> searchRange2(vector<int>& nums, int target) {
    //    auto lower = lower_bound(nums.begin(), nums.end(), target);
    //    auto upper = upper_bound(lower, nums.end(), target);
    //    if (lower == nums.end() || *lower != target)
    //        return vector<int> {-1, -1};
    //    else
    //        return vector<int> {distance(nums.begin(), lower), distance(nums.begin(), prev(upper))};
    //}
    //template<typename ForwardIterator, typename T>
    //ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value) {
    //    while (first != last) {
    //        auto mid = next(first, distance(first, last) / 2 );
    //        if (value > *mid)   first = ++mid;
    //        else                last = mid;
    //    }
    //    return first;
    //}
    //ForwardIterator upperr_bound(ForwardIterator first, ForwardIterator last, T value) {
    //    while (first != last) {
    //        auto mid = next(first, distance(first, last) / 2 );
    //        if (value >= *mid)  first = ++mid;  // the only difference with lower_bound
    //        else                last = mid;
    //    }
    //    return first;
    //}

    // haoel solution
    vector<int> searchRange3(vector<int>& nums, int target) {
        int pos = binary_search(nums, 0, nums.size()-1, target);
        vector<int> result;
        int low = -1, high = -1;
        if (pos >= 0) {
            low = high = pos;
            int l = low;
            do {
                low = l;
                l = binary_search(nums, 0, low-1, target);
            } while (l >= 0);

            int h = high;
            do {
                high = h;
                h = binary_search(nums, high+1, nums.size()-1, target);
            //} while (h <= nums.size()-1); // error: correct result, but may be error! like h=-1
            } while (h >= 0);   // -1 is return if not found.
        }
        result.push_back(low);
        result.push_back(high);
        return result;
    }
    int binary_search(vector<int>& nums, int low, int high, int key) {
        while (low <= high) {
            int mid = (low+high) / 2;
            if (key == nums[mid])
                return mid;
            else if (key < nums[mid])
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
};

void printVector(vector<int>& ivec) {
    cout << "{ ";
    for (int i=0; i<ivec.size(); ++i)
        cout << ivec[i] << " ";
    cout <<"} " << endl;
}

int main(int argc, char **argv)
{
    Solution s;

    const int cnt=6;
    int a[cnt] ={5, 7, 7, 8, 8, 10};
    vector<int> av(a, a+cnt);

    vector<int> v;
    v = s.searchRange3(av, 6);     
    printVector(v);    
    v = s.searchRange1(av, 6);     
    printVector(v);    


    int b[cnt] ={5, 5, 5, 8, 8, 10};
    vector<int> bv(b, b+cnt);
    v = s.searchRange3(bv, 5);     
    printVector(v);    

    int c[cnt] ={5, 5, 5, 5, 5, 5};
    vector<int> cv(c, c+cnt);
    v = s.searchRange3(cv, 5);     
    printVector(v);    

    if (argc < 2)
        return 0;

    return 0;
}
