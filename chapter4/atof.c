#include <stdio.h>
#include <ctype.h>


double atof_scientific(char s[]);
int getLine(char s[]);

#define MAX_LINE 1000

// int main(){

//     double atof(char s[]);

//     char line[MAX_LINE];
//     double res = 0;
//     while(getLine(line) > 0){
//         res += atof_scientific(line);
//         printf("%f\n", res);
//     }
// }


double atof(char s[]){

    int i;

    for(i = 0; isspace(s[i]); i++);

    int sign = s[i] == '-' ? -1: 1;

    if(s[i] == '-' || s[i] == '+'){
        i++;
    }

    double res = 0.0;

    for (; isdigit(s[i]); i++ ){
        res = res * 10 + (s[i] - '0');
    }

    int power = 1;
    if(s[i++] == '.'){
        
        for(;isdigit(s[i]); i++){
            res = res * 10 + (s[i] - '0');
            power = 10 * power;
        }
    }

    return res * sign / power;

}

int getLine(char s[]){
    int i = 0;
    int c;
    while( (c = getchar()) != EOF && i < MAX_LINE-1 && c!= '\n'){        
        s[i++] = c;        
    }
    if(c == '\n'){
        s[i++] = c;        
    }
    s[i] = '\0';

    return i;
}

double atof_scientific(char s[]){

    int i;

    for(i = 0; isspace(s[i]); i++);

    int sign = s[i] == '-' ? -1: 1;

    if(s[i] == '-' || s[i] == '+'){
        i++;
    }

    double res = 0.0;

    for (; isdigit(s[i]); i++ ){
        res = res * 10 + (s[i] - '0');
    }

    int power = 1;
    if(s[i] == '.'){
        i++;
        for(;isdigit(s[i]); i++){
            res = res * 10 + (s[i] - '0');
            power = 10 * power;
        }
    }

    double exp_multiplier = 1.0;
    if(s[i] == 'e' || s[i] == 'E'){
        i++;
        int sign_exp = s[i] == '-'? -1: 1;

        if(s[i] == '-' || s[i] == '+')
            i++;

        int exp = 0;    
        for(;isdigit(s[i]); i++){
            exp = exp * 10 + (s[i] - '0');
        }

        for(int j = 0; j< exp; j++){
            exp_multiplier = exp_multiplier * 10;
        }

        if(sign_exp == -1){
            exp_multiplier = 1 / exp_multiplier;
        }
    }
    return res * sign / power * exp_multiplier;
}
