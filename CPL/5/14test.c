/*This is an attempted rewrite of the chapter 5 excersize 14 activity to
quicksort the arguments of the program. It uses the built-in functions for C
instead of writing it out, because standards have probably changed to include
more since the book was written*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXARGS 5000

int numcmp(void *d1, void *d2);
int revnumcmp(void * d1, void * d2);
void sortnum(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int i;
    if( argc > 1 ) {
        printf("The arguments supplied are:\n");
        for(i = 1; i < argc; i++) {
            printf("%s\t", argv[i]);
        }
        printf("\n");
        if(strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "-nr") == 0 || strcmp(argv[1], "-rn") == 0) {
            sortnum(argc, argv);
        }
    }
    else {
        printf("argument list is empty: cannot sort\n");
    }
    return 0;
}

int numcmp(void * d1, void * d2)
{
    if(*(double*)d1 < *(double*)d2) return -1;
    else if(*(double*)d1 > *(double*)d2) return 1;
    else return 0;
}

int revnumcmp(void * d1, void * d2)
{
    if(*(double*)d1 > *(double*)d2) return -1;
    else if(*(double*)d1 < *(double*)d2) return 1;
    else return 0;
}

void sortnum(int argc, char *argv[])
{
    double dlist[MAXARGS];
    int i;
    int offset = 2;
    
    for(i = 0; i < argc - offset; i++) {
        dlist[i] = atof(argv[i + offset]);
    }
    if(strcmp(argv[1], "-rn") == 0 || strcmp(argv[1], "-nr") == 0) {
         qsort(dlist, argc - 2, sizeof(double), revnumcmp);
    } else {
        qsort(dlist, argc - 2, sizeof(double), numcmp);
    }
    
    printf("The sorted arguments are:\n");
    for(i = 0; i < argc - offset; i++) {
        printf("%.3lf\t", dlist[i]);
    }
    printf("\n");
}

