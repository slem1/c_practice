#include<stdio.h>


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
            {0,31,28,31,30,31, 30, 31, 31, 30, 31, 30, 31},
            {0,31,29,31,30,31, 30, 31, 31, 30, 31, 30, 31}
        };

int main(){

    int res = day_of_year(2022, 2, 26);

    printf("result: %d \n",res);

    int day;
    int month;

    month_day(2022, 57, &month, &day);

    printf("day=%d, month=%d\n", day, month);

}

int day_of_year(int year, int month, int day){
    int i = 0;
    int leap = year % 4 == 0 && year %100 != 0 || year % 400 == 0;

    for(int j = 1; j< month; j++){
        printf("daytab[%d][%d]=%d\n", leap, j,  daytab[leap][j]);
        i += daytab[leap][j];
    }

    return i+day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){

    int leap = year % 4 == 0 && year %100 != 0 || year % 400 == 0;

    int j;
    for(j = 0; yearday > 0; j++){
        yearday -= daytab[leap][j+1];
    }

    *pday = daytab[leap][j] + yearday;
    *pmonth = j;
}