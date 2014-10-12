/*
 * example of chdir() with bug.
 * because chdir() only work in the process called it, but 
 * when execute this program(complied as a.out), shell fork a son process to run it
 * so the directory will not change for shell
 */

#include "apue.h"

int main(int argc, char *argv[])
{
    if (chdir("/tmp") < 0)
        err_sys("chdir failed");
    printf("chdir to /tmp succeeded\n");
	exit(0);
}
