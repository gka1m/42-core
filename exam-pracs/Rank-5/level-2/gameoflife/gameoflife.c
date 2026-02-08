#include "gameoflife.h"

/* Function to allocate a 2D board */
char **allocate_board(int width, int height)
{
	char **board;
	int i, j;

	board = malloc(sizeof(char *) * height);
	if (!board)
		return (NULL);
	
	for (i = 0; i < height; i++)
	{
		board[i] = malloc(sizeof(char) * width);
		if (!board[i])
		{
			while (i > 0)
				free(board[--i]);
			free(board);
			return (NULL);
		}
		/* Initialize all cells as dead (space) */
		for (j = 0; j < width; j++)
			board[i][j] = ' ';
	}
	return (board);
}

/* Function to free a 2D board */
void free_board(char **board, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(board[i]);
	free(board);
}

/* Count alive neighbors of a cell */
int count_neighbors(char **board, int x, int y, int width, int height)
{
	int count = 0;
	int dx, dy, nx, ny;

	for (dy = -1; dy <= 1; dy++)
	{
		for (dx = -1; dx <= 1; dx++)
		{
			if (dx == 0 && dy == 0)
				continue; /* Skip the cell itself */
			
			nx = x + dx;
			ny = y + dy;
			
			/* Cells outside board are considered dead */
			if (nx >= 0 && nx < width && ny >= 0 && ny < height)
			{
				if (board[ny][nx] == 'O')
					count++;
			}
		}
	}
	return (count);
}

/* Simulate one step of Game of Life */
char **simulate_step(char **board, int width, int height)
{
	char **next;
	int x, y, neighbors;

	next = allocate_board(width, height);
	if (!next)
		return (board);

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			neighbors = count_neighbors(board, x, y, width, height);
			
			if (board[y][x] == 'O')
			{
				/* Live cell */
				if (neighbors == 2 || neighbors == 3)
					next[y][x] = 'O';
				else
					next[y][x] = ' ';
			}
			else
			{
				/* Dead cell */
				if (neighbors == 3)
					next[y][x] = 'O';
				else
					next[y][x] = ' ';
			}
		}
	}
	
	free_board(board, height);
	return (next);
}

/* Parse commands from stdin and draw on board */
void parse_commands(char **board, int width, int height)
{
	char buffer[1];
	int x = 0, y = 0;
	int pen_down = 0;
	ssize_t bytes_read;

	while ((bytes_read = read(0, buffer, 1)) > 0)
	{
		char cmd = buffer[0];
		
		if (cmd == 'x')
		{
			/* Toggle pen */
			pen_down = !pen_down;
			/* If pen just went down, mark current position */
			if (pen_down && x >= 0 && x < width && y >= 0 && y < height)
				board[y][x] = 'O';
		}
		else if (cmd == 'w')
		{
			/* Move up */
			y--;
			if (y < 0)
				y = 0;
			if (pen_down && x >= 0 && x < width && y >= 0 && y < height)
				board[y][x] = 'O';
		}
		else if (cmd == 's')
		{
			/* Move down */
			y++;
			if (y >= height)
				y = height - 1;
			if (pen_down && x >= 0 && x < width && y >= 0 && y < height)
				board[y][x] = 'O';
		}
		else if (cmd == 'a')
		{
			/* Move left */
			x--;
			if (x < 0)
				x = 0;
			if (pen_down && x >= 0 && x < width && y >= 0 && y < height)
				board[y][x] = 'O';
		}
		else if (cmd == 'd')
		{
			/* Move right */
			x++;
			if (x >= width)
				x = width - 1;
			if (pen_down && x >= 0 && x < width && y >= 0 && y < height)
				board[y][x] = 'O';
		}
	}
}

/* Print the board */
void print_board(char **board, int width, int height)
{
	int x, y;

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			putchar(board[y][x]);
		}
		putchar('\n');
	}
}

int main(int argc, char **argv)
{
	int width, height, iterations, i;
	char **board;

	if (argc != 4)
		return (1);
	
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	iterations = atoi(argv[3]);

	/* Allocate board */
	board = allocate_board(width, height);
	if (!board)
		return (1);

	/* Parse commands from stdin */
	parse_commands(board, width, height);

	/* Simulate game of life */
	for (i = 0; i < iterations; i++)
		board = simulate_step(board, width, height);

	/* Print final state */
	print_board(board, width, height);

	/* Free memory */
	free_board(board, height);

	return (0);
}


// int init_game(t_game* game, char* argv[])
// {
// 	game->width = atoi(argv[1]);
// 	game->height = atoi(argv[2]);
// 	game->iterations = atoi(argv[3]);
// 	game->alive = 'O';
// 	game->dead = ' ';
// 	game->i = 0;
// 	game->j = 0;
// 	game->draw = 0;
// 	game->board = (char**)malloc((game->height) * sizeof(char *));
// 	if(!(game->board))
// 		return(-1);
// 	for(int i = 0; i < game->height; i++)
// 	{
// 		game->board[i] = (char *)malloc((game->width) * sizeof(char));
// 		if(!(game->board[i])) {
// 			free_board(game);
// 			return(-1);
// 		}
// 		for(int j = 0; j < game->width; j++)
// 		{
// 			game->board[i][j] = ' ';
// 		}
// 	}
// 	return(0);
// }

// void fill_board(t_game* game)
// {
// 	char buffer;
// 	int flag;

// 	while(read(STDIN_FILENO, &buffer, 1) == 1)
// 	{
// 		flag = 0;
// 		switch (buffer)
// 		{
// 		case 'w':
// 			if(game->i > 0)
// 			game->i--;
// 			break;
// 		case 's':
// 			if(game->i < (game->height - 1))
// 			game->i++;
// 			break;
// 		case 'a':
// 			if(game->j > 0)
// 			game->j--;
// 			break;
// 		case 'd':
// 			if(game->j < (game->width - 1))
// 			game->j++;
// 			break;
// 		case 'x':
// 			game->draw = !(game->draw);
// 			break;
// 		default:
// 			flag = 1;
// 			break;
// 		}

// 		if(game->draw && (flag == 0))
// 		{
// 			if((game->i >= 0 )&& (game->i < game->height) && (game->j >= 0) && (game->j < game->width))
// 				game->board[game->i][game->j] = game->alive;
// 		}
// 	}
// }

// int count_neighbors(t_game* game, int i, int j)
// {
// 	int count = 0;
// 	for(int di = -1; di < 2; di++)
// 	{
// 		for(int dj = -1; dj < 2; dj++)
// 		{
// 			if((di == 0) && (dj == 0))
// 				continue;

// 			int ni = i + di;
// 			int nj = j + dj;
// 			if((ni >= 0) && (nj >=0) && (ni < game->height) && (nj < game->width)) {
// 				if(game->board[ni][nj] == game->alive)
// 					count++;
// 			}
// 		}
// 	}
// 	return(count);
// }

// int play(t_game* game)
// {
// 	char** temp = (char**)malloc((game->height) * sizeof(char *));
// 	if(!temp)
// 		return(-1);
// 	for(int i = 0; i < game->height; i++)
// 	{
// 		temp[i] = (char *)malloc((game->width) * sizeof(char));
// 		if(!(temp[i]))
// 			return(-1);
// 	}

// 	for(int i = 0; i < game->height; i++)
// 	{
// 		for(int j = 0; j < game->width; j++)
// 		{
// 			int neighbors = count_neighbors(game, i, j);
// 			if(game->board[i][j] == game->alive) {
// 				if(neighbors == 2 || neighbors == 3) {
// 					temp[i][j] = game->alive;
// 				}
// 				else
// 					temp[i][j] = game->dead;
// 			}
// 			else {
// 				if(neighbors == 3) {
// 					temp[i][j] = game->alive;
// 				}
// 				else
// 					temp[i][j] = game->dead;
// 			}
// 		}
// 	}

// 	free_board(game);
// 	game->board = temp;
// 	return(0);
// }

// void print_board(t_game* game)
// {
// 	for(int i = 0; i < game->height; i++)
// 	{
// 		for(int j = 0; j < game->width; j++)
// 		{
// 			putchar(game->board[i][j]);
// 		}
// 		putchar('\n');
// 	}
// }

// void free_board(t_game* game)
// {
// 	if(game->board)
// 	{
// 		for(int i = 0; i < game->height; i++)
// 		{
// 			if(game->board[i])
// 				free(game->board[i]);
// 		}
// 		free(game->board);
// 	}
// }

// int main(int argc, char* argv[])
// {
// 	if(argc != 4)
// 		return (1);

// 	t_game game;

// 	if(init_game(&game, argv) == -1)
// 		return(1);

// 	fill_board(&game);

// 	for(int i = 0; i < game.iterations; i++) {
// 		if(play(&game) == -1) {
// 			free_board(&game);
// 			return(1);
// 		}
// 	}
// 	print_board(&game);
// 	free_board(&game);

// 	return (0);
// }