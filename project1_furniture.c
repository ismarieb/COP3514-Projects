// Ismarie Birriel: Program collects user input to select furniture type and number of months
// to determine cost of the furniture rented.


#include <stdio.h>
#include <stdlib.h>

int main(){

	int furniture, months;
	int total_cost = 0;

	// Lines for making selections on furniture and number of months

	printf("Please select from the following menu: 1. Sofa, 2. Loveseat, 3. 4 Post Bed, 4. Dresser, 5. Kitchen Table\n");

	printf("Enter furniture selection: ");
	scanf("%d", &furniture);

	if(furniture < 1 || furniture > 5){
		printf("Invalid choice for furniture. Must be between 1 and 5.\n");
		exit(0);
	}

	printf("Enter months rented: ");
	scanf("%d", &months);

	if(months <= 0){
		printf("Invalid choice for months. Must be greater than zero.\n");
		exit(0);
	}

	// After collecting all valid input, now we calculate charge, depending on item and number of months.

	switch(furniture){
		case 1:
			total_cost = 60 + ((months - 1) * 45);
			if (months < 12 && total_cost >= 450){
				total_cost = 450;
			}
			if ((months / 12) >= 1){
				total_cost = 0;
				total_cost += 450 * (months / 12);
				total_cost += 45 * (months % 12);
			}
			break;	
		case 2:	
			total_cost = 45 + ((months - 1) * 30);
			if (months < 12 && total_cost >= 280){
				total_cost = 280;
			}
			if ((months / 12) >= 1){
				total_cost = 0;
				total_cost += 280 * (months / 12);
				total_cost += 30 * (months % 12);
			}
			break;
		case 3:
			total_cost = 55 + ((months - 1) * 38);
			if (months < 12 && total_cost >= 350){
				total_cost = 350;
			}
			if ((months / 12) >= 1){
				total_cost = 0;
				total_cost += 350 * (months / 12);
				total_cost += 38 * (months % 12);
			}
			break;			
		case 4:
			total_cost = 28 + ((months - 1) * 25);
			if (months < 12 && total_cost >= 200){
				total_cost = 200;
			}
			if ((months / 12) >= 1){
				total_cost = 0;
				total_cost += 200 * (months / 12);
				total_cost += 25 * (months % 12);
			}
			break;
		case 5:
			total_cost = 35 + ((months - 1) * 20);
			if (months < 12 && total_cost >= 220){
				total_cost = 220;
			}
			if ((months  / 12) >= 1){
				total_cost = 0;
				total_cost += 220 * (months / 12);
				total_cost += 20 * (months % 12);
			}
			break;
	}


	// Finally print total cost	

	printf("Amount due ($): %d \n", total_cost);

	return 0;
}
