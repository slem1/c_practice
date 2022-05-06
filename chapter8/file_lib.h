#include <stdio.h>

#define _NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 //MAX OPENED FILE
#define PERMS 666

typedef struct _iobuf{
    int cnt;    //characters left
    char *ptr;  //next character position
    char *base; //location of buffer
    int flag;   //mode of file access
    int fd;     // file descriptor
} _FILE;

extern _FILE _iob[OPEN_MAX]; //extern. Déclaré mais non définit (espace mémoire non réservé)

#define _stdin  (&_iob[0])
#define _stdout (&_iob[1])
#define _stderr (&_iob[2])

enum _flags{
    _READ = 01,  // 000 001
    _WRITE = 02, // 000 010
    _UNBUF = 04, // 000 100 file is unbuffered
    _EOF = 010,  // 001 000 EOF has occured on this file
    _ERR = 020,  // 010 000 error occurred on this file

};

int _fillbuf(_FILE *);
int _flushbuf(int, _FILE *);
_FILE *_fopen( char *, char *fil);

#define feof(p) (((p)->flag & _EOF) != 0) 
#define ferror(p) (((p)->flag & _ERR) != 0) 
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))

#define getchar() getc(_stdin)
