/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:00:58 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 17:00:58 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nitems * size;
	if (nitems != 0 && total_size / nitems != size)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

/*int main(void)
{
	// Test case 1: Allocate an array of 5 integers
	size_t num1 = 5;
	size_t size1 = sizeof(int);
	int *array1_std = (int *)calloc(num1, size1);
	int *array1_custom = (int *)ft_calloc(num1, size1);

	printf("Test Case 1:\n");
	printf("Standard calloc:\n");
	for (size_t i = 0; i < num1; i++)
	{
		printf("%d ", array1_std[i]);
	}
	printf("\nCustom ft_calloc:\n");
	for (size_t i = 0; i < num1; i++)
	{
		printf("%d ", array1_custom[i]);
	}
	printf("\nResult: %s\n\n", (memcmp(array1_std, array1_custom,
	num1 * size1) == 0) ? "Pass" : "Fail");

	free(array1_std);
	free(array1_custom);

	// Test case 2: Allocate an array of 10 characters
	size_t num2 = 10;
	size_t size2 = sizeof(char);
	char *array2_std = (char *)calloc(num2, size2);
	char *array2_custom = (char *)ft_calloc(num2, size2);

	printf("Test Case 2:\n");
	printf("Standard calloc:\n");
	for (size_t i = 0; i < num2; i++)
	{
		printf("%d ", array2_std[i]);
	}
	printf("\nCustom ft_calloc:\n");
	for (size_t i = 0; i < num2; i++)
	{
		printf("%d ", array2_custom[i]);
	}
	printf("\nResult: %s\n\n", (memcmp(array2_std, array2_custom,
	num2 * size2) == 0) ? "Pass" : "Fail");

	free(array2_std);
	free(array2_custom);

	// Test case 3: Allocate an array of 0 elements
	size_t num3 = 0;
	size_t size3 = sizeof(int);
	int *array3_std = (int *)calloc(num3, size3);
	int *array3_custom = (int *)ft_calloc(num3, size3);

	printf("Test Case 3:\n");
	printf("Standard calloc: %p\n", (void *)array3_std);
	printf("Custom ft_calloc: %p\n", (void *)array3_custom);
	printf("Result: %s\n\n", ((array3_std == NULL &&
	array3_custom == NULL) || (array3_std != NULL &&
	array3_custom != NULL)) ? "Pass" : "Fail");

	free(array3_std);
	free(array3_custom);

	// Test case 4: Large allocation to check overflow protection
	size_t num4 = SIZE_MAX;
	size_t size4 = SIZE_MAX;
	void *array4_std = calloc(num4, size4);
	void *array4_custom = ft_calloc(num4, size4);

	printf("Test Case 4:\n");
	printf("Standard calloc: %p\n", array4_std);
	printf("Custom ft_calloc: %p\n", array4_custom);
	printf("Result: %s\n\n", (array4_std == array4_custom) ? "Pass" : "Fail");

	free(array4_std);
	free(array4_custom);

	return (0);
}
*/