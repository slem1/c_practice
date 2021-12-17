#include <stdio.h>


#define TAB_LENGTH 4

void exercice1_20();

int main(){
    exercice1_20();
}

void exercice1_20(){

    int c;

    while((c = getchar()) != EOF){
        if(c == '\t'){
            for (int i=0;i<TAB_LENGTH;i++){
                putchar(' ');
            }
        } else {
                putchar(c);
        }    
    }
}