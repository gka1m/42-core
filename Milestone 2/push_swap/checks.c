/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:22:55 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/15 18:05:52 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>

// int	ft_isdigit(char c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

int	valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_store(char **nums, int *unique, int *count)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (nums[i])
	{
		if (!valid_num(nums[i]))
			return (0);
		num = ft_atoi(nums[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (ft_printf("Number out of range\n"), 0);
		j = 0;
		while (j < *count)
		{
			if (unique[j] == num)
				return (0);
			j++;
		}
		unique[*count] = (int)num;
		(*count)++;
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	validate_input(int ac, char **av, int *unique)
{
	int		count;
	int		i;
	char	**nums;

	if (ac < 2)
		return (0);
	count = 0;
	i = 1;
	while (i < ac)
	{
		nums = ft_split(av[i], ' ');
		if (!validate_store(nums, unique, &count))
			return (free_split(nums), 0);
		free_split(nums);
		i++;
	}
	return (count);
}

// int	main(int argc, char **argv)
// {
// 	int	uniq_nums[argc * 10];
// 	int	count;
// 	int	i;

// 	count = validate_input(argc, argv, uniq_nums);
// 	if (count == 0)
// 	{
// 		ft_printf("Error\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (i < count)
// 	{
// 		ft_printf("%d ", uniq_nums[i]);
// 		i++;
// 	}
// 	ft_printf("\n");
// 	return (0);
// }