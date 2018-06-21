#include <stdio.h>

void strncopy(char *s, char *t, int n);
void strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);

int main()
{
    char str1[100];
    char str2[] = "Hello World";
    strncopy(str1, str2, 5);
    printf("%s\n", str1);
    strncopy(str1, str2, 100);
    printf("%s\n", str1);
    
    char str3[100] = "Hello ";
    char str4[] = "World";
    strncat(str3, str4, 3);
    printf("%s\n", str3);
    strncat(str3, str4, 11);
    printf("%s\n", str3);
    
    char str5[] = "Hello World";
    char str6[] = "Hello";
    printf("%d\n", strncmp(str5, str6, 5));
    printf("%d\n", strncmp(str5, str6, 10));
}

void strncopy(char *s, char *t, int n)
{
    int i;
    for(i = 0; i < n && *t != '\0'; i++) {
        *s = *t;
        s++;
        t++;
    }
}

void strncat(char *s, char *t, int n)
{
    int i;
    
    while(*s != '\0') s++; //Skip over the junk in the first string
    for(i = 0; i < n && *t != '\0'; i++) {
        *s = *t;
        s++;
        t++;
    }
}

int strncmp(char *s, char *t, int n)
{
    int i;
    for(i = 0; i < n && *s == *t && *s != '\0'; i++) {
        s++;
        t++;
    }
    return (i == n) ? 1 : (((*s == *t) && (*t == '\0')) ? 1 : 0);  
}