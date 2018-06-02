#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main()
{
    printf("%d\n", setbits(0xFF, 2, 4, 0x00));
    printf("%d\n", setbits(0xF00F, 4, 8, 0x0FF0));
}

int setbits(int x, int p, int n, int y)
{
    while(n != 0) {
        if((x >> p) & 01 == 1) {
            //If x bit is 1 and y bit is 0, set to 0 else ignore
            if(!((y >> p) & 01)){
                x -= 1 << p;
            } 
        }
        else if((y >> p) & 01 == 1) x += 1 << p;
        n--;
        p++;
    }
    return x;
}