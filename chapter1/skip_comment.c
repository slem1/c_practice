#include <stdio.h>

#define CODE 0
#define FIRST_CHAR_COMMENT 1
#define LINE_COMMENT 2
#define BLOCK_COMMENT 2

int solution1();

int main(){
   
    solution1();
}

void readLineComment(){
    int c;
    while((c=getchar())!= EOF && c != '\n');        
}

void readLitteral(){
    int c;
    while((c=getchar())!= EOF && c != '\''){
        putchar(c);
    }

    putchar('\'');       
}

void readBlockComment(){

    int previousChar;
    int c;
    while((c=getchar())!= EOF){
        if( c == '*'){
            previousChar = c;
        }else if(c == '/' && previousChar == '*'){
            return;
        }
    }
}

int solution1()
{
    int c;
   
    int state = CODE;
   
    int previous;

    while((c=getchar()) != EOF){

        if(c == '\''){
            putchar(c);
            readLitteral();
            continue;
        }

        if(previous == '/') {
            if( c == '/'){
                readLineComment();
                previous='\0';
                continue;
            }else if(c == '*'){
                readBlockComment();
                previous='\0';
                continue;
            }else {
                putchar(previous);
            }                          
        }       

        if(c != '/'){
            putchar(c);
        }

        previous = c;
    }
}