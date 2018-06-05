#include <stdio.h>

int strrindex(char s[], char t[]);

int main()
{
    char s[] = "Lorem ipsum dolor sit amet I don\'t remember any of the other words";
    printf("%d\n", strrindex(s, "or"));
    printf("%d\n", strrindex(s, "aaa"));
    printf("%d\n", strrindex(s, "words"));
}

int strrindex(char s[], char t[])
{
    char c; 
    int i, j, ret, pos;
    
    ret = -1;
    i = j = 0;
    while((c = s[i]) != '\0') {
        if(c == t[j]) {
            if(!j) pos = i;
            j++;
            if(t[j] == '\0') ret = pos;
        }
        else j = 0;
        i++;
    }
    return ret;
}