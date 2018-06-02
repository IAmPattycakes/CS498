#include <stdio.h>

int invert(int x, int p, int n);

int main()
{
    printf("%d\n", invert(0xFF, 2, 4));
    printf("%d\n", invert(0xF00F, 4, 8));
}

int invert(int x, int p, int n)
{
    while(n != 0) {
        if((x >> p) & 01 == 1) x -= 1 << p;
        else x += 1 << p;
        n--;
        p++;
    }
    return x;
}