#include <stdio.h>

void maximum_signed_int();
void maximum_char();

int main()
{    
    //computed
    maximum_char();
    maximum_signed_int();

    unsigned int unsignedIntMax = ~0;
    printf("unsigned int max=%u\n", unsignedIntMax);

    int signedIntMin = 1 << 31;
    printf("signed int min=%d\n", signedIntMin);
    printf("signed int max=%d\n", (unsigned int) ~0 >> 1);
    printf("signed int max=%d\n", signedIntMin - 1);


    
}

void maximum_char() {
   
    int howmany = 0;
    int searchMax = 1;
    char c = 1;
    char max = -1;
    char value = 0;
    while(searchMax == 1){
        searchMax = 0;
        c = c * 2;
        value = c - 1;
        if(value > max){
            max = value;
            searchMax = 1;
        }
        howmany++;
    }

    char min = max;
    for(int i=0;i<howmany-1; i++){
        min = min * 2;
    }
    

    printf("max=%d,min=%d\n", max, min);
}

void maximum_signed_int() {     

    int howmany = 0;
    int searchMax = 1;
    int c = 1;
    int max = -1;
    int value = 0;
    while(searchMax == 1){
        searchMax = 0;
        c = c * 2;
        value = c - 1;
        if(value > max){
            max = value;
            searchMax = 1;
        }
          howmany++;
    }

    int min = max;
    for(int i=0;i<howmany-1; i++){
        min = min * 2;
    }

    printf("(signed int)min=%d,max=%d\n", min, max);
}
