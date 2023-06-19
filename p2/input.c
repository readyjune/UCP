#include <stdio.h>
#include "input.h"
int get_integer()
{
	int number;
	printf("please type a positive number less than 10\n");
	scanf("%d", &number);

	if(!is_valid(number))
	{
		printf("Error: Must be positive and less than 10\n");
		number = 0;
	}

	return number;


}

int is_valid(int number)
{
	return number > 0 && number < 10;
}
