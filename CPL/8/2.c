//This program really does not want to compule 

#include <fcntl.h>
//#include <stdio.h>
//#include <stdlib.h>

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 //Max number of files open at a time
#define PERMS 0666

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int flag;
    int fd;
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
    _READ = 01,
    _WRITE = 02,
    _UNBUF = 04,
    _EOF = 010,
    _ERR = 020
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) ((()p->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) + _flushbuf((x),p))
#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE _iob[OPEN_MAX] = { /*stdin, stdout, stderr*/
    {0, (char *) 0, (char *) 0, _READ, 0},
    {0, (char *) 0, (char *) 0, _WRITE, 1},
    {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;
    
    if(*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if(fp->flag  == 0) //Read | Write == 03
            break;
    if(fp >= _iob + OPEN_MAX)
        return NULL;
    
    if(*mode == 'w')
        fd = creat(name, PERMS);
    else if(*mode == 'a') {
        if((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if(fd == -1)
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

/*get: read n bytes from position pos*/
int get(int fd, long pos, char *buf, int n)
{
    if(lseek(fd, pos, 0) >= 0)
        return read(fd, buf, n);
    else 
        return -1;
}

int _fillbuf(FILE *fp)
{
    int bufsize;
    
    if((fp->flag != _EOF && fp->flag != _ERR) //(_READ|_EOF|_ERR) = 0b00110001
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if(fp->base == NULL)
        if((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if(--fp->cnt < 0) {
        if(fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

#define MAXFILESIZE 100000

main(int argc, char *argv[])
{
    int fp;
    void filecopy(FILE *, FILE *);
   
   if(argc == 1)
        filecopy(stdin, stdout);
    else
        while(--argc > 0)
            if((fp = open(*++argv, O_RDONLY)) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                filecopy(fp, stdout);
            }
    return 0;
    
}

void filecopy(FILE *ifp, FILE *ofp)
{
    char c[MAXFILESIZE];
    int size = read(ifp, c, MAXFILESIZE);
    write(1, c, size);
}