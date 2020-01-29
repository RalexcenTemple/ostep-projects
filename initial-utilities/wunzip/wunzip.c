#include <stdlib.h>
#include <stdio.h>
#include <elf.h>

//Reed Ceniviva
//CIS 3207 System Programming and OS
//Lab0 Unix Utils
//Description: Recreate basic unix utility calls


int main(int args, char** argv){//got the main arguments mized up
	if(args == 1){//if there arent enough arguments
		printf("wunzip: file1 [file2 ...]\n");
		return(1);
	}
	for(int i = 1; i < args; i++){// for each file passed 
		FILE *fp = fopen(argv[i], "rb");
		if(fp){//if the file is opened
			char c;
			int a;
			while(1){
				fread(&a, sizeof(int), 1, fp);//read in the number 
				fread(&c, sizeof(char), 1, fp);//read in the char
				if(feof(fp)){//break if the end of the file has been reached
					break;
				}
				if((int)c == 10){//if the char is the new line char then print a new line
					puts("");	
				}else{
					for(int m = 0; m < a; m++){//print the char the number of times read to a (the count)
						printf("%c",c);
					}
				}
			}
			fclose(fp);//close the file
		}
	}
}
	
