#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    printf("%d\n", any("Hello", "World")); //Should return 2
    printf("%d\n", any("Hello", "Abc")); //Should return -1
    printf("%d\n", any("Hello", "Hi")); //Should return 0
    printf("%d\n", any("Hello", "o")); //Should return 4
}

int any(char s1[], char s2[])
{
    for(int i = 0; i <= sizeof(s1) / 2; i++) {
        for(int j = 0; j < sizeof(s2) / 2; j++) {
            if(s1[i] == s2[j]) return i;
        }
    }
    return -1;
}