#include <stdio.h>
#define dprint(expr)	printf(#expr " = %g\n", expr);
#define swap(t, x, y)	t tmp; tmp = x; x = y; y = tmp;

int main()
{
    dprint(19.0 / 3.0);
    int a = 1, b = 2;
    swap(int, a, b);
    printf("a=%d b=%d\n", a, b);
    return 0;
}
