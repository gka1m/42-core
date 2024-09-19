/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:28:33 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/19 15:30:58 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

char	**read_file(char *mapfile)
{
	ssize_t	bytes_read;
	int		fd;
	char	buffer[700];
	char	**result;
	int		len;

	fd = open(mapfile, O_RDONLY);
	len = ft_strlen(mapfile);
	if (len < 4 || ft_strncmp(mapfile + len - 4, ".ber", 4) != 0)
		return (ft_printf("Error\nFile should be .ber format\n"), NULL);
	if (fd < 0)
		return (perror("Failed to open map file"), NULL);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read < 0)
		return (perror("Failed to read map file"), close(fd), NULL);
	buffer[bytes_read] = '\0';
	close(fd);
	if (bytes_read >= 650)
		return (ft_printf("Error\nMap exceeds allowed size limit\n"), NULL);
	result = ft_split(buffer, '\n');
	if (!result)
		return (ft_printf("Memory allocation failed\n"), NULL);
	return (result);
}

void	handle_error(t_map *map, const char *message)
{
	int	i;

	i = 0;
	ft_printf("%s\n", message);
	while (map->map_array[i])
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array);
}

void	init_dims(t_map *map)
{
	map->width = ft_strlen(map->map_array[0]);
	map->height = 0;
	while (map->map_array[map->height])
		map->height++;
}

int	is_rect(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map_array[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	surrounded(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((i == 0 || i == map->height - 1 || j == 0 || j == map->width
					- 1) && map->map_array[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
