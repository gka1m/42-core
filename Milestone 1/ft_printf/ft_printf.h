/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:31:27 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/26 18:00:36 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printnumber(int n);
int		ft_strlen(const char *str);
int		ft_printhexadec(unsigned long long num, char casing);
int		ft_printptr(void *ptr);
int		ft_printunsigned_num(unsigned int n);
char	*ft_strchr(const char *str, int c);
int		ft_printf(const char *text, ...);

#endif