/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:39 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 14:44:06 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	to_stack(t_stack *stack, int value)
{
	t_node	*new;

	new = new_node(value);
	if (!new)
	{
		free_stack(stack);
		exit(1);
	}
	if (stack->top == NULL)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->next = new;
		stack->bottom = new;
	}
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}

t_stack	*initialize(int ac, char **av)
{
	t_stack	*stack;
	char	**nums;
	int		value;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	init_stack(stack);
	nums = validate_input(ac, av);
	if (!nums)
		return (free(stack), NULL);
	i = 0;
	while (nums[i])
	{
		value = (int)ft_atol(nums[i]);
		to_stack(stack, value);
		i++;
	}
	free_split(nums);
	return (stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	ft_printf("Stack A:\n");
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

// int	main(int ac, char **av)
// {
// 	t_stack	*stack;

// 	if (ac < 2)
// 	{
// 		ft_printf("Error: No input provided\n");
// 		return (1);
// 	}
// 	// Initialize stack with validated input
// 	stack = initialize(ac, av);
// 	if (!stack)
// 	{
// 		ft_printf("Error: Invalid input\n");
// 		return (1);
// 	}

// 	// Print the stack to verify values
// 	print_stack(stack);

// 	// Free stack after use
// 	free_stack(stack);
// 	return (0);
// }