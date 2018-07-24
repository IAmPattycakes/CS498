/* THis program converts a file to all lowercase using the -l flag, and to all 
uppercase using the -u flag. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc > 1) {
        if(strcmp(argv[1], "-l") == 0) {
            int c;
            
            while((c = getchar()) != EOF)
                putchar(tolower(c));
            return 0;
        } else if(strcmp(argv[1], "-u") == 0) {
            int c;
        
            while((c = getchar()) != EOF)
                putchar(toupper(c));
            return 0;
        } else {
            printf("Improper flag: %s. Quitting.\n", argv[1]);
        }
    } else {
        printf("Not enough flags");
    }
}