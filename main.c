#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "medianfilter.h"

int main() {
	int** resultmedian;
	int arr[244][310];
	//Add noisy.csv file into 2d-array
	FILE* csvFile = fopen("noisy.csv", "r");

	if (!csvFile) {
		printf("Unable to open the file!");
		exit(1);
	}

	//Creating border
	for (int i = 0; i <= 243; i++) {
		arr[i][0] = arr[i][309] = 0;
		for (int j = 0; j <= 309; j++) {
			arr[0][j] = arr[243][j] = 0;
		}
	}
	
	//Save the value from noisy.csv file into 2d-array
	char line[1500];
	
	for (int i = 1; i < 243; i++) {	
		if( fgets(line, sizeof(line), csvFile)!=NULL ) {
			char* token = strtok(line, ","); //Start the new line
		
			for (int j = 1; j < 309; j++) {
				arr[i][j] = atoi(token);
				if ( (token = strtok(NULL, ",")) )
					continue;
				}
		}
	}
	fclose(csvFile);

	resultmedian = MedianFilter(arr);

	//Export the data into csv file
	FILE *fpt;
	fpt = fopen("testClean-using-pointer.csv", "w+");
	for (int i = 0; i < 242; i++)
	{
		for (int j = 0; j < 308; j++)
		{
			fprintf(fpt, "%d,", resultmedian[i][j]);
		}
		fprintf(fpt,"\n");
	}
	fclose(fpt);
	
	//Test - Check again
	int arrtest[242][308];
	int test = 0;

	FILE* check = fopen("clean.csv", "r");

	if (!check) {
		printf("Unable to open the file!");
		exit(1);
	}

	//Save the value from noisy.csv file into 2d-array
	char linecheck[1500];
	
	for (int i = 0; i < 242; i++) {
		if (fgets(linecheck, sizeof(linecheck), csvFile) != NULL) {
			char* tokencheck = strtok(linecheck, ","); //Start the new line
			for (int j = 0; j < 308; j++) {
				arrtest[i][j] = atoi(tokencheck);
				if ((tokencheck = strtok(NULL, ",")))
					continue;
			}
		}
	}
	fclose(check);

	for (int i = 0; i < 242; i++) {
		for (int j = 0; j < 308; j++) {
			if (arrtest[i][j] == resultmedian[i][j])
				test++;
			else
				printf("Position %d and %d is different",i,j);
		}
	}
	printf("%d", test);
	return 0;
}
			
