#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
    char big[100];
    char s[] = "a-z\nB-S\na-2\n3-8";
    printf("%s\n\n", s);
    expand(s, big);
    printf("%s\n\n", big);
}

void expand(char s1[], char s2[])
{
    int i = 0; //Keeps track of position in s1 
    int j = 0; //Keeps track of position in s2
    char c = 'a';
    while((c = s1[i]) != '\0') {
        switch(c) {
            case '-': //Need to check for valid notation
                if((s1[i - 1] >= '0' && s1[i + 1] <= '9') ||
                    (s1[i - 1] >= 'a' && s1[i + 1] <= 'z') ||
                    (s1[i - 1] >= 'A' && s1[i + 1] <= 'Z')) {
                    
                    char counter = s1[i - 1] + 1;
                    while(counter < s1[i+1]) {
                        s2[j++] = counter;
                        counter++;
                    }
                } else s2[j] = c;
            break;
            default:
                s2[j] = c;
            break;
        }
        i++;
        j++;
    }
}