#include <stdio.h>

#define MAXSTRING 1000

void reverse(char s[]);

int main()
{
    char str[] = "Hello world, this is forwards";
    reverse(str);
    printf("%s\n\n\n", str);
    char str2[] = "abcdefghijklmnopqrstuvwxyz";
    reverse(str2);
    printf("%s\n\n\n", str2);
    reverse(str2);
    printf("%s\n\n\n", str2);
}

void reverse(char s[])
{
    int counter;
    for(counter = 0; s[counter] != 0; counter++);
    if(counter <= 2) {
        if(counter == 2) {
            char temp;
            temp = s[0];
            s[0] = s[1];
            s[1] = temp;
        }
    } else {
        char temparray[MAXSTRING];
        char temp;
        int i;
        for(i = 0; s[i] != '\0'; i++); //skip over things that are relevant
        temp = s[0];
        s[0] = s[i-1];
        s[i-1] = temp;
        long j;
        for(j = 1; j < i-1; j++) {
            temparray[j-1] = s[j];
        }
        reverse(temparray);
        for(j = 1; j < i-1; j++) {
            s[j] = temparray[j-1];
        }
    }
}