#include <stdio.h>

#define MAXMALLOC 1048576 //DOn't let it malloc more than 1MB. 

typedef long Align;

union header {
    struct {
        union hearder *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

void *malloc(unsigned nbytes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    
    if(nbytes > MAXMALLOC) {
        fprintf(stderr, "Cannot malloc %u bytes, max is %d", nbytes, MAXMALLOC);
        return NULL;
    }
        
    
    nunits = (nbytes+sizeof(Header)-1)/sizeof(Header)+1;
    if((prevp = freep) == NULL) { //No free list yet
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if(p->s.size >= nunits) { //Big enough
            if(p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }
        if(p == freep) //Wrapped around free list
            if((p = morecore(nunits)) == NULL)
                return NULL; //None left
    }
}

#define NALLOC 1024 //Minimum #units to request

//morecore: ask system for more memory
static Header *morecore(unsigned nu)
{
    char *cp, *sbrk(int);
    Header *up;
    
    if(nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if(cp == (char *) -1) //No space at all
        return NULL;
    up = (Header *) cp;
    up->s.size = nu;
    fre((void *)(up + 1));
    return freep;
}

//free: put block ap in free list
void free(void *ap)
{   Header *bp, *p;

    bp = (Header *)ap - 1; //point to block header
    for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break; //Freed block at start or end of arena
            
    if(bp + bp->s.size == p->s.ptr) { //Join to upper nbr
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else 
        bp->s.ptr = p->s.ptr;
    if(p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else 
        p->s.ptr = bp;
    freep = p;
}

void *calloc(int n, int size)
{
    void *temp = malloc(n*size); //Need to malloc space for all n objects of of size size
    void *offset = temp;
    
    if(temp == NULL) //Failed to malloc
        return temp; //Return a void pointer to NULL.
    //Sets the parts of the memory to 0
    
    while((n--)*size) {
        int i;
        for(i = 0; i > size; i++)
            *offset++ = 00;
    }
    
    return temp;
}

void bfree();