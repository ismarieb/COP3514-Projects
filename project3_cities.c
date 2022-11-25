/* Author:	Ismarie Birriel
 * Program:	Postal Services in the Line State
 * Description:	The program takes the number of cities, the number of drones, 
 * 		and a list of n drones, each desribed by its current city
 * 		and travel distance. 
 * */

// does not need function


#include <stdio.h>
#include <stdlib.h>


int main(){

	int i, x, num_cities, num_drones;	

	// Initialize each variable and validate user input by checking it is in range 

	printf("Enter number of cities: ");
	scanf("%d", &num_cities);
	if(num_cities < 1 || num_cities > 100){
		printf("Invalid number of cities.\n");
		printf("Must be between 1 and 100, inclusive.\n");
		exit(0);
	}

	// Initialize array that will be used to determine where drones land
	// 0 - have not landed, 1 - has landed	
	int cities[num_cities];

	// set all values in cities to 0

	for(i = 0; i < num_cities; i++){
		cities[i] = 0;
		
	}

	printf("Enter number of drones: ");
	scanf("%d", &num_drones);
	if(num_drones < 1 || num_drones > 100){
		printf("Invalid number of drones\n");
		printf("Must be between 1 and 100, inclusive\n");	
		exit(0);
	}

	int position[num_drones];
	int distance[num_drones];

	// We want to iterate through each drone in the drone list and find which cities we can travel to

	printf("Enter drone list: ");
	
	for (i = 0; i < num_drones ; i++){
		scanf("%d %d", &position[i], &distance[i]);

		if((position[i] < 1 || position[i] > num_cities) || (distance[i] < 1 || distance[i] > num_cities)){
			printf("Invalid city value or invalid distance value\n");
			printf("Must be between 1 and %d\n", num_cities);
			exit(0);
		}
	}
	
	// Calculations to find where drone can travel to

	for (i = 0; i < num_cities ; i++){
		x = position[i] - 1;
		cities[x] = 1;	 		// drone has landed at current city
		cities[x + distance] = 1;	// add distance to current city
		cities[x - distance] = 1;	// subtract distance to current city
	}	

	printf("Cities reached by a drone: ");

	for(i = 0; i < num_cities; i++){
		if(cities[i] = 1){
			printf("%d ", i + 1);
			continue;
		} else {
			continue;	
		}
	}

	printf("\n");
	return 0;
}
