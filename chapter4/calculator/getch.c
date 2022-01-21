#include <stdio.h>

#define BUFSIZE 100

static int buf[BUFSIZE];
static int bufp = 0;

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