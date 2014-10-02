#include <stdio.h>
#include <string.h>

int matrix_chain(char *s, int low, int high, char **output);
char output[5][10];
char s1[5][10];
char s2[5][10];
char tmp[10];

int main(int argc, char *argv[])
{
    char s[] = "ABCD";
    matrix_chain(s,0,9,output);
    puts(output);
    return 0;
}

int  matrix_chain(char *s, int low, int high, char **output)
{
    if (low == high)
        return 1;
    int i, j=0, n1, n2, i1, i2;

    for (i = 0; i < high - low; i++) {
        n1 = matrix_chain(s, low, low+i, s1);
        n2 = matrix_chain(s, low+i+1, high, s2);
        for (i1=0;i1<n1;i1++) {
            for(i2=0;i2<n2;i2++) {
                tmp[0]='(';
                strcat(tmp, s1[i1]);
                strcat(tmp,")(");
                strcat(tmp, s2[i2]);
                strcat(tmp,")");
                strcpy(output[j++],tmp);
            }
        }
    }
    return n1*n2;
}
