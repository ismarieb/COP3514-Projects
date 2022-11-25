/* Author:	Ismarie Birriel
 * Program:	Program computes a suffix with at most M characters for each file
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

	FILE *myfile;
	int i;
	char str[51];
	char result[51]; 
	int M;

	printf("Enter the value of M: ");
	scanf("%d", &M);

	if(argc < 2){
		printf("Usage: ./a.out filename");
		return 1;
	} else {
		for(i = 1; i < argc; i++){
			myfile = fopen(argv[i], "r");
			if(myfile == 0){
				printf("Error opening file\n");
				return 1;
			} else {
				while(!feof(myfile) && !ferror(myfile)){
					if(fscanf(myfile, "%s", str) == 1){
						
						strcat(result, str);
		
						if(strlen(result) > M){
							strcpy(result, "");
							strcpy(result, str);
						}

					}		
				}			


			fclose(myfile);
				
			}
			printf("%s: %s\n", argv[i], result);
		}
	}

	return 0;
}
