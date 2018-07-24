#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

//print longest input line
int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = getLine(line, MAXLINE)) > 0) {
    max = len;
    reverse(line);
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

void reverse(char s[])
{
	char reversal[MAXLINE];
  int high, low;

  high = 0;
  low = 0;
  while(s[high] != '\0') ++high;
  --high;
  while(s[low] != '\0') {
    reversal[high] = s[low];
    low++;
    high--;
  }
  reversal[low] = '\0';

  for(int i = 0; i < 200; i++) {
  	s[i] = reversal[i];
  }
}
