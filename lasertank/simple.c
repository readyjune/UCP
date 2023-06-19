#include <stdio.h>

void player_north(char** array, int aux, int* Player_row, int* Player_col)
{
	aux = array[(*Player_row)-1][*Player_col];
	array[(*Player_row)-1][*Player_col] = array[*Player_row][*Player_col];
	array[*Player_row][*Player_col] = aux;
	(*Player_row) -= 1;
}


void player_south(char** array, int aux, int* Player_row, int* Player_col)
{
	aux = array[(*Player_row)+1][*Player_col];
	array[(*Player_row)+1][*Player_col] = array[*Player_row][*Player_col];
	array[*Player_row][*Player_col] = aux;
	(*Player_row) += 1;
}

void player_west(char** array, int aux, int* Player_row, int* Player_col)
{
	aux = array[*Player_row][(*Player_col)-1];
	array[*Player_row][(*Player_col)-1] = array[*Player_row][*Player_col];
	array[*Player_row][*Player_col] = aux;
	*Player_col -= 1;
}

void player_east(char** array, int aux, int* Player_row, int* Player_col)
{
	aux = array[*Player_row][(*Player_col)+1];
	array[*Player_row][(*Player_col)+1] = array[*Player_row][*Player_col];
	array[*Player_row][*Player_col] = aux;
	*Player_col += 1;
}

void print_map(char** array, int* Rows, int* Columns)
{
	int i;
	int j;
	for (i=0; i<*Rows; i++)
	{
		for(j=0; j<*Columns; j++)
		{
			printf("%c", array[i][j]);
		}
		printf("\n");
	}

}

void print_map_for_linkedlist(char** array, int* Rows, int* Columns)
{
	int i;
	int j;
	FILE *fp;
	fp = fopen("logfile.txt", "a+");


	for (i=0; i<*Rows; i++)
	{
		for(j=0; j<*Columns; j++)
		{
			fprintf(fp, "%c", array[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}


