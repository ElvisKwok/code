#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    for (i = 0; i<2; ++i) {
        fork();
        printf("-\n");
        //printf("-");
    }
    return 0;
}
