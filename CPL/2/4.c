#include <stdio.h>
void squeeze(char s[], char c[]);
int main()
{
	char s[] = "abcd1234";
	squeeze(s, "abc123");
	printf("%s", s);
}

void squeeze(char s[], char s2[])
{
	int i, j;
	int flag = 0;
	for(int i = j = 0; s[i] != '\0'; i++) {
		for(int k = 0; s2[k] != '\0'; k++) {
			if(s[i] == s2[k]) flag = 1;
		}
		if(!flag) s[j++] = s[i];
		flag = 0;
	}
	s[j] = '\0';
}