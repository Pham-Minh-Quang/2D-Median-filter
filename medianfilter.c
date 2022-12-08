#include "medianfilter.h"
#include <stdio.h>
#include <stdlib.h>

int** MedianFilter(int arr[244][310]) {
	int runMedian[3][3];
	//int result[242][308];
	int** result;

	result = malloc(sizeof(int*) * 242); //Dynamically allocate space for an array of pointer to each row of data

	for (int i = 0; i < 300; i++) {
		//Each pointer point to a double is going to a row of data and that row of data needs to store double for each column
		result[i] = malloc(sizeof(int) * 308);
	}

	for (int i = 0; i < 242; i++) {

		for (int j = 0; j < 308; j++) {
			int countRow = i;

			for (int r = 0; r < 3; r++) {

				int countColumn = j;
				//Add each element into the matrix 3x3 
				for (int c = 0; c < 3; c++) {
					runMedian[r][c] = arr[countRow][countColumn];
					countColumn++;
				}
				countRow++;
			}

			//Add vao mang 1 chieu
			int oneArray[9];

			int count = 0;
			for (int r2 = 0; r2 < 3; r2++) {
				for (int c2 = 0; c2 < 3; c2++) {
					oneArray[count] = runMedian[r2][c2];
					count++;
				}
			}

			//Decending order
			for (int k = 0; k < 8; k++) {
				for (int l = k + 1; l < 9; l++) {
					if (oneArray[k] > oneArray[l]) {
						int temp = oneArray[k];
						oneArray[k] = oneArray[l];
						oneArray[l] = temp;
					}
				}
			}
			//After sorting is done, take the number in the middle
			result[i][j] = oneArray[4];
		}
	}
	return result;
}
