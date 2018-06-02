/*
Two's complement removes the rightmost 1-bit in x during the operation
x &= (x - 1) because no matter what, if you remove 1 from the number,
the rightmost digit in binary will change. 0111 - 1 = 0110 where the
right digit did change, and 0110 - 1 = 0101, where the rightmost digit
changed.
*/

#include <stdio.h>

int bitcount(unsigned x);

int main()
{
	printf("%d\n", bitcount(63));
	printf("%d\n", bitcount(64));
}

int bitcount(unsigned x)
{
	int b;

	for(b = 0; x != 0; x >>= 1)
		if(x & 01) b++;
	return b;
}
