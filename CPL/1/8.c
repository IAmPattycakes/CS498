#include <stdio.h>

//I pipe inputs into this program using commands like "cat 6.c | a.out" to test
//file input
main() 
{
  int c, n;
  
  n = 0;
  while((c = getchar()) != EOF)
  {
    if(c == '\n' || c == ' ' || c == '\t') n++;
  }
  printf("%d\n", n);
}
