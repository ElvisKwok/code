#include <stdio.h>

#define MAX_N   1000
#define MAX_S   10000

int most(int *a, int n)
{
    int i, most, max = 0, flag[MAX_S];
    for (i = 0; i < MAX_S; i++)
        flag[i] = 0;
    for (i = 0; i < n; i++)
        flag[a[i]]++;
    for (i = 0; i < MAX_S; i++) {
        if (max < flag[i]) {
            max = flag[i];
            most = i;
        }
    }
    return most;
}

int main(int argc, char *argv[]) 
{
    int i, n, a[MAX_N];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", most(a, n));
    return 0;
}
