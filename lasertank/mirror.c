#define _DEFAULT_SOURCE
#include <time.h>
#include "ucpSleep.h"
#include "simple.h"
#include <stdlib.h>
#include <stdio.h>
#include "mirror2.h"
#include "linkedlist.h"


//when the direction is n
void mirror_backslash_shooting_from_down(char** array, int Player_row, int Player_col, int temp, int* Rows, int* Columns)
{
	system("clear");
	
	if (Player_col-2 == 0)
	{
		array[Player_row-2][Player_col-1] = ' ';
		return ;
	}
	else if (array[Player_row-2][Player_col-2] == '/')
	{
		array[Player_row-2][Player_col-1] = ' ';
		mirror_frontslash_shooting_from_right(array, Player_row-2, Player_col, temp, Rows, Columns);
		return ;
	}
	else if (array[Player_row-2][Player_col-2] == '\\')
	{
		array[Player_row-2][Player_col-1] = ' ';
		mirror_backslash_shooting_from_right(array, Player_row-2, Player_col, temp, Rows, Columns);
		return ;

	}
	array[Player_row-2][Player_col-1] = '-';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);
	
	temp = array[Player_row-2][Player_col-2];
	array[Player_row-2][Player_col-2] = array[Player_row-2][Player_col-1];
	array[Player_row-2][Player_col-1] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	mirror_backslash_shooting_from_down(array, Player_row, Player_col-1 ,temp, Rows, Columns);
}

void mirror_frontslash_shooting_from_down(char** array, int Player_row, int Player_col, int temp, int* Rows, int* Columns)
{

	system("clear");

	if (Player_col+3 == *Columns)
	{
		array[Player_row-2][Player_col+1] = ' ';
		return ;
	}
	else if (array[Player_row-2][Player_col+2] == '/')
	{
		array[Player_row-2][Player_col+1] = ' ';
		mirror_frontslash_shooting_from_left(array, Player_row-2, Player_col+2, temp, Rows, Columns);	
		return ;
	}
	else if (array[Player_row-2][Player_col+2] == '\\')
	{
		array[Player_row-2][Player_col+1] = ' ';
		mirror_backslash_shooting_from_left(array, Player_row-2, Player_col, temp, Rows, Columns);	
		return ;
	}


	array[Player_row-2][Player_col+1] = '-';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);

	temp = array[Player_row-2][Player_col+2];
	array[Player_row-2][Player_col+2] = array[Player_row-2][Player_col+1];
	array[Player_row-2][Player_col+1] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	mirror_frontslash_shooting_from_down(array, Player_row, Player_col+1, temp, Rows, Columns);

}

//when the direction is s
void mirror_backslash_shooting_from_up(char** array, int Player_row, int Player_col, int temp, int* Rows, int* Columns)
{
	system("clear");

	if (Player_col+3 == *Columns)
	{
		array[Player_row+2][Player_col+1] = ' ';
		return ;
	}
	else if (array[Player_row+2][Player_col+2] == '/')
	{
		array[Player_row+2][Player_col+1] = ' ';
		mirror_frontslash_shooting_from_left(array, Player_row+2, Player_col+2, temp, Rows, Columns);
		return;
	} 
	else if (array[Player_row+2][Player_col+2] == '\\')
	{
		array[Player_row+2][Player_col+1] = ' ';
		mirror_backslash_shooting_from_left(array, Player_row+2, Player_col, temp, Rows, Columns);
		return;
	}

	array[Player_row+2][Player_col+1] = '-';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);

	temp = array[Player_row+2][Player_col+2];
	array[Player_row+2][Player_col+2] = array[Player_row+2][Player_col+1];
	array[Player_row+2][Player_col+1] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	mirror_backslash_shooting_from_up(array, Player_row, Player_col+1, temp, Rows, Columns);
}

void mirror_frontslash_shooting_from_up(char** array, int Player_row, int Player_col, int temp, int* Rows, int* Columns)
{
	system("clear");
	
	if (Player_col-2 == 0)
	{
		array[Player_row+2][Player_col-1] = ' ';
		return ;
	}
	else if (array[Player_row+2][Player_col-2] == '/')
	{
		array[Player_row+2][Player_col-1] = ' ';
		mirror_frontslash_shooting_from_right(array, Player_row+2, Player_col, temp, Rows, Columns);
		return ;	
	}
	else if (array[Player_row+2][Player_col-2] == '\\')
	{
		array[Player_row+2][Player_col-1] = ' ';
		mirror_backslash_shooting_from_right(array, Player_row+2, Player_col, temp, Rows, Columns);
		return ;
	}


	array[Player_row+2][Player_col-1] = '-';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);

	temp = array[Player_row+2][Player_col-2];
	array[Player_row+2][Player_col-2] = array[Player_row+2][Player_col-1];
	array[Player_row+2][Player_col-1] = temp;

	
	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	mirror_frontslash_shooting_from_up(array, Player_row, Player_col-1, temp, Rows, Columns);

}

//when the direction is w
void mirror_backslash_shooting_from_right(char** array, int Player_row, int Player_col, int temp, int* Rows, int* Columns)
{

	system("clear");

	if (Player_row-2 == 0)
	{
		array[Player_row-1][Player_col-2] = ' ';
		return ;
	}
	else if (array[Player_row-2][Player_col-2] == '/')
	{
		array[Player_row-1][Player_col-2] = ' ';
		mirror_frontslash_shooting_from_down(array, Player_row, Player_col-2, temp, Rows, Columns);
		return ;

	}
	else if (array[Player_row-2][Player_col-2] == '\\')
	{
		array[Player_row-1][Player_col-2] = ' ';
		mirror_backslash_shooting_from_down(array, Player_row, Player_col-2, temp, Rows, Columns);
		return ;
	}
///////3rd reflection
//	else if (array[Player_row-4][Player_col-2] == '/')
//	{
//		array[Player_row-3][Player_col-2] = ' ';
//		mirror_frontslash_shooting_from_down(array, Player_row, Player_col, temp, Rows, Columns);
//		return ;
//	}

//////
	array[Player_row-1][Player_col-2] = '|';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);


	temp = array[Player_row-2][Player_col-2];
	array[Player_row-2][Player_col-2] = array[Player_row-1][Player_col-2];
	array[Player_row-1][Player_col-2] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	mirror_backslash_shooting_from_right(array, Player_row-1, Player_col, temp, Rows, Columns);
}

void mirror_frontslash_shooting_from_right(char** array, int Player_row, int Player_col, int temp, int* Rows, int* Columns)
{

	system("clear");

	if (Player_row+3 == *Rows)
	{
		array[Player_row+1][Player_col-2] = ' ';
		return;
	}
	else if (array[Player_row+2][Player_col-2] == '/')
	{
		array[Player_row+1][Player_col-2] = ' ';
		mirror_frontslash_shooting_from_up(array, Player_row, Player_col-2, temp, Rows, Columns);
		return ;
	}
	else if (array[Player_row+2][Player_col-2] == '\\')
	{
		array[Player_row+1][Player_col-2] = ' ';
		mirror_backslash_shooting_from_up(array, Player_row, Player_col-2, temp, Rows, Columns);
		return ;
	}
////// 3rd reflection
/*	else if (array[Player_row][Player_col-2] == '/')
	{
		array[Player_row-1][Player_col-2] = ' ';
		mirror_frontslash_shooting_from_up(array,Player_row, Player_col, temp, Rows, Columns);
		return ;
	}
	else if (array[Player_row][Player_col-2] == '\\')
	{
		array[Player_row-1][Player_col-2] = ' ';
		mirror_backslash_shooting_from_up(array,Player_row, Player_col, temp, Rows, Columns);
		return ;
	}*/
//////
	array[Player_row+1][Player_col-2] = '|';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);

	temp = array[Player_row+2][Player_col-2];
	array[Player_row+2][Player_col-2] = array[Player_row+1][Player_col-2];
	array[Player_row+1][Player_col-2] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	mirror_frontslash_shooting_from_right(array, Player_row+1, Player_col, temp, Rows, Columns);
}


//when the direction is e
void mirror_backslash_shooting_from_left(char** array, int Player_row, int Player_col, int temp, int* Rows, int* Columns)
{
//	int i;
//	int j;
	system("clear");

	if (Player_row+3 == *Rows)
	{
		array[Player_row+1][Player_col+2] = ' ';
		return;
	}
	else if (array[Player_row+2][Player_col+2] == '/')
	{
		array[Player_row+1][Player_col+2] = ' ';
		mirror_frontslash_shooting_from_up(array, Player_row, Player_col+2, temp, Rows, Columns);
		return ;
	}
	else if (array[Player_row+2][Player_col+2] == '\\')
	{
		array[Player_row+1][Player_col+2] = ' ';
		mirror_backslash_shooting_from_up(array, Player_row, Player_col+2, temp, Rows, Columns);
		return ;

	}

	array[Player_row+1][Player_col+2] = '|';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);

	temp = array[Player_row+2][Player_col+2];
	array[Player_row+2][Player_col+2] = array[Player_row+1][Player_col+2];
	array[Player_row+1][Player_col+2] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	mirror_backslash_shooting_from_left(array, Player_row+1, Player_col, temp, Rows, Columns);

}

void mirror_frontslash_shooting_from_left(char** array, int Player_row, int Player_col, int temp, int* Rows, int* Columns)
{
//	int i;
//	int j;
	system("clear");

	if (Player_row-2 == 0)
	{
		array[Player_row-1][Player_col+2] = ' ';
		return;
	}
	else if (array[Player_row-2][Player_col+2] == '/')
	{
		array[Player_row-1][Player_col+2] = ' ';	
		mirror_frontslash_shooting_from_down(array, Player_row, Player_col+2, temp, Rows, Columns);
		return ;
	}

	else if (array[Player_row-2][Player_col+2] == '\\')
	{
		array[Player_row-1][Player_col+2] = ' ';
		mirror_backslash_shooting_from_down(array, Player_row, Player_col+2, temp, Rows, Columns);
		return ;

	}

	array[Player_row-1][Player_col+2] = '|';
	print_map(array, Rows, Columns);
	system("clear");
	fflush(stdin);


	temp = array[Player_row-2][Player_col+2];
	array[Player_row-2][Player_col+2] = array[Player_row-1][Player_col+2];
	array[Player_row-1][Player_col+2] = temp;

	print_map(array, Rows, Columns);
	ucpSleep(0.25);
	system("clear");
	fflush(stdin);

	mirror_frontslash_shooting_from_left(array, Player_row-1, Player_col, temp, Rows, Columns);

}


