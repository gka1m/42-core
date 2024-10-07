/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:03:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/07 17:25:16 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	check_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->bottom;
	while (current && current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (stack == NULL || stack->top == NULL)
		return (0);
	current = stack->top;
	max = current->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	calc_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b, int max, int bits)
{
	int		i;
	int		j;
	t_node	*current;

	if (a == NULL || b == NULL)
		return ;
	max = find_max(a);
	if (max == 0)
		return ;
	bits = calc_bits(max);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->top == NULL)
				break ;
			current = a->top;
			if (((current->value >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		i++;
	}
	while (a->size-- > 0)
		pa(b, a);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	max;
	int	bits;

	if (check_sorted(a) == 1)
	{
		ft_printf("Stack A is sorted. Pushing to B...\n");
		while (a->size-- > 0)
			pb(a, b);
	}
	else
	{
		max = find_max(a);
		bits = calc_bits(max);
		radix_sort(a, b, max, bits);
	}
}
