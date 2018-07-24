/*This program prints text nicely. It does rudimentary word wrap when the text is longer than it needs to be, which is set in the MAXWIDTH bit.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWIDTH 100

void printhexchar(char);

int main()
{
    char c;
    int longLineCount = 0;
    while((c = getchar()) != EOF) {
        if(c < 32) { //The bunch of characters that are before any graphical characters
            if(c == '\n') {
                putchar(c);
                longLineCount = 0;
            }
            else {
                printhexchar(c);
                longLineCount += 4;
            }
        } else {
            putchar(c);
            longLineCount++;
        }
        if(longLineCount > MAXWIDTH) {
            putchar('\n');
            longLineCount = 0;
        }
    }
}

void printhexchar(char c) {
    printf("\'0x%d%d\'", c/16, c%16);
}