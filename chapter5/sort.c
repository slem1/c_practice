#include <stdio.h>

#define LINE_MAX_SIZE 1000

int _getline(char *line);

int main(){

    char line[LINE_MAX_SIZE];

    while(_getline(line) != EOF){
        printf("%s", line);
    }
}

int _getline(char *line){

    int c;

    while((c=getchar()) != EOF){
        *line++ = c;

        if(c == '\n'){
            *line = '\0';
            return c;
        }
    }

    return EOF;
}