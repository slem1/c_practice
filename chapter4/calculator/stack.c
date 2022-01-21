#include<stdio.h>

#include "calc.h"

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

void push(double v){
    if(sp == MAXVAL){
        printf("cannot push %g on stack", v);
    } else {
        val[sp++]=v;
    }
}

double pop(){
    if(sp > 0){
        return val[--sp];
    }else {
        printf("stack is empty");
        return 0.0;
    }
}

void printTopStack(){
    if(sp > 0){
        printf("stack head is %g\n", val[sp-1]);
    }
}

void duplicateTopStack(){
    if(sp > 0){
        push(val[sp-1]);
    }
}

void swaptop(){
    if(sp > 1){
        double top = pop();
        double previous = pop();
        push(top);
        push(previous);
    }
}

void clear(stack){
    sp = 0;
}

void printStack(){
    for(int i=0; i < sp; i++){
        printf("stack[%d]=%g\n", sp, val[i]);
    }
}