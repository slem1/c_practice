#include "file_lib.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){

    _FILE _iob[OPEN_MAX] = {
        {0, (char *) 0, (char *) 0, _READ, 0 },
        {0, (char *) 0, (char *) 0, _WRITE, 1 },
        {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 },
    }; 

    _FILE *f = _fopen("file.txt", "r");

    if(f == NULL){
        fprintf(stderr, "Une erreur est survenue");
        return -1;
    }

    int c = getc(f);

    if(c!= EOF){
        printf("%c", c);
    }

}

_FILE _iob[OPEN_MAX];

_FILE *_fopen( char *name, char *mode){
    int fd;
    _FILE *fp;

    if(*mode != 'r' && *mode != 'w' && *mode != 'a'){
        return NULL;
    }

    for(fp = _iob; fp < _iob + OPEN_MAX ; fp++){
        if((fp->flag & (_READ | _WRITE)) == 0){
            //find free slot
            break;
        }
    }

    if( fp >= _iob + OPEN_MAX){
        //no free slot available
        return NULL;
    }

    if(*mode == 'w'){
        fd = creat(name, PERMS);
    }else if (*mode == 'a'){
        if( (fd = open(name, O_WRONLY, 0)) == -1){
               fd = creat(name, PERMS); 
        };
        lseek(fd, 0L, 2);   // 0 = beginning , 1 = current position, 2 = end of file
    }else {
        fd = open(name, O_RDONLY, 0);
    }

    if(fd == -1){
        return NULL;
    }

    fp->fd = fd;
    fp->cnt=0;
    fp->base = NULL;
    fp->flag = (*mode == 'r' ? _READ: _WRITE);
    return fp;
}

int _fillbuf(_FILE *fp){

    //fill on read only
    if((fp->flag & (_READ | _EOF | _ERR)) != _READ){
        return EOF;
    }

    //is it buffered
    int bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    if(fp->base == NULL){
        //no buffer, allocate it
        if((fp->base = (char *) (malloc(bufsize * sizeof(char)))) == NULL){
            //failed allocate buffer
            return EOF;
        }
    }

    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp -> ptr, bufsize);

    if(--fp->cnt < 0){
        if(fp->cnt == -1){
            fp->flag |= EOF;
        }else {
            fp->flag |= _ERR;
        }
        fp->cnt = 0;
        return EOF;
    }

    //return the first character at the start of the buffer
    return (unsigned char) *fp->ptr++;


}