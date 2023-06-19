

void character_direction(char** array, int Player_row, int Player_col, char* Player_direction, int Enemy_col, int Enemy_row, char* Enemy_direction, int Mirror_row, int Mirror_col, char* Slash)
{
// Deciding Player Direction
	if (*Player_direction == 'n') 
	{
		array[Player_row][Player_col] = '^';
	}
	else if (*Player_direction == 's')
	{
		array[Player_row][Player_col] = 'v';
	}
	else if (*Player_direction == 'w')
	{
		array[Player_row][Player_col] = '<';
	}
	else if (*Player_direction == 'e')
	{
		array[Player_row][Player_col] = '>';
	}



// Deciding Enemy Direction
	if (*Enemy_direction == 'n') 
	{
		array[Enemy_row][Enemy_col] = '^';
	}
	else if (*Enemy_direction == 's')
	{
		array[Enemy_row][Enemy_col] = 'v';
	}
	else if (*Enemy_direction == 'w')
	{
		array[Enemy_row][Enemy_col] = '<';
	}
	else if (*Enemy_direction == 'e')
	{
		array[Enemy_row][Enemy_col] = '>';
	}


// Deciding Mirror
	if (*Slash == 'b')
	{
		array[Mirror_row][Mirror_col] = '\\';
	}
	else if (*Slash == 'f')
	{
		array[Mirror_row][Mirror_col] = '/';
	}
}

void character_direction_player_enemy(char** array, int Player_row, int Player_col, char* Player_direction, int Enemy_col, int Enemy_row, char* Enemy_direction)
{
// Deciding Player Direction
	if (*Player_direction == 'n') 
	{
		array[Player_row][Player_col] = '^';
	}
	else if (*Player_direction == 's')
	{
		array[Player_row][Player_col] = 'v';
	}
	else if (*Player_direction == 'w')
	{
		array[Player_row][Player_col] = '<';
	}
	else if (*Player_direction == 'e')
	{
		array[Player_row][Player_col] = '>';
	}



// Deciding Enemy Direction
	if (*Enemy_direction == 'n') 
	{
		array[Enemy_row][Enemy_col] = '^';
	}
	else if (*Enemy_direction == 's')
	{
		array[Enemy_row][Enemy_col] = 'v';
	}
	else if (*Enemy_direction == 'w')
	{
		array[Enemy_row][Enemy_col] = '<';
	}
	else if (*Enemy_direction == 'e')
	{
		array[Enemy_row][Enemy_col] = '>';
	}

}

void character_direction_mirror(char** array, int Mirror_row, int Mirror_col, char* Slash)
{
// Deciding Mirror
	if (*Slash == 'b')
	{
		array[Mirror_row][Mirror_col] = '\\';
	}
	else if (*Slash == 'f')
	{
		array[Mirror_row][Mirror_col] = '/';
	}
}

