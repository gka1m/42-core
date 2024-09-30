/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:50:56 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/30 14:25:04 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

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
	int	error_flag;

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

int	check_invalid_c(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_array[i][j] != '1' && map->map_array[i][j] != '0'
				&& map->map_array[i][j] != 'C' && map->map_array[i][j] != 'E'
				&& map->map_array[i][j] != 'P')
			{
				ft_printf("Error\nInvalid char %c found at x:%d, y:%d\n",
					map->map_array[i][j], j, i);
				handle_error(map, "Invalid character");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
