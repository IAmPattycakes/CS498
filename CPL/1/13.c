#include <stdio.h>

//I pipe inputs into this program using commands like "cat 6.c | a.out" to test file input
// This     is   a    piece   of   text with    multiple    spaces

main() 
{
  int c, n, w;
  int words[20];
  n = 0;
  w = 0;
  for(int i = 0; i < 20; i++) words[i] = 0;
  
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\t' || c == '\n') {
      if(w > 0) words[w]++;
      n++; //increase the number of blanks
      w = 0; //Letters in word are now 0
    }
    else { //if character is not a blank
      if(n > 0) { //There was spaces beforehand
        n = 0;    // Sets blanks to 0
        w = 1;
      } 
      else w++;
    }
  }
  
  for(int i = 0; i < 20; i++) {
    if(words[i] != 0) {
      printf("%d\t", i);
      for(int j = 0; j < words[i]; j++) {
        printf("#");
      }
      printf("\n");
    }
  }
}
