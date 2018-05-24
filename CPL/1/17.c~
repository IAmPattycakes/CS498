#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

//prints all lines that are above 80 characters. For example, this line is above 80 characters.
//This line is not above 80 characters, so it shouldn't show up. 
//When this file is fed into the program it should only show two really long comment lines 
int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = getLine(line, MAXLINE)) > 0) {
    if(len > 80) {
      copy(longest, line);
      printf("%s", longest);
    }
  }
  return 0;
}

//getline : read a line into s, return length
int getLine(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0') ++i;
}
