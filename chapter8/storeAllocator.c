#include <stdio.h>


typedef long Align;

union header {
    struct {
        unsigned size;
        union header *ptr;
    } s;
    Align x;

};

typedef union header Header;

static Header base;
static Header *freep = NULL;

void * _malloc(unsigned nbytes){
    Header *p, *prevp = freep;
    Header *morecore(unsigned);
    unsigned nunits;

    nunits = (sizeof(Header) + nbytes -1)/sizeof(Header) +1;

    if(prevp == NULL){
        base.s.ptr = freep =prevp = &base;
        base.s.size = 0;

    }


}

int main(){


}