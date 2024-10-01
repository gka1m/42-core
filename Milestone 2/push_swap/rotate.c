/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:21:12 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/01 14:01:11 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	stack->top = second;
	second->prev = NULL;
	first->next = NULL;
	first->prev = stack->bottom;
	stack->bottom->next = first;
	stack->bottom = first;
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

// // Function to create a new node
// t_node	*new_node(int value)
// {
// 	t_node	*node;

// 	node = (t_node *)malloc(sizeof(t_node));
// 	if (!node)
// 		return (NULL);
// 	node->value = value;
// 	node->next = NULL;
// 	node->prev = NULL;
// 	return (node);
// }

// // Function to initialize an empty stack
// void	init_stack(t_stack *stack)
// {
// 	stack->top = NULL;
// 	stack->bottom = NULL;
// 	stack->size = 0;
// }

// // Function to push a new value to the top of the stack
// void	stack_push(t_stack *stack, int value)
// {
// 	t_node	*node;

// 	node = new_node(value);
// 	if (!node)
// 		return ;
// 	if (stack->size == 0)
// 	{
// 		stack->top = node;
// 		stack->bottom = node;
// 	}
// 	else
// 	{
// 		node->next = stack->top;
// 		stack->top->prev = node;
// 		stack->top = node;
// 	}
// 	stack->size++;
// }

// // Function to print the contents of a stack
// void	print_stack(t_stack *stack, char *name)
// {
// 	t_node	*current;

// 	printf("Stack %s: ", name);
// 	current = stack->top;
// 	if (current == NULL)
// 	{
// 		printf("Empty\n");
// 		return ;
// 	}
// 	while (current)
// 	{
// 		printf("%d ", current->value);
// 		current = current->next;
// 	}
// 	printf("\n");
// }

// // Test function in main
// int	main(void)
// {
// 	// Initialize two stacks
// 	t_stack a, b;
// 	init_stack(&a);
// 	init_stack(&b);

// 	// Add some elements to stack a
// 	stack_push(&a, 5);
// 	stack_push(&a, 10);
// 	stack_push(&a, 15);
// 	stack_push(&a, 20);

// 	// Add some elements to stack b
// 	stack_push(&b, 100);
// 	stack_push(&b, 200);
// 	stack_push(&b, 300);

// 	// Print the initial stacks
// 	printf("Initial stacks:\n");
// 	print_stack(&a, "a");
// 	print_stack(&b, "b");

// 	// Perform ra: rotate stack a
// 	ra(&a);
// 	printf("\nAfter ra (rotate a):\n");
// 	print_stack(&a, "a");

// 	// Perform rb: rotate stack b
// 	rb(&b);
// 	printf("\nAfter rb (rotate b):\n");
// 	print_stack(&b, "b");

// 	// Perform rr: rotate both a and b
// 	rr(&a, &b);
// 	printf("\nAfter rr (rotate both a and b):\n");
// 	print_stack(&a, "a");
// 	print_stack(&b, "b");

// 	return (0);
// }