/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:13:59 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/16 14:17:02 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	count_words(char const *s, char c)
{
	size_t	wordcount;
	int		i;

	i = 0;
	wordcount = 0;
	if (!s || s[0] == '\0')
		return (0);
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
	word[i] = '\0';
	return (word);
}

void	free_word(char **split_arr)
{
	int	i;

	i = 0;
	if (split_arr == NULL)
		return ;
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
		if (result[i] == NULL)
			return (free_word(result), NULL);
		i++;
		k++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordcount;
	char	**result;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	wordcount = count_words(s, c);
	result = malloc((wordcount + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (split_string(s, c, result, wordcount) == NULL)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

// void print_split(char **split_result)
// {
// 	int i = 0;

// 	if (split_result == NULL)
// 	{
// 		printf("NULL result\n");
// 		return ;
// 	}

// 	while (split_result[i] != NULL)
// 	{
// 		printf("split[%d]: %s\n", i, split_result[i]);
// 		i++;
// 	}
// }

// int main(void)
// {
// 	// Test Case 1: Simple string
// 	char **result1 = ft_split("hello world this is a test", ' ');
// 	printf("Test Case 1: Simple string\n");
// 	print_split(result1);
// 	free_word(result1);

// 	// Test Case 2: Multiple consecutive delimiters
// 	char **result2 = ft_split("hello   world  this   is a test", ' ');
// 	printf("\nTest Case 2: Multiple consecutive delimiters\n");
// 	print_split(result2);
// 	free_word(result2);

// 	// Test Case 3: String with delimiters at the start and end
// 	char **result3 = ft_split("  hello world this is a test  ", ' ');
// 	printf("\nTest Case 3: Delimiters at start and end\n");
// 	print_split(result3);
// 	free_word(result3);

// 	// Test Case 4: Empty string
// 	char **result4 = ft_split("", ' ');
// 	printf("\nTest Case 4: Empty string\n");
// 	print_split(result4); // Expect NULL result or empty array
// 	free_word(result4);

// 	// Test Case 5: String with only delimiters
// 	char **result5 = ft_split("     ", ' ');
// 	printf("\nTest Case 5: String with only delimiters\n");
// 	print_split(result5); // Expect NULL result or empty array
// 	free_word(result5);

// 	// Test Case 6: Single word
// 	char **result6 = ft_split("word", ' ');
// 	printf("\nTest Case 6: Single word\n");
// 	print_split(result6); // Expect "word"
// 	free_word(result6);

// 	// Test Case 7: String without any delimiter (should return the whole string)
// 	char **result7 = ft_split("node_limit", ' ');
// 	printf("\nTest Case 7: No delimiter\n");
// 	print_split(result7); // Expect "node_limit"
// 	free_word(result7);

// 	// Test Case 8: Delimiter that doesn't exist in string
// 	char **result8 = ft_split("abcdef", 'x');
// 	printf("\nTest Case 8: Delimiter not present\n");
// 	print_split(result8); // Expect "abcdef"
// 	free_word(result8);

// 	return (0);
// }