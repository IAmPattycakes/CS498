#include <stdio.h>

//I pipe inputs into this program using commands like "cat 6.c | a.out" to test
//file input
main() 
{
  int c, n;
  
  n = 0;
  while((c = getchar()) != EOF)
  {
    if(c == '\t') printf("\\t");
    else
    {
      if(c == '\b') printf("\\b"); //I couldn't figure out how to give it a backspace
      else
      {
        if(c == '\\') printf("\\\\");
        else
        {
          if(c == '\n') printf("\\n");
          else putchar(c);
        }
      }
    }
  }
}
