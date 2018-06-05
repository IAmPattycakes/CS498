#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);
void itob(int n, char s[], int b);
int main()
{
    int smallest = -2147483648;
    char s[100];
    itob(smallest, s, 8);
    printf("%s\n", s);
    itob(2147483647, s, 2);
    printf("%s\n", s);
    itob(267242409, s, 16); //FEDCBA9
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

void itob(int n, char s[], int b)
{
    int i, sign;

    sign = n; //Record sign and make it positive
    i = 0;
    do {
        if(b > 10) {
            if(n < 0) {
                if((n % b) > 9) s[i++] = (('A' - 10) - (n % b));
                else s[i++] = ('0' - (n % b));
            }
            else {
                if((n % b) > 9) s[i++] = n % b + ('A' - 10);
                else s[i++] = n % b + '0';
            }
        } else {
            if(n < 0) s[i++] = ('0' - (n % b));
            else s[i++] = n % b + '0';
        }
    } while((n /= b) != 0);
    if(sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    
}