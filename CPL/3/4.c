/*
The reason why itoa would not properly record the largest number is due to when
it does the n = -n operation. Because the largest negative number is one greater
than the largest positive number, the number overflows back to the largest 
negative number and promptly messes everything up. 
*/ 

#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int smallest = -2147483648;
    char s[100];
    itoa(smallest, s);
    printf("%s\n", s);
    itoa(2147483647, s);
    printf("%s\n", s);
}

void itoa(int n, char s[])
{
    int i, sign;

    sign = n; //Record sign and make it positive
    i = 0;
    do {
        if(n < 0) s[i++] = ('0' - (n % 10));
        else s[i++] = n % 10 + '0';
    } while((n /= 10) != 0);
    if(sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}