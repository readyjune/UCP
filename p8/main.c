#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bucket_list.h"

int main()
{
	bucket_list_t* bucket_list = calloc(1, sizeof(bucket_list_t));

	int add_more = 1;
	while(add_more)
	{
		bucket_entry_t* new_item = malloc(1*sizeof(bucket_entry_t));
		printf("description: ");
		scanf(" %63[^\n]", new_item->description);
		printf("completed\n1. yes\n0. no\n");
		scanf(" %d", &new_item->completed);

		insert(bucket_list, new_item);

		printf("do you want to add another?\n1. yes\n0. no\n");
		scanf(" %d", &add_more);
	}

	printf("the items are: \n");
	bucket_node_t* current = bucket_list->head;
	while(current != NULL)
	{
		printf("%s\n", current->data->description);
		current = current->next;
	}
	free(bucket_list);
	return 0;

}
