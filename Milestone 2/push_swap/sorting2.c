/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:36:55 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 15:06:30 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (check_sorted(a) == 1)
	{
		ft_printf("Stack A is sorted. No sorting needed.\n");
		return ;
	}
	else
	{
		// less than 6 numbers, simple sort of numbers
		// if more than 6 numbers, call radix sort
		radix_sort(a, b);
	}
}

