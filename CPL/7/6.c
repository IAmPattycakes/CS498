/*This is a simple diff program which just prints outthe first line where the files are different.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 10000
#define getchar() getc(stdin)
#define putchar(c) putc((c), stdout)

main(int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;
    void filediff(FILE *, FILE *);
    if(argc < 3) 
        printf("Cannot compare the difference of less than two files.");
    else {
        fp1 = fopen(*++argv, "r");
        fp2 = fopen(*++argv, "r");
        filediff(fp1, fp2);
    }
    return 0;
}

void filediff(FILE *fp1, FILE *fp2)
{
    char line1[MAXLINE], line2[MAXLINE];
    /*Need to make sure that both of the files end at the same time, and that they are the same all the way through.*/
    while(fgets(line1, MAXLINE, fp1) != NULL && fgets(line2, MAXLINE, fp2) != NULL && strcmp(line1, line2) == 0) {
    }
    if(strcmp(line1, line2) != 0) {
        printf("%s%s", line1, line2);
    } 
}