#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * intToBinary(int count, char c, char* out);

int main(int argv, char ** argc){
	//puts("INSDIE THE MAIN");
	if(argv < 3){
		printf("ARGV: %d\n", argv);
		FILE *fp = fopen(argc[1], "r");
		if(fp == NULL){
			puts("FILE NOT FOUND");
			return (-1);
		}
		//size_t size = 5;
		int count = 1;
		int c;
		int temp = 0;
		while((c = fgetc(fp)) != EOF){
			//puts("IN THE WHILE LOOP");
			if(c == temp && count < 15){
				//puts("REPEATED LETTER FOUND");
				count++;
			}else{
				//puts("REPEAT CHARACTER NOT FOUND");
				//char tempChar = (char)temp;
				//printf("%c",tempChar);
				//char * str;
				//printf("COUNT: %d\n", count);
				if(temp != 0){
					//printf("%c",(char)c);
					char *In = malloc(sizeof(char)*5);
					In = intToBinary(count, (char)temp, In);
					fwrite(In, (sizeof(char)*5), 1, stdout);
					//printf("%s", In);
					temp = c;
					count = 1;
				}else{
					//printf("%c",(char)c);
					temp = c;
				}
			}
		}
	}
}

char * intToBinary(int count, char c, char* out){
	//puts("IN CONVERSION FUNCTION");
	//char *out = malloc(sizeof(char)*5);
	//printf("START COUNT: %d\n", count); 
	if(count%2 == 0){
		out[3] = '0';
	}else{
		out[3] = '1';
	}
	count = count/2;
	//printf("%s\n",out);
	//printf("COUNT: %d\n", count);
	if(count%2 == 0){
                out[2] = '0';
        }else{
                out[2] = '1';
        }
	count = count/2;
	//printf("%s\n",out);
	//printf("COUNT: %d\n", count);
	if(count%2 == 0){
                out[1] = '0';
        }else{
                out[1] = '1';
        }
	count = count/2;
	//printf("%s\n",out);
	//printf("COUNT: %d\n", count);
	if(count%2 == 0){
                out[0] = '0';
        }else{
                out[0] = '1';
        }
	//printf("%s\n",out);
	out[4] = c;
	//printf("%s\n",out);
	return out;
}
