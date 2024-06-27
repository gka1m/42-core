/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:30:28 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/23 18:11:10 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

/*int main(void)
{
    char *s1;
    char *s2;
    char *result;

    // Test case 1: Join two non-empty strings
    s1 = "Hello";
    s2 = ", World!";
    result = ft_strjoin(s1, s2);
    printf("Test case 1:\nExpected: 'Hello, World!'\nGot: '%s'\n\n", result);
    free(result);

    // Test case 2: Join with an empty string (s1 is empty)
    s1 = "";
    s2 = "World";
    result = ft_strjoin(s1, s2);
    printf("Test case 2:\nExpected: 'World'\nGot: '%s'\n\n", result);
    free(result);

    // Test case 3: Join with an empty string (s2 is empty)
    s1 = "Hello";
    s2 = "";
    result = ft_strjoin(s1, s2);
    printf("Test case 3:\nExpected: 'Hello'\nGot: '%s'\n\n", result);
    free(result);

    // Test case 4: Join two empty strings
    s1 = "";
    s2 = "";
    result = ft_strjoin(s1, s2);
    printf("Test case 4:\nExpected: ''\nGot: '%s'\n\n", result);
    free(result);

    // Test case 5: Join strings with spaces
    s1 = "Hello ";
    s2 = "World!";
    result = ft_strjoin(s1, s2);
    printf("Test case 5:\nExpected: 'Hello World!'\nGot: '%s'\n\n", result);
    free(result);

    // Test case 6: Join strings with special characters
    s1 = "Hello, ";
    s2 = "World!\\n";
    result = ft_strjoin(s1, s2);
    printf("Test case 6:\nExpected: 'Hello, World!\\n'\nGot: '%s'\n\n", result);
    free(result);

    return 0;
}
*/