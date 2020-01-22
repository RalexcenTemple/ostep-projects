#include <stdlib.h>
#include <stdio.h>

int main(int argv, char** argc){
	//printf("NUMBER OF ARGUMENTS PASS TO THE PROGRAM: %d\n", argv);
	//printf("ARGUMENT 1: %s\n", argc[0]);
	//printf("ARGUMENT 2: %s\n", argc[1]);
	FILE *fp = fopen(argc[1],"r");
	if(!fp){
		puts("ERROR GETTING FILE");
		return (-1);
	}
	int c;
	int pos = 0;//keep track of position within 5 bit sets
	int num = 0;
	while((c = fgetc(fp)) != EOF){
		//printf("CHARACTER READ: %c\n", (char)c);
		//printf("ASCII REPRESENTATION: %d\n", c);
		//printf("NUM VALUE: %d \n", num); 
		if((c < 50 && c > 47) && pos < 4){
			int temp = 0;
			if(c == 49){
				temp = 1;
				for(int i = 0; i < (3 - pos);i++){
					temp = temp * 2;
				}
				num += temp;	
			}
			pos++;
		}else if((c < 50 && c > 47) && pos >= 4){
			puts("BINARY VALUE READ AT CHARACTER POSITION");
			return (-2);
		}else if((c > 49 || c < 48) && pos < 4){
			//puts("NON BINARY VALUE READ AT BINARY POSITION");
			//for some reason the EOF check doesnt hit when all the characters from the file have been read so just using this as a completion check for now
			return (1);
		}else if((c > 49 || c < 48)  && pos == 4){
			//char str[num];
			for(int j = 0; j < num; j++){
				//str[j] = (char)c;
				printf("%c", (char)c); 
			}
			//printf("%s", str);
			pos = 0;
			num = 0;
		}else{
			puts("UNFORESEEN ERROR, POSSIBLY:");
			puts("POSITION VALUE NOT BEING RESET");
			return (-3);
		}	
	}

}
	
