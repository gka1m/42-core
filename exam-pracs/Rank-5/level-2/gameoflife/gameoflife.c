#include "gameoflife.h"

// #include "gameoflife.h"

// /* Function to initialize the game struct and allocate board */
// int init_game(t_game *game, int width, int height)
// {
// 	int i, j;

// 	game->width = width;
// 	game->height = height;
// 	game->x = 0;
// 	game->y = 0;
// 	game->pendown = 0;

// 	game->board = malloc(sizeof(char *) * height);
// 	if (!game->board)
// 		return (-1);
	
// 	for (i = 0; i < height; i++)
// 	{
// 		game->board[i] = malloc(sizeof(char) * width);
// 		if (!game->board[i])
// 		{
// 			while (i > 0)
// 				free(game->board[--i]);
// 			free(game->board);
// 			return (-1);
// 		}
// 		/* Initialize all cells as dead (space) */
// 		for (j = 0; j < width; j++)
// 			game->board[i][j] = ' ';
// 	}
// 	return (0);
// }

// /* Function to free the game board */
// void free_game(t_game *game)
// {
// 	int i;

// 	if (game->board)
// 	{
// 		for (i = 0; i < game->height; i++)
// 			free(game->board[i]);
// 		free(game->board);
// 	}
// }

// /* Count alive neighbors of a cell */
// int count_neighbors(t_game *game, int x, int y)
// {
// 	int count = 0;
// 	int dx, dy, nx, ny;

// 	for (dy = -1; dy <= 1; dy++)
// 	{
// 		for (dx = -1; dx <= 1; dx++)
// 		{
// 			if (dx == 0 && dy == 0)
// 				continue; /* Skip the cell itself */
			
// 			nx = x + dx;
// 			ny = y + dy;
			
// 			/* Cells outside board are considered dead */
// 			if (nx >= 0 && nx < game->width && ny >= 0 && ny < game->height)
// 			{
// 				if (game->board[ny][nx] == 'O')
// 					count++;
// 			}
// 		}
// 	}
// 	return (count);
// }

// /* Simulate one step of Game of Life */
// int simulate_step(t_game *game)
// {
// 	char **next;
// 	int x, y, neighbors, i, j;

// 	next = malloc(sizeof(char *) * game->height);
// 	if (!next)
// 		return (-1);

// 	for (i = 0; i < game->height; i++)
// 	{
// 		next[i] = malloc(sizeof(char) * game->width);
// 		if (!next[i])
// 		{
// 			while (i > 0)
// 				free(next[--i]);
// 			free(next);
// 			return (-1);
// 		}
// 	}

// 	for (y = 0; y < game->height; y++)
// 	{
// 		for (x = 0; x < game->width; x++)
// 		{
// 			neighbors = count_neighbors(game, x, y);
			
// 			if (game->board[y][x] == 'O')
// 			{
// 				/* Live cell */
// 				if (neighbors == 2 || neighbors == 3)
// 					next[y][x] = 'O';
// 				else
// 					next[y][x] = ' ';
// 			}
// 			else
// 			{
// 				/* Dead cell */
// 				if (neighbors == 3)
// 					next[y][x] = 'O';
// 				else
// 					next[y][x] = ' ';
// 			}
// 		}
// 	}
	
// 	/* Free old board and assign new one */
// 	for (i = 0; i < game->height; i++)
// 		free(game->board[i]);
// 	free(game->board);
// 	game->board = next;
	
// 	return (0);
// }

// /* Parse commands from stdin and draw on board */
// void parse_commands(t_game *game)
// {
// 	char buffer[1];
// 	ssize_t bytes_read;

// 	while ((bytes_read = read(0, buffer, 1)) > 0)
// 	{
// 		char cmd = buffer[0];
		
// 		if (cmd == 'x')
// 		{
// 			/* Toggle pen */
// 			game->pendown = !(game->pendown);
// 			/* If pen just went down, mark current position */
// 			if (game->pendown && game->x >= 0 && game->x < game->width 
// 				&& game->y >= 0 && game->y < game->height)
// 				game->board[game->y][game->x] = 'O';
// 		}
// 		else if (cmd == 'w')
// 		{
// 			/* Move up */
// 			game->y--;
// 			if (game->y < 0)
// 				game->y = 0;
// 			if (game->pendown && game->x >= 0 && game->x < game->width 
// 				&& game->y >= 0 && game->y < game->height)
// 				game->board[game->y][game->x] = 'O';
// 		}
// 		else if (cmd == 's')
// 		{
// 			/* Move down */
// 			game->y++;
// 			if (game->y >= game->height)
// 				game->y = game->height - 1;
// 			if (game->pendown && game->x >= 0 && game->x < game->width 
// 				&& game->y >= 0 && game->y < game->height)
// 				game->board[game->y][game->x] = 'O';
// 		}
// 		else if (cmd == 'a')
// 		{
// 			/* Move left */
// 			game->x--;
// 			if (game->x < 0)
// 				game->x = 0;
// 			if (game->pendown && game->x >= 0 && game->x < game->width 
// 				&& game->y >= 0 && game->y < game->height)
// 				game->board[game->y][game->x] = 'O';
// 		}
// 		else if (cmd == 'd')
// 		{
// 			/* Move right */
// 			game->x++;
// 			if (game->x >= game->width)
// 				game->x = game->width - 1;
// 			if (game->pendown && game->x >= 0 && game->x < game->width 
// 				&& game->y >= 0 && game->y < game->height)
// 				game->board[game->y][game->x] = 'O';
// 		}
// 	}
// }

// /* Print the board */
// void print_board(t_game *game)
// {
// 	int x, y;

// 	for (y = 0; y < game->height; y++)
// 	{
// 		for (x = 0; x < game->width; x++)
// 		{
// 			putchar(game->board[y][x]);
// 		}
// 		putchar('\n');
// 	}
// }

// int main(int argc, char **argv)
// {
// 	int iterations, i;
// 	t_game game;

// 	if (argc != 4)
// 		return (1);

// 	/* Initialize game */
// 	if (init_game(&game, atoi(argv[1]), atoi(argv[2])) == -1)
// 		return (1);
	
// 	iterations = atoi(argv[3]);

// 	/* Parse commands from stdin */
// 	parse_commands(&game);

// 	/* Simulate game of life */
// 	for (i = 0; i < iterations; i++)
// 	{
// 		if (simulate_step(&game) == -1)
// 		{
// 			free_game(&game);
// 			return (1);
// 		}
// 	}

// 	/* Print final state */
// 	print_board(&game);

// 	/* Free memory */
// 	free_game(&game);

// 	return (0);
// }


int init_game(t_game* game, char* argv[])
{
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);
	game->alive = 'O';
	game->dead = ' ';
	game->i = 0;
	game->j = 0;
	game->draw = 0;
	game->board = (char**)malloc((game->height) * sizeof(char *));
	if(!(game->board))
		return(-1);
	for(int i = 0; i < game->height; i++)
	{
		game->board[i] = (char *)malloc((game->width) * sizeof(char));
		if(!(game->board[i])) {
			free_board(game);
			return(-1);
		}
		for(int j = 0; j < game->width; j++)
		{
			game->board[i][j] = ' ';
		}
	}
	return(0);
}

void fill_board(t_game* game)
{
	char buffer;
	int flag;

	while(read(STDIN_FILENO, &buffer, 1) == 1)
	{
		flag = 0;
		switch (buffer)
		{
		case 'w':
			if(game->i > 0)
			game->i--;
			break;
		case 's':
			if(game->i < (game->height - 1))
			game->i++;
			break;
		case 'a':
			if(game->j > 0)
			game->j--;
			break;
		case 'd':
			if(game->j < (game->width - 1))
			game->j++;
			break;
		case 'x':
			game->draw = !(game->draw);
			break;
		default:
			flag = 1;
			break;
		}

		if(game->draw && (flag == 0))
		{
			if((game->i >= 0 )&& (game->i < game->height) && (game->j >= 0) && (game->j < game->width))
				game->board[game->i][game->j] = game->alive;
		}
	}
}

int count_neighbors(t_game* game, int i, int j)
{
	int count = 0;
	for(int di = -1; di < 2; di++)
	{
		for(int dj = -1; dj < 2; dj++)
		{
			if((di == 0) && (dj == 0))
				continue;

			int ni = i + di;
			int nj = j + dj;
			if((ni >= 0) && (nj >=0) && (ni < game->height) && (nj < game->width)) {
				if(game->board[ni][nj] == game->alive)
					count++;
			}
		}
	}
	return(count);
}

int play(t_game* game)
{
	char** temp = (char**)malloc((game->height) * sizeof(char *));
	if(!temp)
		return(-1);
	for(int i = 0; i < game->height; i++)
	{
		temp[i] = (char *)malloc((game->width) * sizeof(char));
		if(!(temp[i]))
			return(-1);
	}

	for(int i = 0; i < game->height; i++)
	{
		for(int j = 0; j < game->width; j++)
		{
			int neighbors = count_neighbors(game, i, j);
			if(game->board[i][j] == game->alive) {
				if(neighbors == 2 || neighbors == 3) {
					temp[i][j] = game->alive;
				}
				else
					temp[i][j] = game->dead;
			}
			else {
				if(neighbors == 3) {
					temp[i][j] = game->alive;
				}
				else
					temp[i][j] = game->dead;
			}
		}
	}

	free_board(game);
	game->board = temp;
	return(0);
}

void print_board(t_game* game)
{
	for(int i = 0; i < game->height; i++)
	{
		for(int j = 0; j < game->width; j++)
		{
			putchar(game->board[i][j]);
		}
		putchar('\n');
	}
}

void free_board(t_game* game)
{
	if(game->board)
	{
		for(int i = 0; i < game->height; i++)
		{
			if(game->board[i])
				free(game->board[i]);
		}
		free(game->board);
	}
}

int main(int argc, char* argv[])
{
	if(argc != 4)
		return (1);

	t_game game;

	if(init_game(&game, argv) == -1)
		return(1);

	fill_board(&game);

	for(int i = 0; i < game.iterations; i++) {
		if(play(&game) == -1) {
			free_board(&game);
			return(1);
		}
	}
	print_board(&game);
	free_board(&game);

	return (0);
}