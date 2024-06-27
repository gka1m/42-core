/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:38:14 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/27 16:32:15 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier(const char *specifier, va_list args)
{
	int	count;

	count = 0;
	if (*specifier == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (*specifier == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (*specifier == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (*specifier == 'd' || *specifier == 'i')
		count += ft_printnumber(va_arg(args, int));
	else if (*specifier == 'u')
		count += ft_printunsigned_num(va_arg(args, unsigned int));
	else if (*specifier == 'x')
		count += ft_printhexadec(va_arg(args, unsigned int), 'x');
	else if (*specifier == 'X')
		count += ft_printhexadec(va_arg(args, unsigned int), 'X');
	else if (*specifier == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *text, ...)
{
	va_list			args;
	int				i;
	int				count;

	i = 0;
	count = 0;
	va_start(args, text);
	while (text[i] != '\0')
	{
		if (text[i] == '%')
		{
			i++;
			if (text[i] == '\0')
				break ;
			count += specifier(&text[i], args);
			while (text[i] != '\0' && ft_strchr("cspdiuxX%", text[i]) == NULL)
				i++;
		}
		else
			count += ft_printchar(text[i]);
		i++;
	}
	va_end(args);
	return (count);
}
