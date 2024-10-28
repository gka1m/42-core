/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:35:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/28 15:56:36 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	is_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	validate_input(int ac, char **av)
{
	int	i;
	int	value;

	if (ac < 5 || ac > 6)
	{
		printf("Usage: ./philo <num_philos> <die_time> <eat_time> <sleep_time> ");
		return (printf("<[number of meals to be eaten]\n"), 1);
	}
	i = 1;
	while (i < ac)
	{
		if (is_digit(av[i]) != 0)
			return (printf("Inputs must be positive integers\n"), 1);
		value = ft_atoi(av[i]);
		if (i == 1 && (value <= 0 || value > 200))
			return (printf("Error: num_philos out of range\n"), 1);
		if ((i >= 2 && i <= 4) && value <= 0)
			return (printf("Time values must be positive\n"), 1);
		if (i == 5 && value <= 0)
			return (printf("Number of meals to be eaten must be positive\n"), 1);
		i++;
	}
	return (0);
}

// int main(void)
// {
//     // Test cases for validate_input function

//     // Valid input cases
//     char *test1[] = {"./philo", "5", "800", "200", "200"};
//     printf("Test 1 (Valid): %s\n", validate_input(5, test1) == 0 ? "Passed" : "Failed");

//     char *test2[] = {"./philo", "4", "400", "100", "300", "3"};
//     printf("Test 2 (Valid with optional max_meals): %s\n", validate_input(6, test2) == 0 ? "Passed" : "Failed");

//     // Invalid cases: Too few arguments
//     char *test3[] = {"./philo", "5", "800", "200"};
//     printf("Test 3 (Too few arguments): %s\n", validate_input(4, test3) != 0 ? "Passed" : "Failed");

//     // Invalid cases: Too many arguments
//     char *test4[] = {"./philo", "5", "800", "200", "200", "3", "extra"};
//     printf("Test 4 (Too many arguments): %s\n", validate_input(7, test4) != 0 ? "Passed" : "Failed");

//     // Invalid cases: Non-numeric strings
//     char *test5[] = {"./philo", "five", "800", "200", "200"};
//     printf("Test 5 (Non-numeric input): %s\n", validate_input(5, test5) != 0 ? "Passed" : "Failed");

//     char *test6[] = {"./philo", "5", "abc", "200", "200"};
//     printf("Test 6 (Non-numeric input): %s\n", validate_input(5, test6) != 0 ? "Passed" : "Failed");

//     // Invalid cases: Negative numbers
//     char *test7[] = {"./philo", "-5", "800", "200", "200"};
//     printf("Test 7 (Negative philosopher count): %s\n", validate_input(5, test7) != 0 ? "Passed" : "Failed");

//     char *test8[] = {"./philo", "5", "-800", "200", "200"};
//     printf("Test 8 (Negative time value): %s\n", validate_input(5, test8) != 0 ? "Passed" : "Failed");

//     // Invalid cases: Zero values
//     char *test9[] = {"./philo", "0", "800", "200", "200"};
//     printf("Test 9 (Zero philosopher count): %s\n", validate_input(5, test9) != 0 ? "Passed" : "Failed");

//     char *test10[] = {"./philo", "5", "800", "0", "200"};
//     printf("Test 10 (Zero time_to_eat): %s\n", validate_input(5, test10) != 0 ? "Passed" : "Failed");

//     // Invalid case: number_of_philosophers exceeding 200
//     char *test11[] = {"./philo", "201", "800", "200", "200"};
//     printf("Test 11 (Too many philosophers): %s\n", validate_input(5, test11) != 0 ? "Passed" : "Failed");

//     // Invalid cases: Extra spaces
//     char *test12[] = {"./philo", "   5", "800", "200", "200"};
//     printf("Test 12 (Spaces around number): %s\n", validate_input(5, test12) == 0 ? "Passed" : "Failed");

//     // Optional boundary test: Very large values (boundary check)
//     char *test13[] = {"./philo", "100", "1000000", "100000", "100000"};
//     printf("Test 13 (Large time values): %s\n", validate_input(5, test13) == 0 ? "Passed" : "Failed");

//     return 0;
// }