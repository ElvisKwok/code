#include <stdio.h>
#include <string.h>

char final[100];
int len = 0;

void invert(char *s)
{
    int i = 0, j = strlen(s)-1;
    char tmp;
    while (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}


int LCS(int i, int j, int len, char *x, char *y, char *final) {
    if (i == 0 || j == 0) {
        return len;
    }
    if ((i > 0 && j > 0) && x[i-1] == y[j-1]) {
        final[len++] = x[i-1];
        return LCS(i-1, j-1, len, x, y, final);
    }
    
    int u = LCS(i-1, j, len, x, y, final);
    int v = LCS(i, j-1, len, x, y, final);
    if (u > v)
        return LCS(i-1, j, len, x, y, final);
    else 
        return LCS(i, j-1, len, x, y, final);
    /*
    return LCS(i-1, j, len, x, y, final) > LCS(i, j-1, len, x, y, final) 
           ?
           LCS(i-1, j, len, x, y, final) 
           :
           LCS(i, j-1, len, x, y, final);
    */
}


int main(int argc, char *argv[]) 
{
    char x[100] = "abcdef",  y[100] = "kagbdft";
    int c = LCS(strlen(x), strlen(y), len, x, y, final);
    invert(final);
    printf("x = \"%s\", y = \"%s\"\n", x, y);
    printf("max common length = %d\n", c);
    printf("longest common subsequence = \"%s\"\n", final);
    return 0;
}
