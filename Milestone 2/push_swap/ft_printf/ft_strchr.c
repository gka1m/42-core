/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:58:02 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/24 16:35:32 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	if (chr == '\0')
	{
		while (str[i] != '\0')
			i++;
		return ((char *)(str + i));
	}
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)(str + i));
		else
			i++;
	}
	return (NULL);
}
