#include <stdio.h>

#define SWAP(t,x,y) t y, t x

void function(SWAP(int,a1,a2));

int main(){

    function(1,9);


}

void function(SWAP(int,a1,a2)){
    
    printf("a1=%d,a2=%d\n",a1,a2);
}