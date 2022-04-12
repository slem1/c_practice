#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MAXLINES 5000

#define MAX_ALLOC 10000

static char allocbuf[MAX_ALLOC];
static char *ptralloc = allocbuf;

char *alloc(int);
void afree(char *);

int _getline(char *, int);
int readlines(char *[], int );
void printlines(char *[], int);


void swap(void *[], int, int);

void _qsort(char *[], int,int (*comp)(void * ,void *));
void __qsort(char *[], int , int, int (*comp)(void * ,void *) );
void printArray(char *[], int);
int partition(char*[], int, int, int (*comp)(void * ,void *));
int _strcmp(char *s, char *t);
int numcmp(char *s, char *t);

int main()
{
    char *values[] = {"Hello","World","Tree","Lake","Horse","Cup","Cofffe","Manga","C"};
    _qsort(values, 9, strcmp);
    printArray(values,9);

    char *lines[MAXLINES];
    int nlines = readlines(lines, MAXLINES);
    _qsort(lines, nlines,strcmp);
    printArray(lines, nlines);

    char *nums[] = {"5","3", "9", "10", "2"};
    _qsort(nums, 5, numcmp);
    printArray(nums,5);

}

char *alloc(int len)
{

    if (ptralloc - allocbuf + len > MAX_ALLOC)
    {
        printf("cannot allocate \n");
        return 0;
    }
    else
    {
        char *result = ptralloc;
        ptralloc += len;
        return result;
    }
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + MAX_ALLOC)
    {
        ptralloc = p;
    }
    else
    {
        printf("invalid afree");
    }
}

int readlines(char *lineptr[], int maxlines)
{

    int len;
    char line[MAXLEN];
    int nlines = 0;

    while ((len = _getline(line, MAXLEN)) != 0)
    {
        if (nlines >= maxlines)
        {
            return -1;
        }
        else
        {
            char * lineBuf = alloc(len + 1);
            strcpy(lineBuf, line);
            lineptr[nlines++] = lineBuf;
        }
    }

    return nlines;
}

void printlines(char *lines[], int nlines)
{
    printf("number of lines: %d\n", nlines);
    for (int i = 0; i < nlines; i++)
    {
        printf("line %d: %s\n", i, lines[i]);
    }
}

int _getline(char *line, int maxlength)
{

    int c;
    int i = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            *line = '\0';
            return i;   
        } else {
            *line++ = c;
            i++;
        }
    }

    return EOF;
}

void _qsort(char *array[], int len, int (*comp)(void * ,void *)){
    __qsort(array, 0, len - 1, comp);
}

void __qsort(char *array[], int lo, int hi, int (*comp)(void * ,void *)){

    int pivot;

    if( hi > lo ){
        pivot = partition(array, lo, hi, comp);
        __qsort(array, lo, pivot -1, comp);
        __qsort(array, pivot + 1, hi, comp);
    }
}

int partition(char *array[], int low, int high, int (*comp)(void * ,void *)){
    char* pivot = array[high];
    int i = low - 1;
    int j = low;

    for(int j = low; j <= high - 1; j++){
        if((*comp)(array[j], pivot)<0){
            i++;
            swap(array, i, j);
        }
    }

    swap(array, i + 1, high);

    return i +1;
}

void swap(void *array[], int i, int j){
    char* tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void printArray(char *array[], int size){
     for(int i =0; i< size; i++){
        printf("%s,", array[i]);
    }
       printf("\n");
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

int numcmp(char *s, char *t){

    double v1 = atof(s);
    double v2 = atof(t);

    if(v1 < v2){
        return -1;
    }else if(v1 > v2){
        return 1;
    }else{
        return 0;
    }
}
