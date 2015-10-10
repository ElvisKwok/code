#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 求next数组
 * 1. 对于值k，已有"p0 p1 ... pk-1" == "pj-k pj-k+1 ... pj-1"，相当于next[j] = k
 *    因为p[j]之前的模式串子串中，有长度为k的相同前缀&后缀
 * 2. 已知next[0,...,j]，求next[j+1]
 *    若p[k]==p[j]，则next[j+1] = next[j]+1 = k+1;
 *    若p[k]!=p[j]，如果此时p[next[k]]==p[j]，则next[j+1]=next[k]+1，否则，继续递归k=next[k]，
 *    以寻找更短的前后缀匹配
 */
void GetNext(char* p, int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1) {
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
void GetNextval(char* p, int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1) {
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

int kmpSearch(char *s, char *p, int next[])
{
    int i = 0, j = 0;
    int sLen = strlen(s), pLen = strlen(p);
    while ((i < sLen) && (j < pLen)) {
        if ((j == -1) || (s[i] == p[j])) {
            ++i;
            ++j;
        }
        else {
            // i不变
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}

int main()
{
    char s[] = "BBC ABCDAB ABCDABCDABDE", p[] = "ABCDABD";
    int *next = (int *)malloc(strlen(p)*sizeof(int));
    GetNext(p, next);
    for (int i = 0; i < 7; ++i) 
        printf("%d ", next[i]);
    puts("");
    int i = kmpSearch(s, p, next);
    printf("%d\n", i);
    free(next);
    return 0;
}
