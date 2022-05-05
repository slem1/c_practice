#include <stdio.h>
#include <stdlib.h>

void scanDate();
void scanDatePlus();


int main(){

    // double sum, v;

    // sum = 0;

    // while(scanf("%lf", &v) == 1){
    //     printf("\t%.2f\n", sum += v); 
    // }

    //scanDate();

    scanDatePlus();

}


void scanDate(){

    int day = 1,month =1,year=1970;

    int match = scanf("%d/%d/%d", &day, &month, &year);

    printf("(match %d)%d/%d/%d\n", match, day, month, year);
}

void scanDatePlus(){

    int day, month, year;

    char monthname[20];

    char buffer[256];

    char *my_string;

    my_string = (char *)malloc(256+1);

    char *buf = buffer;

    char **d = &buffer;

    char **b = &buf;

    size_t n = sizeof(buffer)/sizeof(buffer[0]);

    getline(b, &n, stdin);

    printf("read line is %s", *b);

    if(sscanf(*b, "%d/%d/%d", &day, &month, &year) == 3){
        printf("valid: %d/%d/%d", day, month, year);
    }else if(sscanf(*b,"%d %s %d", &day, monthname, &year) == 3){
        printf("valid: %d %s %d", day, monthname, year);
    }else {
        printf("invalid %s", *b);
    }
}