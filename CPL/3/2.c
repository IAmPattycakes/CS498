#include <stdio.h>

void escape(char s[], char t[]);

int main()
{

}

void escape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while((char c = t[i]) != '\0') {
		switch (c) {
			case '\n':
			case '\t':
			default:
		}
		i++;
		j++;
	}
}