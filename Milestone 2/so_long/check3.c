/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:39:53 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/24 15:21:21 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void dfs(char **map, int i, int j)
{
	int arrlen;

	arrlen = 0;
	while (map[arrlen])
		arrlen++;
	if (i < 0 || i >= arrlen || j < 0 || j >= ft_strlen(map[0]) || map[i][j] == '1' || map[i][j] == 'V')
		return;
	map[i][j] = 'V';
	dfs(map, i + 1, j);
	dfs(map, i - 1, j);
	dfs(map, i, j + 1);
	dfs(map, i, j - 1);
}

void floodfill(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				dfs(map, i, j);
				break;
			}
			j++;
		}
		i++;
	}
}

int check_path(t_map *map, char **map_arr)
{
	int i;
	int j;

	i = 0;
	floodfill(map_arr);
	while (map_arr[i])
	{
		j = 0;
		while (map_arr[i][j])
		{
			if (map_arr[i][j] == 'C' || map_arr[i][j] == 'E')
				return (free_map(map_arr), handle_error(map, "Error\nInvalid path"), 1);
			j++;
		}
		i++;
	}
	free_map(map_arr);
	free_map(map->map_array);
	return (0);
}

void free_map(char **map_array)
{
	int i;

	i = 0;
	if (map_array)
	{
		while (map_array[i])
		{
			free(map_array[i]);
			i++;
		}
		free(map_array);
	}
}

int validate_map(t_map *map, char *mapfile)
{
	char **copy;

	map->map_array = read_file(mapfile);
	if (!map->map_array)
		return (ft_printf("Failed to read map\n"), 1);
	init_dims(map);
	if (!validate_str(map))
		return (1);
	count_elems(map);
	if (!check_invalid_c(map))
		return (1);
	if (!validate_elem(map))
		return (1);
	copy = read_file(mapfile);
	if (check_path(map, copy) != 0)
		return (1);
	return (0);
}
