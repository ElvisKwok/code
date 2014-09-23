/*
 * execute the command from stdin, adding signal-catching function sig_int
 */

#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);       /* out signal-catching function */

int main(int argc, char *argv[])
{
    char buf[MAXLINE];          /* from apue.h */
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");              /* printf requires %% to print % */
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {  /* child */
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0) 
            err_sys("waitpid error");
        printf("%% ");
    }

	exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n%% ");
}