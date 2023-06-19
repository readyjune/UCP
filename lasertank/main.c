#include <stdio.h>
#include "arrays.h"
#include <stdlib.h>
#include "simple.h"
#include "ucpSleep.h"
#include "shoot.h"
#include "linkedlist.h"


int main( int argc, char* argv[])
{
	square_t map;
	
	tank_t player;

	tank_t enemy;

	mirror_t mirror;


	char buf[1000];
	FILE *fp;

//	printf("'%s'", argv[1]);
	fp = fopen(argv[1], "r");


	if (fp == NULL)
	{
		printf("Error! Could not open file\n");
	}	

	fscanf(fp, "%d", &map.row);
//	printf("Row of n=%d\n", map.row);
	fscanf(fp, "%d", &map.col);

//	printf("Column of n=%d\n", map.col);

	fscanf(fp, "%d", &player.row);
//	printf("Player_row of n=%d\n", player.row);

	fscanf(fp, "%d", &player.col);
//	printf("Player_col of n=%d\n", player.col);

	fscanf(fp, " %c", &player.direction);
//	printf("Player_direction of n=%c\n", player.direction);

	fscanf(fp, "%d", &enemy.row);
//	printf("Enemy_row of n=%d\n", enemy.row);

	fscanf(fp, "%d", &enemy.col);
//	printf("Enemy_col of n=%d\n", enemy.col);

	fscanf(fp, " %c", &enemy.direction);
//	printf("Enemy_direction of n=%c\n", enemy.direction);









	getc(fp);

	//if there is not a command line argument.
	if(argv == NULL)
	{
		return printf("Error: Must provide proper command line argument!\n");	
	}
	// if the map size is not between 5~25
	else if (map.row < 5 || map.col < 5 || map.row > 25 || map.col > 25)
	{
		return printf("Error: map's row and col should be between 5~25\n");
	}
	//if player is located outside of the map.
	else if (player.row < 0 || player.row > map.row || player.col < 0 || player.col > map.col)
	{
		return printf("Error: player shouldn't be exist outside of map!\n");
	}

	//if enemy is located outside of the map.
	else if (enemy.row < 0 || enemy.row > map.row || enemy.col < 0 || enemy.col > map.col)
	{
		return printf("Error: enemy shouldn't be exist outside of the map!\n");
	}

	//when player and enemy are in same location.
	else if ((player.row == enemy.row) & (player.col == enemy.col))
	{
		return printf("Error: player and enemy can't be in same location!\n");
	}

	//when player is on the * boundary.
	else if(player.row == 0 || player.col == 0 || player.row == map.row || player.col == map.col)
	{
		return printf("Error: Player shouldn't be on the boundary \n");
	}

	//when enemy is on the * boundary.
	else if(enemy.row == 0 || enemy.col == 0 || enemy.row == map.row || enemy.col == map.col)
	{
		return printf("Error: Enemy shouldn't be on the boundary\n");
	}

	// The player tank will not be in front of the enemy tank immediately upon starting the game.(No instant lose)
	// When the enemy tank direction is North or South, player tank shouldn't be in same Columns.
	else if ((enemy.direction == 'n') || (enemy.direction == 's'))
	{
		if (player.col == enemy.col)
		{
			return printf("player is dead as soon as you started game\n");
		}
	}


	// When the enemy tank direction is West or East, player tank shouldn't be in the same Rows.
	else if ((enemy.direction == 'w') || (enemy.direction == 'e'))
	{
		if (player.row == enemy.row)
		{
			return printf("player is dead as soon as you started game\n");
		}
	}

	// When they don't put proper letter like t, x, q...
	else if ((player.direction != 'n') || (player.direction != 's') || (player.direction != 'w') || (player.direction != 'e'))
	{
		if ((player.direction == 'N') || (player.direction == 'S') || (player.direction == 'W') || (player.direction == 'E'))
		{
			return printf("Error: you have to put lowercase for letters");
		}
		else if ((player.direction != 'N') || (player.direction != 'S') || (player.direction != 'W') || (player.direction != 'E'))
		{
			return printf("Error: please put valid letter!");
		}

	}

	// When they didn't put proper letter like t, x q...
	else if ((enemy.direction != 'n') || (enemy.direction != 's') || (enemy.direction != 'w') || (enemy.direction != 'e'))
	{
		if ((enemy.direction == 'N') || (enemy.direction == 'S') || (enemy.direction == 'W') || (enemy.direction == 'E'))
		{
			return printf("Error: you have to put lowercase for letters");
		}
		else if ((enemy.direction != 'N') || (enemy.direction != 'S') || (enemy.direction != 'W') || (enemy.direction != 'E'))
		{
			return printf("Error: please put valid letter!");
		}

	}

	create_map_for_player_enemy(&map, player, enemy);

	while( (fgets(buf,1000, fp))!=NULL)
	{

		sscanf(buf, "%d %d %c", &mirror.row, &mirror.col, &mirror.direction);

	//	printf("mirror_row of n=%d\n", mirror.row);
	
	//	printf("mirror_col of n=%d\n", mirror.col);
	
	//	printf("mirror_direction of n=%c\n", mirror.direction);


		create_map_for_mirror(&map, mirror);
		

	}

	fclose(fp);

	create_map(map, player, enemy, mirror);

	//do free stuff for linked list

	free_map(map, player, enemy);



	return 0;

}







//fgets()  function reads characters from the stream and store them into the str.

// Use the fgetc() function to read from a text file, a character at a time.
// reads a character from a file.

// Use the fgets() function to read from a textfile, line by line.
// reads a string from a file.

// argc - will be the count of input arguments to your program.
// argv - will be a pointer to all the input arguments.






