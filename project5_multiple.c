/* Author:	Ismarie Birriel
 * Program:	Identifies multiples of 11 when user inputs a number*/


#include <stdio.h>
#include <string.h>

#define LENGTH 1000

int read_line(char *str, int n);

int main(){

	int result;
	char X[LENGTH];
	int sum_odd = 0; /* use to store the sum of odd digits and even digits*/
	int sum_even = 0;
	int i;
	int ch;

	printf("Enter the value of X: ");
	int n = read_line(X, LENGTH);


	// now we go on to configuring the string to get odd and even places
	// so we are able to test if it is a multiple of 11

	for(i = 0; i < n + 1 ; i++){
		ch = X[i] - '0';	
		sum_odd += ch;
		i++;
	}
	for(i = 1; i < n; i++){
		ch = X[i] - '0';
		if(ch < 0){
			break;
		}
		sum_even += ch;
		i++;
	}

	result = sum_odd - sum_even; 
		
	if((result % 11) == 0){
		printf("%s is a multiple of 11\n", X);
	} else {
		printf("%s is not a multiple of 11\n", X);
	}

	return 0;
}

int read_line(char *str, int n){

	int ch, i = 0;
	
	while ((ch = getchar()) != '\n'){
		if (i < n){
			*str++ = ch;
			i++;
		}
	}

	*str = '\0';
	return i;
}
