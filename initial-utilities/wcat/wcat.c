#include <stdlib.h>
#include <stdio.h>

//Reed Ceniviva
//CIS 3207 System Programming and OS
//Lab0 Unix Utils
//Description: Recreate basic unix utility calls

int main(int argv, char** argc){
	int stat = 0;
	if(argv == 1){//not enough arguments
		return(0);
	}
	for(int i = 1 ; i < argv; i++){//for loop to go through the files
		FILE *rFile = fopen(argc[i],"r");
		int BUFFSIZE = 128;
		char buff[BUFFSIZE];
		if(rFile){//check if opening the file succeeded
			while(fgets(buff,BUFFSIZE,rFile) != NULL){
				printf("%s",buff);
			}
			fclose(rFile);//close file after finished reading
		}else{
			printf("wcat: cannot open file\n");
			stat = 1;
			return 1;
		}
	}
	return(stat);//stat variable likely not needed
}
