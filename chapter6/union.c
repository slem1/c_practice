#include <stdio.h>

struct number {
    unsigned int isInteger : 1;
    unsigned int isDouble : 1;
    union {
        int e;
        double d;
    };
};

void printNumber(struct number n);

union my_union{
    int e;
    double d;
} u;


int main(){

    u.e = 100;

    u.d = 30;

    printf("%f\n", u.d);

    printf("%d\n", u.e);

    int k = (int) u.d;

    printf("%d\n", k);

    struct number n;

    n.isInteger = 1;
    n.e = 50;
    printNumber(n);    

}

void printNumber(struct number n){

    if(n.isInteger){
        printf("%d\n", n.e);
    }else if(n.isDouble){
        printf("%f\n", n.d);    
    }   
}