#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

//print longest input line
int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  while((len = getLine(line, MAXLINE)) > 0) {
    
    printf("%s", line);    
    
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

int goodLine(char s[])
{
	for()
}