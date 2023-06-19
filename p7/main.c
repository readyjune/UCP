#include <stdio.h>
#include <string.h>
#include "book.h"
#include <stdlib.h>


int main()
{
	book_t* robs_biography = malloc(1*sizeof(book_t));

	robs_biography->number_of_pages = 20;
	strcpy(robs_biography->title, "Coding is a thing I do.");

	printf("My book has %d pages and is named '%s'\n", robs_biography->number_of_pages, robs_biography->title);


	free(robs_biography);
	return 0;
}
