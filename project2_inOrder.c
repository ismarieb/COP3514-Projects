/* Author:	 Ismarie Birriel
 * Program:	 Characters in Order
 * Description:	 This program determines if user input of characters is in order
		 considering their ASCII values*/



#include <stdio.h>
#include <stdlib.h>
#define LENGTH 20

int main(){

	char ch, sentence[LENGTH];
	char x, y;
	int i;

	// First we need to collect input from user

	printf("Input: ");

	// We collect input and make all the characters lowercase first
	// Next we begin comparing each character to see if they are 
	// in order or not by comapring their ASCII values

	do{
		ch = getchar();
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch + 'a' - 'A';
		}
		for (i=0; i < LENGTH; i++){
			sentence[i] = ch;
			x = sentence[ch];
			y = sentence[ch -1];
			if(y >= x){
				printf("Not in order\n");	
				exit(0);
			} else {
				printf("In order\n");	
				exit(0);
			}			
		}
	} while (ch != '\n');

	return 0;
}
