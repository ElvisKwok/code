#include <stdio.h>
#include <string.h>


int LCS(int i, int j, char *x, char *y) {
    if (i == 0 && j == 0)
        return 0;
    if ((i > 0 && j > 0) && x[i] == y[j]) {
        return LCS(i-1, j-1, x, y) + 1;
    }
    int u;
    if (i > 0) 
        u = LCS(i-1, j, x, y);
    int v;
    if (j > 0)
        v = LCS(i, j-1, x, y);
    if (u > v)
        return u;
    else 
        return v;
}


int main(int argc, char *argv[]) 
{
    char x[100],  y[100];
    *(x+1) = "abcdef";
    *(y+1) = "adf";
    printf("%d\n", LCS(7, 3, x, y));
    return 0;
}
