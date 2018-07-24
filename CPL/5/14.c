#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000
char *lineptr[MAXLINES];

int getlinenew(char *line, int max);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void newqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    
    if(argc > 1 && strcmp(argv[1], "-n") == 0) numeric = 1;
    if((nlines = readlines(lineptr, MAXLINES)) == 0) {
        newqsort((void **) lineptr, 0, nlines - 1, 
            (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Input too big to sort\n");
        return 1;
    }
}

void newqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    
    if(left >= right)  /*do nothing if array contains */
        return;        /*fewer than two elements*/
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++) {
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    newqsort(v, left, last-1, comp);
    newqsort(v, last+1, right, comp);
}
#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0; 
    while((len = getlinenew(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; //Deletes newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    
    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int getlinenew(char s[], int lim)
{
    int c, i;
    
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}