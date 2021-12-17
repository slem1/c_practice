#include<stdio.h>

int main(){

    sizeOfWords();

    // int ndigit[10];
    // int nwhite = 0, nother=0;

    // for(int i=0; i<10; i++){
    //     ndigit[i] = 0;
    // }

    // int c;

    // while((c = getchar()) != EOF){
    //     if( c >= '0' && c <='9'){
    //         ++ndigit[c - '0'];
    //     }else if( c == ' ' || c=='\t' || c=='\n'){
    //         ++nwhite;
    //     }else {
    //         ++nother;
    //     }
    // }

    // for(int i=0; i<10; i++){
    //     printf(" %d", i, ndigit[i]);
    // }

}

#define IN 1
#define OUT 0

int sizeOfWords(){    

    int nw , nc , nl ,state, c;

    nw = nc = nl = 0;

    int sizeOfCurrentWord = 0;

    int sizes[10];

    for(int i=0; i<10; i++){
        sizes[i] = 0;
    }

    while((c = getchar()) != EOF){
        nc++;
        
        if(c == '\n'){
            nl++;
        }

        if(c == ' ' || c=='\t' || c=='\n' ){        
            if(state == IN){
                putchar('\n');
                if(sizeOfCurrentWord > 10){
                    sizeOfCurrentWord = 10;
                }
                sizes[sizeOfCurrentWord-1]++;                 
                sizeOfCurrentWord=0;
            }
            state = OUT;           
            
            
        } else if(state == OUT){
            state=IN;
            nw++;            
        }

        if(state == IN){
            putchar(c);
            sizeOfCurrentWord++;
        }
    }

    printf("%d %d %d \n", nl, nw, nc);    

//horizontal histogram
  for(int i=0; i<10; i++){
      printf("%d: ", i+1);
      for(int j=0; j<sizes[i]; j++){
          printf("-");          
      }
      putchar('\n');
  }
//vertical histogram

int stillOutput = 0;
    for(int i = 0; i< 10; i++){
        printf("%d\t",i+1);
    }
    putchar('\n');

    for(int i = 0; i< 10; i++){
        printf("_________",i+1);
    }
    putchar('\n');


    do {
    stillOutput = 0;
    for(int i = 0; i< 10; i++){
        if(sizes[i] > 0){
            
            sizes[i]--;
            if(sizes[i] == 0){
                printf("|_|\t");
            }else{
                printf("| |\t");
            }
            stillOutput =1;
            
        } else{
            printf("\t");
        }
    }
        printf("\n");    
        
    }
    while(stillOutput == 1 );
       
    
}