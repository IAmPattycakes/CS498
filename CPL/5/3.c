#include <stdio.h>

void strcat(char *s, char *t);

int main()
{
    char str1[100] = "Hello ";
    char str2[] = "World!";
    strcat(str1, str2);
    printf("%s\n", str1);
}

void strcat(char *s, char *t)
{
    while(*s != '\0') s++; //Skip over the junk in the first string
    while((*s = *t) != '\0') { //copy the string over to the end
        s++;
        t++;
    }
}