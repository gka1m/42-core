/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexadec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:15:23 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/23 14:15:23 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

/* handles %x and %X specifier */
static int	calc_hexlen(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	fill_hexstr(char *str, unsigned long long num, int len, char casing)
{
	int	digit;

	str[len] = '\0';
	while (len > 0)
	{
		len--;
		digit = num % 16;
		if (digit < 10)
			str[len] = digit + '0';
		else
		{
			if (casing == 'x')
				str[len] = (digit + 'a' - 10);
			else if (casing == 'X')
				str[len] = (digit + 'A' - 10);
		}
		num /= 16;
	}
}

static char	*create_hexstr(unsigned long long num, char casing)
{
	char	*result;
	int		len;

	len = calc_hexlen(num);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	fill_hexstr(result, num, len, casing);
	return (result);
}

int	ft_printhexadec(unsigned long long num, char casing)
{
	char	*hexstr;
	int		printed;

	hexstr = create_hexstr(num, casing);
	if (hexstr == NULL)
		return (0);
	printed = write(1, hexstr, ft_strlen(hexstr));
	free(hexstr);
	return (printed);
}
