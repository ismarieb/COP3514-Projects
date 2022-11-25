/* Author:	Ismarie Birriel
 * Program:	Takes in input of computer parts in storage and then determines
 * 		how many computers can be assembled with the parts in storage*/


#include <stdio.h>
#include <stdlib.h>

int find_minimum(int *a, int n);

int main(){

	int i, N, K, part;

	printf("Enter number of parts (N): ");
	scanf("%d", &N);

	if((N < 1) || (N > 1000000)){
		printf("Number of parts must be between 1 and 1,000,000\n");
		exit(0);
	}

	printf("Enter number of part types (K): ");
	scanf("%d", &K);

	if((K < 1) || (K > 10000)){
		printf("Number of part types must be between 1 and 10,000\n");
		exit(0);
	}
	
	// array used for counting
	int parts[K];

	// initialize all elements to 0 in parts[]
	int j;
	for(j = 0; j < K; j++){
		parts[j] = 0;
	}

	printf("Enter part list: ");
	for(i = 0; i < N; i++){
		scanf("%d", &part);
		if((part < 1) || (part > K )){
			printf("Part code must be between 1 and %d\n", K);
			exit(0);
		}	
		parts[part - 1] += 1;
	}

	printf("The factory can build %d computer(s).\n", find_minimum(parts, K));

	return 0;
}


int find_minimum(int *a, int n){

	// a represents array of counters (parts) with length n (K)
	// function returns minimum value of array a

	// only use pointer arithmetic
	
	int *p;
	int min;

	for(p = a; p < a + n; p++){
		min = *a;
		if(*p < min){
			min = *p;
		}
	}

	return min;



}
