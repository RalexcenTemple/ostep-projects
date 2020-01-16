#include <stdlib.h>
#include <stdio.h>

//recreate the cat utility


int main(int argv, char** argc){
	for(int i = 1 ; i < argv; i++){
		FILE *rFile = fopen(argc[i],"r");
		int BUFFSIZE = 128;
		char buff[BUFFSIZE];
		if(argv > 0 && rFile){
			printf("File Number: %d | File Name: %s\n--------------------------\n", i,argc[i]);
			while(fgets(buff,BUFFSIZE,rFile) != NULL){
				puts(buff);
			}
		}else{
			printf("Could not access the files");
		}
	}
}
