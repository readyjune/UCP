#include <stdio.h>

int main(void)
{

	int number;
	printf("Please type a number\n");
	scanf("%d", &number);

	if (number < 0 || number > 10)
	{
		printf("Out of range\n");
	}
	else if (number != 5)
	{
		printf("Wrong\n");
		printf("You need to type 5! not whatever you typed!\n");
	}
	else
	{
		printf("Correct\n");
		printf("You got it right!!!!\n");
	}
}
