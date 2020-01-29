#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Reed Ceniviva
//CIS 3207 System Programming and OS
//Lab0 Unix Utils


int main(int args, char** argv){
        if(args == 1){//incorrect number of arguments
                puts("wzip: file1 [file2 ...]");
                return 1;
        }
        char c = 0;
        int count = 0;
        char d = 0;
        int i = 1;
        while(i < args){
		FILE *fp = fopen(argv[i], "r");
                if(fp){//if opening the file worked
                        while(1){//infinite while loop to handle multiple lines
				c = fgetc(fp);
                                if(count == 0){//catch initial run
                                        d = c;
                                        count ++;
                                }else if(c == d){//adjust for conecutive matches
                                        count ++;
                                }else{//adjust for a change in character
                                        if(c==EOF){//break out of while if its the end of the file
						break;
					}else{//write out the int and char, reassign the current char, reset count
						fwrite(&count, sizeof(int), 1, stdout);
                                        	fwrite(&d, sizeof(char), 1, stdout);
                                        	d = c;
                                        	count = 1;
					}
                                }
                        }
                i++;
                }else{
                        puts("FAILED TO OPEN FILE");
                        return(-1);
                }
                if(i == args){//print the last character being counted and its count
                        fwrite(&count, sizeof(int), 1, stdout);
                        fwrite(&d, sizeof(char), 1, stdout);
                }
        }
}

