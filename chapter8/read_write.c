#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void readStd()
{

    char *b = malloc(sizeof(char) * 100);

    int fd = open("file.txt", O_RDONLY, 0);

    int r = read(fd, b, 4096);

    printf("result is %d\n", r);

    free(b);
}

static char *buf;
static int n = 0;
static char *p;

int getMychar(int fd)
{
    if (n == 0)
    {
        printf("read from file system\n");
        n = read(fd, buf, 4096);
        p = buf;
    }

    return (--n >= 0) ? (unsigned char) *p++ : EOF ;
}

int main()
{
    buf = malloc(sizeof(char) * 100);

    int fd = open("file.txt", O_RDONLY, 0);

    int c ;

    for(int i=0; i< 4096; i++){
        c = getMychar(fd);
        //printf("%c", c);
    }

    c = getMychar(fd);
    c = getMychar(fd);
    c = getMychar(fd);
    free(buf);
}