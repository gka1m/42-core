/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:03:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/15 18:02:29 by kagoh            ###   ########.fr       */
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

void	radix_sort(t_stack *a, t_stack *b)
{
	int		bits;
	int		i;
	int		j;
	t_node	*current;

	rank_nums(a);
	bits = calc_bits(a->size - 1);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < a->size)
		{
			current = a->top;
			if (((current->rank >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (check_sorted(a) == 1)
	{
		ft_printf("Stack A is sorted. No sorting needed.\n");
		return ;
	}
	else
		radix_sort(a, b);
}


// void	print_stack(t_stack *stack)
// {
// 	t_node	*current;

// 	if (stack == NULL || stack->top == NULL)
// 		return ;
// 	current = stack->top;
// 	while (current)
// 	{
// 		ft_printf("%d\n", current->value);
// 		current = current->next;
// 	}
// 	ft_printf("\n");
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		i;

// 	if (argc < 2)
// 	{
// 		ft_printf("Usage: ./push_swap <numbers>\n");
// 		return (1);
// 	}

// 	// Initialize stacks
// 	a = malloc(sizeof(t_stack));
// 	b = malloc(sizeof(t_stack));
// 	if (!a || !b)
// 		return (ft_printf("Error: Stack allocation failed\n"), 1);
// 	init_stack(a); // Assume you have a function to initialize a stack
// 	init_stack(b);

// 	// Fill stack A with input numbers
// 	i = 1;
// 	while (i < argc)
// 	{
// 		int num = ft_atoi(argv[i]);
// 		push(a, num); // Assume push adds a node with value `num` to stack A
// 		i++;
// 	}

// 	// Print original stack for reference
// 	ft_printf("Original Stack A:\n");
// 	print_stack(a); // Assume you have a function to print the stack

// 	// Sort stack A using radix sort
// 	sort_stack(a, b);

// 	// Print sorted stack for verification
// 	ft_printf("Sorted Stack A:\n");
// 	print_stack(a);

// 	// Free stacks
// 	free_stack(a); // Assume you have a function to free a stack
// 	free_stack(b);

// 	return (0);
// }
