/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:26:34 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/27 16:56:49 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*free_and_null(char **target)
{
	if (*target)
	{
		free(*target);
		*target = NULL;
	}
	return (NULL);
}

static char	*get_line(char *buffer)
{
	char	*leftover;
	ssize_t	i;
	int		buff_len;

	if (buffer == NULL)
		return (NULL);
	i = 0;
	buff_len = ft_strlen(buffer);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0' || (buffer[i] == '\n' && buffer[i + 1] == '\0'))
		return (NULL);
	leftover = ft_substr(buffer, i + 1, buff_len - i - 1);
	if (leftover && *leftover == '\0')
		free_and_null(&leftover);
	buffer[i + 1] = '\0';
	return (leftover);
}

static char	*to_buffer(int fd, char *left, char *buffer, int *status)
{
	ssize_t	readed;
	char	*temp;

	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			*status = readed;
			return (NULL);
		}
		else if (readed == 0)
			break ;
		buffer[readed] = '\0';
		if (!left)
			left = ft_strdup("");
		temp = left;
		left = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*big_l = NULL;
	char		*buffer;
	char		*line;
	int			status;

	status = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || buffer == NULL)
	{
		free_and_null(&big_l);
		free_and_null(&buffer);
		return (NULL);
	}
	line = to_buffer(fd, big_l, buffer, &status);
	free(buffer);
	if (status < 0)
	{
		free_and_null(&big_l);
		return (NULL);
	}
	if (line == NULL)
		return (NULL);
	big_l = get_line(line);
	return (line);
}
