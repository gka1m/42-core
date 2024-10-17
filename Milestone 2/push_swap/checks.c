/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:22:55 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/17 16:49:29 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>

int	valid_num(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(char **nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
		{
			if (ft_strcmp(nums[i], nums[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**split_input(int ac, char **av)
{
	int		i;
	char	**nums;

	if (ac == 2)
		nums = ft_split(av[1], ' ');
	else
	{
		nums = malloc(ac * sizeof(char *));
		if (!nums)
			return (NULL);
		i = 1;
		while (i < ac)
		{
			nums[i - 1] = ft_strdup(av[i]);
			i++;
		}
		nums[ac - 1] = NULL;
	}
	return (nums);
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

char	**validate_input(int ac, char **av)
{
	char	**nums;
	int		i;

	nums = split_input(ac, av);
	if (!nums || has_duplicates(nums))
		return (free_split(nums), NULL);
	i = 0;
	while (nums[i])
	{
		if (valid_num(nums[i]) == 0)
			return (free_split(nums), NULL);
		i++;
	}
	return (nums);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: ./a.out <numbers> or ./a.out <numbers in string>\n");
		return 1;
	}
	char **result = validate_input(ac, av);
	if (result)
	{
		printf("Input is valid!\n");
		for (int i = 0; result[i] != NULL; i++)
            printf("%s ", result[i]);
	}
	else
	{
		printf("Invalid Input.\n");
		return (1);
	}
	free_split(result);
	return (0);
}
