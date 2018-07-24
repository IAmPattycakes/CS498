/*Make a program that lists all the variable names, and groups them up with other variables
that have a similar number of characters at the start. Variables have to start
with a letter, and can be alphanumeric after that, and cannot be within quotes
or comments, and cannot be the same as C keywords. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NKEYS 32
#define BUFSIZE 1000000
#define MAXSIMILAR 1000
#define MAXOCCURRANCES 100000

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
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "else", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

struct tnode {
    char *word;
    int count;
    char *to;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);


void skipComments();
void skipQuotes();
int getword(char *, int);
int binsearch(char *, struct key *, int);
void ungetch(int);
int getch();
int buf[BUFSIZE];
int bufp = 0;
int linenumber = 1;


int main(void)
{
    struct tnode *root;
    int docBuffer[BUFSIZE], docp = 0;
    char word[MAXWORD], c;
    
    /*First pass through the document, searching for #defines*/
    
    while((c = getch()) != EOF) {
        if(c == '#') { //See if next word is 'define'
            docBuffer[docp++] = c;
            getword(word, MAXWORD);
            if(strcmp(word, "define") == 0) { 
                char *newword;
                struct tnode *node = addtree(root, (newword = getword(word, MAXWORD)));
                for(i = strlen(s) - 1; i >= 0; i++) {
            		docBuffer[docp++] = *newword++;
            	}
            }
        }
    }
    
    
    
    /*Second pass through the document, searching for the things defined and swapping them out.*/
    
    
    
    
    
    
    root = NULL;
    while(getword(word, MAXWORD) != EOF) {
        if(isalpha(word[0])) {
            if(binsearch(word, keytab, NKEYS) == -1) {//Could not be found in the keywords
                root = addtree(root, word);
            }
        }
    }
    treeprint(root);
    
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    
    if(p == NULL) {
        p = talloc();
        p -> word = strdup(w);
        p -> count = 1;
        p -> left = p -> right = NULL;
    } else if((cond = strcmp(w, p->word)) == 0) {
        p -> count++;
    } else if(cond < 0) {
        p -> left = addtree(p->left, w);
    } else 
        p-> right = addtree(p->right, w);
    return p;
}

void treeprint(struct tnode *p)
{
    if(p != NULL) {
        treeprint(p->left);
        printf("%s", p->word);
        printf("\n");
        treeprint(p->right);
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
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
    while(isspace(c = getch())) { //Skip over whitespace
        if(c == '\n') {
            linenumber++;
        }
    }
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
        linenumber++;
    } else if(c == '*') { //has hit '/*' and needs to find the '*/'
        int actualEnd = 0;
        while(actualEnd < 1) { //Looking for the * in */
            if((c = getch()) == '*') {
                if((c = getch()) == '/') {
                    actualEnd = 1; //Breaks out of the while. 
                } else ungetch(c);
            } else if(c == '\n') {
                linenumber++;
            }
        }
    } else {
        ungetch(c);
    }
}

void skipQuotes()
{
    int c;
    while((c = getchar()) != '\"' && c != EOF) { //Skips until the next quotation mark.
        if(c == '\n') {
            linenumber++;
        }
    } 
    if(c == EOF) ungetch(c);
}
