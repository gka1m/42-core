/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:50:56 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/23 12:31:57 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

int	validate_str(t_map *map)
{
	int	error_flag;

	error_flag = 0;
	if (!is_rect(map))
	{
		ft_printf("Error\nMap is not rectangular\n");
		error_flag = 1;
	}
	if (!surrounded(map))
	{
		ft_printf("Error\nMap not surrounded by walls\n");
		error_flag = 1;
	}
	if (error_flag)
		return (handle_error(map, "Invalid structure"), 0);
	return (1);
}

void	count_elems(t_map *map)
{
	int	i;
	int	j;

	map->player = 0;
	map->collectibles = 0;
	map->exit = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_array[i][j] == 'C')
				map->collectibles++;
			else if (map->map_array[i][j] == 'E')
				map->exit++;
			else if (map->map_array[i][j] == 'P')
				map->player++;
			j++;
		}
		i++;
	}
}

int	validate_elem(t_map *map)
{
	int error_flag;

	error_flag = 0;
	if (map->player != 1)
	{
		ft_printf("Error\nMap must have 1 player.\n");
		error_flag = 1;
	}
	if (map->collectibles < 1)
	{
		ft_printf("Error\nMap must have at least 1 collectible.\n");
		error_flag = 1;
	}
	if (map->exit != 1)
	{
		ft_printf("Error\nMap must have exactly 1 exit.\n");
		error_flag = 1;
	}
	if (error_flag)
		return (handle_error(map, "Missing map elements."), 0);
	return (1);
}

void	dfs(char **map, int i, int j)
{
	int	arrlen;

	arrlen = 0;
	while (map[arrlen])
		arrlen++;
	if (i < 0 || i >= arrlen || j < 0 || j >= ft_strlen(map[0])
		|| map[i][j] == '1' || map[i][j] == 'V')
		return ;
	map[i][j] = 'V';
	dfs(map, i + 1, j);
	dfs(map, i - 1, j);
	dfs(map, i, j + 1);
	dfs(map, i, j - 1);
}

void	floodfill(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				dfs(map, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
}
