/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:10:07 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/24 16:35:08 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* prints an unsigned decimal (base 10) number ; handles %u specifier */

int	ft_printunsigned_num(unsigned int n)
{
	unsigned long	num;
	int				count;

	num = n;
	count = 0;
	if (num >= 10)
		count += ft_printnumber(num / 10);
	ft_printchar(num % 10 + '0');
	count++;
	return (count);
}
