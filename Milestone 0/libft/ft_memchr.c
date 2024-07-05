/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:28:11 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 17:28:11 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*string;
	size_t				i;

	string = (const unsigned char *)str;
	i = 0;
	c = (unsigned char)c;
	while (i < n)
	{
		if (string[i] == c)
		{
			return ((void *)(string + i));
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	const char str[] = "Hello, World!";
	int c;
	size_t n;

	// Test case 1: Search for character 'o' in the first 12 bytes of str
	c = 'o';
	n = 12;
	void *result1 = memchr(str, c, n);
	void *result2 = ft_memchr(str, c, n);
	printf("Test Case 1:\n");
	printf("Standard memchr: %s\n", (char *)result1);
	// Expected: "o, World!"
	printf("Custom ft_memchr: %s\n", (char *)result2);
	// Expected: "o, World!"
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	// Test case 2: Search for character 'W' in the first 12 bytes of str
	c = 'W';
	n = 12;
	result1 = memchr(str, c, n);
	result2 = ft_memchr(str, c, n);
	printf("Test Case 2:\n");
	printf("Standard memchr: %s\n", (char *)result1);
	// Expected: "World!"
	printf("Custom ft_memchr: %s\n", (char *)result2);
	// Expected: "World!"
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	// Test case 3: Search for character 'z' (not in the string) in
	// the first 12 bytes of str
	c = 'z';
	n = 12;
	result1 = memchr(str, c, n);
	result2 = ft_memchr(str, c, n);
	printf("Test Case 3:\n");
	printf("Standard memchr: %p\n", result1);  // Expected: (null)
	printf("Custom ft_memchr: %p\n", result2); // Expected: (null)
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	// Test case 4: Search for character ',' in the first 5 bytes of str
	c = ',';
	n = 5;
	result1 = memchr(str, c, n);
	result2 = ft_memchr(str, c, n);
	printf("Test Case 4:\n");
	printf("Standard memchr: %p\n", result1);  // Expected: (null)
	printf("Custom ft_memchr: %p\n", result2); // Expected: (null)
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	// Test case 5: Search for character 'H' in the first 12 bytes of str
	c = 'H';
	n = 12;
	result1 = memchr(str, c, n);
	result2 = ft_memchr(str, c, n);
	printf("Test Case 5:\n");
	printf("Standard memchr: %s\n", (char *)result1);
	// Expected: "Hello, World!"
	printf("Custom ft_memchr: %s\n", (char *)result2);
	// Expected: "Hello, World!"
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	return (0);
}
*/