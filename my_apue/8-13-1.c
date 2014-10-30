/*
 * Test the status of system() call 
 */

#include "apue.h"
#include "8-6.h"        /* include extern function pr_exit() */

int main(int argc, char *argv[])
{
    int     status;
    
    if ((status = system("date")) < 0)
        err_sys("system() error");
    pr_exit(status);

    if ((status = system("nosuchcommand")) < 0)
        err_sys("system() error");
    pr_exit(status);

    if ((status = system("who; exit 44")) < 0)
        err_sys("system() error");
    pr_exit(status);

	exit(0);
}
