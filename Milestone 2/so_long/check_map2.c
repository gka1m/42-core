/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:23:56 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/05 15:41:17 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void	dfs(t_map *map, int i, int j, char old)
{
	if (i < 0 || i >= map->height || j < 0 || j >= map->width
		|| map->map_array[i][j] == 'V' || (map->map_array[i][j] != old
			&& map->map_array[i][j] != 'C' && map->map_array[i][j] != 'E'))
		return ;
	if (map->map_array[i][j] == 'C')
		map->collectibles--;
	else if (map->map_array[i][j] == 'E' && map->collectibles == 0)
		map->exit--;
	map->map_array[i][j] = 'V';
	dfs(map, i + 1, j, old);
	dfs(map, i - 1, j, old);
	dfs(map, i, j + 1, old);
	dfs(map, i, j - 1, old);
}

int	find_valid_path(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	map->height = 0;
	while (map->map_array[map->height])
		map->height++;
	map->width = ft_strlen(map->map_array[0]);
	map->collectibles = 0;
	map->exit = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_array[i][j] == 'C')
				map->collectibles++;
			if (map->map_array[i][j] == 'E')
				map->exit++;
			if (map->map_array[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
	dfs(map, player->y, player->x, '0');
	if (map->collectibles == 0 && map->exit == 0)
		return (1);
	return (0);
}
