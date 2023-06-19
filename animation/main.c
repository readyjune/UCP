#include <stdio.h>
#include <stdlib.h>
#include "ucpSleep.h"

int main()
{

	system("clear");
	printf("I'm going to do cool dance! \n");
	ucpSleep(1.0);
	system("clear");
	char* dance_guy[4];
	dance_guy[0] ="   ___  \n"
				  "  |   | \n"
				  "  |\e[0;34mo o\e[0m| \n"
				  "  |___| \n"
				  "    |   \n"
				  "  --|-- \n"
				  "   / \\ \n";

	dance_guy[1]= "   ___  \n"
				  "  |   | \n"
				  "  |\e[0;34mo o\e[0m| \n"
				  "  |___|/\n"
				  "    |_/ \n"
				  "  --|   \n"
				  "   / \\ \n";

	dance_guy[2]= "   ___  \n"
				  "  |   | \n"
				  "  |\e[0;34mo o\e[0m| \n"
				  " \\|___|/\n"
				  "  \\_|_/ \n"
				  "    |   \n"
				  "   / \\ \n";
	dance_guy[3]= "   ___  \n"
				  "  |   | \n"
				  "  |\e[0;34mo o\e[0m| \n"
				  " \\|___| \n"
				  "  \\_|__ \n"
				  "    |   \n"
				  "   / \\ \n";



	int i, j;
	for(i = 0; i < 30; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%s", dance_guy[j]);
			ucpSleep(0.25);
			system("clear");

		}
	}

	return 0;
}
