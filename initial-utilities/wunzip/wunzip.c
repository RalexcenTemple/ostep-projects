#include <stdlib.h>
#include <stdio.h>


//Reed Ceniviva
//CIS 3207 System Programming and OS
//Lab0 Unix Utils
//Description: Recreate basic unix utility calls


int main(int argv, char** argc){//got the main arguments mized up
	for(int r = 1; r < argv;r++){
	FILE *fp = fopen(argc[r],"r");
	if(!fp){
		puts("ERROR GETTING FILE");
		return (-1);
	}
	int c;
	int pos = 0;//keep track of position within 5 bit sets
	int num = 0;
	while((c = fgetc(fp)) != EOF){
		if(pos < 4){
			int temp = 0;
			if(c == 49){
				temp = 1;
				for(int i = 0; i < (3 - pos);i++){
					temp = temp * 2;
				}
				num += temp;	
			}
			pos++;
		}else if((c > 49 || c < 48) && pos < 4){
			//puts("NON BINARY VALUE READ AT BINARY POSITION");
			//for some reason the EOF check doesnt hit when all the characters from the file have been read so just using this as a completion check for now
			puts("END OF ENCRYPTION REACHED");
			return (1);
		}else if(pos == 4){
			for(int j = 0; j < num; j++){
				printf("%c", (char)c); 
			}
			pos = 0;
			num = 0;
		}else{
			puts("UNFORESEEN ERROR, POSSIBLY:");
			puts("POSITION VALUE NOT BEING RESET");
			return (-3);
		}	
	}
	}
}
	
