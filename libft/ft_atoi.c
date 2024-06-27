/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:57:42 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/20 17:57:42 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

/*int main(void)
{
	const char *test1 = "42";
	const char *test2 = "   -42";
	const char *test3 = "4193 with words";
	const char *test4 = "words and 987";
	const char *test5 = "-91283472332";
	const char *test6 = "2147483647";
	const char *test7 = "-2147483648";
	const char *test8 = "0";
	const char *test9 = "+123";
	const char *test10 = "   +0 123";

	// Test case 1
	printf("Test Case 1:\n");
	printf("Standard atoi: %d\n", atoi(test1));
	printf("Custom ft_atoi: %d\n", ft_atoi(test1));
	printf("Result: %s\n\n", (atoi(test1)
	== ft_atoi(test1)) ? "Pass" : "Fail");

	// Test case 2
	printf("Test Case 2:\n");
	printf("Standard atoi: %d\n", atoi(test2));
	printf("Custom ft_atoi: %d\n", ft_atoi(test2));
	printf("Result: %s\n\n", (atoi(test2)
	== ft_atoi(test2)) ? "Pass" : "Fail");

	// Test case 3
	printf("Test Case 3:\n");
	printf("Standard atoi: %d\n", atoi(test3));
	printf("Custom ft_atoi: %d\n", ft_atoi(test3));
	printf("Result: %s\n\n", (atoi(test3)
	== ft_atoi(test3)) ? "Pass" : "Fail");

	// Test case 4
	printf("Test Case 4:\n");
	printf("Standard atoi: %d\n", atoi(test4));
	printf("Custom ft_atoi: %d\n", ft_atoi(test4));
	printf("Result: %s\n\n", (atoi(test4)
	== ft_atoi(test4)) ? "Pass" : "Fail");

	// Test case 5
	printf("Test Case 5:\n");
	printf("Standard atoi: %d\n", atoi(test5));
	printf("Custom ft_atoi: %d\n", ft_atoi(test5));
	printf("Result: %s\n\n", (atoi(test5)
	== ft_atoi(test5)) ? "Pass" : "Fail");

	// Test case 6
	printf("Test Case 6:\n");
	printf("Standard atoi: %d\n", atoi(test6));
	printf("Custom ft_atoi: %d\n", ft_atoi(test6));
	printf("Result: %s\n\n", (atoi(test6)
	== ft_atoi(test6)) ? "Pass" : "Fail");

	// Test case 7
	printf("Test Case 7:\n");
	printf("Standard atoi: %d\n", atoi(test7));
	printf("Custom ft_atoi: %d\n", ft_atoi(test7));
	printf("Result: %s\n\n", (atoi(test7)
	== ft_atoi(test7)) ? "Pass" : "Fail");

	// Test case 8
	printf("Test Case 8:\n");
	printf("Standard atoi: %d\n", atoi(test8));
	printf("Custom ft_atoi: %d\n", ft_atoi(test8));
	printf("Result: %s\n\n", (atoi(test8)
	== ft_atoi(test8)) ? "Pass" : "Fail");

	// Test case 9
	printf("Test Case 9:\n");
	printf("Standard atoi: %d\n", atoi(test9));
	printf("Custom ft_atoi: %d\n", ft_atoi(test9));
	printf("Result: %s\n\n", (atoi(test9)
	== ft_atoi(test9)) ? "Pass" : "Fail");

	// Test case 10
	printf("Test Case 10:\n");
	printf("Standard atoi: %d\n", atoi(test10));
	printf("Custom ft_atoi: %d\n", ft_atoi(test10));
	printf("Result: %s\n\n", (atoi(test10)
	== ft_atoi(test10)) ? "Pass" : "Fail");

	return (0);
}
*/