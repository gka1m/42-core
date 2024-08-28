/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:32:09 by kagoh             #+#    #+#             */
/*   Updated: 2024/08/28 16:00:52 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(t_game *game, const char *map)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to open map file\n");
		exit(1);
	}
	game->map.height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	load_data(t_game *game, const char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to open map file\n");
		exit(1);
	}
	game->map.map_array = malloc(game->map.height * sizeof(char));
	if (game->map.map_array == NULL)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
		game->map.map_array[i++] = line;
	close(fd);
	game->map.width = ft_strlen(game->map.map_array[0]);
}
