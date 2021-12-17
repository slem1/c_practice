#include <stdio.h>

unsigned int getBits(unsigned int, int,  int);
// unsigned char setBits(unsigned char x, int p, unsigned char y, int n);   
unsigned int setBitsInt(unsigned int x, int p, unsigned int y, int n);

unsigned int invert(unsigned int x, int p, int n);

int main(){

    //0000 0000
    //1111 1111
    //0000 0000 + 1 = -(0000 0001)

    //0010 1010 
    //1101 0101
    //0010 1010 + 1 = -(00101011) = -(42 + 1) = -43

    //unsigned int i = 0;
    //unsigned int j = ~i;

    int i = 42;
    int j = ~i;

    //printf("valeur de j: %d",j);

    unsigned int x = setBitsInt(225,0,42,4);

    printf("valeur setBitsInt(255,0,42,4) est %d \n",x);


    printf("valeur inversé: %d", invert(42,1,4));


}

//return n bits from p position
unsigned int getBits(unsigned int x, int n,  int p){    

    return (x >> p ) & ~(~0 << n);
}

unsigned int setBitsInt(unsigned int x, int p, unsigned int y, int n){    
    unsigned int rightMostNOfY =  y & ~(~0 << n);
    return (x & (~0 << n)) | (y << p);    
}

unsigned int invert(unsigned int x, int p, int n){    
    unsigned int nullifyPart = setBitsInt(x,p,0,n);   
    unsigned int mask = ~(~0 << n);
    unsigned int tmp = ~((x >> p) & mask) & ~(~0 << n);
    return nullifyPart | (tmp << p);    
}