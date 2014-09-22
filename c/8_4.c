#include <stdio.h>
#include <sys/syscall.h>
#include <fcntl.h>

#define PERMS 0666

int main(int argc, char *argv[])
{
    int get(int, long, char *, int);
    int fd, n;
    long pos;
    char buf[10];
    
    fd = open(argv[1], O_RDONLY, PERMS);
    get(fd, 2, buf, 8);
    puts(buf);
    return 0;
}

/* read n bytes from posistion pos */
int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) >= 0)        /* move to position pos */
        return read(fd, buf, n);
    else 
        return -1;
}
