/*
 * example of exec() 
 */

#include "apue.h"
#include <sys/wait.h>

char    *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(int argc, char *argv[])
{
    pid_t   pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {      /* specify pathname, specify environment */
        if (execle("/root/code_and_book_notes/code/my_apue/8-10-echoall", "8-10-echoall", "myarg1",
                "MY ARG2", (char *)0, env_init) < 0)
                    err_sys("execle error");
    }

    if (waitpid(pid, NULL, 0) < 0)
        err_sys("wait error");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {      /* specify filename, inherit environment */
        if (execlp("./8-10-echoall", "8-10-echoall", "only 1 arg", (char *)0) < 0)
            err_sys("execlp error");
    }

	exit(0);
}
