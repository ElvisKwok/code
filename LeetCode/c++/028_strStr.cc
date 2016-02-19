// Source : https://leetcode.com/problems/implement-strstr/
// Author : Elvis Kwok
// Date   : 2015-10-15

/********************************************************************************** 
 * 
 * Implement strStr().
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is 
 * not part of haystack.
 * 
 * Update (2014-11-02):
 * The signature of the function had been updated to return the index instead of the 
 * pointer. If you still see your function signature returns a char * or String, please 
 * click the reload button  to reset your code definition.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // my version: brute-force
    int strStr(string haystack, string needle) {
        int i=0, j=0;
        int n1 = haystack.size(), n2 = needle.size();
        if (n1 == 0 && n2 == 0) return 0;

        while (i < n1 && j < n2) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == n2)
            return i - j;
        else return -1;
/* Note: the code below will exceed time limit(result is correct by short length)*/        
//        while (i < n1) {
//            while (i < n1 && haystack[i] == needle[j]) {  //"this should not be 'while', overhead o(n*m*m)
//                ++i;
//                ++j;
//            }
//            if (j == n2)
//                return i-j;
//            else {
//                i = i-j+1;
//                j = 0;
//            }
//        }
//        return -1;
    }

    // my version 2: kmp
    int strStr1(string haystack, string needle) {
        int i=0, j=0;
        int n1 = haystack.size(), n2 = needle.size();
        if (n1 == 0 && n2 == 0) return 0;

        int *next = new int[needle.size()];
        GetNextval(needle, next);

        while ((i < n1) && (j < n2)) {
            if ((j == -1) || (haystack[i] == needle[j])) {
                ++i;
                ++j;
            }
            else {
                // i不变
                j = next[j];
            }
        }

        delete next;
        if (j == n2)
            return i - j;
        else return -1;
    }
private:
    /* 求next数组
     * 1. 对于值k，已有"p0 p1 ... pk-1" == "pj-k pj-k+1 ... pj-1"，相当于next[j] = k
     *    因为p[j]之前的模式串子串中，有长度为k的相同前缀&后缀
     * 2. 已知next[0,...,j]，求next[j+1]
     *    若p[k]==p[j]，则next[j+1] = next[j]+1 = k+1;
     *    若p[k]!=p[j]，如果此时p[next[k]]==p[j]，则next[j+1]=next[k]+1，否则，继续递归k=next[k]，
     *    以寻找更短的前后缀匹配
     */
    void GetNext(string p, int next[])
    {
        int n2 = p.size();
        next[0] = -1;
        int k = -1;
        int j = 0;
        while (j < n2 - 1) {
            // prefix p[k], suffix p[j]
            if (k == -1 || p[j] == p[k]) {
                ++k;
                ++j;
                next[j] = k;
            }
            else 
                /* i不变 
                 * 递归前缀索引k=next[k],去找到长度更短的相同前缀后缀
                 * "p0 ... pk-1 pk"(这里看成模式串P)和"pj-k ... pj-1 pj"(这里看成S)匹配, pk与pj失配
                 * 应用next数组的含义（即kmp的思想），下次用p[next[k]]去跟pj匹配
                 * 这样j不用回溯到每一趟的开头，k也不用回到0(即violentSearch)
                 */
                k = next[k];   
        }
    }
    
    // 优化版：不允许出现p[t] == p[next[t]]的情况
    // 因为若p[t]与主串的s[i]失配，那么等于p[t]的p[next[t]]肯定会与主串的s[i]失配
    void GetNextval(string p, int next[])
    {
        int n2 = p.size();
        next[0] = -1;
        int k = -1;
        int j = 0;
        while (j < n2 - 1) {
            // prefix p[k], suffix p[j]
            if (k == -1 || p[j] == p[k]) {
                ++k;
                ++j;
                if (p[j] != p[k])
                    // 当p[j]与主串失配时，用p[next[j]]即这里的p[k]去与主串匹配
                    // 前提是p[k]不能和失配的p[j]相同
                    next[j] = k;
                else // p[j]==p[k]时，用p[k]去匹配必定失败，这里用递归p[next[k]]省去不必要的匹配失败。
                    next[j] = next[k];
            }
            else 
                /* i不变 
                 * 递归前缀索引k=next[k],去找到长度更短的相同前缀后缀
                 * "p0 ... pk-1 pk"(这里看成模式串P)和"pj-k ... pj-1 pj"(这里看成S)匹配, pk与pj失配
                 * 应用next数组的含义（即kmp的思想），下次用p[next[k]]去跟pj匹配
                 * 这样j不用回溯到每一趟的开头，k也不用回到0(即violentSearch)
                 */
                k = next[k];   
        }
    }
};

int main(int argc, char **argv)
{
    if (argc < 3)
        return 0;
    Solution s;
    cout << "strStr(" << "\"" << argv[1] << "\",\"" << argv[2] << "\") = " << s.strStr1(argv[1], argv[2]) << endl;

    return 0;
}
