#include "bucket_list.h"
#include <stdlib.h>
void insert(bucket_list_t* list, bucket_entry_t* item)
{

	bucket_node_t* new_node = calloc(1, sizeof(bucket_node_t));
	new_node->next = list->head;
	list->head = new_node;
	new_node->data = item;
}
