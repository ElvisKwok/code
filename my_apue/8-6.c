/*
 * To show different exit value
 */

#include "apue.h"
#include <sys/wait.h>
#include "8-6.h"

int main(int argc, char *argv[])
{
    pid_t   pid;
    int     status;

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)          /* child */
        exit(7);

    if (wait(&status) != pid)   /* wait for child */
        err_sys("wait error");
    pr_exit(status);            /* print its status */


    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        abort();                /* generates SIGABRT */

    if (wait(&status) != pid)   /* wait for child */
        err_sys("wait error");
    pr_exit(status);            /* print its status */


    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        status /= 0;            /* divide by 0 generaes SIGFPE */

    if (wait(&status) != pid)   /* wait for child */
        err_sys("wait error");
    pr_exit(status);            /* print its status */

    
	exit(0);
}
