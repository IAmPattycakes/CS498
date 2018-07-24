#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define IN 1

struct nlist {
    struct nlist *next;
    char *name;
    char *denf;
};

static struct nlist *hashtab[HASHSIZE];

int main() // ¯\_(ツ)_/¯
{
    printf("\n");
}

/*hash: form hash valuse for string s*/
unsigned hash(char *s) 
{
    unsigned hashval;
    
    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/*lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    
    for(np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if(strcmp(s, np->name) == 0)
            return np;
    }
    return NULL;
}

/*install: put (name , defn) in hashtab*/
struct nlist *install(char *name, char *defn) 
{
    struct nlist *np;
    unsigned hashval;
    
    if((np = lookup(name)) = NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np -> name = strdup(name)) = NULL)
            return NULL;
        hashval = hash(name);
        np -> next = hashtab[hashval];
        hashtab[hashval] = np;
    } else 
        free((void *) np -> defn); //Free previous defn
    if((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void undef(char *s) 
{
    struct nlist *np;
    struct nlist *npprev;
    
    for(np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if(strcmp(s, np->name) == 0) {
            npprev->next = np->next;
            free((void *) np -> defn);
            free((void *) np -> name);
            free(np);
            return;
        } else {
            npprev = np;
        }
    }
    return NULL;
}