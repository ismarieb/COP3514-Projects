// Ismarie Birriel
// This program computes the next time the comet Halley will be seen after being seen in 
// 1986, where it is seen every year.


#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int year, appearance;
	int x; 		// variable to use for calculations
	
	// First we need to collect user input and assign it to our variable, then make sure it is valid.

	printf("Enter year: ");
	scanf("%d", &year);

	if (year <= 1986){
		printf("Invalid input, must be greater than 1986.\n");
		exit(0);
	}

	// Now we can do calculations to determine the next time Halley is seen

	x = (year - 1986) % 76;
	appearance = year + 76 - x;

	// Finally print the answer

	printf("Next appearance: %d\n", appearance);

	return 0;
}
