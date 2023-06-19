#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"



int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Hello! Usage: ./program <number> \n");
		printf("The program will repeat \"number\" times \n");


	}
	else
	{
		int repeatTimes = atoi(argv[1]);
		
		int i;
		for(i = 0; i < repeatTimes; i++)
		{
	
	

			int* numbers = malloc(5 * sizeof(int));

			memcpy(numbers,(int[5]){28, 30, 5, 1, 6}, 5);

			printf("The sum of all the numbers is %d\n", sum(numbers, 5));

			free(numbers);	

		}
	}
	return 0;
}
