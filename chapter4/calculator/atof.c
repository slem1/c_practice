#include <stdio.h>
#include <ctype.h>

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
