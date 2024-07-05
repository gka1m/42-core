/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:02:41 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/24 18:33:52 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* handles %p specifier */

int	ft_printptr(void *ptr)
{
	unsigned long	add;
	int				count;

	count = 0;
	add = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_printstr("(nil)");
		count += 5;
		return (count);
	}
	ft_printchar('0');
	ft_printchar('x');
	count += 2;
	count += ft_printhexadec(add, 'x');
	return (count);
}
