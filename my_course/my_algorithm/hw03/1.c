#include <stdio.h>
#include <string.h>

#define MAX 100

char final[MAX];
int len = 0;
int subProblem[MAX][MAX];

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
        subProblem[i][j]++;
        return len;
    }
    if ((i > 0 && j > 0) && x[i-1] == y[j-1]) {
        final[len++] = x[i-1];
        subProblem[i-1][j-1]++;
        return LCS(i-1, j-1, len, x, y, final);
    }
    
    int u = LCS(i-1, j, len, x, y, final);
    int v = LCS(i, j-1, len, x, y, final);
    if (u > v) {
        subProblem[i-1][j]++;
        return LCS(i-1, j, len, x, y, final);
    }
    else {
        subProblem[i][j-1]++;
        return LCS(i, j-1, len, x, y, final);
    }

    /* another way */
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
    //char x[MAX] = "abcdef",  y[MAX] = "kagbdft";
    char x[MAX], y[MAX];
    printf("input string x:");
    gets(x);
    printf("input string y:");
    gets(y);
    int len_x = strlen(x), len_y = strlen(y);
    
    int i, j;
    for (i = 0; i <= len_x; i++)
        for (j = 0; j <= len_y; j++)
            subProblem[i][j] = 0;
    subProblem[len_x][len_y] = 1;

    int c = LCS(len_x, len_y, len, x, y, final);
    
    invert(final);
    printf("x = \"%s\", y = \"%s\"\n", x, y);
    printf("Max common length = %d\n", c);
    printf("Longest common subsequence = \"%s\"\n\n", final);
    
    printf("Each subProblem has been calculated:\n");
    printf("(i,j)\t|");
    for (j = 0; j <= len_y; j++)
        printf("%d\t", j);
    printf("\n");
    for (j = 0; j <= len_y; j++)
        printf("————————");
    printf("\n");
    for (i = 0; i <= len_x; i++) {
        printf("%d\t|", i);
        for (j = 0; j <= len_y; j++)
            printf("%d\t",subProblem[i][j]);
        printf("\n");
    }
     
    return 0;
}
