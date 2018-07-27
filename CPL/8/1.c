#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

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