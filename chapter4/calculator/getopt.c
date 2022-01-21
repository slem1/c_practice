#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getopt(char s[]){

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
        ungetch(c);
    }

    s[++i] = '\0';

    return NUMBER;
}