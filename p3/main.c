#include <stdio.h>
#include "example.h"
#include <stdlib.h>
int* readInt()
{
	int* x = malloc(sizeof(int));
	printf("Please enter a number\n");
	scanf("%d", x);
	return x;
}

int main()
{
	

	int numberOne = 50;
	int numberTwo = 25;
	ascending2(&numberOne, &numberTwo);

	printf("%d and %d\n", numberOne, numberTwo);


	return 0;
}
