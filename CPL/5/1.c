#include <stdio.h>

#define BUFSIZE 1000
#define MAXVAL 100

int getint(int *pn);
int getch();
void ungetch(int);

char buf[BUFSIZE]; //Buffer for ungetch
int bufp = 0; //Next free positon in buffer
int sp = 0;

int main()
{
    int a = 123;
    int* ptr = &a;
    //char num[] = "-1234";
    printf("%d\n", getint(ptr));
}

int getint(int *pn)
{
    int c, sign;
    while(isspace(c = getch())); //skips whitespace
    
    if(isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getch();
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if(c != EOF) {
        ungetch(c);
    }
    return c;
    
}
/*
int getint(int *pn)
{
    int c, sign;
    
    while(isspace(c = getch())); //skip whitespace
    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-') {
        c = getch();
    }
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c- '0');
    *pn *= sign;
    if(c != EOF) ungetch(c);
    return c;
}*/

int getch(void)
{
    return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE) printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}
