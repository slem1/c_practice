#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char** args){

	char *filename;

	if(argc > 1){

		filename = args[1];
	}

//printf("%s\n", filename);

	FILE* csvFile = fopen(filename, "r");

	if(!csvFile){
		fprintf(stderr,"Error while opening file %s errno=%d\n", filename, errno);
		exit(1);
	}

	
	char* line;
	size_t len=0;
	int expectedTokens = 2;

	while(getline(&line, &len, csvFile) > 0){
		char** tokens = (char**) malloc(sizeof(char*) * expectedTokens);
		char** tp = tokens;

		int i = expectedTokens;
		char* token;

		token = strtok(line, ",");

		while(token != NULL){
			*tp++ = token;
			token = strtok(NULL, ",");
		}
	};


}
