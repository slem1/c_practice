#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

#define NUMBER '0'
#define MAXVAL 100

double atof_scientific(char s[]);

int getch();
int getopt(char[]);

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

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

void printHead(){
    if(sp > 0){
        printf("stack head is %g\n", val[sp-1]);
    }
}

int main(){
    char input_buf[100];
    int type;
    double op2;

    while((type = getopt(input_buf)) != EOF){
        switch(type){
            case NUMBER: 
                push(atof_scientific(input_buf));
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
            case '\n': 
                printf("result is %g\n", pop());
            break;
            default:
                printf("unknow command: %s\n", input_buf);
                break;
        }
    }
    
}

int getch(){
    if(bufp > 0){
        return buf[--bufp];
    }else{
        return getchar();
    }
}

void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters");
    }
    buf[bufp++] = c;
}

int getopt(char s[]){

    // printf("buf[%d] = %d \n", bufp, buf[bufp - 1]);
    int c;
    while((c = s[0] = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if(!isdigit(c)){
        return c;
    }

    int i = 0;

    if(isdigit(s[0])){    
        while(isdigit(s[++i] = c = getch()));
    }

    if(s[i] == '.'){
        while(isdigit(s[++i] = c = getch()));        
    }

    if(c != EOF){
      //  printf("unget of %d\n", c);
        ungetch(c);
    }

    s[++i] = '\0';

    return NUMBER;

}