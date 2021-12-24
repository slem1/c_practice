#include <stdio.h>

#define MAX_LINE 1000

int strindex(char s[], char t[]);
int getLine(char s[]);
int strindex_rightmost_0(char s[], char t[]);

int main(){

    char s[MAX_LINE];

    while(getLine(s)){        
        if(strindex(s, "world") != -1){
            printf("%s", s);
        }
     }    

    //strindex_rightmost_0("hello world", "hello");

}


int getLine(char s[]){

    int i = 0;

    int c;

    while( (c = getchar()) != EOF && i < MAX_LINE-1 && c!= '\n'){        
        s[i++] = c;        
    }

    if(c == '\n'){
        s[i++] = c;        
    }

    s[i] = '\0';

}




