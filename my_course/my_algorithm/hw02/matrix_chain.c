#include <stdio.h>

void matrix_chain(char *s);
char output[][7];

int main(int argc, char *argv[])
{
    char s[] = "ABCD";
    matrix_chain(s);
    return 0;
}

void matrix_chain(char *s)
{
    int k, i;

    for (k = 0; k < 3; k++) {
        
        for (i = 0; i <= k; i++) {
            output[k][i] = s[i];
        }
        for (i=0; i <= k; i++) {
            output[k][i]=',';
        }
    }
}
