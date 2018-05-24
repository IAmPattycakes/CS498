#include <stdio.h>

//I pipe inputs into this program using commands like "cat 6.c | a.out" to test
//EOF characters, as those can't really be typed reasonably. 

main() 
{
  int c;
  
  while((c = getchar()) != EOF) putchar(c);
  putchar(c); //EOF character shows up as a questionmark box in the terminal. 
  printf("\n%d", c);  //EOF shows up as -1 for it's integer value. 
}
