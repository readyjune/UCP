#define _DEFAULT_SOURCE
#include <time.h>
#include "ucpSleep.h"

#include <stdlib.h>
#include <stdio.h>
#include "mirror.h"
#include "arrays.h"
#include "linkedlist.h"
#include "simple.h"

square_t map;
	
tank_t player;

tank_t enemy;

mirror_t mirror;

void shoot_north(char** array, char* Player_direction, int Player_row, int Player_col, int temp, int* Rows, int* Columns, int Enemy_row, int Enemy_col, int *enemy_hp, int Mirror_row, int Mirror_col, char* Slash)
{
//	int i;
//	int j;
	system("clear");
	*Player_direction = 'n';

	if (Player_row-2 == 0)
	{
		array[Player_row-1][Player_col] = ' ';
		return;
	}

	else if (Player_row-2 == Enemy_row && Player_col == Enemy_col)
	{
		array[Enemy_row][Enemy_col] = 'X';
		array[Player_row-1][Player_col] = ' ';
		*enemy_hp = -1000;		
		return ;
	}
	else if (array[Player_row-2][Player_col] == '\\')
//	else if (Player_row-2 == Mirror_row && Player_col == Mirror_col && *Slash == 'b')
	{
		array[Player_row-1][Player_col] = ' ';
		mirror_backslash_shooting_from_down(array, Player_row, Player_col, temp, Rows, Columns);
		return ;

	}
	else if (array[Player_row-2][Player_col] == '/')
//	else if (Player_row-2 == Mirror_row && Player_col == Mirror_col && *Slash == 'f')
	{
		array[Player_row-1][Player_col] = ' ';
		mirror_frontslash_shooting_from_down(array, Player_row, Player_col, temp, Rows, Columns);
		return ;

	}


	array[Player_row-1][Player_col] = '|';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);


	temp = array[Player_row-2][Player_col];
	array[Player_row-2][Player_col] = array[Player_row-1][Player_col];
	array[Player_row-1][Player_col] = temp;


	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

//	II_input(map, player, enemy);
//	system("clear");
//	fflush(stdin);



	if (enemy_hp > 0)
	{
		shoot_north(array, Player_direction, Player_row-1, Player_col, temp, Rows, Columns,  Enemy_row, Enemy_col, enemy_hp, Mirror_row, Mirror_col, Slash);
	}
}

void shoot_south(char** array, char* Player_direction, int Player_row, int Player_col, int temp, int* Rows, int* Columns, int Enemy_row, int Enemy_col, int *enemy_hp, int Mirror_row, int Mirror_col, char* Slash)
{
//	int i;
//	int j;
	system("clear");
	*Player_direction = 's';

	if (Player_row+3 == *Rows) 
	{
		array[Player_row+1][Player_col] = ' ';
		return;
	}

	else if (Player_row+2 == Enemy_row && Player_col == Enemy_col)
	{
		array[Enemy_row][Enemy_col] = 'X';
		array[Player_row+1][Player_col] = ' ';
		*enemy_hp = -1000;
		return;
	}
	else if (array[Player_row+2][Player_col] == '\\')
//	else if (Player_row+2 == Mirror_row && Player_col == Mirror_col && *Slash == 'b')
	{
		array[Player_row+1][Player_col] = ' ';
		mirror_backslash_shooting_from_up(array, Player_row, Player_col, temp, Rows, Columns);
		return ;
	}
	else if (array[Player_row+2][Player_col] == '/')
//	else if (Player_row+2 == Mirror_row && Player_col == Mirror_col && *Slash == 'f')
	{
		array[Player_row+1][Player_col] = ' ';
		mirror_frontslash_shooting_from_up(array, Player_row, Player_col, temp, Rows, Columns);
		return ;
	}

	array[Player_row+1][Player_col] = '|';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);


	temp = array[Player_row+2][Player_col];
	array[Player_row+2][Player_col] = array[Player_row+1][Player_col];
	array[Player_row+1][Player_col] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);


	if (enemy_hp > 0)
	{
		shoot_south(array, Player_direction, Player_row+1, Player_col, temp, Rows, Columns,  Enemy_row, Enemy_col, enemy_hp, Mirror_row, Mirror_col, Slash);
	}
}

void shoot_west(char** array, char* Player_direction, int Player_row, int Player_col, int temp, int* Rows, int* Columns, int Enemy_row, int Enemy_col, int *enemy_hp, int Mirror_row, int Mirror_col, char* Slash)
{
//	int i;
//	int j;
	system("clear");
	*Player_direction = 'w';

	if (Player_col-2 == 0)
	{
		array[Player_row][Player_col-1] = ' ';
		return;
	}

	else if (Player_col-2 == Enemy_col && Player_row == Enemy_row)
	{
		array[Enemy_row][Enemy_col] = 'X';
		array[Player_row][Player_col-1] = ' ';
		*enemy_hp = -1000;
		return ;
	}
	else if (array[Player_row][Player_col-2] == '\\')
//	else if (Player_col-2 == Mirror_col && Player_row == Mirror_row && *Slash == 'b')
	{
		array[Player_row][Player_col-1] = ' ';
		mirror_backslash_shooting_from_right(array, Player_row, Player_col, temp, Rows, Columns);
		return ;

	}
	else if (array[Player_row][Player_col-2] == '/')
//	else if (Player_col-2 == Mirror_col && Player_row == Mirror_row && *Slash == 'f')
	{
		array[Player_row][Player_col-1] = ' ';
		mirror_frontslash_shooting_from_right(array, Player_row, Player_col, temp, Rows, Columns);
		return ;

	}


	array[Player_row][Player_col-1] = '-';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);


	temp = array[Player_row][Player_col-2];
	array[Player_row][Player_col-2] = array[Player_row][Player_col-1];
	array[Player_row][Player_col-1] = temp;	

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	if (enemy_hp > 0)
	{
		shoot_west(array, Player_direction, Player_row, Player_col-1, temp, Rows, Columns, Enemy_row, Enemy_col, enemy_hp, Mirror_row, Mirror_col, Slash);
	}
}

void shoot_east(char** array, char* Player_direction, int Player_row, int Player_col, int temp, int* Rows, int* Columns, int Enemy_row, int Enemy_col, int *enemy_hp, int Mirror_row, int Mirror_col, char* Slash)
{
//	int i;
//	int j;
	system("clear");
	*Player_direction = 'e';

	if (Player_col+3 == *Columns)
	{
		array[Player_row][Player_col+1] = ' ';
		return;
	}

	else if (Player_col+2 == Enemy_col && Player_row == Enemy_row)
	{
		array[Enemy_row][Enemy_col] = 'X';
		array[Player_row][Player_col+1] = ' ';
		*enemy_hp = -1000;
		return;
	}
	else if (array[Player_row][Player_col+2] == '\\')
//	else if (Player_col+2 == Mirror_col && Player_row == Mirror_row && *Slash == 'b')
	{
		array[Player_row][Player_col+1] = ' ';
		mirror_backslash_shooting_from_left(array, Player_row, Player_col, temp, Rows, Columns);
		return;
	}
	else if (array[Player_row][Player_col+2] == '/')
//	else if (Player_col+2 == Mirror_col && Player_row == Mirror_row && *Slash == 'f')
	{
		array[Player_row][Player_col+1] = ' ';
		mirror_frontslash_shooting_from_left(array, Player_row, Player_col, temp, Rows, Columns);
		return;

	}


	array[Player_row][Player_col+1] = '-';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);



	temp = array[Player_row][Player_col+2];
	array[Player_row][Player_col+2] = array[Player_row][Player_col+1];
	array[Player_row][Player_col+1] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);


	if (enemy_hp > 0)
	{
		shoot_east(array, Player_direction, Player_row, Player_col+1, temp, Rows, Columns, Enemy_row, Enemy_col, enemy_hp, Mirror_row, Mirror_col, Slash);
	}
}

