#include <stdio.h>
#include <string.h>

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


void swap(char *[], int, int);

void qsort(char *[], int);
void _qsort(char *[], int , int );
void printArray(char *[]);
int partition(char*[], int, int);
int _strcmp(char *s, char *t);

int main()
{
    char *values[] = {"Hello","World","Tree","Lake","Horse","Cup","Cofffe","Manga","C"};
    qsort(values, 9);
    printArray(values);

    char *lines[MAXLINES];
    int nlines = readlines(lines, MAXLINES);
    qsort(lines, nlines);

    printArray(lines);



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

void qsort(char *array[], int len){
    _qsort(array, 0, len - 1);
}

void _qsort(char *array[], int lo, int hi){

    int pivot;

    if( hi > lo ){
        pivot = partition(array, lo, hi);
        _qsort(array, lo, pivot -1);
        _qsort(array, pivot + 1, hi);
    }
}

int partition(char *array[], int low, int high){
    char* pivot = array[high];
    int i = low - 1;
    int j = low;

    for(int j = low; j <= high - 1; j++){
        if(_strcmp(array[j], pivot)<0){
            i++;
            swap(array, i, j);
        }
    }

    swap(array, i + 1, high);

    return i +1;
}

void swap(char *array[], int i, int j){
    char* tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void printArray(char *array[]){
     for(int i =0; i< 9; i++){
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
