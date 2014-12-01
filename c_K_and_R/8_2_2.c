/*
 * 无缓冲的单字符输入, version 2
 * 读入一组字符，每次只输出一个字符
 */

#include <stdio.h>
#include <sys/syscall.h>

int getchar2(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }

    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}


int main(int argc, char *argv[])
{
    char c;
    c = getchar2();
    putchar(c);

    return 0;
}
