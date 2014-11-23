#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    float p;
    p = (float)rand() / RAND_MAX;
    printf("%f\n", p);
    return 0;
}
