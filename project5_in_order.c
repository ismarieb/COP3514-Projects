/* Author:	Ismarie Birriel
 * Program:	We modify project2, problem2 program to determine if characters in a
 * 		command-line argument are in order*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in_order(char *word);

int main(int argc, char *argv[]){

	int result = 0;

	if(argc != 2){
		printf("Incorrect number of outputs. Usage: ./a.out word\n");
		exit(0);
	}

	result = in_order(argv[1]);

	//printf("%d\n", result);

	if(result == 1){
		printf("In order\n");
	} else {
		printf("Not in order\n");
	}

	return 0;
}

int in_order(char *word){

	char *p;
	char *q;
	int flag = 0;

	q = word + 1;

	for(p = word; *p != '\0'; p++, q++){
		if(*q == '\0') break;
		if(*p >= 'A' && *p <= 'Z'){
			*p = *p + 'a' - 'A';
		}
		if(*q >= 'A' && *q <= 'Z'){
			*q = *q + 'a' - 'A';
		}
		//printf("p:%s q:%s\n", p, q);

		//printf("%d \n", strcmp(p,q));
		if(*p == *q){
			continue;
		}
		if(strcmp(p,q) > 0){
			// > 0 means p and p+1 are not in order
			flag = 1;
			//printf("flag raised");
		}	
	}
	*p = '\0';

	if(flag)
		return 0;
	else
		return 1;

}
