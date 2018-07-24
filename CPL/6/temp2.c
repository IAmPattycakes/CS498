/* This program displays groups of variables that have similar initial n characters, 
where n can be set from an argument in the command line. */
/*THis is a temporary testing file to see if I can write it with mostly original
code, because I always end up getting seg faults with the textbook code */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define BUFSIZE 100


void skipComments();
void skipQuotes();
int getword(char *, int);

//Variables for getch and ungetch
char buf[BUFSIZE];
int bufp = 0;

struct charTrie {
    int ending;
    struct charTrie[26];
}


int main()
{
    
}

/*skipComments: Skips through the characters to see if it is a comment and quits 
when it hits the end of the comment or EOF.*/
void skipComments()
{
    int c;
    if((c = getch()) == '/') { //has hit "//" and needs to skip to the next line.
        while((c = getch()) != '\n');
    } else if(c == '*') { //has hit '/*' and needs to find the '*/'
        int actualEnd = 0;
        while(actualEnd < 1) { //Looking for the * in */
            if((c = getch()) == '*') {
                if((c = getch()) == '/') {
                    actualEnd = 1; //Breaks out of the while. 
                } else ungetch(c);
            }
        }
    }
}

void skipQuotes()
{
    int c;
    while((c = getchar()) != '\"' && c != EOF); //Skips until the next quotation mark. 
    if(c == EOF) ungetch(c);
}

int getword(char *word, int lim) 
{
    int c;
    char *w = word;
    while(isspace(c = getch())); //Skip over whitespace
    
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)) { //First character is not a letter
        if(c == '\"') {
            
            skipQuotes(w);
        } else if(c == '/') {
            skipComments(w);
        }
        *w = '\0';
        return c;
    }
    for(; --lim > 0; w++) 
        if(!isalnum(*w = getch()) && *w != '_') {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}


int getch() {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}