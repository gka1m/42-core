/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:32:09 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/04 13:44:29 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

char	*read_file(char *mapfile)
{
	ssize_t	bytes_read;
	int		fd;
	char	buffer[700];

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open map file");
		return (NULL);
	}
	bytes_read = read(fd, buffer, 700);
	if (bytes_read < 0)
	{
		perror("Failed to read map file");
		close(fd);
		return (NULL);
	}
	close(fd);
	if (bytes_read >= 700)
	{
		ft_printf("Map exceeds allowed size limit\n");
		return (NULL);
	}
	return (ft_split(buffer, '\n'));
}

void	error_msg(t_map *map, const char *message)
{
	int	i;

	i = 0;
	ft_printf("%s\n", message);
	while (i < map->height)
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array);
}

void	check_structure(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->map_array = read_map(map);
	map->width = ft_strlen(map->map_array[0]);
	map->height = 0;
	while (map->map_array[map->height])
		map->height++;
	while (i < map->height)
	{
		if (ft_strlen(map->map_array[i]) != map->width)
			error_msg(map, "Map is not rectangular");
		j = 0;
		while (j < map->width)
		{
			if ((i == 0 || i == map->height - 1 || j == 0 || j == map->width
					- 1) && map->map_array[i][i] != '1')
				error_msg(map, "Map not surrounded by walls");
			j++;
		}
		i++;
	}
}

void	check_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->player = 0;
	map->collectibles = 0;
	map->exit = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_array[i][j] == 'C')
				map->collectibles++;
			else if (map ->map_array[i][j] == 'E')
				map->exit++;
			else if (map->map_array[i][j] == 'P')
				map->player++;
			j++;
		}
		i++;
	}
}

int	check_map(t_map *map)
{
	check_structure(map);
	check_elements(map);
	if (map->collectibles < 1)
	{
		error_msg(map, "Map needs at least 1 collectible");
		return (1);
	}
	else if (map->exit != 1)
	{
		error_msg(map, "Map has no exit");
		return (1);
	}
	else if (map->player != 1)
	{
		error_msg(map, "Map has no player");
		return (1);
	}
	return (0);
}
