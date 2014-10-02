#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrix(char *, int);

int main(int argc, char *argv[])
{
    char s[5] = "ABCD";
    matrix(s, strlen(s)-1);
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
        if (strlen(final_s1[i]) <= 2 && strlen(final_s2[i]) <=2) {
            if (strlen(final_s1[i]) == 1 && strlen(final_s2[i]) == 2)
                printf("(%s(%s))\n",final_s1[i], final_s2[i]);
            else if (strlen(final_s1[i]) == 2 && strlen(final_s2[i])== 1)
                printf("((%s)%s)\n",final_s1[i], final_s2[i]);
            else printf("((%s)(%s))\n",final_s1[i], final_s2[i]);
        }
        else if (strlen(final_s1[i]) > 2) {
            matrix(final_s1[i], strlen(final_s1[i])-1);
            printf("%s)\n", final_s2[i]);
        }
        else 
            matrix(final_s2[i], strlen(final_s2[i])-1);
    }
}

