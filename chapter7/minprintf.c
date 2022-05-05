#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...){
    va_list ap;
    char *p, *sval;

    int ival;
    double dval;

    va_start(ap,fmt);
    for(p = fmt; *p != '\0'; p++){

        if(*p != '%'){
            putchar(*p);
            continue;
        }

        switch(*++p){
            case 'd': 
                ival = (int)va_arg(ap, int);
                printf("%d", ival);
            break;
            case 'f':
                dval = (double) va_arg(ap, double);
                printf("%f", dval);
            break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++){
                    putchar(*sval);
                }
            break;
            default:
                putchar(*p);
                break;
                
        }
    }
    va_end(ap); 
}

int main(){
    minprintf("hello world %d, %f, %s", 10, 2.0, "plop");
}
