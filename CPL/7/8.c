#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 10000
#define getchar() getc(stdin)
#define putchar(c) putc((c), stdout)

main(int argc, char *argv[])
{
    FILE *fp;
    int page = 1;
    void printPage(FILE *, int);
    if(argc == 1) 
        printf("Please specify a file.");
    else {
        while(--argc > 0) {
            if((fp = fopen(*++argv, "r")) == NULL) {
                printf("Cannot open %s\n", *argv);
            } else {
                printPage(fp, page++);
            }
        }
    }
    return 0;
}

void printPage(FILE *fp, int page)
{
    char line[MAXLINE];
    
    while(fgets(line, MAXLINE, fp) != NULL) {
        printf("%s", line);
    }
    printf("\n\n\n\n%d\n\n\n\n", page);
}