#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define ORG_NAME_LEN 50
#define SIZE_LEN 3

struct tshirt {
	char org_name[ORG_NAME_LEN+1];
	char size[SIZE_LEN+1];
	double price;
	int quantity;
	struct tshirt *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

struct tshirt * add_to_inventory(struct tshirt *inventory);
void search_by_organization(struct tshirt *inventory);
void search_by_size(struct tshirt *inventory);
void print_inventory(struct tshirt *inventory);
void clear_inventory(struct tshirt *inventory);
int read_line(char str[], int n);
void help();

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main() {
	char code;

	struct tshirt *inventory = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'a':
				inventory = add_to_inventory(inventory);
				break;
			case 'h':
				help();
				break;
			case 'o':
				search_by_organization(inventory);
				break;
			case 's':
				search_by_size(inventory);
				break;
			case 'p':
				print_inventory(inventory);
				break;
			case 'q':
				clear_inventory(inventory);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}

//////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'a' for adding a t-shirt to the inventory;\n");
	printf("\t'h' for help;\n");
	printf("\t'o' for searching t-shirts by organization;\n");
	printf("\t's' for searching t-shirts by size;\n");
	printf("\t'p' for printing the inventory;\n");
	printf("\t'q' for quit.\n");
}

struct tshirt *add_to_inventory(struct tshirt *inventory) {

	struct tshirt *p = (struct tshirt*)malloc(sizeof(struct tshirt)); 
	struct tshirt *prev, *cur;

	if(p == NULL){
		printf("Error with malloc\n");
		return inventory;
	}

	printf("Enter the student organization name: ");
	read_line(p->org_name, ORG_NAME_LEN + 1);

	printf("Enter t-shirt size: ");
	read_line(p->size, SIZE_LEN + 1);

	// if no previous inventory
	if(inventory == NULL){

		inventory = p;
		p->next = NULL;

		printf("Enter price: ");
		scanf("%lf", &p->price);

		printf("Enter quantity: ");
		scanf("%d", &p->quantity);
		
		return inventory;
	}


	// for statement stops at point of insertion for case to insert org_name
	for(cur = inventory, prev = NULL; cur != NULL && strcmp(p->org_name, cur->org_name) > 0; prev = cur, cur = cur->next);

	if(cur != NULL && strcmp(p->org_name, cur->org_name)==0){
		if(strcmp(p->size, cur->size)==0){
			printf("T-shirt already exists in the inventory!\n");
		} else if (strcmp(p->size, cur->size) >0){
			printf("Enter price: ");
			scanf("%lf", &p->price);
			printf("Enter quantity: ");
			scanf("%d", &p->quantity);

			p->next = cur->next;
			cur->next = p;
			prev->next = cur;
			return inventory;
		}
	} 

	printf("Enter price: ");
	scanf("%lf", &p->price);

	printf("Enter quantity: ");
	scanf("%d", &p->quantity);


	p->next = cur;
	if(prev == NULL){
		return p;
	} else {
		prev->next = p;
		return inventory;
	}
		
}

void search_by_organization(struct tshirt *inventory) {

	struct tshirt *p = inventory;
	char org_name[ORG_NAME_LEN + 1];
	p = malloc(sizeof(struct tshirt));
	if(p == NULL){
		printf("Error with malloc\n");
		exit(0);
	}

	printf("Enter student organization name: ");
	read_line(org_name, ORG_NAME_LEN + 1);

	
	while(p != NULL){
		if(strcmp(p->org_name, org_name) == 0){
			p = p->next;
			printf("|----------------------------------------------------|-----|-------|------|\n");
			printf("| Student Organization                               | Sz. | Price | Qty. |\n");
			printf("|----------------------------------------------------|-----|-------|------|\n");
			
			printf("| %-50s | %-3s | %5.2lf | %4d |\n", p->org_name, p->size, p->price, p->quantity);
			
			printf("|----------------------------------------------------|-----|-------|------|\n");
			return;
		} else {
			printf("No t-shirt found!\n");
		}
		p = p->next;
	}	
}
	
void search_by_size(struct tshirt *inventory) {
 
	struct tshirt *p;
	char size[SIZE_LEN + 1];

	p = malloc(sizeof(struct tshirt));
	if(p == NULL){
		printf("Error with malloc\n");
		exit(0);
	}

	printf("Enter desired size: \n");
	read_line(size, SIZE_LEN);

	while(p != NULL){
		if(strcmp(p->size, size) == 0){
			p = p->next;	
			printf("|----------------------------------------------------|-----|-------|------|\n");
			printf("| Student organization                               | Sz. | Price | Qty. |\n");
			for(p = inventory; p != NULL; p = p->next){
			printf("| %-50s | %-3s | %5.2f | %4d |\n", p->org_name, p->size, p->price, p->quantity);
			}
			printf("|----------------------------------------------------|-----|-------|------|\n");	
			return;
		} else {
			printf("No t-shirt found!\n");
		}
		p = p->next;
	}
}


void print_inventory(struct tshirt *inventory){

	struct tshirt *p;

	if(inventory == NULL){
		printf("No t-shirt found!\n");
	} else {

	printf("|----------------------------------------------------|-----|-------|------|\n");
	printf("| Student organization                               | Sz. | Price | Qty. |\n");
	printf("|----------------------------------------------------|-----|-------|------|\n");
	for( p = inventory; p != NULL; p = p->next){

	printf("| %-50s | %-3s | %5.2f | %4d |\n", p->org_name, p->size, p->price, p->quantity);
	}
	printf("|----------------------------------------------------|-----|-------|------|\n");

	}
}

void clear_inventory(struct tshirt *inventory) {

	struct tshirt *p;

	while(inventory != NULL){
		p = inventory;
		inventory = inventory->next;
		if(p != NULL){
			free(p);
		}
	}

}

int read_line(char str[], int n){
	int ch, i=0;

	while (isspace(ch = getchar()))
		;
	str[i++] = ch;
	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;    
	}
	str[i] = '\0';
	return i;
}

