#include <stdio.h>


struct test {
    char a;
    int b;
};

int main()
{
    printf("%d\n", sizeof(struct test));
    return 0;
}
