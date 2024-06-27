/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:51:37 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 17:51:37 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)(haystack));
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && i + j < len && haystack[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

/*char *custom_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (*needle == '\0')
		return ((char *)haystack);

	for (i = 0; haystack[i] != '\0' && i < len; i++)
	{
		for (j = 0; needle[j] != '\0' && (i + j) < len; j++)
		{
			if (haystack[i + j] != needle[j])
				break ;
		}
		if (needle[j] == '\0')
			return (char *)(haystack + i);
	}
	return (NULL);
}


int main(void)
{
	const char *haystack1 = "Hello, World!";
	const char *needle1 = "World";
	size_t len1 = 12;

	const char *haystack2 = "Hello, World!";
	const char *needle2 = "Coder";
	size_t len2 = 12;

	const char *haystack3 = "Hello, World!";
	const char *needle3 = "";
	size_t len3 = 5;

	const char *haystack4 = "Hello, World!";
	const char *needle4 = "World";
	size_t len4 = 5;

	// Test case 1: needle found within length
	printf("Test Case 1:\n");
	printf("Standard strnstr: %s\n", custom_strnstr(haystack1, needle1, len1));
		// Expected: "World!"
	printf("Custom ft_strnstr: %s\n", ft_strnstr(haystack1, needle1, len1));   
		// Expected: "World!"
	printf("Result: %s\n\n", (custom_strnstr(haystack1, needle1,
				len1) == ft_strnstr(haystack1, needle1,
				len1)) ? "Pass" : "Fail");

	// Test case 2: needle not found within length
	printf("Test Case 2:\n");
	printf("Standard strnstr: %s\n", custom_strnstr(haystack2, needle2, len2));
		// Expected: (null)
	printf("Custom ft_strnstr: %s\n", ft_strnstr(haystack2, needle2, len2));   
		// Expected: (null)
	printf("Result: %s\n\n", (custom_strnstr(haystack2, needle2,
				len2) == ft_strnstr(haystack2, needle2,
				len2)) ? "Pass" : "Fail");

	// Test case 3: needle is an empty string
	printf("Test Case 3:\n");
	printf("Standard strnstr: %s\n", custom_strnstr(haystack3, needle3, len3));
		// Expected: "Hello, World!"
	printf("Custom ft_strnstr: %s\n", ft_strnstr(haystack3, needle3, len3));   
		// Expected: "Hello, World!"
	printf("Result: %s\n\n", (custom_strnstr(haystack3, needle3,
				len3) == ft_strnstr(haystack3, needle3,
				len3)) ? "Pass" : "Fail");

	// Test case 4: needle found beyond length
	printf("Test Case 4:\n");
	printf("Standard strnstr: %s\n", custom_strnstr(haystack4, needle4, len4));
		// Expected: (null)
	printf("Custom ft_strnstr: %s\n", ft_strnstr(haystack4, needle4, len4));   
		// Expected: (null)
	printf("Result: %s\n\n", (custom_strnstr(haystack4, needle4,
				len4) == ft_strnstr(haystack4, needle4,
				len4)) ? "Pass" : "Fail");

	return (0);
}
*/