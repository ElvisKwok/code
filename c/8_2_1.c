/*
 * 无缓冲的单字符输入
 */

#include <stdio.h>
#include <sys/syscall.h>

int getchar2(void)
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}


int main(int argc, char *argv[])
{
    char c;
    c = getchar2();
    putchar(c);

    return 0;
}
