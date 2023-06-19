#include <stdio.h>
#include "arrays.h"
#include <stdlib.h>

int main()
{

	
	//function for reading data
	int rows, columns;
	float** number_map = read_data(&rows, &columns);
	

	//making a grid
	print_map(number_map, rows, columns);

	int i;
	for(i = 0; i < rows; i++)
	{
		free(number_map[i]);
	}


	free(number_map);
	return 0;
}
