/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:03:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 14:34:01 by kagoh            ###   ########.fr       */
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
		ft_printf("Value: %d, Rank: %d\n", current->value, current->rank);
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
	int		bits;
	int		i;
	int		j;
	int		max_rank;
	t_node	*current;

	rank_nums(a);
	max_rank = find_max_rank(a);
	bits = calc_bits(max_rank);
	i = -1;
	while (++i < bits)
	{
		j = -1;
		while (++j < a->size)
		{
			current = a->top;
			if (((current->rank >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
	}
}

// void	print_stack_ranks(t_stack *stack)
// {
// 	t_node	*current;

// 	current = stack->top;
// 	ft_printf("Stack with ranks:\n");
// 	while (current)
// 	{
// 		ft_printf("Value: %d, Rank: %d\n", current->value, current->rank);
// 		current = current->next;
// 	}
// }

// int	main(int ac, char **av)
// {
// 	t_stack	*stack;

// 	if (ac < 2)
// 	{
// 		ft_printf("Error: No input provided\n");
// 		return (1);
// 	}

// 	// Initialize the stack with validated input
// 	stack = initialize(ac, av);
// 	if (!stack)
// 	{
// 		ft_printf("Error: Invalid input\n");
// 		return (1);
// 	}

// 	// Rank the numbers in the stack
// 	rank_nums(stack);

// 	// Print the stack values and their ranks
// 	print_stack_ranks(stack);

// 	// Free the stack after use
// 	free_stack(stack);
// 	return (0);
// }