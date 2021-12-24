#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void itoa_char(char , char[]);
void itob(int , char[], int);

int main(){

    char s[10];    

   // itoa(421,s);

    itoa_char(-128,s);

    itob(1128,s,16);

}


//convert n to char in s
void itoa(int n, char s[]){

    int r; 
    int i = 0;
    
    do {
        r = n % 10;
        s[i++] = '0' + r;
    } while((n/=10) != 0);

    s[i] = '\0';

    //todo add reverse
}

//convert n to char in s
void itoa_char(char n, char s[]){

    int r; 
    int i = 0, sign;
    
    unsigned char zero = ~0;    
    char min = -(zero ^ (zero >> 1));    

    //unsigned char min = unsigned_max ^ unsigned_min;

    //printf("%d\n",min);

    int shift1 = 0;

    if((sign = n) < 0){

        if(n == min){     
            shift1 = 1;           
            n = -(n + 1);
        }else {
            n = -n;
        }         
    }
    
    do {
        r = n % 10;
        s[i++] = '0' + r + shift1;
        shift1 = 0;
    } while((n/=10) != 0);

    if(sign < 0){
        s[i++] = '-';
    }

    s[i] = '\0';

    //todo add reverse

    printf("result = %s\n", s);
}


void itob(int n, char s[], int b){

    int r; 
    int i = 0, sign;
    
    unsigned int zero = ~0;    
    int min = -(zero ^ (zero >> 1));       

    int shift1 = 0;

    if((sign = n) < 0){

        if(n == min){     
            shift1 = 1;           
            n = -(n + 1);
        }else {
            n = -n;
        }         
    }
    
    do {
        r = n % b;
        s[i++] = '0' + r + shift1;
        shift1 = 0;
    } while((n/=b) != 0);

    if(sign < 0){
        s[i++] = '-';
    }

    s[i] = '\0';

    //todo add reverse

    printf("result = %s\n", s);

}



