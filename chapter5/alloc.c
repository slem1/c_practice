#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;


char* alloc(int n){

    char * start = allocbuf;

    if(allocp - start + n < ALLOCSIZE ){
        allocp += n;
        return allocp - n;
    }else{
        printf("Cannot allocate %d\n", n);
        return 0;
    }
}

void afree(char *p){

    if(p > allocbuf && p <allocbuf + ALLOCSIZE){
        allocp = p;        
    }
}

int main(){
    
}

