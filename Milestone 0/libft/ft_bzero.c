/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:47:42 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/23 17:54:47 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	c = (unsigned char *)s;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char	test1[10] = "Hello";
	char	test1_ft[10] = "Hello";
	int		test2[5] = {1, 2, 3, 4, 5};
	int		test2_ft[5] = {1, 2, 3, 4, 5};
	char	test3[5] = "Test";
	char	test3_ft[5] = "Test";

	// Test case 1: Zeroing an array of 10 characters
	bzero(test1, 10);
	ft_bzero(test1_ft, 10);
	printf("Test Case 1:\n");
	printf("Standard bzero: ");
	for (int i = 0; i < 10; i++) printf("%d ", test1[i]);
	printf("\nCustom ft_bzero: ");
	for (int i = 0; i < 10; i++) printf("%d ", test1_ft[i]);
	printf("\nResult: %s\n\n",
	(memcmp(test1, test1_ft, 10) == 0) ? "Pass" : "Fail");
	// Test case 2: Zeroing an array of 5 integers
	bzero(test2, sizeof(test2));
	ft_bzero(test2_ft, sizeof(test2));
	printf("Test Case 2:\n");
	printf("Standard bzero: ");
	for (int i = 0; i < 5; i++) printf("%d ", test2[i]);
	printf("\nCustom ft_bzero: ");
	for (int i = 0; i < 5; i++) printf("%d ", test2_ft[i]);
	printf("\nResult: %s\n\n", (memcmp(test2, test2_ft,
	sizeof(test2)) == 0) ? "Pass" : "Fail");
	// Test case 3: Zeroing an array of 0 elements (should do nothing)
	bzero(test3, (0));
	ft_bzero(test3_ft, 0);
	printf("Test Case 3:\n");
	printf("Standard bzero: ");
	for (int i = 0; i < 5; i++) printf("%d ", test3[i]);
	printf("\nCustom ft_bzero: ");
	for (int i = 0; i < 5; i++) printf("%d ", test3_ft[i]);
	printf("\nResult: %s\n\n", (memcmp(test3, test3_ft,
	5) == 0) ? "Pass" : "Fail");
	return (0);
}
*/