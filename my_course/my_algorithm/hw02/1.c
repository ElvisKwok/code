#include <stdio.h>
#include <string.h>

void matrix(char *, int);

int main(int argc, char *argv[])
{
    char s[5] = "ABCDE";
    matrix(s, 4);
    return 0;
}

void matrix(char *s, int high)
{
    char **final_s1 = (char **)malloc(high*sizeof(char *));
    char **final_s2 = (char **)malloc(high*sizeof(char *));
    int i, k;
    for (i = 0, k = 0; k < high; k++, i++) {
        final_s1[i] = (char *)malloc((k+1)*sizeof(char));
        strncpy(final_s1[i], s, k+1);
        final_s2[i] = (char *)malloc((high-k+2)*sizeof(char));
        char *tmp = s;
        strncpy(final_s2[i], tmp+k+1, high-k);
        strcat(final_s2[i], "\0");
        printf("((%s)(%s))\n",final_s1[i], final_s2[i]);
    }
}

