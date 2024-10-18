/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:36:55 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 15:54:56 by kagoh            ###   ########.fr       */
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
		// less than 6 numbers, simple sort of numbers using quicksort
		if (ft_lstsize(a) <= 6)
			quicksort(a, b);
		// if more than 6 numbers, call radix sort
		else if (ft_lstsize(a) > 6)
			radix_sort(a, b);
	}
}

void	quicksort(t_stack *a, t_stack *b)
{
	int		pivot;
	t_node	*current;

	pivot = 0;
	current = a->top;
	if (a->size <= 1)
		return ;
	while (current)
	{
		if (current->value < pivot)
			pb(a, b);
		else
			ra(a);
		current = a->top;
	}
	quicksort(a, b);
	quicksort(b, a);
	while (b->size > 0)
		pa(b, a);
	to_stack(a, pivot);
}
