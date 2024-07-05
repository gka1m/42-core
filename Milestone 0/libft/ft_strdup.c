/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:02:42 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 18:02:42 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	int			i;
	int			len;
	char		*result;
	const char	*temp;

	len = 0;
	i = 0;
	temp = string;
	while (*temp)
	{
		len++;
		temp++;
	}
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i <= len)
	{
		result[i] = string[i];
		i++;
	}
	return (result);
}

/*int main(void)
{
	// Test case 1: Basic string
	const char *test1 = "Hello, World!";
	char *result1_std = strdup(test1);
	char *result1_custom = ft_strdup(test1);
	printf("Test Case 1:\n");
	printf("Standard strdup: %s\n", result1_std);
	printf("Custom ft_strdup: %s\n", result1_custom);
	printf("Result: %s\n\n", (strcmp(result1_std,
				result1_custom) == 0) ? "Pass" : "Fail");
	free(result1_std);
	free(result1_custom);

	// Test case 2: Empty string
	const char *test2 = "";
	char *result2_std = strdup(test2);
	char *result2_custom = ft_strdup(test2);
	printf("Test Case 2:\n");
	printf("Standard strdup: %s\n", result2_std);
	printf("Custom ft_strdup: %s\n", result2_custom);
	printf("Result: %s\n\n", (strcmp(result2_std,
				result2_custom) == 0) ? "Pass" : "Fail");
	free(result2_std);
	free(result2_custom);

	// Test case 3: String with spaces
	const char *test3 = "This is a test string.";
	char *result3_std = strdup(test3);
	char *result3_custom = ft_strdup(test3);
	printf("Test Case 3:\n");
	printf("Standard strdup: %s\n", result3_std);
	printf("Custom ft_strdup: %s\n", result3_custom);
	printf("Result: %s\n\n", (strcmp(result3_std,
				result3_custom) == 0) ? "Pass" : "Fail");
	free(result3_std);
	free(result3_custom);

	// Test case 4: String with special characters
	const char *test4 = "Special characters: !@#$%^&*()_+";
	char *result4_std = strdup(test4);
	char *result4_custom = ft_strdup(test4);
	printf("Test Case 4:\n");
	printf("Standard strdup: %s\n", result4_std);
	printf("Custom ft_strdup: %s\n", result4_custom);
	printf("Result: %s\n\n", (strcmp(result4_std,
				result4_custom) == 0) ? "Pass" : "Fail");
	free(result4_std);
	free(result4_custom);

	// Test case 5: Long string
	const char *test5 = "This is a much longer test string to 
	ensure that everything works correctly.";
	char *result5_std = strdup(test5);
	char *result5_custom = ft_strdup(test5);
	printf("Test Case 5:\n");
	printf("Standard strdup: %s\n", result5_std);
	printf("Custom ft_strdup: %s\n", result5_custom);
	printf("Result: %s\n\n", (strcmp(result5_std,
				result5_custom) == 0) ? "Pass" : "Fail");
	free(result5_std);
	free(result5_custom);

	return (0);
}
*/