#include <stdlib.h>
#include <stdio.h>
#include <string.h>
	
int main(int argv, char** args){
	printf("ARG 1: %s\n", args[0]);
	printf("ARG 1: %s\n", args[1]);
	printf("ARG 1: %s\n", args[2]);
	printf("ARG NUM: %d\n", argv);
	if(argv >= 2){
		for(int i = 2 ; i < argv; i++){
			printf("Inside the first for loop\n");
			FILE *rFile = fopen(args[i],"r");
			if(rFile){
				printf("found the file\n");
				//assigne getline to a variable
				char* buff = NULL;
				size_t buffSize = 0;
				ssize_t line;//using signed size_t to catch the -1 errors
				int lineCount = 0;
				//while that isnt null
				while((line = getline(&buff, &buffSize, rFile)) != -1){//failed to read if -1
					//printf("Inside the first while loop\n");
					lineCount++;
					int count = 0;
					for(int m = 0; m < line; m++){
						//printf("Inside the second for loop\n");
						for(int j = 0; j < strlen(args[1]); j++){
							//printf("Inside the third for loop\n");
							//printf("M: %d \n",m);
							//printf("count: %d\n",count);
							if(args[1][j] == buff[m]){
								//printf("Found a matching letter\n");
								count++;
								m++;
								if(count == strlen(args[1])){
									//printf("Found the word\n");
									printf("Line: %d | %s\n", lineCount, buff);
									m -= (count-1);
									count = 0;
								}
							}else{
								//printf("Matching Letters were not the word\n");
								m -= count;
								count = 0;
							}
						}
					}
				}
			}
		}
	}	
}
