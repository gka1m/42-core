/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:22:55 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/02 16:40:00 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

int	is_int(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			ft_printf("Number %d is out of int range\n", num);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

int	dig_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("Invalid input: %s\n", argv[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// int main(int argc, char **argv)
// {
//     // Test case 1: Valid integer inputs
//     argv[1] = "1";
//     argv[2] = "2";
//     argv[3] = "3";
//     argc = 4;
//     if (is_int(argc, argv) && dig_input(argc, argv))
//         printf("Test case 1: Passed\n");
//     else
//         printf("Test case 1: Failed\n");

//     // Test case 2: Out of int range
//     argv[1] = "2147483648";
//     argc = 2;
//     if (!is_int(argc, argv))
//         printf("Test case 2: Passed\n");
//     else
//         printf("Test case 2: Failed\n");

//     // Test case 3: Non-integer input
//     argv[1] = "ABC";
//     argc = 2;
//     if (!dig_input(argc, argv))
//         printf("Test case 3: Passed\n");
//     else
//         printf("Test case 3: Failed\n");

//     // Test case 4: Negative integer input
//     argv[1] = "-56";
//     argc = 2;
//     if (is_int(argc, argv) && dig_input(argc, argv))
//         printf("Test case 4: Passed\n");
//     else
//         printf("Test case 4: Failed\n");

//     // Test case 5: Multiple arguments
//     argv[1] = "1";
//     argv[2] = "2";
//     argv[3] = "ABC";
//     argc = 4;
//     if (!dig_input(argc, argv))
//         printf("Test case 5: Passed\n");
//     else
//         printf("Test case 5: Failed\n");

//     return 0;
// }