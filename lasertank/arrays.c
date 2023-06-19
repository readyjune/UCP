#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "string.h"
#include "simple.h"
#include "ucpSleep.h"
#include "direction.h"
#include "shoot.h"
#include "linkedlist.h"


//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wunused"




void create_map_for_player_enemy(square_t* map, tank_t player, tank_t enemy)
{

	int i, j;

	map->array = malloc(map->row*sizeof(char*));

//Making a square!!!
	for (i=0; i<map->row; i++)
	{
		map->array[i] = malloc(map->col*sizeof(char));
		for (j=0; j<map->col; j++)
		{
			if(i==0 || i==map->row-1 || j==0 || j==map->col-1)
			{
				map->array[i][j] = '*';
			}
			else
			{
				map->array[i][j] = ' ';
			}
		}
	}
// Deciding Player & Enemy Direction
	character_direction_player_enemy(map->array, player.row, player.col, &player.direction, enemy.col, enemy.row, &enemy.direction);

}
/////////////////////////////////////////////////
void create_map_for_mirror(square_t* map, mirror_t mirror)
{
	if (mirror.direction == 'f')
	{
		map->array[mirror.row][mirror.col] = '/';
	}
	else if (mirror.direction == 'b')
	{
		map->array[mirror.row][mirror.col] = '\\';
	}

// Deciding Player & Enemy Direction
	character_direction_mirror(map->array, mirror.row, mirror.col, &mirror.direction);

}

//////////////////////////////////////////////////////////////////////////
//actual printing
////////////////
void create_map(square_t map, tank_t player, tank_t enemy, mirror_t mirror)

//void map(int map.row, int map.col, int player.row, int player.col, char* player.direction, int enemy.row, int enemy.col, char* enemy.direction, int mirror.row, int mirror.col, char* mirror.direction)
{	
	system("clear");

	int i, k;
	char aux = 'a';
	char temp = 'b';




// Initialize Player and Enemy HP
	int player_hp = 100;
	int enemy_hp = 100;

// Deciding Player & Enemy Direction
	character_direction(map.array, player.row, player.col, &player.direction, enemy.col, enemy.row, &enemy.direction, mirror.row, mirror.col, &mirror.direction);






// Printing Out Square ON Screen
	printf("Game's going on!!!!!!!!!!!!!\n");

	print_map(map.array, &map.row, &map.col);


		
	char choice;

// While loop will continue until enemy is dead or player is dead
	while (enemy_hp > 0 && player_hp > 0)
	{
		printf("w to go/face up\n");
		printf("s to go/face down\n");
		printf("a to go/face left\n");
		printf("d to go/face right\n");
		printf("f to shooot laser\n");
		printf("l to save the sequence\n");
		printf("action:			\n");
		scanf("%c", &choice);
//////////////////////////////////
//////    When player direction is North.
		if ((player.direction == 'n') && (enemy_hp > 0) && (player_hp > 0))
		{
			if (choice == 'w' && enemy_hp > 0 && player_hp > 0)
			{
				///When Player is just under the Enemy, and when player wants to move to North, it won't change anything.
				if ((player.row-1)==enemy.row && player.col==enemy.col && enemy_hp > 0 && player_hp > 0)
				{
					printf("can't change\n");

				}
				// can not go to mirror side
				else if (map.array[player.row-1][player.col] == '\\')
				{
					printf("can't change)\n");
				}
				else if (map.array[player.row-1][player.col] == '/')
				{
					printf("can't change)\n");
				}
				//Same map.col with enemy but it will move until just under the enemy
				else if ((player.row-1)!=enemy.row && player.col==enemy.col && enemy_hp > 0 && player_hp > 0)
				{
					player_north(map.array, aux, &player.row, &player.col);
					player.direction = 'n';
				}
				//When Player meets the wall, it won't change anything.
				else if (player.row-1 == 0)
				{
					printf("can't move\n");

				}
				//When Player and Enemy is on different Column. (Assumption for making a enemy tank shoot the player tank)
				else if(player.row - 1 > 0 && player.col != enemy.col && enemy_hp > 0 && player_hp > 0){
					//When Player moves only North, if enemy direction is North or South, it won't affect anyting. so player will just move to North)	
					if (enemy.direction == 'n' || enemy.direction == 's')
					{
						player_north(map.array, aux, &player.row, &player.col);				
						player.direction = 'n';
					}
					//But when enemy faces West or East and player moves but only if player tank is not just under the enemy, it will just move to North.
					else if ((enemy.direction == 'w' || enemy.direction == 'e') && player.row-1 != enemy.row && enemy_hp > 0 && player_hp > 0)
					{
						player_north(map.array, aux, &player.row, &player.col);	
						player.direction = 'n';
					}
///////Enemy direction is West and tank is trying to pass that way. it will get shot.

					// When enemy faces West and Player-1 row is same with enemy row.
					else if ((enemy.direction == 'w') && player.row-1 == enemy.row && enemy_hp > 0 &&  player_hp > 0)
					{
						///// When enemy's facing a west side and player passes to enemy west side------YOU LOSE
						if (player.col < enemy.col)
						{
							player_north(map.array, aux, &player.row, &player.col);	

							print_map(map.array, &map.row, &map.col);

							map.array[enemy.row][enemy.col-1] = '-';

							print_map(map.array, &map.row, &map.col);


							system("clear");
							for(k=enemy.col; k>player.col+1; k--)
							{
								temp = map.array[enemy.row][k-2];
								map.array[enemy.row][k-2] = map.array[enemy.row][k-1];
								map.array[enemy.row][k-1] = temp;

								if (k-2>player.col && player_hp > 0 && enemy_hp > 0)
								{
									print_map(map.array, &map.row, &map.col);
									ucpSleep(0.25);
									system("clear");
									fflush(stdin);				
								}
								else if ((k-2) == player.col && player_hp > 0 && enemy_hp > 0)
								{
									map.array[player.row][player.col] = 'X';
									map.array[enemy.row][k-1] = ' ';
									player_hp -= 1000;
									fflush(stdin);	
								}
							}

						}
						///// When enemy's facing a west side and player just wants to pass enemy right side, nothing happen.
						else if (player.col > enemy.col)
						{
							player_north(map.array, aux, &player.row, &player.col);	
							player.direction = 'n';
						}

					}
////////////Enemy direction is East and tank is trying to pass that way. it will get shot.
					//When enemy faces East, and player row-1 with enemy row and player tries to pass that row.
					else if ((enemy.direction == 'e') && player.row-1 == enemy.row && enemy_hp > 0 &&  player_hp > 0)
					{
						//when enemy faces East, and player tries to pass that way ------ YOU LOSE
						if (player.col > enemy.col)
						{
							player_north(map.array, aux, &player.row, &player.col);	

							print_map(map.array, &map.row, &map.col);

							map.array[enemy.row][enemy.col+1] = '-';

							print_map(map.array, &map.row, &map.col);


							system("clear");
							for(k=enemy.col; k<player.col-1; k++)
							{
								temp = map.array[enemy.row][k+2];
								map.array[enemy.row][k+2] = map.array[enemy.row][k+1];
								map.array[enemy.row][k+1] = temp;

								if (k+2<player.col && player_hp > 0 && enemy_hp > 0)
								{
									print_map(map.array, &map.row, &map.col);

									ucpSleep(0.25);
									system("clear");
									fflush(stdin);				
								}
								else if ((k+2) == player.col && player_hp > 0 && enemy_hp > 0)
								{
									map.array[player.row][player.col] = 'X';
									map.array[enemy.row][k+1] = ' ';
									player_hp -= 1000;
									fflush(stdin);
									
								}
							}
						}
						//When Enemy faces East and player tries to pass West side - nothing happen
						else if (player.col < enemy.col)
						{
							player_north(map.array, aux, &player.row, &player.col);	
							player.direction = 'n';
							ucpSleep(0.25);
							system("clear");
							fflush(stdin);


						}

					}
				}
			}
			//When you choose different direction with current direction, it will just change the direction.from here to
			else if ((choice == 's') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = 'v';
				player.direction = 's';
				fflush(stdin);

			}
			else if ((choice == 'a') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '<';
				player.direction = 'w';
				fflush(stdin);
			}
			else if ((choice == 'd') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '>';
				player.direction = 'e';
				fflush(stdin);
			}
			
			//until here
			//shooting function.
			else if ((choice == 'f') && (enemy_hp > 0) && player_hp > 0){


				shoot_north(map.array, &player.direction, player.row, player.col, temp, &map.row, &map.col, enemy.row, enemy.col, &enemy_hp, mirror.row, mirror.col, &mirror.direction);

			}
			else if (choice == 'l')
			{

				FILE *fp;
				fp = fopen("logfile.txt", "a+");

				ptr = head;
				while(ptr != NULL)
				{
					
					print_map_for_linkedlist(ptr->map.array, &ptr->map.row, &ptr->map.col);
					ptr = ptr->next;
				}

				fclose(fp);
			}
		
			fflush(stdin);


		}


///////////////////////////////////////////////////////
///When player direction is South
		else if ((player.direction == 's') && (enemy_hp > 0) && (player_hp > 0))
		{
			//When player direction is South and wants to go down
			if (choice == 's' && enemy_hp > 0 && player_hp > 0)
			{
				///When Player is just on the Enemy, and when player wants to move to South, it won't change anything.
				if ((player.row+1)==enemy.row && player.col==enemy.col && enemy_hp > 0 && player_hp > 0)
				{
					printf("can't change\n");

				}
				else if (map.array[player.row+1][player.col] == '\\')
				{
					printf("can't change)\n");
				}
				else if (map.array[player.row+1][player.col] == '/')
				{
					printf("can't change)\n");
				}
				else if ((player.row+1)!=enemy.row && player.col==enemy.col && enemy_hp > 0 && player_hp > 0)
				{
					player_south(map.array, aux, &player.row, &player.col);

					player.direction = 's';
					ucpSleep(0.25);
					system("clear");
					fflush(stdin);
				}
				else if (player.row+1 == map.row-1)
				{
					printf("can't move\n");

				}
				//When Player and Enemy is on different Column. (Assumption for making a enemy tank shoot the player tank)
				else if(player.row + 1 < map.row -1  && player.col != enemy.col && enemy_hp > 0 && player_hp > 0){
					//When Player moves only South, if enemy direction is North or South, it won't affect anyting. so player will just move to South)
					if (enemy.direction == 'n' || enemy.direction == 's')
					{
						player_south(map.array, aux, &player.row, &player.col);

						player.direction = 's';
						ucpSleep(0.25);
						system("clear");
						fflush(stdin);
					}
					//But when enemy faces West or East and player moves but only if player tank is not just on the enemy, it will just move to South.
					else if ((enemy.direction == 'w' || enemy.direction == 'e') && player.row+1 != enemy.row && enemy_hp > 0 && player_hp > 0)
					{
						player_south(map.array, aux, &player.row, &player.col);

						player.direction = 's';
						ucpSleep(0.25);
						system("clear");
						fflush(stdin);
					}

					// When enemy faces West and Player+1 row is same with enemy row.
					else if ((enemy.direction == 'w') && player.row+1 == enemy.row && enemy_hp > 0 &&  player_hp > 0)
					{
						///// When enemy's facing a west side and player passes to enemy west side------YOU LOSE
						if (player.col < enemy.col)
						{

							player_south(map.array, aux, &player.row, &player.col);
							print_map(map.array, &map.row, &map.col);

							map.array[enemy.row][enemy.col-1] = '-';

							print_map(map.array, &map.row, &map.col);


							system("clear");
							for(k=enemy.col; k>player.col+1; k--)
							{
								temp = map.array[enemy.row][k-2];
								map.array[enemy.row][k-2] = map.array[enemy.row][k-1];
								map.array[enemy.row][k-1] = temp;

								if (k-2>player.col && player_hp > 0 && enemy_hp > 0)
								{
									print_map(map.array, &map.row, &map.col);


									ucpSleep(0.25);
									system("clear");
									fflush(stdin);				
								}
								else if ((k-2) == player.col && player_hp > 0 && enemy_hp > 0)
								{
									map.array[player.row][player.col] = 'X';
									map.array[enemy.row][k-1] = ' ';
									player_hp -= 1000;
									fflush(stdin);
									
								}
							}
						}
						///// When enemy's facing a west side and player just wants to pass enemy right side, nothing happen.
						else if (player.col > enemy.col)

						{
							player_south(map.array, aux, &player.row, &player.col);
							player.direction = 's';
							ucpSleep(0.25);
							system("clear");
							fflush(stdin);
						}

					}
					//When enemy faces East, and player row-1 with enemy row and player tries to pass that row.
					else if ((enemy.direction == 'e') && player.row+1 == enemy.row && enemy_hp > 0 &&  player_hp > 0)
					{
						//when enemy faces East, and player tries to pass that way ------ YOU LOSE
						if (player.col > enemy.col)
						{

							player_south(map.array, aux, &player.row, &player.col);

							print_map(map.array, &map.row, &map.col);


							map.array[enemy.row][enemy.col+1] = '-';

							print_map(map.array, &map.row, &map.col);

							system("clear");
							for(k=enemy.col; k<player.col-1; k++)
							{
								temp = map.array[enemy.row][k+2];
								map.array[enemy.row][k+2] = map.array[enemy.row][k+1];
								map.array[enemy.row][k+1] = temp;

								if (k+2<player.col && player_hp > 0 && enemy_hp > 0)
								{
									print_map(map.array, &map.row, &map.col);

									ucpSleep(0.25);
									system("clear");
									fflush(stdin);				
								}
								else if ((k+2) == player.col && player_hp > 0 && enemy_hp > 0)
								{
									map.array[player.row][player.col] = 'X';
									map.array[enemy.row][k+1] = ' ';
									player_hp -= 1000;
									fflush(stdin);
									
								}
							}
						}
						//When Enemy faces East and player tries to pass West side - nothing happen
						else if (player.col < enemy.col)
						{
							player_south(map.array, aux, &player.row, &player.col);
							player.direction = 's';
							ucpSleep(0.25);
							system("clear");
							fflush(stdin);


						}

					}
				}
			}

//////////////
			
			else if ((choice == 'w') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '^';
				player.direction = 'n';

			}
			else if ((choice == 'a') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '<';
				player.direction = 'w';

			}
			else if ((choice == 'd') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '>';
				player.direction = 'e';

			}
			else if ((choice == 'f') && (enemy_hp > 0) && player_hp > 0){
				shoot_south(map.array, &player.direction, player.row, player.col, temp, &map.row, &map.col,  enemy.row, enemy.col, &enemy_hp, mirror.row, mirror.col, &mirror.direction);

			}
			else if (choice == 'l')
			{

				FILE *fp;
				fp = fopen("logfile.txt", "a+");

				ptr = head;
				while(ptr != NULL)
				{
					
					print_map_for_linkedlist(ptr->map.array, &ptr->map.row, &ptr->map.col);
					
					ptr = ptr->next;
				}

				printf("\n");
				fclose(fp);
			}
		
			fflush(stdin);
		}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

		else if ((player.direction == 'w') && (enemy_hp > 0))
		{

//////////////
			if (choice == 'a' && enemy_hp > 0 && player_hp > 0)
			{
				///When Player is just right side of the Enemy, and when player wants to move to West, it won't change anything.
				if (player.row==enemy.row && (player.col-1)==enemy.col && enemy_hp > 0 && player_hp > 0)
				{
					printf("can't change\n");

				}
				else if (map.array[player.row][player.col-1] == '\\')
				{
					printf("can't change)\n");
				}
				else if (map.array[player.row][player.col-1] == '/')
				{
					printf("can't change)\n");
				}
				else if (player.row==enemy.row && (player.col-1)!=enemy.col && enemy_hp > 0 && player_hp > 0)
				{
					player_west(map.array, aux, &player.row, &player.col);

					player.direction = 'w';
					ucpSleep(0.25);
					system("clear");
					fflush(stdin);
				}
				else if (player.col-1 == 0)
				{
					printf("can't move\n");

				}
				//When Player and Enemy is on different Row. (Assumption for making a enemy tank shoot the player tank)
				else if(player.row != enemy.row && player.col-1 > 0 && enemy_hp > 0 && player_hp > 0){
					//When Player moves only West, if enemy direction is West or East, it won't affect anyting. so player will just move to North)
					if (enemy.direction == 'w' || enemy.direction == 'e')
					{
						player_west(map.array, aux, &player.row, &player.col);

						player.direction = 'w';
						ucpSleep(0.25);
						system("clear");
						fflush(stdin);
					}
					//But when enemy faces North or South and player moves but only if player tank is not just right side of the enemy, it will just move to West.
					else if ((enemy.direction == 'n' || enemy.direction == 's') && player.col-1 != enemy.col && enemy_hp > 0 && player_hp > 0)
					{
						player_west(map.array, aux, &player.row, &player.col);

						player.direction = 'w';
						ucpSleep(0.25);
						system("clear");
						fflush(stdin);
					}

					// When enemy faces North and player.col-1 is same with enemy columns.
					else if ((enemy.direction == 'n') && player.col-1 == enemy.col && enemy_hp > 0 &&  player_hp > 0)
					{
						///// When enemy's facing a west side and player passes to enemy west side------YOU LOSE
						if (player.row < enemy.row && player_hp > 0)
						{

							player_west(map.array, aux, &player.row, &player.col);


							print_map(map.array, &map.row, &map.col);

							map.array[enemy.row-1][enemy.col] = '|';

							print_map(map.array, &map.row, &map.col);


							system("clear");
							for(k=enemy.row; k>player.row+1; k--)
							{
								temp = map.array[k-2][enemy.col];
								map.array[k-2][enemy.col] = map.array[k-1][enemy.col];
								map.array[k-1][enemy.col] = temp;
								if (k-2>player.row && player_hp > 0 && enemy_hp > 0)
								{

									print_map(map.array, &map.row, &map.col);

									ucpSleep(0.25);
									system("clear");
									fflush(stdin);				
								}
								else if ((k-2) == player.row && player_hp > 0 && enemy_hp > 0)
								{
									map.array[player.row][player.col] = 'X';
									map.array[k-1][enemy.col] = ' ';
									player_hp -= 1000;
									fflush(stdin);
									
								}
							}
						}
						///// When enemy's facing a North side and player just wants to pass enemy down side, nothing happen.
						else if (player.row > enemy.row && player_hp > 0)

						{
							player_west(map.array, aux, &player.row, &player.col);

							player.direction = 'w';
							ucpSleep(0.25);
							system("clear");
							fflush(stdin);



						}

					}
					//When enemy faces South, and player col-1 with enemy col and player tries to pass that row.
					else if ((enemy.direction == 's') && player.col-1 == enemy.col && enemy_hp > 0 &&  player_hp > 0)
					{
						//when enemy faces South, and player tries to pass that way ------ YOU LOSE
						if (player.row > enemy.row)
						{
							player_west(map.array, aux, &player.row, &player.col);


							print_map(map.array, &map.row, &map.col);

							map.array[enemy.row+1][enemy.col] = '|';

							print_map(map.array, &map.row, &map.col);

							system("clear");
							for(k=enemy.row; k<player.row-1; k++)
							{
								temp = map.array[k+2][enemy.col];
								map.array[k+2][enemy.col] = map.array[k+1][enemy.col];
								map.array[k+1][enemy.col] = temp;

								if (k+2<player.row && player_hp > 0 && enemy_hp > 0)
								{
									print_map(map.array, &map.row, &map.col);


									ucpSleep(0.25);
									system("clear");
									fflush(stdin);				
								}
								else if ((k+2) == player.row && player_hp > 0 && enemy_hp > 0)
								{
									map.array[player.row][player.col] = 'X';
									map.array[k+1][enemy.col] = ' ';
									player_hp -= 1000;
									fflush(stdin);
									
								}
							}
						}
						//When Enemy faces East and player tries to pass West side - nothing happen
						else if (player.row < enemy.row)
						{
							player_west(map.array, aux, &player.row, &player.col);

							player.direction = 'w';
							ucpSleep(0.25);
							system("clear");
							fflush(stdin);
						}

					}
				}
			}
			else if ((choice == 'w') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '^';
				player.direction = 'n';

			}
			else if ((choice == 'd') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '>';
				player.direction = 'e';

			}
			else if ((choice == 's') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = 'v';
				player.direction = 's';

			}
			else if ((choice == 'f') && (enemy_hp > 0) && player_hp > 0){
			shoot_west(map.array, &player.direction, player.row, player.col, temp, &map.row, &map.col,  enemy.row, enemy.col, &enemy_hp, mirror.row, mirror.col, &mirror.direction);


			}	
			else if (choice == 'l')
			{

				FILE *fp;
				fp = fopen("logfile.txt", "a+");

				ptr = head;
				while(ptr != NULL)
				{
					
					print_map_for_linkedlist(ptr->map.array, &ptr->map.row, &ptr->map.col);
					ptr = ptr->next;
				}

				printf("\n");
				fclose(fp);
			}
		
			fflush(stdin);
		}

///////////////////////////////////////////////////////
//When player directino is East
		else if ((player.direction == 'e') && (enemy_hp > 0) && (player_hp > 0))
		{
////////////When player direction is East and wants to go East way.
			if (choice == 'd' && enemy_hp > 0 && player_hp > 0)
			{
				///When Player is just left side of the Enemy, and when player wants to move to East, it won't change anything.
				if (player.row==enemy.row && (player.col+1)==enemy.col && enemy_hp > 0 && player_hp > 0)
				{
					printf("can't change\n");

				}
				else if (map.array[player.row][player.col+1] == '\\')
				{
					printf("can't change)\n");
				}
				else if (map.array[player.row][player.col+1] == '/')
				{
					printf("can't change)\n");
				}
				else if (player.row==enemy.row && (player.col+1)!=enemy.col && enemy_hp > 0 && player_hp > 0)
				{
					player_east(map.array, aux, &player.row, &player.col);

					player.direction = 'e';
					ucpSleep(0.25);
					system("clear");
					fflush(stdin);
				}
				else if (player.col+1 == map.col-1)
				{
					printf("can't move\n");

				}
				//When Player and Enemy is on different Row. (Assumption for making a enemy tank shoot the player tank)
				else if(player.row != enemy.row && player.col+1 < map.col -1 && enemy_hp > 0 && player_hp > 0){
					//When Player moves only East, if enemy direction is West or East, it won't affect anyting. so player will just move to North)
					if (enemy.direction == 'w' || enemy.direction == 'e')
					{
						player_east(map.array, aux, &player.row, &player.col);
						player.direction = 'e';
						ucpSleep(0.25);
						system("clear");
						fflush(stdin);
					}
					//But when enemy faces North or South and player moves but only if player tank is not just left side of the enemy, it will just move to West.
					else if ((enemy.direction == 'n' || enemy.direction == 's') && player.col+1 != enemy.col && enemy_hp > 0 && player_hp > 0)
					{
						player_east(map.array, aux, &player.row, &player.col);

						player.direction = 'e';
						ucpSleep(0.25);
						system("clear");
						fflush(stdin);
					}

					// When enemy faces North and player.col+1 is same with enemy columns.
					else if ((enemy.direction == 'n') && player.col+1 == enemy.col && enemy_hp > 0 &&  player_hp > 0)
					{
						///// When enemy's facing a North side and player passes to enemy north side------YOU LOSE
						if (player.row < enemy.row)
						{

							player_east(map.array, aux, &player.row, &player.col);


							print_map(map.array, &map.row, &map.col);

							map.array[enemy.row-1][enemy.col] = '|';

							print_map(map.array, &map.row, &map.col);

							system("clear");
							for(k=enemy.row; k>player.row+1; k--)
							{
								temp = map.array[k-2][enemy.col];
								map.array[k-2][enemy.col] = map.array[k-1][enemy.col];
								map.array[k-1][enemy.col] = temp;

								if (k-2>player.row && player_hp > 0 && enemy_hp > 0)
								{
									print_map(map.array, &map.row, &map.col);

									ucpSleep(0.25);
									system("clear");
									fflush(stdin);				
								}
								else if ((k-2) == player.row && player_hp > 0 && enemy_hp > 0)
								{
									map.array[player.row][player.col] = 'X';
									map.array[k-1][enemy.col] = ' ';
									player_hp -= 1000;
									fflush(stdin);
									
								}
							}
						}
						///// When enemy's facing a North side and player just wants to pass enemy down side, nothing happen.
						else if (player.row > enemy.row)

						{
							player_east(map.array, aux, &player.row, &player.col);

							player.direction = 'e';
							ucpSleep(0.25);
							system("clear");
							fflush(stdin);



						}

					}
					//When enemy faces South, and player col+1 with enemy col and player tries to pass that row.
					else if ((enemy.direction == 's') && player.col+1 == enemy.col && enemy_hp > 0 &&  player_hp > 0)
					{
						//when enemy faces South, and player tries to pass that way ------ YOU LOSE
						if (player.row > enemy.row)
						{
							player_east(map.array, aux, &player.row, &player.col);


							print_map(map.array, &map.row, &map.col);


							map.array[enemy.row+1][enemy.col] = '|';

							print_map(map.array, &map.row, &map.col);

							system("clear");
							for(k=enemy.row; k<player.row-1; k++)
							{
								temp = map.array[k+2][enemy.col];
								map.array[k+2][enemy.col] = map.array[k+1][enemy.col];
								map.array[k+1][enemy.col] = temp;

								if (k+2<player.row && player_hp > 0 && enemy_hp > 0)
								{
									print_map(map.array, &map.row, &map.col);

									ucpSleep(0.25);
									system("clear");
									fflush(stdin);				
								}
								else if ((k+2) == player.row && player_hp > 0 && enemy_hp > 0)
								{
									map.array[player.row][player.col] = 'X';
									map.array[k+1][enemy.col] = ' ';
									player_hp -= 1000;
									fflush(stdin);
									
								}
							}
						}
						//When Enemy faces East and player tries to pass West side - nothing happen
						else if (player.row < enemy.row)
						{
							player_east(map.array, aux, &player.row, &player.col);

							player.direction = 'e';
							ucpSleep(0.25);
							system("clear");
							fflush(stdin);


						}

					}
				}
			}

//////////////	경계선
			else if ((choice == 'w') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '^';
				player.direction = 'n';

			}
			else if ((choice == 'a') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = '<';
				player.direction = 'w';

			}
			else if ((choice == 's') && (enemy_hp > 0) && player_hp > 0){
				map.array[player.row][player.col] = 'v';
				player.direction = 's';

			}
			else if (choice == 'f' && (enemy_hp > 0) && player_hp > 0){
				shoot_east(map.array, &player.direction, player.row, player.col, temp, &map.row, &map.col, enemy.row, enemy.col, &enemy_hp, mirror.row, mirror.col, &mirror.direction);


			}		
			else if (choice == 'l')
			{

				FILE *fp;
				fp = fopen("logfile.txt", "a+");

				ptr = head;
				while(ptr != NULL)
				{
					
					print_map_for_linkedlist(ptr->map.array, &ptr->map.row, &ptr->map.col);
					ptr = ptr->next;
				}

				printf("\n");
				fclose(fp);
			}
		
			fflush(stdin);
			
		}


		else
		{
			printf("you put the wrong input\n");
			fflush(stdin);
		}

		system("clear");
		printf("Game's going on111111111111111\n");

	//	II_input(  --- i want to put map whenever my map is changed )   void  
	//	void II_input();
		II_input(map, player, enemy);

		system("clear");
		
		print_map(map.array, &map.row, &map.col);



	}

	if (player_hp < 0)
	{
		printf("you lose\n");
	}
	else if (enemy_hp < 0)
	{
		printf("You Win!!!\n");
	}

	FILE *fp;
	fp = fopen("logfile.txt", "a+");

	ptr = head;
	while(ptr != NULL)
	{
			
		print_map_for_linkedlist(ptr->map.array, &ptr->map.row, &ptr->map.col);
		ptr = ptr->next;
	}

	printf("\n");
	fclose(fp);

	fflush(stdin);



	for(i=0; i<map.row; i++)
	{
		free(map.array[i]);
	}
	free(map.array);
}


