/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:51:17 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/23 18:16:00 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start_len;
	int		end_len;
	int		i;

	start_len = 0;
	end_len = ft_strlen(s1);
	i = 0;
	if (set == NULL || s1 == NULL)
		return (NULL);
	while (s1[start_len] != '\0' && inset(s1[start_len], set))
		start_len++;
	while (end_len > start_len && inset(s1[end_len - 1], set))
		end_len--;
	result = malloc((end_len - start_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (start_len < end_len)
	{
		result[i] = s1[start_len];
		i++;
		start_len++;
	}
	result[i] = '\0';
	return (result);
}

/*int main(void)
{
	char	*s1;
	char	*set;
	char	*result;

	s1 = "   Hello, World!   ";
	set = " ";
	// Test case 1: Trim spaces from both ends
	result = ft_strtrim(s1, set);
	printf("Test case 1:\nExpected: 'Hello, World!'\nGot: '%s'\n\n", result);
	free(result);
	// Test case 2: Trim characters from both ends
	s1 = "***Hello, World!***";
	set = "*";
	result = ft_strtrim(s1, set);
	printf("Test case 2:\nExpected: 'Hello, World!'\nGot: '%s'\n\n", result);
	free(result);
	// Test case 3: No characters to trim
	s1 = "Hello, World!";
	set = "*";
	result = ft_strtrim(s1, set);
	printf("Test case 3:\nExpected: 'Hello, World!'\nGot: '%s'\n\n", result);
	free(result);
	// Test case 4: Empty string as input
	s1 = "";
	result = ft_strtrim(s1, set);
	printf("Test case 4:\nExpected: ''\nGot: '%s'\n\n", result);
	free(result);
	// Test case 5: Trim all characters (resulting in an empty string)
	s1 = "*****";
	result = ft_strtrim(s1, set);
	printf("Test case 5:\nExpected: ''\nGot: '%s'\n\n", result);
	free(result);
	// Test case 6: No characters in set
	s1 = "Hello, World!";
	set = "";
	result = ft_strtrim(s1, set);
	printf("Test case 6:\nExpected: 'Hello, World!'\nGot: '%s'\n\n", result);
	free(result);
	return (0);
}
*/