/*
 * Change directory to a given one(temporarily),
 * then called getcwd, print current directory.
 * notice: when the execution is terminated, the directory will not be changed!
 * By the way, we change to a directory which is a symbol link.
 * As the result, the final directory will be the destination which the symbol link linking to.
 */

#include "apue.h"
#include "pathalloc.c"

int main(int argc, char *argv[])
{
    char    *ptr;
    int     size;
    if (chdir("./test/2") < 0)
        err_sys("chdir failed");

    ptr = path_alloc(&size);            /* our own function */
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");
    printf("cwd = %s\n", ptr);
	exit(0);
}
