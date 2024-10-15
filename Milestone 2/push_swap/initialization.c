/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:39 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/15 18:11:34 by kagoh            ###   ########.fr       */
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
	int		unique[ac * 10];
	int		count;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	init_stack(stack);
	count = validate_input(ac, av, unique);
	if (count == 0)
		return (free(stack), NULL);
	i = 0;
	while (i < count)
	{
		to_stack(stack, unique[i]);
		i++;
	}
	return (stack);
}

// // Function to print the stack
// void print_stack(t_stack *stack) {
//     t_node *current = stack->top;
//     printf("Stack (size %d): ", stack->size);
//     while (current) {
//         printf("%d ", current->value);
//         current = current->next;
//     }
//     printf("\n");
// }

// // Main function
// int	main(int argc, char **argv)
// {
// 	t_stack	*stack;
// 	t_node	*current;

// 	if (argc < 2)
// 	{
// 		printf("Usage: %s <numbers>\n", argv[0]);
// 		return (1);
// 	}

// 	stack = initialize(argc, argv);
// 	if (!stack)
// 	{
// 		printf("Error: Invalid input or memory allocation failed\n");
// 		return (1);
// 	}

// 	printf("Stack contents:\n");
// 	current = stack->top;
// 	while (current)
// 	{
// 		printf("%d\n", current->value);
// 		current = current->next;
// 	}

// 	free_stack(stack);
// 	return (0);
// }