/*
 * example of fork() 
 */

#include "apue.h"

int     glob = 6;           /* external variable in initialized data */
char    buf[] = "a write to stdout\n";

int main(int argc, char *argv[])
{
    int     var;            /* automatic variable on the stack */
    pid_t   pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)      /* sizeof计算的长度包括null字节，strlen不包括 */
        err_sys("write error");
    printf("before fork\n");    /* we don't flush stdout */

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {      /* child */
        glob++;
        var++;
    } else {
        sleep(2);               /* parent */    /* sleep 2秒尽量（不保证）使得子进程先执行 */
    }

    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);

	exit(0);
}
