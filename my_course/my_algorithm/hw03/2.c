#include <stdio.h>
#include <string.h>

#define MAX 100

int b[MAX][MAX];
int c[MAX][MAX];

void LCSLength(int m, int n, char *x, char *y, int c[MAX][MAX], int b[MAX][MAX])
{
    int i, j;
    for (i = 1; i <= m; i++)
        c[i][0] = 0;
    for (i = 1; i <= n; i++)
        c[0][i] = 0;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }
            else if (c[i-1][j] > c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}

void LCS(int i, int j, char *x, int b[MAX][MAX])
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1) {
        LCS(i-1, j-1, x, b);
        printf("%c", x[i-1]);
    }
    else if (b[i][j] == 2) {
        LCS(i-1, j, x, b);
    }
    else LCS(i, j-1, x, b);
}

int main(int argc, char *argv[])
{
    char x[MAX] = "abcdefg" , y[MAX] = "kabllkjdoejf";
    /*
    char x[MAX], y[MAX];
    puts("input string x and y:");
    gets(x);
    gets(y);
    */
    int m = strlen(x), n = strlen(y);
    LCSLength(m, n, x, y, c, b);
    LCS(m, n, x, b);
    putchar('\n');
    printf("the max common length is: %d\n", c[m][n]);
    return 0;
}

