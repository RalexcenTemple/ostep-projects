#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Reed Ceniviva
//CIS 3207 System Programming and OS
//Lab0 Unix Utils
//Description: Recreate basic unix utility calls


char * intToBinary(int count, char c, char* out);

int main(int argv, char ** argc){
	if(argv > 1){
		printf("ARGV: %d\n", argv);
		for(int i = 1; i < argv; i++){
		FILE *fp = fopen(argc[1], "r");
		if(fp == NULL){
			puts("FILE NOT FOUND");
			return (-1);
		}
		int count = 1;
		int c;
		int temp = 0;
		while((c = fgetc(fp)) != EOF){
			if(c == temp && count < 15){//catch duplicated greater than 15 successive
				count++;
			}else{
				if(temp != 0){
					char *In = malloc(sizeof(char)*5);
					In = intToBinary(count, (char)temp, In);
					fwrite(In, (sizeof(char)*5), 1, stdout);
					temp = c;
					count = 1;
				}else{
					temp = c;
				}
			}
		}
	}
	}else if(argv == 1){
		puts("wzip: file1 [file2...]");//this is not the format of the way the program was directed to be implemented
		return 1;
	}
}

char * intToBinary(int count, char c, char* out){ 
	if(count%2 == 0){
		out[3] = '0';
	}else{
		out[3] = '1';
	}
	count = count/2;
	if(count%2 == 0){
                out[2] = '0';
        }else{
                out[2] = '1';
        }
	count = count/2;
	if(count%2 == 0){
                out[1] = '0';
        }else{
                out[1] = '1';
        }
	count = count/2;
	if(count%2 == 0){
                out[0] = '0';
        }else{
                out[0] = '1';
        }
	out[4] = c;
	return out;
}
