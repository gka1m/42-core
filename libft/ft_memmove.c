/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:00:29 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/27 14:30:26 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	unsigned char		*t;
	const unsigned char	*f;
	size_t				i;

	t = (unsigned char *) to;
	f = (const unsigned char *) from;
	i = n;
	if (to == from || n == 0)
		return (to);
	if (f < t && t < f + n)
	{
		while (i-- > 0)
			t[i] = f[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			t[i] = f[i];
			i++;
		}
	}
	return (to);
}
