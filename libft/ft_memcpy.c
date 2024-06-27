/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:13 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/27 11:39:36 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == src || n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
    // Test case 1: Copy a string
    char src1[] = "Hello, World!";
    char dest1_std[20];
    char dest1_custom[20];
    memcpy(dest1_std, src1, sizeof(src1));
    ft_memcpy(dest1_custom, src1, sizeof(src1));

    printf("Test Case 1:\n");
    printf("Standard memcpy: %s\n", dest1_std);
    printf("Custom ft_memcpy: %s\n", dest1_custom);
    printf("Result: %s\n\n", (strcmp(dest1_std,
	dest1_custom) == 0) ? "Pass" : "Fail");

    // Test case 2: Copy an array of integers
    int src2[] = {1, 2, 3, 4, 5};
    int dest2_std[5];
    int dest2_custom[5];
    memcpy(dest2_std, src2, sizeof(src2));
    ft_memcpy(dest2_custom, src2, sizeof(src2));

    printf("Test Case 2:\n");
    printf("Standard memcpy: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dest2_std[i]);
    }
    printf("\nCustom ft_memcpy: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dest2_custom[i]);
    }
    printf("\nResult: %s\n\n", (memcmp(dest2_std, dest2_custom,
	sizeof(src2)) == 0) ? "Pass" : "Fail");

    // Test case 3: Copy a portion of a string
    char src3[] = "This is a test.";
    char dest3_std[10];
    char dest3_custom[10];
    memcpy(dest3_std, src3, 9);
    ft_memcpy(dest3_custom, src3, 9);

    printf("Test Case 3:\n");
    printf("Standard memcpy: %.*s\n", 9, dest3_std);
    printf("Custom ft_memcpy: %.*s\n", 9, dest3_custom);
    printf("Result: %s\n\n", (memcmp(dest3_std,
	dest3_custom, 9) == 0) ? "Pass" : "Fail");

    // Test case 4: Copy with zero length
    char src4[] = "Should not change.";
    char dest4_std[20] = "Initial value.";
    char dest4_custom[20] = "Initial value.";
    memcpy(dest4_std, src4, 0);
    ft_memcpy(dest4_custom, src4, 0);

    printf("Test Case 4:\n");
    printf("Standard memcpy: %s\n", dest4_std);
    printf("Custom ft_memcpy: %s\n", dest4_custom);
    printf("Result: %s\n\n", (strcmp(dest4_std,
	dest4_custom) == 0) ? "Pass" : "Fail");

    // Test case 5: Copy a large buffer
    char src5[1000];
    char dest5_std[1000];
    char dest5_custom[1000];
    for (size_t i = 0; i < 1000; i++)
    {
        src5[i] = (char)(i % 256);
    }
    memcpy(dest5_std, src5, 1000);
    ft_memcpy(dest5_custom, src5, 1000);

    printf("Test Case 5:\n");
    printf("Standard memcpy: %s\n", memcmp(dest5_std,
	src5, 1000) == 0 ? "Match" : "Mismatch");
    printf("Custom ft_memcpy: %s\n", memcmp(dest5_custom,
	src5, 1000) == 0 ? "Match" : "Mismatch");
    printf("Result: %s\n\n", (memcmp(dest5_std,
	dest5_custom, 1000) == 0) ? "Pass" : "Fail");

    return 0;
}
*/