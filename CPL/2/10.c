#include <stdio.h>

void lower(char s[]);

int main()
{
	char s1[] = "This is a test";
	char s2[] = "Random CHaracters;'123!@##";
	lower(s1);
	lower(s2);
	printf("%s\n%s\n", s1, s2);
}

void lower(char s[])
{
	for(int i = 0; s[i] != '\0'; i++) {
		(s[i] >= 65 && s[i] <= 90) ? s[i] += 32 : s[i];
	}
}
