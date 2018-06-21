#include <stdio.h>

void printd(int);
void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void itoa(char v[], int i);
int magnitude(int i);
void itoarest(char v[], int i);

int main() {
    char v[100];
    itoa(v, 23781);
    printf("%s\n", v);
}

void itoa(char v[], int i)
{
    v[magnitude(i)] = (i % 10) + '0';
    v[magnitude(i) + 1] = -1;
    itoarest(v, i / 10);
}

void itoarest(char v[], int i)
{
    if(i > 0) {
        v[magnitude(i)] = (i % 10) + '0';
        itoarest(v, i / 10);
    }
}

int magnitude(int i) 
{
    return(((i / 10) > 0) ? 1 + magnitude(i / 10) : 1);
}