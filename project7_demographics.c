/* Author:	Ismarie Birriel
 * Program:	Program sorts data from .csv file based on percentage of 
 * 		population equal or greater than 65 years old.
 * 		*/

#include <stdio.h>
#include <string.h>
#define MAX 100
#define STR_LEN 150 

struct state_info{
	char name[MAX];
	int pop20;
	int pop10;
	double under5;
	double under18;
	double over65;
};

void sort_states(struct state_info list[], int n);

int find_largest(struct state_info list[], int n);

int main(){

	FILE *fp;
	char filename[MAX];
	int i;

	struct state_info states[MAX];

	printf("Enter the file name: ");
	fscanf(stdin, "%s", filename);	

	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error opening file\n");
		return 1;
	}

	while(!feof(fp) && !ferror(fp)){
		fscanf(fp, "%[^,], %d, %d, %lf, %lf, %lf", states[i].name, &states[i].pop20,
			&states[i].pop10, &states[i].under5, &states[i].under18, 
			&states[i].over65);
		i++;		
	}

	sort_states(states, i);

	char outputfile[] = "sorted_";

	strcat(outputfile, filename);

	FILE *fw  = fopen(outputfile, "w");
	if(fw == NULL){
		printf("Error writing to file\n");
		return 1;
	}

	printf("Output file name: sorted_state_demographics.csv\n");

	int a;	

	for(a = i - 1; a > 0 ; a--){
		fprintf(fw, "%s, %.1d, %.1d, %.1lf, %.1lf, %.1lf", states[a].name, 
			states[a].pop20, states[a].pop10, states[a].under5, 
			states[a].under18, states[a].over65);
	
	}

	fprintf(fw, "\n");	

	fclose(fp);
	fclose(fw);

	return 0;
}

// this function sorts the states
void sort_states(struct state_info list[], int n){

	struct state_info temp;
	int largest = 0;
	
	// base case of recursive sort function call
	if(n == 1){
		return;
	}

	largest = find_largest(list, n);

	// swap statements
	if(largest < n - 1){
		temp = list[n-1];
		list[n-1] = list[largest];
		list[largest] = temp;
	}

	sort_states(list, n-1);

};

// this function finds the index of the state with largest population over 65
int find_largest(struct state_info list[], int n){

	int i, max_index = 0;

	for(i = 1; i < n; i++){
		if(list[i].over65 > list[max_index].over65){
			max_index = i;
		}	
	}

	return max_index;
};
