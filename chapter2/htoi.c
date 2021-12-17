#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int htoi(char[]);
int hexToInt(char c);


int main()
{
    int result = htoi("0xACED");
    printf("result vaut %d", result);

    return 0;
}

int htoi(char s[]){
   
    int idxStart = 0;
    char firstChar = s[0];
    int ln = strlen(s);
    int result = 0;
   
    if(firstChar == '0' && (s[1] == 'x' || s[1] == 'X')){
        idxStart = 2;
    }
   
    for(int i = idxStart; s[i] != '\0'; i++){
        int power = ln - i -1;
        int hexVal = hexToInt(s[i]);
       
        if(hexVal == -1){
            return -1;
        }
       
        result = result + pow(16,power) * hexVal;
    }
   
    return result;
}

int hexToInt(char c){
   
    int upc = toupper(c);
   
    if(upc >= '0' && upc <= '9' ){
        int value = upc - '0';
    }else if (upc >= 'A' && upc <= 'F') {
        int value = upc - 'A' + 10;
    }else {
        return -1;
    }
}