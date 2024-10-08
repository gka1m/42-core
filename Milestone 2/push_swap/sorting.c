/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:03:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/08 17:57:01 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

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
	int		rank;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		rank = 0;
		compare = stack->top;
		while (compare)
		{
			if (current->value > compare->value)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
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
// 	t_stack	a;
// 	t_stack	b;
// 	t_node	*current;
// 	t_node	*new;
// 	int		i;
// 	int		value;

// 	// Initialize stacks
// 	init_stack(&a);
// 	init_stack(&b);

// 	// Check if there are enough arguments
// 	if (argc < 2)
// 	{
// 		ft_printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
// 		return (1);
// 	}

// 	// Parse command-line arguments and create nodes
// 	for (i = 1; i < argc; i++)
// 	{
// 		value = atoi(argv[i]); // Convert argument to integer
// 		new = new_node(value);
// 		if (!new)
// 		{
// 			ft_printf("Error: Memory allocation failed\n");
// 			return (1);
// 		}
// 		// Add node to the bottom of the stack
// 		if (a.size == 0)
// 		{
// 			a.top = new;
// 			a.bottom = new;
// 		}
// 		else
// 		{
// 			a.bottom->next = new;
// 			new->prev = a.bottom;
// 			a.bottom = new;
// 		}
// 		a.size++;
// 	}

// 	// Print initial stack state
// 	ft_printf("Initial stack A: \n");
// 	print_stack(&a);

// 	// Test check_sorted
// 	if (check_sorted(&a))
// 		ft_printf("Stack A is already sorted.\n");
// 	else
// 		ft_printf("Stack A is not sorted.\n");

// 	// Test rank_nums
// 	ft_printf("Assigning ranks to stack A:\n");
// 	rank_nums(&a);  // This should print the values and ranks

// 	// Check if sorted
// 	if (check_sorted(&a) == 0)
// 	{
// 		ft_printf("Sorting stack: \n");
// 		sort_stack(&a, &b);
// 	}

// 	// Print final stack A after sorting
// 	ft_printf("Final sorted stack A: \n");
// 	print_stack(&a);

// 	return (0);
// }

