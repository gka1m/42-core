/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:15:16 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/24 16:50:26 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* print a string; handles %s specifier */

int	ft_printstr(char *s)
{
	int		i;
	int		count;
	char	*nullstr;

	i = 0;
	count = 0;
	nullstr = "(null)";
	if (s == NULL)
	{
		while (*nullstr)
		{
			write(1, nullstr, 1);
			nullstr++;
			count++;
		}
		return (count);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}
