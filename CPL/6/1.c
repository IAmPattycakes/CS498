#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 12
#define BUFSIZE 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "uint_8t", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

void skipComments();
void skipQuotes();
int getword(char *, int);
int binsearch(char *, struct key *, int);
void ungetch(int);
int getch();
int buf[BUFSIZE];
int bufp = 0;


//Count C keywords
int main(void)
{
    int n;
    char word[MAXWORD];
    
    while(getword(word, MAXWORD) != EOF) 
        if(isalpha(word[0]))
            if((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for(n = 0; n < NKEYS; n++)
        if(keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

/*binsearch: find word in tab[0] ... tab[n-1]*/
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else return mid;
    }
    return -1;
}

/*getword: get next word or character from input*/
int getword(char *word, int lim) 
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while(isspace(c = getch())); //Skip over whitespace
    
    if(c != EOF)
        *w++ = c;
    if(c == '\"')
        skipQuotes(w);
    else if(c == '/')
        skipComments(w);
    if(!isalpha(c) && c != '_') { //First character is neither letter or '_'
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
    } else {
        ungetch(c);
    }
}

void skipQuotes()
{
    int c;
    while((c = getchar()) != '\"' && c != EOF); //Skips until the next quotation mark. 
    if(c == EOF) ungetch(c);
}
