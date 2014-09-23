/*
 * test whether we can set offset to stdin 
 */

#include "apue.h"

int main(int argc, char *argv[])
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
	exit(0);
}
