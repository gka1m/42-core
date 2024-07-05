/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:01:11 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 18:01:11 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/*int main(void)
{
	const char str1[] = "Hello, World!";
	const char str2[] = "Hello, World!";
	const char str3[] = "Hello, Coder!";
	const char str4[] = "Hello, World!!";
	size_t n;

	// Test case 1: Compare identical strings
	n = 13;
	int result1 = memcmp(str1, str2, n);
	int result2 = ft_memcmp(str1, str2, n);
	printf("Test Case 1:\n");
	printf("Standard memcmp: %d\n", result1);  // Expected: 0
	printf("Custom ft_memcmp: %d\n", result2); // Expected: 0
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	// Test case 2: Compare different strings
	n = 13;
	result1 = memcmp(str1, str3, n);
	result2 = ft_memcmp(str1, str3, n);
	printf("Test Case 2:\n");
	printf("Standard memcmp: %d\n", result1);  // Expected: non-zero
	printf("Custom ft_memcmp: %d\n", result2); // Expected: non-zero
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	// Test case 3: Compare up to 'n' characters
	// (ensuring 'n' does not exceed string lengths)
	n = 13;
	result1 = memcmp(str1, str3, n);
	result2 = ft_memcmp(str1, str3, n);
	printf("Test Case 3:\n");
	printf("Standard memcmp: %d\n", result1);  // Expected: non-zero
	printf("Custom ft_memcmp: %d\n", result2); // Expected: non-zero
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	// Test case 4: Compare strings with different lengths
	n = 14;
	result1 = memcmp(str1, str4, n);
	result2 = ft_memcmp(str1, str4, n);
	printf("Test Case 4:\n");
	printf("Standard memcmp: %d\n", result1);  // Expected: non-zero
	printf("Custom ft_memcmp: %d\n", result2); // Expected: non-zero
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	// Test case 5: Compare identical strings with n = 0
	n = 0;
	result1 = memcmp(str1, str2, n);
	result2 = ft_memcmp(str1, str2, n);
	printf("Test Case 5:\n");
	printf("Standard memcmp: %d\n", result1);  // Expected: 0
	printf("Custom ft_memcmp: %d\n", result2); // Expected: 0
	printf("Result: %s\n\n", (result1 == result2) ? "Pass" : "Fail");

	return (0);
}
*/