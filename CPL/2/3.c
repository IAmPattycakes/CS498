#include <stdio.h>

long htoi(char str[]);

int main()
{
	printf("%ld\n", htoi("1234"));
	printf("%ld\n", htoi("ABCD"));
	printf("%ld\n", htoi("abcd"));
	printf("%ld\n", htoi("a1b2"));
	printf("%ld\n", htoi("BEEF"));
}

long htoi(char str[])
{
	long total = 0;
	int start = (sizeof(str) / 2) - 1;
	int offset = 1;
	for(int i = start; i >-1; --i) {
		int temp;
		if((temp = str[i] - 48) < 10) {
			total += temp * offset;
		} else if((temp = str[i] - 65) < 6) {
			total += (10 + temp) * offset;
		} else if((temp = str[i] - 97) < 6) {
			total += (10 + temp) * offset;
		}
		offset = offset * 16;
	}
	return total;
}