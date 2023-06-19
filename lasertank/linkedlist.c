#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "linkedlist.h"
#include "simple.h"



void II_input(square_t map, tank_t player, tank_t enemy)
{
	printf("this is input part\n");	
	int i, j;

	ptr = (struct NODE *)malloc(sizeof(struct NODE));
	if (head == NULL)
	{
		head = ptr;
	}
	else
	{
		tail->next = ptr;
	}

	ptr->map.row = map.row;
	ptr->map.col = map.col;

	ptr->player.row = player.row;
	ptr->player.col = player.col;
	ptr->player.direction = player.direction;
	ptr->enemy.row = enemy.row;
	ptr->enemy.col = enemy.col;
	ptr->enemy.direction = enemy.direction;

	ptr->map.array = malloc(ptr->map.row*sizeof(char*));

	for (i=0; i<ptr->map.row; i++)
	{
		ptr->map.array[i] = malloc(ptr->map.col*sizeof(char));
		for (j=0; j<ptr->map.col; j++)
		{
			ptr->map.array[i][j] = map.array[i][j];
		}
		
	}
	ptr->next = NULL;
	tail = ptr;
	
	II_print();
	free(ptr);

}

void free_map(square_t map, tank_t player, tank_t enemy)
{
	int i;
	struct NODE *next;
	ptr = head;
	while (ptr != NULL)
	{
		for(i=0; i<ptr->map.row; i++)
		{
			free(ptr->map.array[i]);
		}
		free(ptr->map.array);

		next = ptr->next;
		free(ptr);
		ptr = next;		

	}


}




void II_print()
{
	ptr = head;
	while(ptr != NULL)
	{

		printf(" %d", ptr->map.row);
		printf(" %d", ptr->map.col);
		printf(" %d", ptr->player.row);
		printf(" %d", ptr->player.col);
		printf(" %c", ptr->player.direction);
		printf(" %d", ptr->enemy.row);
		printf(" %d", ptr->enemy.col);
		printf(" %c", ptr->enemy.direction);

		print_map(ptr->map.array, &ptr->map.row, &ptr->map.col);

		
		ptr = ptr->next;
	}
	printf("\n");

}
