#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_elem
{
    int nlines;
    char empty;
    char obstacle;
    char full;
} t_elem;

typedef struct s_map
{
    char **grid;
    int width;
    int height;
} t_map;

typedef struct s_sq
{
    int size;
    int i;
    int j;
} t_sq;

// utils
char *substr_own(char *arr, int start, int len);
void free_map(char** arr);
int check_elem(char **arr, char c1, char c2);
int findmin(int n1, int n2, int n3);

// bsq file
int loadelem(FILE* file, t_elem* elem);
int loadmap(FILE* file, t_map *map, t_elem *elem);
void findbigsq(t_map *map, t_sq *sq, t_elem *elem);
void printfilled(t_map *map, t_sq *sq, t_elem *elem);
int exec(FILE *file);
int convert_file(char *filename);


#endif