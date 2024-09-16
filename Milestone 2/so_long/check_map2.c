/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:23:56 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/16 13:13:41 by kagoh            ###   ########.fr       */
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

char	**validate_map(t_map *map, char *mapfile)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	if (check_map(map, mapfile) == 0)
	{
		copy = read_file(mapfile);
		floodfill(copy);
		while (copy[i])
		{
			j = 0;
			while (copy[j])
			{
				if (copy[i][j] == '0' || copy[i][j] == 'C' || copy[i][j] == 'E')
					return (NULL);
				j++;
			}
			i++;
		}
		return (copy);
	}
	return (NULL);
}
