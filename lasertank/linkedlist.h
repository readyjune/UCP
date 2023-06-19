#ifndef LINKEDLIST_H
#define LINKEDLIST_H
void free_map(square_t map, tank_t player, tank_t enemy);
#include "arrays.h"

void II_input();
void II_print();

struct NODE
{

	tank_t player;
	tank_t enemy;
	square_t map;
	mirror_t mirror;
	struct NODE *next;


} *head, *tail, *ptr;

#endif
