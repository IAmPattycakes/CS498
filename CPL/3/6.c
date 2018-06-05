#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    int smallest = -2147483648;
    char s[100];
    itoa(smallest, s, 16);
    printf("%s\n", s);
    itoa(2147483647, s, 16);
    printf("%s\n", s);
    itoa(2147483647, s, 16);
    printf("%s\n", s);
}

void itoa(int n, char s[], int w)
{
    int i, sign;

    sign = n; //Record sign and make it positive
    i = 0;
    do {
        w--;
        if(n < 0) s[i++] = ('0' - (n % 10));
        else s[i++] = n % 10 + '0';
    } while((n /= 10) != 0);
    if(sign < 0) {
        s[i++] = '-'; 
        w--;
    }
    while(w-- > 0) s[i++] = ' ';
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