#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <errno.h>

#define MAXPATH 1024
#define NAME_MAX 14 

typedef struct {
    long ino;
    char name[NAME_MAX+1];
} _Dirent;

typedef struct {
    int fd;
    _Dirent d;
} _DIR;

void dirwalk(char *dir, void (fcn)(char*) );
_DIR * __opendir(char *dirnname);
_Dirent *_readdir(_DIR *dp);


void _closedir(_DIR *dp){
    if(dp){
        close(dp -> fd);
        free(dp);
    }
}


void fsize(char *name){

    struct stat stbuf;

    if(stat(name, &stbuf) == -1){
        fprintf(stderr, "Error accessing file %s\n", name);
        return;
    }

    if((stbuf.st_mode & S_IFMT) == S_IFDIR ){
        dirwalk(name, fsize);
    }

    printf("%8ld %s\n", stbuf.st_size, name);

}

 void dirwalk(char *dir, void (fcn)(char*) ){

     char name[MAXPATH];
     _Dirent *dp;
     _DIR *dfd;

     if((dfd = __opendir(dir)) == NULL){
         fprintf(stderr, "dirwalk: can't open %s\n", dir);
         return;
     }

     while((dp = _readdir(dfd)) != NULL){
      if(strcmp(dp->name, ".") == 0 ||
         strcmp(dp->name, "..") == 0 ){
          continue;
      } 
      
        sprintf(name, "%s%s", dir , dp ->name);
        (*fcn)(name);

     }

     _closedir(dfd);


 }

 _Dirent *_readdir(_DIR *dp){

     struct direct dirbuf; //local dir struct
     static _Dirent d;

     int c = read(dp->fd, (char *) &dirbuf, sizeof(dirbuf));

     printf("%d\n",c);
     fprintf(stderr, "%s", strerror(errno));

     while(read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)){
         

         if(dirbuf.d_ino == 0){
             //file remove
             continue;
         }

        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, 14);
        d.name[14] = '\0';
        return &d;
     }

     return NULL;

 }

_DIR * __opendir(char *dirnname){

     _DIR *dp;
     int fd;
     struct stat stbuf;

     if((fd = open(dirnname, O_RDONLY, 0)) == -1 
     || fstat(fd, &stbuf)
     || (stbuf.st_mode & S_IFMT) != S_IFDIR
     || (dp = (_DIR*) malloc(sizeof(_DIR))) == NULL
     ){
         return NULL;
     }
     dp->fd = fd;
     return dp;

 }

int main(){

    fsize("/Users/dev/workspace/c_practice/");

    return 0;
}