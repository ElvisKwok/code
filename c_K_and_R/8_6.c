#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>
#include <fcntl.h>          /* 读写标志 */
#include <sys/stat.h>       /* 类型定义 */
#include <dirent.h> 
#include <sys/dir.h>        /* 本地目录结构 */



#define NAME_MAX    14      /* max file name */
#define DIRSIZ      14

typedef struct {
    long ino;               /* inode No. */
    char name[NAME_MAX+1];  /* file name + '\0' */    
} Dirent;

typedef struct {
    int fd;         /* 目录的文件描述符 */
    Dirent d;       /* 目录项 */
} DIR2;



DIR2 *opendir2(char *dirname);
Dirent *readdir2(DIR2 *dfd);
void closedir2(DIR2 *dfd);


void fsize(char *);

int main(int argc, char *argv[])
{
    if (argc == 1)
        fsize(".");
    else
        while(--argc > 0)
            fsize(*++argv);
    return 0;
}

void dirwalk(char *, void (*fcn)(char *));

void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    Dirent *dp;
    DIR2 *dfd;

    if ((dfd = opendir2(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir2(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
            continue;
        if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s%s too long\n", dir, dp->name);
        else {
            sprintf(name, "%s%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    closedir2(dfd);
}

int fstat(int fd, struct stat *);

DIR2 *opendir2(char *dirname)
{
    int fd;
    struct stat stbuf;
    DIR2 *dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1
     || fstat(fd, &stbuf) == -1
     || (stbuf.st_mode & S_IFMT) != S_IFDIR
     || (dp = (DIR2 *) malloc (sizeof(DIR2))) == NULL)
        return NULL;
    dp->fd = fd;
    return dp;
}

void closedir2(DIR2 *dp)
{
    if (dp) {
        close(dp->fd);
        free(dp);
    }
}

Dirent *readdir2(DIR2 *dp)
{
    struct direct dirbuf;       /* 本地目录结构，定义在<sys/dir.h> */
    static Dirent d;            /* 返回：可移植的结构 */

    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
        if (dirbuf.d_ino == 0)
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0';
        return &d;
    }
    return NULL;
}
