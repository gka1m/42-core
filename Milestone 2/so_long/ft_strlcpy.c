/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/05/18 15:21:23 by marvin            #+#    #+#             */
/*   Updated: 2024/05/18 15:21:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t length;
	size_t copy;
	size_t i;
	const char *s;

	s = src;
	length = 0;
	i = 0;
	while (s[length] != '\0')
		length++;
	if (size > 0)
	{
		if (length < size - 1)
			copy = length;
		else
			copy = size - 1;
		while (i < copy)
		{
			dest[i] = s[i];
			i++;
		}
		dest[copy] = '\0';
	}
	return (length);
}