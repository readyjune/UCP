#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	time_t current_time = time(NULL);
	printf("The current time is: %ld\n", current_time);

	srand(time(NULL));

	int range = 5;
	int start = 100;

	int random_number = rand() % range + start;
	printf("The random number is : %d\n", random_number);

	if (random_number < 3)
	{
		printf("There's a spooky ghost here!\n");
	}

	else
	{
		printf("The street is quiet...\n");
	}


	return 0;
}
