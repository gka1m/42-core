#include "bsq.h"

int loadelem(FILE* file, t_elem* elem)
{
    int r = fscanf(file, "%d%c%c%c", &(elem->nlines), &(elem->empty), &(elem->obstacle), &(elem->full));

    if (r != 4)
        return (-1);
    if (elem->nlines <= 0)
        return (-1);
    if (elem->empty == elem->obstacle || elem->empty == elem->full || elem->obstacle == elem->full)
        return (-1);
    if (elem->empty < 32 || elem->empty > 126)
        return (-1);
    if (elem->full < 32 || elem->full > 126)
        return (-1);
    if (elem->obstacle < 32 || elem->obstacle > 126)
        return (-1);
    return (0);
}

int loadmap(FILE *file, t_map *map, t_elem *elem)
{
    map->height = elem->nlines;
    map->grid = (char **)malloc((map->height + 1) * sizeof(char *));
    map->grid[map->height] = NULL;
    
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, file) == -1)
        return (free_map(map->grid), -1);
    for (int i = 0; i < map->height; i++)
    {
        int readed = getline(&line, &len, file);
        if (readed == -1)
            return (free(line), free_map(map->grid), -1);
        if (line[readed - 1] == '\n')
            readed--;
        else
            return (free(line), free_map(map->grid), -1);
        map->grid[i] = substr_own(line, 0, readed);
        if (!map->grid[i])
            return (free(line), free_map(map->grid), -1);
        if (i == 0)
            map->width = readed;
        else
        {
            if (map->width != readed)
                return (free(line), free_map(map->grid), -1);
        }
    }

    if (check_elem(map->grid, elem->empty, elem->obstacle) == -1)
        return (free(line), free_map(map->grid), -1);
    free(line);
    return (0);
}

void findbigsq(t_map *map, t_sq *sq, t_elem *elem)
{
    int mat[map->height][map->width];
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
            mat[i][j] = 0;
    }

    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            if (map->grid[i][j] == elem->obstacle)
                mat[i][j] = 0;
            else if (i == 0 || j == 0)
                mat[i][j] = 1;
            else
            {
                int min = findmin(mat[i - 1][j], mat[i - 1][j - 1], mat[i][j - 1]);
                mat[i][j] = min + 1;
            }
            if (mat[i][j] > sq->size)
            {
                sq->size = mat[i][j];
                sq->i = i - mat[i][j] + 1;
                sq->j = j - mat[i][j] + 1;
            }
        }
    }
}

void printfilled(t_map *map, t_sq *sq, t_elem *elem)
{
    for (int i = sq->i; i < sq->i + sq->size; i++)
    {
        for (int j = sq->j; j < sq->j + sq->size; j++)
        {
            if (i < map->height && j< map->width)
                map->grid[i][j] = elem->full; 
        }
    }
    for (int i = 0; i < map->height; i++)
    {
        fputs(map->grid[i], stdout);
        fputc('\n', stdout);
    }
}

int exec(FILE *file)
{
    t_elem elem;
    if (loadelem(file, &elem) == -1)
        return (-1);
    t_map map;
    if (loadmap(file, &map, &elem) == -1)
        return (-1);
    t_sq sq;
    sq.size = 0;
    sq.i = 0;
    sq.j = 0;
    findbigsq(&map, &sq, &elem);
    printfilled(&map, &sq, &elem);
    free_map(map.grid);
    return (0);
}

int convert_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return (-1);
    int ret = 0;
	ret = exec(file);
    fclose(file);
    return (ret);
}
