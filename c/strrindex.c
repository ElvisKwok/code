/*
* The function strindex(s,t) return a index of string t in string s from right to left
* if not found, return -1
*/

#include<string.h>
#include"reverse.c"

int strrindex(char s[], char t[])
{
    int i, j, k;
    reverse(s);
    reverse(t);
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k=0; (s[j] == t[k]) && (t[k] != '\0'); j++, k++)
            ;
        if (t[k] == '\0') {
            reverse(s);
            reverse(t);
            return strlen(s) - strlen(t) - i;
        }
    }
    reverse(s);
    reverse(t);
    return -1;
}
