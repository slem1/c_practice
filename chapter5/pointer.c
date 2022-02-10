#include <stdio.h>

void _strcpy(char *, char *);
void part1();
int _strcmp(char *s, char *t);
void _strcat(char *s, char *t);

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

    _strcat(t1,t2);

    printf("strcat result: %s\n", t1);

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

int _strcmp(char *s, char *t){
    
    for(; *s == *t && *s!= '\0' && *t != '\0'; s++, t++);

    if(*s == '\0' && *t == '\0'){
        return 0;
    }

    return *s - *t;
}

/**
 * Concatenate t to the end of s
 */
void _strcat(char *s, char *t){
    for(;*s!= '\0'; s++);
    while((*s++ = *t++));
}