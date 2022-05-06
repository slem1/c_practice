#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

void error(char *fmt, ...);

#define PERMS 0666
#define BUFFER_SIZE 4096

int main(int argc, char **argv){
    if(argc !=3){
        error("invalid number of argument");
    }
    int src, dest;
    
    if((src = open(argv[1], O_RDONLY, 0)) == -1 ){
        error("cp: cannot open %s", argv[1]);
    }

    if((dest = creat(argv[2], PERMS)) == -1 ){
        error("cp: cannot create %s with perms %03o", argv[2], 0666);
    }


    char buf[BUFFER_SIZE];
    int n;

    while((n = read(src, buf, BUFFER_SIZE)) > 0){
        if( write(dest, buf, n) != n){
            error("error on write %s", argv[2]);
        }
    }

    if(n == -1){
        error(strerror(errno));
    }

    close(src);
    close(dest);



    return 0;
}


void error(char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr,"\n");
    va_end(args);
    exit(1);
}