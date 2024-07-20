/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:45:50 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 17:45:50 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t ft_strlcat(char *dest, const char *src, size_t dest_len)
{
	size_t dest_size;
	size_t src_size;
	size_t i;

	dest_size = 0;
	src_size = 0;
	i = 0;
	while (dest_size < dest_len && dest[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0')
		src_size++;
	if (dest_size == dest_len)
		return (dest_size + src_size);
	while (src[i] != '\0' && dest_size + i < dest_len - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	if (dest_size + i < dest_len)
		dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
