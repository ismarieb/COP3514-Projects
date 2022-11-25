/* Author:	Ismarie Birriel
 * Program:	Factorial
 * Description:	This program calculates and displays the factorial of each
 * 		element in an integer array.*/


#include <stdio.h>


// function to calculate factorial of integer value n, used as a parameter

int fact(int n){

	if(n <= 1){
		return 1;
	} else {
		return n * fact(n-1);
	}
}

// n = size of array, array a = input array, array b = output array
// function calls the fact function to calculate factorial of an element

void calculate_fact(int a[], int n, int b[]){

	int i;

	printf("\nOutput: ");

	for(i = 0; i < n; i++){
		b[i] = fact(a[i]);
		printf("%d ", b[i]);
	}
	printf("\n");
}

int main(){

	int size, i, num;

	// Collect user input and elements to put in array

	printf("Enter the length of the array: ");
	scanf("%d", &size);

	int array[size];
	int final_array[size];

	printf("Enter %d elements in the array: ", size);
	for(i = 0; i < size; i++){
		scanf("%d", &num);
		array[i] = num;
		printf("%d ", array[i]);
	}

	// Call calculate_fact function

	calculate_fact(array, size, final_array);

	return 0;
}


