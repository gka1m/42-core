/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:29 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 18:08:29 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == chr)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}

/*int main(void)
{
	// Test case 1: Character present in the string
	char str1[] = "Hello, World!";
	int ch1 = 'o';
	printf("Test Case 1:\n");
	printf("Standard strrchr: %s\n", strrchr(str1, ch1));
	printf("Custom ft_strrchr: %s\n", ft_strrchr(str1, ch1));
	printf("Result: %s\n\n", (strrchr(str1, ch1) == ft_strrchr(str1,
				ch1)) ? "Pass" : "Fail");

	// Test case 2: Character not present in the string
	char str2[] = "Hello, World!";
	int ch2 = 'z';
	printf("Test Case 2:\n");
	printf("Standard strrchr: %s\n", strrchr(str2, ch2));
	printf("Custom ft_strrchr: %s\n", ft_strrchr(str2, ch2));
	printf("Result: %s\n\n", (strrchr(str2, ch2) == ft_strrchr(str2,
				ch2)) ? "Pass" : "Fail");

	// Test case 3: Character at the beginning of the string
	char str3[] = "Hello, World!";
	int ch3 = 'H';
	printf("Test Case 3:\n");
	printf("Standard strrchr: %s\n", strrchr(str3, ch3));
	printf("Custom ft_strrchr: %s\n", ft_strrchr(str3, ch3));
	printf("Result: %s\n\n", (strrchr(str3, ch3) == ft_strrchr(str3,
				ch3)) ? "Pass" : "Fail");

	// Test case 4: Character at the end of the string
	char str4[] = "Hello, World!";
	int ch4 = '!';
	printf("Test Case 4:\n");
	printf("Standard strrchr: %s\n", strrchr(str4, ch4));
	printf("Custom ft_strrchr: %s\n", ft_strrchr(str4, ch4));
	printf("Result: %s\n\n", (strrchr(str4, ch4) == ft_strrchr(str4,
				ch4)) ? "Pass" : "Fail");

	// Test case 5: Null terminator character
	char str5[] = "Hello, World!";
	int ch5 = '\0';
	printf("Test Case 5:\n");
	printf("Standard strrchr: %s\n", strrchr(str5, ch5));
	printf("Custom ft_strrchr: %s\n", ft_strrchr(str5, ch5));
	printf("Result: %s\n\n", (strrchr(str5, ch5) == ft_strrchr(str5,
				ch5)) ? "Pass" : "Fail");

	return (0);
}
*/