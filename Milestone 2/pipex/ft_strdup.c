/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:02:42 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 18:02:42 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_strdup(const char *string)
{
	int i;
	int len;
	char *result;
	const char *temp;

	len = 0;
	i = 0;
	temp = string;
	while (*temp)
	{
		len++;
		temp++;
	}
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i <= len)
	{
		result[i] = string[i];
		i++;
	}
	return (result);
}
