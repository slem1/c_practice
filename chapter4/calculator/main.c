#include <stdio.h>

#include "calc.h"

int main(){

    sp = 3;
    char input_buf[100];
    int type;
    double op2;

    while((type = getopt(input_buf)) != EOF){
        switch(type){
            case NUMBER: 
                push(atof(input_buf));
            break;
            case '+': 
                push(pop() + pop());
            break;
            case '-':
                op2 = pop();
                push(pop() - op2);
            break;
            case '*':
                push(pop() * pop());
            break;
            case '/':
                op2 = pop();
                if(op2 != 0){
                    push(pop() / op2);
                }else {
                    printf("error: zero divisor");
                }
            break;
            case '%':
                op2 = pop();

                if(op2 != 0){
                    push((int)pop() % (int)op2);
                }else {
                    printf("error: zero divisor (modulus)");
                }
            break;
            case '\n': 
                printf("result is %g\n", pop());
            break;
            default:
                printf("unknow command: %s\n", input_buf);
                break;
        }
    }
}