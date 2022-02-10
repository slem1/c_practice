#include <stdio.h>

int main(){



}

int strlen(char* s){
    
    int i;

    for(i = 0; *s != '\0'; s++){
        i++;
    }

    return i;
}