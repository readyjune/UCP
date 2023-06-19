#ifndef ARRAYS_H
#define ARRAYS_H

typedef struct tank
{
	int row;
	int col;
	char direction;

} tank_t;

typedef struct square
{
	int row;
	int col;
	char** array;
} square_t;

typedef struct mirror
{
	int row;
	int col;
	char direction;

} mirror_t;



void create_map(square_t map, tank_t player, tank_t enemy, mirror_t mirror);
void create_map_for_player_enemy(square_t* map, tank_t player, tank_t enemy);
void create_map_for_mirror(square_t* map, mirror_t mirror);

#endif
