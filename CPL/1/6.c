#include <stdio.h>

//I pipe inputs into this program using commands like "cat 6.c | a.out" to test
//EOF characters, as those can't really be typed reasonably. 

main() 
{
  int c;
  if(getchar() != EOF) printf("1\n"); //getchar() != EOF will be 1 when the character is not EOF.
  else printf("0\n");
  while((c = getchar()) != EOF) putchar(c);
}
