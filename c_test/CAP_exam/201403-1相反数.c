#include <stdio.h>

#define MAX 500

int f(int *a, int n)
{
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (a[i] + a[j] == 0) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    int i, n, a[MAX];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", f(a, n));
}
