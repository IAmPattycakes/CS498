#include <stdio.h>

void escape(char s[], char t[]);
void contract(char s[], char t[]);
char testString[] = "THis is a\ttest of \ttabs and \n some \n newlines";

char outputString[100];
char outputString2[100];

int main()
{
	printf("%s\n\n\n", testString);
	escape(outputString, testString);
	printf("%s\n\n\n", outputString);
	contract(outputString2, outputString);
	printf("%s\n\n\n", outputString2);
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
			default: s[j] = c;
		}
		i++;
		j++;
	}
}

void contract(char s[], char t[])
{
	int i, j;
	i = j = 0;
	char c;
	while((c = t[i]) != '\0') {
		switch (c) {
			case '\\':
				if(t[++i] == 'n') s[j] = '\n';
				else if(t[i] == 't') s[j] = '\t';
				else if(t[i] == '\\') s[j] = '\\';
			break;
			default:
				s[j] = c;
			break;
		}
		i++;
		j++;
	}
}