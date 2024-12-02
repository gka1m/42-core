/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:35:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/12/02 15:13:40 by kagoh            ###   ########.fr       */
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

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!is_digit(str[i]))
		return (1);
	while (str[i])
	{
		if (!is_digit(str[i]))
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
	i = 0;
	while (++i < ac)
	{
		if (is_valid_number(av[i]) == 1)
			return (printf("Inputs should be numbers\n"), 1);
		else
		{
			value = ft_atoi(av[i]);
			if (i == 1 && value <= 0)
				return (printf("Error: num_philos must be positive\n"), 1);
			else if ((i >= 2 && i <= 4) && value <= 0)
				return (printf("Time values must be positive\n"), 1);
			else if (i == 5 && value <= 0)
				return (printf("Number of meals must be positive\n"), 1);
		}
	}
	return (0);
}
