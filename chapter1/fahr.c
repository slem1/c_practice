#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){

    printf("print reverse\n");

    farhReverse();

    float celsius, fahr;   
    

    // for(int fahr=lower; fahr<= upper; fahr+=step){
    //     celsius = 5 * (fahr -32) / 9;
    //     printf("%d\t%d\n", fahr, celsius);
    // }

    fahr = LOWER;

    printf("Farhenheit\tCelsius\n");
    while(fahr <= UPPER){
         celsius = (5.0 / 9.0) * (fahr -32);
         printf("%10.0f\t%7.1f\n", fahr, celsius);
         fahr+=STEP;
    }
}

int farhReverse(){

    float celsius;

    for(float fahr=UPPER; fahr>=LOWER; fahr-=STEP){
        celsius = 5 * (fahr -32) / 9;
        printf("%.0f\t%.1f\n", fahr, celsius);
    }


}