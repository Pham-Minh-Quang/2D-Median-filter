#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "medianfilter.h"

int main() {
	int** resultmedian;
	int arr[244][310];
	//Add csv file into 2d-array
	FILE* csvFile = fopen("noisy.csv", "r");

	if (!csvFile) {
		printf("Unable to open the file!");
		exit(1);
	}

	//Save the value from csv file into 2d-array
	for (int i = 0; i <= 243; i++) {
		arr[i][0] = arr[i][309] = 0;
		for (int j = 0; j <= 309; j++) {
			arr[0][j] = arr[243][j] = 0;
		}
	}

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

	return 0;
}
			
