#include<stdio.h>

int getLine(char line[], int maxline);

void copy(char dest[], char src[]);

void reverseWord(char input[]);

void exercise119_reverseLine();


#define MAX_LINE 1000

int main(){

    //doMain();
    exercise119_reverseLine();

}

void doMain(){
    char line[MAX_LINE];
    char longest[MAX_LINE];

    int length;

    int maxLength = 0;

    while((length = getLine(line, MAX_LINE)) != 0){
        if(length > maxLength){
            maxLength = length;         
            copy(longest, line);
        }
    }

    if(maxLength > 0){
        printf("Max length is : %s", longest);
    }    
}

void exercise119_reverseLine(){
    char line[MAX_LINE];
    char longest[MAX_LINE];

    int length;

    int maxLength = 0;

    while((length = getLine(line, MAX_LINE)) != 0){
        reverseWord(line);
    }    
}

void reverseWord(char input[]){

    int i=0;

    char output[MAX_LINE];

    while(input[i++] != '\0');

    int end = i-1;

    if(end > 0){
        for(i=0, end = end -1;end >= 0; end--, i++){
            output[i] = input[end];
        }
        output[i] = '\0',
        printf("%s", output);
    }else{
        printf("Empty String");
    }
    
}

int getLine(char line[], int lim){

    int c;
    
    int i = 0;

    while( i<lim - 1 && (c = getchar()) != EOF && c != '\n'){
        line[i++] = c;        
    }

    if(c == '\n'){
        line[i++] = c;                
    }

    line[i] = '\0';
    return i;
}

void copy(char dest[], char src[]){   
    int i = 0;    
    while((dest[i] = src[i]) != '\0'){
        ++i;
    }
}