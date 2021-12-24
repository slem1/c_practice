#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]){

    if(strlen(t) == 0 || strlen(s) == 0){
        return -1;
    }

    int k;
    int j;

    for(int i = 0; s[i] != '\0'; i++){

        k = i;

        for(j=0; t[j] != '\0' && t[j] == s[k]; j++, k++ ){
             //printf("comparaison de t[%d]=%c avec s[%d]=%c \n", j, t[j], k, s[k]);
        }

        if(t[j] == '\0'){
            return i;
        }
    }

    return -1;
}

int strindex_rightmost_0(char s[], char t[]){

    int lnOfT;
    int lnOfS;

    if((lnOfT = strlen(t)) == 0 || (lnOfS = strlen(s)) == 0){
        return -1;
    }    

    int k;
    int j;

    for(int i = lnOfS - 1; i > 0; i--){

        k = i;

        for(j=lnOfT - 1 ; j >= 0 && t[j] == s[k]; j--, k-- ){
//             printf("comparaison de t[%d]=%c avec s[%d]=%c \n", j, t[j], k, s[k]);
        }

            
        if(j < 0){
  //          printf("rightmost occurence of %s found at %d", t, k + 1);
            return k + 1;
        }
    }

    return -1;
}