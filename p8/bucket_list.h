#ifndef BUCKET_LIST_H
#define BUCKET_LIST_H

typedef struct BucketEntry
{
	char description[64];
	int completed;
} bucket_entry_t;

typedef struct BucketNode
{
	bucket_entry_t* data;
	struct BucketNode* next; //it's kind of self.
} bucket_node_t;

typedef struct BucketList
{
	bucket_node_t* head;
	int count;
} bucket_list_t;

void insert(bucket_list_t* list, bucket_entry_t* item);

#endif
