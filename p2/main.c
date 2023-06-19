#include <stdio.h>
#include "powers.h"
#include "input.h"

int main()
{
	int answer;

	int i;
	int count;
	count = get_integer();

	for (i = 0; i < count; i++)
	{
		answer = power_of_two();
		printf("the next  power is %d\n", answer);
	}

	return 0;
}
