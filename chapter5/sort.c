#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000

#define MAX_ALLOC 10000

static char allocbuf[MAX_ALLOC];
static char* ptralloc = allocbuf;

char* alloc(int);
void afree(char *);

int _getline(char *line, int maxlength);
int readlines(char *lineptr[], int maxlines);
void printlines(char *lines[], int nlines);

int main()
{
    char *lines[MAXLINES];
    int nlines = readlines(lines, MAXLINES);
    printlines(lines, nlines);
}

char* alloc(int len){

    if(ptralloc - allocbuf + len > MAX_ALLOC){
      printf("cannot allocate \n");
      return 0;
    }else {
        char * result = ptralloc;
        ptralloc += len;
        return result;
    }  
}

void afree(char *p){
  if(p >= allocbuf && p < allocbuf + MAX_ALLOC){
    ptralloc = p;
  } else {
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
        printf("line is %s(%d)\n", line, len);

        if (nlines >= maxlines)
        {
            return -1;
        }
        else
        {
            char lineStore[len];
            strcpy(lineStore, line);
             printf("lineStore is %s(%d)\n", lineStore, len);
            lineptr[nlines++] = lineStore;
              printf("lineptr is %s(%d)\n", lineptr[nlines-1], len);
        }
    }

    return nlines;
}

void printlines(char *lines[], int nlines){
    printf("number of lines: %d\n", nlines);
    for (int i=0; i< nlines; i++){
        printf("line %d: %s", i, lines[i]);
    }
}

int _getline(char *line, int maxlength)
{

    int c;
    int i = 0;

    while ((c = getchar()) != EOF)
    {
        if (i < maxlength -1)
        {
            if (c == '\n')
            {
                *line = '\0';
                return i;
            }else {
                *line++ = c;
                i++;
            }
        }
        else
        {
            *line = '\0';
            return i;
        }
    }

    return EOF;
}
