/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:35:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/11/22 15:24:24 by kagoh            ###   ########.fr       */
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
		printf("Usage: ./philo <num_philos> <die_time> <eat_time> ");
		return (printf("<sleep_time> <[number of meals to be eaten]>\n"), 1);
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
			return (printf("Number of meals to be eaten must be positive\n"),
				1);
		i++;
	}
	return (0);
}
