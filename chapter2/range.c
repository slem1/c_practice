#include <stdio.h>

int main()
{
    //1111 1111
    //signed char
   
    maximum_int();
}

void maximum_char() {
    //maximum char
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
    }
}

void maximum_int() {
   
    unsigned int check = (unsigned int)~0 ;
   
    printf("check: %u\n", check);
   
    //maximum char
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
    }
    printf("maximum value for int: %d  \n", max);
}
