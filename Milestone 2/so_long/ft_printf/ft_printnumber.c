/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:23:45 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/24 16:34:28 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* prints an integer in base 10 or decimal number (base 10);
handles both %d and %i specifier*/

int	ft_printnumber(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		ft_printchar('-');
		num = -num;
		count++;
	}
	if (num >= 10)
		count += ft_printnumber(num / 10);
	ft_printchar(num % 10 + '0');
	count++;
	return (count);
}
