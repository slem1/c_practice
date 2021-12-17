#include <stdio.h>
#include <string.h>

void expand(char [], char []);

int main(){

    char s2[100];

    for (int i=0; i< 100; i++){
        s2[i] = 0;
    }
    
    expand("------a-zA-Z-----1-9",s2);
    
}



void expand(char s1[], char s2[]){
    int i = skipHeading(s1);
    char startc = '\0';
    int idxS2 = 0;    
    
    for(;s1[i] != '\0'; i++){                                
        if(startc == '\0'){
            if(s1[i] == '-'){
                s2[idxS2++] = s1[i];                    
            }else {
                startc = s1[i];
            }            
        }else {            
            char nextChar = s1[i + 1];                     
            if(s1[i] == '-' && nextChar != '\0' && startc < nextChar){
                for(char c = startc; c<= nextChar; c++){                    
                    s2[idxS2++] = c;                    
                }
                startc ='\0';
                i++;
            }
        }
    }

    printf("result=%s\n", s2);
}

int skipHeading(char s[]){
    int start = 0;    
    for(;s[start] == '-'; start++);       
    return start;    
}
