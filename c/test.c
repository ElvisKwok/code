#include <stdio.h>

#define ok(s)   ((s) >= 'A' && (s) <= 'Z') ? 1: 0
struct test {
    char a;
    int b;
};

int main()
{
    printf("%d\n",ok('A'));
    return 0;
}
