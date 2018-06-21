#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char str1[] = "Hello ";
    char str2[] = "World!";
    printf("%d\n", strend(str1, str2));
    
    char str3[] = "Hello World";
    char str4[] = "World";
    printf("%d\n", strend(str3, str4));
}

int strend(char *s, char *t)
{
    int startt = t;
    while(*s != '\0') s++; //Skip over the junk in the first string
    while(*t != '\0') t++;
    while((*s == *t) && startt < t) { //copy the string over to the end
        s--;
        t--;
    }
    printf("%d %d\n", t, startt);
    int tpos = t; //Because it didn't like comparing an int to a pointer. 
    return( (tpos < startt) ? 1 : 0);
}