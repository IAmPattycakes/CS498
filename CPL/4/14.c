#include <stdio.h>

#define swap(t, x, y) ({t a = (x); (x = (y));printf("%d\n", x); (y = (a));})

int main()
{
    int a = 2;
    int b = 4;
    swap(int, a, b);
    printf("%d %d\n", a, b);
}