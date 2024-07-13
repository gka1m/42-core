/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:15:06 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/19 16:07:54 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* print a single character; handles %c specifier */

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}
