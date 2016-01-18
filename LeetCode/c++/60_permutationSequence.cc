// Source : https://leetcode.com/problems/permutation-sequence/
// Author : Elvis Kwok
// Date   : 2016-01-12

/********************************************************************************** 
 * 
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 * 
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    // time limit exceed
    string getPermutation(int n, int k) {
        string s;
        for (int i=1; i <= n; i++)
            s.push_back(i+'0');
        for (int i = 1; i < k; ++i)
            nextPermutation(s);
            //next_permutation(s.begin(), s.end());
        
        return s; 
    }
    // implement next_permutation()
    void nextPermutation(string &s) {
        int pivot, change;
        pivot = s.size()-2;
        while (pivot >= 0 && s[pivot] >= s[pivot+1])    // step 1
            --pivot;
        if (pivot < 0)  {   // rearrange to the 1st permutation
            reverse(s.begin(), s.end());
            return;
        }
        for (change=s.size()-1; change > pivot; --change) {        // step 2
            if (s[change] > s[pivot])
                break;
        }
        swap(s[change], s[pivot]);   // step 3
        reverse(s.begin()+pivot+1, s.end());
    }
    // implement next_permutation()
    void nextPermutation2(string &s) {
        string::reverse_iterator pivot, change;
        pivot = s.rbegin()+1;
        while (pivot != s.rend() && *pivot >= *(pivot-1))   // step 1
            ++pivot;
        if (pivot == s.rend()) {
            reverse(s.begin(), s.end());
            return;
        }
        change = find_if(s.rbegin(), pivot, bind1st(less<char>(), *pivot)); // step 2
        swap(*pivot, *change);  // step 3
        reverse(s.rbegin(), pivot);
    }

    // haoel solution1: nextPermutation optimized(little) by determining the group
    // to reduce unnecessary iteration
    string getPermutation1(int n, int k) {
        string s;
        int total = 1;
        for (int i=1; i <= n; i++) {
            s.push_back(i+'0');
            total *= i;
        }

        // invalid k
        if (total < k)  return "";

        int group = total / n;
        int idx = (k-1) / group;
        char c = s[idx];
        s.erase(s.begin()+idx);
        s.insert(s.begin(), c);
        
        int offset = (k-1) % group;
        for (int i=0; i<offset; i++)
            nextPermutation(s);

        return s;
    }

    // haoel solution2: extreamly optimized
    // O(N)
    string getPermutation2(int n, int k) {
        vector<int> nums;
        int total = 1;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            total *= i;
        }

        // invalid k;
        if (total < k)
            return "";
        
        // 康托编码
        // Construct the k-th permutation with a list n numbers
        // Idea: group all permutations according to their first common number (so n groups, each
        // of (n-1)! numbers), find the group where the k-th permutation belongs, remove the 
        // common first number from the list and append it to the resulting string, and 
        // iteratively construct the (((k-1)%(n-1)!)+1)-th permutation with the remaining n-1 numbers
        int group = total;
        stringstream ss;
        while (n>0) {
            group = group / n;              // current group size
            int idx = (k-1) / group;        // belongs to which group
            ss << nums[idx];
            nums.erase(nums.begin()+idx);
            n--;
            // the next k also can be caculated like this: k = (k-1)%group + 1
            k -= group * idx;               // next iteration
       }
       return ss.str();
   }


};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.getPermutation1(atoi(argv[1]), atoi(argv[2])) << endl;


    if (argc < 2)
        return 0;

    return 0;
}
