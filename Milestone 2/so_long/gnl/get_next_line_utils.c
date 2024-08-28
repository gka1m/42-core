/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:28:51 by kagoh             #+#    #+#             */
/*   Updated: 2024/06/07 16:35:45 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	j = -1;
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (++i < s1_len)
		result[i] = s1[i];
	while (++j < s2_len)
		result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	if (str == NULL)
		return (NULL);
	if (chr == '\0')
	{
		while (str[i] != '\0')
			i++;
		return ((char *)(str));
	}
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)(str));
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *string)
{
	int			i;
	int			len;
	char		*result;

	if (string == NULL)
		return (NULL);
	len = 0;
	i = 0;
	while (string[len])
		len++;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		result[i] = string[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	result = malloc((len + 1) * sizeof(char));
	i = 0;
	if (result == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
