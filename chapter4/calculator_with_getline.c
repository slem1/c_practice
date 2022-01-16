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
void calculator();

void playstack();

int getch();
int getopt(char s[], char input[]);

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

int position = 0;

int main(){
    
    char input_buf[100];

    char input[100] = "10 15 *";

    calculator();


    
}

void calculator(){

    char line[100];
    char input_buf[100];
    int type;
    double op2;

    while(getLine(line)){    

        position = 0;
        type =0;

        while(type != '\n'){
            type = getopt(input_buf,line);

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
}

int getopt(char s[], char input[]){

    int c;
    while((c = s[0] = input[position++]) == ' ' || c == '\t');

    s[1] = '\0';

    if(input[position] == '\0'){
        position--;
        return '\n';
    }

    if(!isdigit(c)){
        return c;
    }

    position--;

    int i = 0;

    if(isdigit(s[0])){    
        while(isdigit(s[++i] = c = input[++position]));
    }

    s[i] = '\0';

    return NUMBER;

}

