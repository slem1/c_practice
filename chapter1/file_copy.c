#include <stdio.h>

int main(){
    oneWordPerLine();
  
}



int countChars(){

    long nc;    

    for(nc=0; getchar() != EOF; ++nc);

    printf("%ld", nc);

}

int countLines(){

    long nl = 0;  

    int c;  

    while((c = getchar()) != EOF){
        if(c == '\n'){
            nl++;
        }
    }    

    printf("%ld", nl);

}

int readAndPrint(){
    int c;

    printf("%d", EOF);

    while ((c = getchar()) != EOF){
        putchar(c);        
    }
}

#define IN 1
#define OUT 0

int wc(){    

    int nw , nc , nl ,state, c;

    nw = nc = nl = 0;

    while((c = getchar()) != EOF){
        nc++;
        
        if(c == '\n'){
            nl++;
        }

        if(c == ' ' || c=='\t' || c=='\n' ){
            state = OUT;
        } else if(state == OUT){
            state=IN;
            nw++;
        }
    }

    printf("%d %d %d", nl, nw, nc);    
}

int oneWordPerLine(){    

    int nw , nc , nl ,state, c;

    nw = nc = nl = 0;

    while((c = getchar()) != EOF){
        nc++;
        
        if(c == '\n'){
            nl++;
        }

        if(c == ' ' || c=='\t' || c=='\n' ){        
            if(state == IN){
                putchar('\n');
            }
            state = OUT;           
            
            
        } else if(state == OUT){
            state=IN;
            nw++;            
        }

        if(state == IN){
            putchar(c);
        }
    }

    printf("%d %d %d", nl, nw, nc);    
}