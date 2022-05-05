#include <stdio.h>
#include <string.h>

void filecopy(FILE*, FILE* );

int main(int argc, char **argv){

    FILE* src;
    char *prog = argv[0];
    if(argc == 1){
        filecopy(stdin, stdout);
    }else{
        while(--argc != 0){
            
            if((src = fopen(*++argv, "r")) == NULL){
                fprintf(stderr,"cat error, cannot open file %s (prog is %s) ", *argv, prog);
                return 1;
            }else{
                filecopy(src, stdout);
                fclose(src);
            }
        }
    }

    if(ferror(stdout)){
        fprintf(stderr, "%s: error writing to stdout \n", prog);
    }

}


void filecopy(FILE* source, FILE* dest){

    int c;

    while((c = getc(source)) != EOF ){
        putc(c, dest);
    }

}

int _getline(char *line, int maxlength){

    if(fgets(line, maxlength, stdin) ==  NULL){
        return 0;
    }else {
        return strlen(line);
    }

}