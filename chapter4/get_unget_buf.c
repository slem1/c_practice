#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

#define NUMBER '0'
#define MAXVAL 100
#define MAX_LINE 1000

double atof_scientific(char s[]);
void ungetchs(char s[]);
void ungetch_all();
int getLine(char s[]);

void playstack();

int getch();
int getopt(char[]);

int buf[BUFSIZE];
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


int main(){
    playstack();

    ungetch_all();

    char line[10000];

    while(getLine(line)){

       getopt(line)
    }
    
}

void playstack(){

    push(4);

    push(5);

  //  printStack();

    printTopStack();

    swaptop();

   // printStack();

    duplicateTopStack();

    printStack();

}


void ungetch_all(){

    ungetchs("laplace");

    for(int i =0; i<8; i++){
        int c = getch();
        printf("%c\n", c);
    }
}


void calculator(){
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

void ungetchs(char s[]){

    for(int i=0; s[i] != '\0'; i++){
        ungetch(s[i]);
    }
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



