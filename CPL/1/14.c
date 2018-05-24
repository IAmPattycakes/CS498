#include <stdio.h>

//I pipe inputs into this program using commands like "cat 6.c | a.out" to test file input
// This     is   a    piece   of   text with    multiple    spaces

int main() 
{
  int c, n, w;
  int words[2000];
  n = 0;
  w = 0;
  for(int i = 0; i < 2000; i++) words[i] = 0;
  
  while((c = getchar()) != EOF) {
    words[c]++;
  }
  
  for(int i = 0; i < 2000; i++) {
    if(words[i] != 0) {
      if(i == '\n') printf("\\n");
      else if(i == '\b') printf("\\b");
      else if(i == '\t') printf("\\t");
      else {
        putchar(i);
      }
      printf("\t");
      for(int j = 0; j < words[i]; j++) {
        printf("#");
      }
      printf("\n");
    }
  }
}
