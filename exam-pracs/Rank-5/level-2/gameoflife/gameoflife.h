#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_game
{
    char **board;
    int width;
    int height;
    int x;
    int y;
    int pendown;
} t_game;

char **allocate_board(int width, int height);
void free_board(char **board, int height);
int count_neighbors(char **board, int x, int y, int width, int height);
char **simulate_step(char **board, int width, int height);
void parse_commands(char **board, int width, int height);
void print_board(char **board, int width, int height);

// typedef struct s_game
// {
// 	int width;
// 	int height;
// 	int iterations;
// 	char alive;
// 	char dead;
// 	int i;
// 	int j;
// 	int draw;
// 	char** board;
// } t_game;

// int init_game(t_game* game, char* argv[]);
// void fill_board(t_game* game);
// int play(t_game* game);
// void print_board(t_game* game);
// void free_board(t_game* game);


#endif