#include <stdio.h>

void _strcpy(char *, char *);
void part1();
int _strcmp(char *s, char *t);
void _strcat(char *s, char *t);
int _strlen(char *s);
int _strend(char *s, char *t);
void _strncpy(char *s, char *t, int n);

int main()
{

    char s1[100] = "Hello world";

    char s2[100];

    char *s3 = s2;

    _strcpy(s2, s1);

    printf("%s \n", s2);

    int result = _strcmp("Hello", "Hello");

    printf("Result is %d\n", result);

    char t1[100] = "Sakura";
    char *t2 = "Chan";

    _strcat(t1, t2);

    printf("strcat result: %s\n", t1);

    char *t3 = "Hello";
    int ln = _strlen(t3);

    printf("lentgh: %d\n", ln);

    int endWith = _strend(t3, "ello");
    printf("endWith: %d\n", endWith);

    char chun[100] = "Chun-";
    char *liang = "Liang";

    _strncpy(chun, liang, 2);

    printf("strncpy result: %s\n", chun);
}

void part1()
{

    char *strg = "Hello world";

    printf("%s \n", strg);

    char a[100];

    char *secChar = strg + 1;

    *secChar = 'i';
}

void _strcpy(char *destination, char *source)
{

    while ((*destination++ = *source++))
    {
    }
}

int _strcmp(char *s, char *t)
{

    for (; *s == *t && *s != '\0' && *t != '\0'; s++, t++)
        ;

    if (*s == '\0' && *t == '\0')
    {
        return 0;
    }

    return *s - *t;
}

/**
 * Concatenate t to the end of s
 */
void _strcat(char *s, char *t)
{
    for (; *s != '\0'; s++)
        ;
    while ((*s++ = *t++))
        ;
}

int _strend(char *s, char *t)
{
    int lnS = _strlen(s);
    int lnT = _strlen(t);

    if (lnT > lnS)
    {
        return 0;
    }
    else
    {
        int d = lnS - lnT;
        while (s[d] == *t && *t != '\0')
        {
            d++;
            t++;
        }

        if (*t == '\0')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int _strlen(char *s)
{

    int i;
    for (i = 0; *s++ != '\0'; i++)
        ;

    return i;
}

void _strncpy(char *s, char *t, int n){

    for(;*s != '\0'; s++);

    while(n-- != 0){
        printf("copie %c\n", *t);
        *s++ = *t++;
    }

    *s = '\0';

}