#define NAME_MAX 14 //Longest filename component, system dependent. However, we are no logner on V6FS. 

char *name;
struct stat stbuf;

typedef struct {
    long ino;
    char name[NAME_MAX + 1]; //Name + '\0' terminator
} Dirent;

#define S_IFMT 0160000
#define S_IFDIR 0040000
#define S_IFCHR 0020000
#define S_IFBLK 0060000
#define S_IFREG 0100000

#include <stdio.h> //Finally get this back. 
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

void fsize(char *);

int main(int argc, char **argv)
{
    if(argc == 1)
        fsize(".");
    else 
        while(--argc > 0)
            fsize(*++argv);
    return 0;
}

void dirwalk(char *, void (*fcn)(char *));

//fsize: print size of the file "name"
void fsize(char *name)
{
    struct stat stbuf;
    
    if(stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't acccess %s\n", name);
        return;
    }
    if((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s mod:%d acc:%d\n", stbuf.st_size, name, stbuf.st_mtime, stbuf.st_atime);
}

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;
    if((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "Dirwalk: can't open %s\n", dir);
        return;
    }
    while((dp = readdir(dfd)) != NULL) {
        if(strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
            continue; //Skip self and parent
        if(strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk:name %s/%s too long\n", dir, dp->name);
        else {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}