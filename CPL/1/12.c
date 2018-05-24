#include <stdio.h>

//I pipe inputs into this program using commands like "cat 6.c | a.out" to test file input
// This     is   a    piece   of   text with    multiple    spaces
main() 
{
  int c, n;
  
  n = 0;
  while((c = getchar()) != EOF)
  {
    if(c == ' ' || c == '\t' || c == '\n') n++; //increase the number of blanks
    else //if character is not a blank
    {
      if(n > 0)//There was spaces beforehand
      {
        n = 0;
        putchar('\n');
        putchar(c);
      } 
      else putchar(c);
    }
  }
}
