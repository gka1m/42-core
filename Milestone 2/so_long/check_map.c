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

char *read_file(char *mapfile)
{
	int fd;
	char buffer[1024];
	int bytes_read;
	char *content;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	bytes_read = read(fd, buffer, 1024);
	if (bytes_read == -1)
	{
		perror("Error reading file");
		exit(1);
	}
	close(fd);
	content = malloc((bytes_read + 1) * sizeof(char));
	if (content == NULL)
		return (NULL);
	ft_strlcpy(mapfile, buffer, 1024);
	mapfile[bytes_read] = '\0';
	return (mapfile);
}

int validate_shape(char **lines)
{
	int width;
	int i;

	width = ft_strlen(lines[0]);
	i = 0;
	while (lines[i] != NULL)
	{
		if (ft_strlen(lines[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

void count_elements(char **lines, int *exit, int *collectibles, int *start)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (lines[i] != NULL)
	{
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] == 'E')
				*exit++;
			if (lines[i][j] == 'C')
				*collectibles++;
			if (lines[i][j] == 'P')
				*start++;
			j++;
		}
		i++;
	}
}

int check_closure(char **lines, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (lines[i] != NULL)
	{
		if (lines[i][0] != '1' || lines[i][width - 1] != '1')
			return (0);
		i++;
	}
	while (j < width)
	{
		if (lines[0][j] != '1' || lines[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int validate_map(char **lines)
{
	int exits;
	int start;
	int collectibles;
	int width;

	width = ft_strlen(lines[0]);
	if (!validate_shape(lines))
		return (0);
	count_elements(lines, &exits, &collectibles, &start);
	if (exits != 1 || collectibles < 1 || start != 1)
		return (0);
	if (!check_closure(lines, width))
		return (0);
	return (1);
}
