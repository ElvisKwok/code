#include <stdio.h>
#define MAX 1000
int pair(int a[], int n)
{
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if ((a[i] - a[j]) == 1 || (a[i] - a[j]) == -1) {
                count++;
            }
        }
    }
    return count;
}
int main(int argc, char *argv[])
{
    int i, n;
    int a[MAX];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", pair(a, n));
    return 0;
}