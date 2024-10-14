/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:13:59 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/27 11:13:59 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	wordcount;
	int		i;

	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			wordcount++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (wordcount);
}

static char	*create_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (i < end - start)
	{
		word[i] = s[start + i];
		i++;
	}
	word[end - start] = '\0';
	return (word);
}

void	free_word(char **split_arr)
{
	int	i;

	i = 0;
	while (split_arr[i] != NULL)
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

char	**split_string(char const *s, char c, char **result, size_t wordcount)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < wordcount)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		start = j;
		while (s[j] != '\0' && s[j] != c)
			j++;
		result[i] = create_word(s, start, j);
		if (result[i++] == NULL)
		{
			free_word(result);
			return (NULL);
		}
		k++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordcount;
	char	**result;

	if (s == NULL)
		return (NULL);
	wordcount = count_words(s, c);
	result = malloc((wordcount + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (split_string(s, c, result, wordcount));
}
