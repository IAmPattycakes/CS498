#include <stdio.h>

#define swap(t, x, y) t TEMP = (x); x = (y); y = TEMP

int main()
{
    int a = 2;
    int b = 4;
    swap(int, a, b);
    printf("%d %d\n", a, b);
}