#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, x, n;
    n = rand() % 100;
    printf("输入一个100以内的数字，你有5次机会:");
    for(i = 4; i >= 0; i--) {
        scanf("%d", &x);
        if (x == n) {
            printf("bingo\n");
            break;
        }
        else if( x < n) {
            if ( i == 0)
                printf("还是不对，你输了!\n");
            else printf("不对，输入大于%d的数字，还剩下%d次机会:\n", x, i);
        }
        else {
            if ( i == 0)
                printf("还是不对，你输了!\n");
            else printf("不对，输入小于%d的数字，还剩下%d次机会:\n", x, i);
        }
    }
    return 0;
}
