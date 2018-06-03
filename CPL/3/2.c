#include <stdio.h>

void escape(char s[], char t[]);
char testString[] = "THis is a\ttest of \ttabs and \n some \n newlines";

char outputString[100];

int main()
{
	printf("%s\n\n\n", testString);
	escape(outputString, testString);
	printf("%s\n\n\n", outputString);
}

void escape(char s[], char t[])
{
	int i, j;
	i = 0;
	j = 0;
	char c;
	while((c = t[i]) != '\0') {
		switch (c) {
			case '\n': s[j++] = '\\'; s[j] = 'n'; break;
			case '\t': s[j++] = '\\'; s[j] = 't'; break;
			//case '\n': s[j] = "\\n"; break;
			//case '\t': s[j] = "\\t"; break;
			default: s[j] = c;
		}
		i++;
		j++;
	}
}