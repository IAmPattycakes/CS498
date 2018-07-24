//Practice to mess around with CLI arguments

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXARGS 5000

int numcmp(void *d1, void *d2);

int main(int argc, char *argv[])
{
    int i;
    if( argc >= 2 ) {
        printf("The arguments supplied are:\n");
        for(i = 1; i < argc; i++) {
            printf("%s\t", argv[i]);
        }
        printf("\n");
        double dlist[MAXARGS];
        int i;
        for(i = 1; i < argc; i++) {
            dlist[i-1] = atof(argv[i]);
        }
        qsort(dlist, argc - 1, sizeof(double), numcmp);
        
        printf("The sorted arguments are:\n");
        for(i = 0; i < argc - 1; i++) {
            printf("%.3lf\t", dlist[i]);
        }
        printf("\n");
        
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