// Source : https://leetcode.com/problems/gray-code/
// Author : Elvis Kwok
// Date   : 2016-02-27

/********************************************************************************** 
 * 
 * The gray code is a binary numeral system where two successive values differ in only 
 * one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the code, 
 * print the sequence of gray code. A gray code sequence must begin with 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * 
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above 
 * definition.
 * 
 * For now, the judge is able to judge based on one instance of gray code sequence. 
 * Sorry about that.
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution1: formula
    // 第i个数的gray code = i ^ (i/2)
    // 函数参数的n是gray code二进制位数
    // O(2^N)
    vector<int> grayCode(int n) {
        vector<int> result;
        const int size = 1 << n;
        result.reserve(size);   // recommended: avoid unnecessary realloc
        for (int i=0; i < size; ++i)
            result.push_back(binary_to_gray(i));
        return result;
    }
    int binary_to_gray(int num) {
        return num ^ (num >> 1);
    }
    // soulmachine solution2: reflect-and-prefix method
    // O(2^N)
    vector<int> grayCode2(int n) {
        vector<int> result;
        result.reserve(1 << n);   // recommended: avoid unnecessary realloc
        result.push_back(0);
        for (int i=0; i<n; ++i) {
            for (int j=result.size()-1; j>=0; --j) {
                result.push_back(result[j] | (1<<i));
            }
        }
        return result;
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
    vector<int> vec = s.grayCode2(atoi(argv[1]));
    printVector(vec);
    vec = s.grayCode3(atoi(argv[1]));
    printVector(vec);
    if (argc < 2)
        return 0;

    return 0;
}
