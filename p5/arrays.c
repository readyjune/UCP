#include <stdio.h>
#include <stdlib.h>    //array
#include "arrays.h"
void print_map(float** map, int rows, int columns)
{
	int i, j;
	for(i = 0; i < rows; i++)
	{

		for(j = 0; j < columns; j++)
			printf("________");

		printf("\n");
		printf("| ");

		for(j = 0; j < columns; j++)
		{
			//print the number and a space for each cell
			printf("%-5.2f | ", map[i][j]);



		}
		//print enter at the end of each row
	
		//for(j = 0; j < columns; j++)
		//	printf("________");
		printf("\n");

	}




}

float** read_data(int* rows, int* columns)
{
	
	printf("reading the data\n");
	//open the file
	FILE* data_file = fopen("data.txt", "r");
	//Error checking
	if(data_file == NULL)
	{
		perror("Error opening file");
		return NULL;
	}

	//reading from txt file.

	fscanf(data_file, "%d %d", rows, columns);

	printf("Number of rows is: %d\nNumber of columns is: %d\n", *rows, *columns);

	//2D arrays
	//making array
	//array of array **
	float** array = malloc(*rows*sizeof(float*));
	int i;
	for(i = 0; i < *rows; i++)
	{
		array[i] = malloc(*columns*sizeof(float));
	}


	//going through all the array	
	for(i = 0; i < *rows; i++)
	{
		int j;
		for(j = 0; j < *columns; j++)
		{
			fscanf(data_file, "%f", &array[i][j]);
			//printf("(%d, %d): %f\n", i, j, array[i][j]); //어떤것이 있는지 보여줌.
			

		}
	}


	fclose(data_file);


	return array;
}
