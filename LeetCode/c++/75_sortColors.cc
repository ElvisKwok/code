// Source : https://leetcode.com/problems/sort-colors/
// Author : Elvis Kwok
// Date   : 2016-01-21

/********************************************************************************** 
 * 
 * Given an array with n objects colored red, white or blue, sort them so that objects 
 * of the same color are adjacent, with the colors in the order red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and 
 * blue respectively.
 * 
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * 
 * click to show follow up.
 * 
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array 
 * with total number of 0's, then 1's and followed by 2's.
 * Could you come up with an one-pass algorithm using only constant space?
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    // Two-Pointers
    // two-pass
    void sortColors(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        while (low < high) {
            while (nums[low]==0 && low<high)
                ++low;
            while (nums[high]!=0 && low<high)
                --high;
            if (low < high)
                swap(nums[low], nums[high]);    // nums[low]!=0, nums[high]=0
        }

        low = high;
        high = nums.size()-1;
        while (low < high) {
            while (nums[low]==1 && low<high)
                ++low;
            while (nums[high]!=1 && low<high)
                --high;
            if (low < high)
                swap(nums[low], nums[high]);    // nums[low]!=1, nums[high]=1
        }
    }
    
    // soulmachine solution1: counting sort
    // two-pass
    void sortColors1(vector<int>& nums) {
        vector<int> count(3, 0);
        for (int i=0; i<nums.size(); ++i)
            count[nums[i]]++;
        for (int color=0, i=0; color<3; ++color) 
            for (int j=0; j<count[color]; ++j) 
                nums[i++] = color;
    }

    // haoel & soulmachine solution2: Two-Pointers ???
    // one-pass
    /* 
     * swap(nums[i], nums[two--]): i isn't changed.
     * in next iteration, we need to judge whether nums[i]==0.
     * using swap(nums[i++], nums[two--]) will place the final 0 among 1s.
     *
     */
    void sortColors2(vector<int>& nums) {
        int zero=0, two=nums.size()-1;
        for (int i=0; i<=two; ) {
            if (nums[i]==0)         // zero
                swap(nums[i++], nums[zero++]);   // zero <= i
            else if (nums[i]==2)    // two
                swap(nums[i], nums[two--]);     
            else                    // one 
                i++;
        }
    }

    // soulmachine solution3: using partition()
    // two-pass
    void sortColors3(vector<int>& nums) {
        vector<int>::iterator end0 = partition(nums.begin(), nums.end(), bind1st(equal_to<int>(), 0));
        partition(end0, nums.end(), bind1st(equal_to<int>(), 1));

    }

    // soulmachine solution4: reimplement partition()
    // two-pass
    void sortColors4(vector<int>& nums) {
        vector<int>::iterator end0 = my_partition(nums.begin(), nums.end(), bind1st(equal_to<int>(), 0));
        my_partition(end0, nums.end(), bind1st(equal_to<int>(), 1));
    }

    template<typename ForwardIterator, typename UnaryPredicate>
    ForwardIterator my_partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
        ForwardIterator pos = first;
        for ( ; first != last; ++first) {
            if (pred(*first))
                swap(*first, *(pos++));
        }
        return pos;
   }
                
};

void printVector(vector<int> &v) {
    cout << "{ ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "}" << endl;
}

int main(int argc, char **argv)
{
    Solution s;
    int n=7;

    if (argc == 2)
        n = atoi(argv[1]);
    srand(time(NULL));
    vector<int> a(n);
    for (int i=0; i<n; ++i)
        a[i] = rand()%3;
    printVector(a);
    s.sortColors(a);
    printVector(a);
    cout << endl;

    for (int i=0; i<n; ++i)
        a[i] = rand()%3;
    printVector(a);
    s.sortColors1(a);
    printVector(a);
    cout << endl;

    for (int i=0; i<n; ++i)
        a[i] = rand()%3;
    printVector(a);
    s.sortColors2(a);
    printVector(a);
    cout << endl;

    for (int i=0; i<n; ++i)
        a[i] = rand()%3;
    printVector(a);
    s.sortColors3(a);
    printVector(a);
    cout << endl;

    for (int i=0; i<n; ++i)
        a[i] = rand()%3;
    printVector(a);
    s.sortColors4(a);
    printVector(a);
    cout << endl;


    return 0;
}
