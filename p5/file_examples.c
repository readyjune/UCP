#include <stdio.h>

int main()
{

	/* Open the file */
	FILE* inputFile = fopen("data.txt", "r");
	if(inputFile == NULL)
	{

		printf("Error the ile failed to open\n");

	}
	else
	{
		char text[28];

		int number_of_items;

		do

		{

			number_of_items = fscanf(inputFile, "%27s", text);

			if(number_of_items == 1)
			{

				fprintf(stdout, "the text is: %s\n", text);
			}
		} while (number_of_items == 1);

		if (ferror(inputFile))

		{
			perror("Error");
		}
		fclose(inputFile);
	}

	return 0;

}
