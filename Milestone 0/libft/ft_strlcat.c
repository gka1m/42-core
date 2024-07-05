/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:45:50 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 17:45:50 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_len)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	dest_size = 0;
	src_size = 0;
	i = 0;
	while (dest_size < dest_len && dest[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0')
		src_size++;
	if (dest_size == dest_len)
		return (dest_size + src_size);
	while (src[i] != '\0' && dest_size + i < dest_len - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	if (dest_size + i < dest_len)
		dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}

/*int main(void)
{
	// Test case 1: Concatenate with sufficient space
	char dest1[50] = "Hello, ";
	const char *src1 = "World!";
	size_t dest_len1 = sizeof(dest1);
	size_t result1_std = strlcat(dest1, src1, dest_len1);
	char dest1_custom[50] = "Hello, ";
	size_t result1_custom = ft_strlcat(dest1_custom, src1, dest_len1);

	printf("Test Case 1:\n");
	printf("Standard strlcat: %zu, Result: %s\n", result1_std, dest1);
	printf("Custom ft_strlcat: %zu, Result: %s\n", result1_custom,
		dest1_custom);
	printf("Result: %s\n\n", (result1_std == result1_custom && strcmp(dest1,
				dest1_custom) == 0) ? "Pass" : "Fail");

	// Test case 2: Concatenate with limited space
	char dest2[10] = "Hello, ";
	const char *src2 = "World!";
	size_t dest_len2 = sizeof(dest2);
	size_t result2_std = strlcat(dest2, src2, dest_len2);
	char dest2_custom[10] = "Hello, ";
	size_t result2_custom = ft_strlcat(dest2_custom, src2, dest_len2);

	printf("Test Case 2:\n");
	printf("Standard strlcat: %zu, Result: %s\n", result2_std, dest2);
	printf("Custom ft_strlcat: %zu, Result: %s\n", result2_custom,
		dest2_custom);
	printf("Result: %s\n\n", (result2_std == result2_custom && strcmp(dest2,
				dest2_custom) == 0) ? "Pass" : "Fail");

	// Test case 3: Zero-sized buffer
	char dest3[10] = "Hello";
	const char *src3 = "World!";
	size_t dest_len3 = 0;
	size_t result3_std = strlcat(dest3, src3, dest_len3);
	char dest3_custom[10] = "Hello";
	size_t result3_custom = ft_strlcat(dest3_custom, src3, dest_len3);

	printf("Test Case 3:\n");
	printf("Standard strlcat: %zu, Result: %s\n", result3_std, dest3);
	printf("Custom ft_strlcat: %zu, Result: %s\n", result3_custom,
		dest3_custom);
	printf("Result: %s\n\n", (result3_std == result3_custom && strcmp(dest3,
				dest3_custom) == 0) ? "Pass" : "Fail");

	// Test case 4: Empty source string
	char dest4[50] = "Hello, ";
	const char *src4 = "";
	size_t dest_len4 = sizeof(dest4);
	size_t result4_std = strlcat(dest4, src4, dest_len4);
	char dest4_custom[50] = "Hello, ";
	size_t result4_custom = ft_strlcat(dest4_custom, src4, dest_len4);

	printf("Test Case 4:\n");
	printf("Standard strlcat: %zu, Result: %s\n", result4_std, dest4);
	printf("Custom ft_strlcat: %zu, Result: %s\n", result4_custom,
		dest4_custom);
	printf("Result: %s\n\n", (result4_std == result4_custom && strcmp(dest4,
				dest4_custom) == 0) ? "Pass" : "Fail");

	// Test case 5: Empty destination string
	char dest5[50] = "";
	const char *src5 = "World!";
	size_t dest_len5 = sizeof(dest5);
	size_t result5_std = strlcat(dest5, src5, dest_len5);
	char dest5_custom[50] = "";
	size_t result5_custom = ft_strlcat(dest5_custom, src5, dest_len5);

	printf("Test Case 5:\n");
	printf("Standard strlcat: %zu, Result: %s\n", result5_std, dest5);
	printf("Custom ft_strlcat: %zu, Result: %s\n", result5_custom,
		dest5_custom);
	printf("Result: %s\n\n", (result5_std == result5_custom && strcmp(dest5,
				dest5_custom) == 0) ? "Pass" : "Fail");

	return (0);
}
*/