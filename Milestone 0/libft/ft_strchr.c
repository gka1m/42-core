/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:02:21 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 18:02:21 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	if (chr == '\0')
	{
		while (str[i] != '\0')
			i++;
		return ((char *)(str + i));
	}
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)(str + i));
		else
			i++;
	}
	return (NULL);
}

/*int main(void)
{
	// Test case 1: Character is present in the string
	const char *str1 = "Hello, World!";
	char ch1 = 'W';
	char *result1_std = strchr(str1, ch1);
	char *result1_custom = ft_strchr(str1, ch1);

	printf("Test Case 1:\n");
	printf("Standard strchr: %s\n", result1_std);
	printf("Custom ft_strchr: %s\n", result1_custom);
	printf("Result: %s\n\n",
		(result1_std == result1_custom) ? "Pass" : "Fail");

	// Test case 2: Character is not present in the string
	const char *str2 = "Hello, World!";
	char ch2 = 'x';
	char *result2_std = strchr(str2, ch2);
	char *result2_custom = ft_strchr(str2, ch2);

	printf("Test Case 2:\n");
	printf("Standard strchr: %s\n", result2_std);
	printf("Custom ft_strchr: %s\n", result2_custom);
	printf("Result: %s\n\n",
		(result2_std == result2_custom) ? "Pass" : "Fail");

	// Test case 3: Search for the null terminator
	const char *str3 = "Hello, World!";
	char ch3 = '\0';
	char *result3_std = strchr(str3, ch3);
	char *result3_custom = ft_strchr(str3, ch3);

	printf("Test Case 3:\n");
	printf("Standard strchr: %p\n", result3_std);
	printf("Custom ft_strchr: %p\n", result3_custom);
	printf("Result: %s\n\n",
		(result3_std == result3_custom) ? "Pass" : "Fail");

	// Test case 4: Empty string
	const char *str4 = "";
	char ch4 = 'H';
	char *result4_std = strchr(str4, ch4);
	char *result4_custom = ft_strchr(str4, ch4);

	printf("Test Case 4:\n");
	printf("Standard strchr: %p\n", result4_std);
	printf("Custom ft_strchr: %p\n", result4_custom);
	printf("Result: %s\n\n",
		(result4_std == result4_custom) ? "Pass" : "Fail");

	// Test case 5: Search for the first character
	const char *str5 = "Hello, World!";
	char ch5 = 'H';
	char *result5_std = strchr(str5, ch5);
	char *result5_custom = ft_strchr(str5, ch5);

	printf("Test Case 5:\n");
	printf("Standard strchr: %s\n", result5_std);
	printf("Custom ft_strchr: %s\n", result5_custom);
	printf("Result: %s\n\n",
		(result5_std == result5_custom) ? "Pass" : "Fail");

	return (0);
}
*/