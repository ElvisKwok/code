#include <stdio.h>
#define MAX 100
int a[MAX][MAX];
int point[MAX][4];
int count = 0;
int draw(int point[][4], int n)
{
    int i, j, k;
    for (k = 0; k < n; k++) {
        for(i = point[k][0]; i < point[k][2]; i++) {
            for (j = point[k][1]; j < point[k][3]; j++) {
                if (a[i][j] != 1) {
                    a[i][j] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}
int main(int argc, char *argv[])
{
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &point[i][j]);
    printf("%d\n", draw(point, n));
    return 0;
}