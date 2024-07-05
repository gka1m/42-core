/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:28:48 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/27 17:02:59 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int main(void)
{
    char *s1 = "Hello, World!";
    char *s2 = "42";
    char *s3 = "";
    char *result;

    // Test case 1: Normal case
    result = ft_substr(s1, 7, 5);
    printf("Test case 1:\nExpected: 'World'\nGot: '%s'\n\n", result);
    free(result);

    // Test case 2: Start index is 0
    result = ft_substr(s1, 0, 5);
    printf("Test case 2:\nExpected: 'Hello'\nGot: '%s'\n\n", result);
    free(result);

    // Test case 3: Start index is greater than string length
    result = ft_substr(s1, 20, 5);
    printf("Test case 3:\nExpected: ''\nGot: '%s'\n\n", result);
    free(result);

    // Test case 4: Length is greater than remaining string length
    result = ft_substr(s1, 7, 20);
    printf("Test case 4:\nExpected: 'World!'\nGot: '%s'\n\n", result);
    free(result);

    // Test case 5: Empty string input
    result = ft_substr(s3, 0, 5);
    printf("Test case 5:\nExpected: ''\nGot: '%s'\n\n", result);
    free(result);

    // Test case 6: Substring length is zero
    result = ft_substr(s1, 5, 0);
    printf("Test case 6:\nExpected: ''\nGot: '%s'\n\n", result);
    free(result);

    // Test case 7: Non-zero length but empty source string
    result = ft_substr(s3, 0, 3);
    printf("Test case 7:\nExpected: ''\nGot: '%s'\n\n", result);
    free(result);

    // Test case 8: Substring in a short string
    result = ft_substr(s2, 1, 1);
    printf("Test case 8:\nExpected: '2'\nGot: '%s'\n\n", result);
    free(result);

    return 0;
}
*/