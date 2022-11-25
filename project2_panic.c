// Ismarie Birriel
// This program helps prevent panic buying by multiplying the cost of items 
// by how many units a customer wants to buy


#include <stdio.h>
#include <stdlib.h>

int main(){

	int cost, units, dollars, count;
	int sum = 0, remainder;

	// Print and scan statements to collect user info
	// Input validation to make sure input is in range
	
	printf("Enter item price: \n");
	scanf("%d", &cost);
	if(cost <= 0){
		printf("Invalid price %d\n", cost);
		printf("Price must be greater than 0\n");
		exit(0);
	}
	

	printf("Enter number of units: \n");
	scanf("%d", &units);
	if(units <= 0){
		printf("Invalid number of units %d\n", units);
		printf("Number of units must be greater than 0\n");
		exit(0);	
	}	

	printf("Enter money amount: \n");
	scanf("%d", &dollars);
	if(dollars < 0){
		printf("Invalid money amount %d\n", dollars);
		printf("Money amount must be greater than or equal to 0\n");
		exit(0);
	}

	// Calculations for total cost of items and whether they have
	// enough money or still need x dollars more
	
	for(count = 0; count < units; count++){
		sum += (count + 1)  * cost;
	}
	
	if(sum > dollars){
		remainder = sum - dollars;
		printf("Needs %d dollar(s) to complete the purchase!\n", remainder);
	} else {
		printf("Has enough money!\n");
	}
	


	return 0;
}
