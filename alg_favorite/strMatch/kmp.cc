#include <stdio.h>
#include <string.h>

int next[7];

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
            k = next[k]; // 递归前缀索引k=next[k],去找到长度更短的相同前缀后缀
    }
}

int kmpSearch(char *s, char *p)
{
    int i = 0, j = 0;
    int sLen = strlen(s), pLen = strlen(p);
    while ((i < sLen) && (j < pLen)) {
        if ((i != -1) && (s[i] == p[j])) {
            ++i;
            ++j;
        }
        else {
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
    GetNext(p, next);
    int i = kmpSearch(s, p);
    printf("%d\n", i);
    return 0;
}
