#include <stdio.h>

#define MAX 100

char target[MAX];
char str[MAX][MAX];
int case_flag;
int count;
int ok[MAX];

char lower(char c, int case_flag) 
{
    if (case_flag == 0)
        if (c >= 'A' && c <= 'Z')
            return c+32;
        else return c;
    else return c;
}


void match(int n)
{
    int i, j, k, tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; str[i][j] != '\0'; j++) {
            tmp = j;
            k = 0;
            while(lower(str[i][j], case_flag) == lower(target[k], case_flag) && target[k] != '\0') {
                j++;
                k++;
            }
            if (target[k] == '\0') {
                ok[i] = 1;
                break;
            }
            else {
                j = tmp;
                k = 0;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i, n;
    scanf("%s", target);
    scanf("%d", &case_flag);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s", str[i]);
    match(n);
    for (i = 0; i < n; i++)
        if(ok[i] == 1)
            printf("%s\n", str[i]);
    return 0;
}
