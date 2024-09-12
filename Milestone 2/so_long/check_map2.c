/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:23:56 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/12 17:14:44 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

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
// update to take char **map not struct
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
				break;
			}
			j++;
		}
		i++;
	}
}

int	check_map(t_map *map, char *mapfile)
{
	check_structure(map, mapfile);
	check_elements(map);
	if (map->collectibles < 1)
		error_msg(map, "Map needs at least 1 collectible");
	else if (map->exit != 1)
		error_msg(map, "Map has no exit");
	else if (map->player != 1)
		error_msg(map, "Map has no player");
	return (0);
}

char	**validate_map(t_map *map, char *mapfile)
{
	char	**copy;
	int		i;

	i = 0;
	if (check_map(map, mapfile))
	{
		// call copy of map here
		copy = read_file(mapfile);
		floodfill(copy);
		return (copy);
	}
	return (NULL);
}
