#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Reed Ceniviva
//CIS 3207 System Programming and OS
//Lab0 Unix Utils
//Description: Recreate basic unix utility calls
	
int main(int argv, char** args){
	if(argv >= 3){//if there are enough arguments
		for(int i = 2 ; i < argv; i++){//for all the files
			FILE *rFile = fopen(args[i],"r");
			if(rFile){//if opening the files worked
				char* buff = NULL;
				size_t buffSize = 0;
				ssize_t line;//using signed size_t to catch the -1 errors
				int lineCount = 0;
				while((line = getline(&buff, &buffSize,rFile)) != -1){//failed to read if -1
					lineCount++;
					int count = 0;
					for(int m = 0; m < line; m++){//for each character in the line
						for(int j = 0; j < strlen(args[1]); j++){//for each character in the searched word
							if(args[1][j] == buff[m]){//check if they match
								count++;
								m++;//increment if a match is found
								if(count == strlen(args[1])){//if matches is equal to the char is the searched term
									//print line, reassign m to the value of line since it doesnt matter if there are more than one match per line
									printf("%s", buff);
									m -= (count-1);
									count = 0;
									m = line;
								}
							}else{//if a match isnt found fix m's location and reset count
								m -= count;
								count = 0;
								break;
							}
						}
					}
				}
			}else{
				puts("wgrep: cannot open file");
				return 1;
			}
		}
	}else if(argv == 2){//basically a duplication of the code above to hand the users input rather than a file
		char* buff = NULL;
		size_t buffSize = 0;
		ssize_t line;
		int lineCount = 0;
		while((line = getline(&buff, &buffSize, stdin)) != -1){//failed to read if -1
                                        lineCount++;
                                        int count = 0;
					if(strcmp(buff,"\n") == 0){//check if the user is not entering informaion anymore
						break;
					}
                                        for(int m = 0; m < line; m++){
                                                for(int j = 0; j < strlen(args[1]); j++){
                                                        if(args[1][j] == buff[m]){
                                                                count++;
                                                                m++;
                                                                if(count == strlen(args[1])){
                                                                        printf("%s", buff);
                                                                        m -= (count-1);
                                                                        count = 0;
									m = line;
                                                                }
                                                        }else{
                                                                m -= count;
                                                                count = 0;
								break;
                                                        }
                                                }
                                        }
                                }
	}else if(argv == 1){//not enough arguments
		puts("wgrep: searchterm [file ...]");
		return(1);
	}
	return(0);	
}
