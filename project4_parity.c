/* Author:	Ismarie Birriel
 * Program:	Parity in an array
 * Description:	An array of values is considered good if all values share
 * 		the same parity (even or odd) and not good if otherwise*/


#include <stdio.h>

void find_parity(int *a, int n, int *all_even, int *all_odd);

int main(){

	int length, i;
	int is_even, is_odd;

	printf("Enter the length of the array: ");
	scanf("%d", &length);

	int array[length];

	printf("Enter the elements of the array: ");
	for(i = 0; i < length; i++){
		scanf("%d", &array[i]);
	}

	find_parity(array, length, &is_even, &is_odd);

	printf("Output: ");
	if(is_odd){
		printf("Good, all elements are odd\n");
	} else if(is_even){
		printf("Good, all elements are even\n");
	} else {
		printf("Not good\n");
	}

	return 0;	
}


// function will store whether all of the array elements are
// all even or all odd


void find_parity(int *a, int n, int *all_even, int *all_odd){

	int *p;
		
	// test to see if first element is odd or even
	// then compare with the rest of the array to make sure they share the same parity

	p = a;	

	if(*p % 2 == 0){
		*all_even = 1;
		for(p = a + 1; p < a + n; p++){
			if(*p %2 == 0){
				*all_even = 1;
			} else {
				*all_even = 0;
			}
			if(*all_even == 0){
				break;
			}
		}
	} else {
		*all_odd = 1;
		for(p = a + 1; p < a + n; p++){
			if(*p %2 == 1){
				*all_odd = 1;
			} else {
				*all_odd = 0;
			}
			if(*all_odd == 0){
				break;
			}
		}
	}
		
}
