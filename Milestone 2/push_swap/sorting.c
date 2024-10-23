/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:03:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/23 11:40:29 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>

int	check_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	rank_nums(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		current->rank = 0;
		compare = stack->top;
		while (compare)
		{
			if (current->value > compare->value)
				current->rank++;
			compare = compare->next;
		}
		current = current->next;
	}
}

int	calc_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	find_max_rank(t_stack *stack)
{
	t_node	*current;
	int		max_rank;

	if (!stack || !stack->top)
		return (0);
	max_rank = stack->top->rank;
	current = stack->top;
	while (current)
	{
		if (current->rank > max_rank)
			max_rank = current->rank;
		current = current->next;
	}
	return (max_rank);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		size;
	int		i;
	int		j;
	int		max_rank;
	t_node	*current;

	rank_nums(a);
	max_rank = find_max_rank(a);
	i = -1;
	size = a->size;
	while (++i < calc_bits(max_rank))
	{
		j = -1;
		while (++j < size)
		{
			current = a->top;
			if (((current->rank >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size)
			pa(a, b);
	}
}
