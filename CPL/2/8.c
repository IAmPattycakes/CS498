#include <stdio.h>

int rightrot(int x, int n);

int main()
{
	printf("%d\n", rightrot(100, 3));
	printf("%d\n", rightrot(0xFFFF, 16));
	printf("%d\n", rightrot(0x0F0F, 8));
	printf("%d\n", rightrot(0xFFF0, 4));
}

int rightrot(int x, int n)
{
	int y;
	for(y = x; n > 0; n--) {
		if(y & 01 == 1) {
			//printf("Hello");
			y = y >> 1;
			y += 0x8000;
		} else y >>= 1;
	}
	return y;
}
