#include <stdio.h>
#include <ctype.h>

int readInt(int *res);
int readFloat(float *res);

int main()
{
    float result = 0;
    readFloat(&result);
    printf("res=%f\n", result);
}

int readInt(int *res)
{
    int c, sign;
    while ((c = getchar()) && isspace(c))
        ;

    if (!isdigit(c) && c != '+' && c != '-')
    {
        //not a number
        return 0;
    }

    sign = c == '-' ? -1 : 1;

    if (c == '-' || c == '+')
    {
        c = getchar();
    }

    for (*res = 0; isdigit(c); c = getchar())
    {
        *res = *res * 10 + (c - '0');
    }

    *res *= sign;

    return c;
}

int readFloat(float *res)
{

    int c, sign;
    while ((c = getchar()) && isspace(c))
    {
    }

    if (!isdigit(c) && c != '+' && c != '-')
    {
        //not a number
        return 0;
    }

    sign = c == '-' ? -1 : 1;

    if (c == '-' || c == '+')
    {
        c = getchar();
    }

    for (*res = 0; isdigit(c); c = getchar())
    {
        *res = *res * 10 + (c - '0');
    }

    int divisor = 1;
    if (c == '.')
    {
        c = getchar();
        for (; isdigit(c); c = getchar())
        {
            *res = *res * 10 + (c - '0');
            divisor *=10;
        }
    }

    *res = sign * *res/divisor;

    return c;
}


int readIntInvalidZero(int *res)
{
    int c, sign;
    while ((c = getchar()) && isspace(c))
        ;

    if (!isdigit(c) && c != '+' && c != '-')
    {
        //not a number
        return 0;
    }

    sign = c == '-' ? -1 : 1;

    if (c == '-' || c == '+')
    {
        c = getchar();

        if(c== '0'){
            return c;
        }
    }

    for (*res = 0; isdigit(c); c = getchar())
    {
        *res = *res * 10 + (c - '0');
    }

    *res *= sign;

    return c;
}