/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:06:29 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/08 12:18:31 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push(t_stack *src, t_stack *dest)
{
	t_node	*src_top;

	if (src->size == 0)
		return ;
	src_top = src->top;
	if (!src_top)
		return ;
	src->top = src_top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src_top->next = dest->top;
	if (dest->top)
		dest->top->prev = src_top;
	else
		dest->bottom = src_top;
	src_top->prev = NULL;
	dest->top = src_top;
	if (dest->size == 0)
		dest->bottom = src_top;
	src->size--;
	dest->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL)
		return ;
	push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL)
		return ;
	push(a, b);
}

// t_node *new_node(int value)
// {
//     t_node *node = (t_node *)malloc(sizeof(t_node));
//     if (!node)
//         return (NULL);
//     node->value = value;
//     node->next = NULL;
//     node->prev = NULL;
//     return (node);
// }

// // Function to initialize an empty stack
// void init_stack(t_stack *stack)
// {
//     stack->top = NULL;
//     stack->bottom = NULL;
//     stack->size = 0;
// }

// // Function to push a new value to the top of the stack
// void stack_push(t_stack *stack, int value)
// {
//     t_node *node = new_node(value);
//     if (!node)
//         return ;
//     if (stack->size == 0)
//     {
//         stack->top = node;
//         stack->bottom = node;
//     }
//     else
//     {
//         node->next = stack->top;
//         stack->top->prev = node;
//         stack->top = node;
//     }
//     stack->size++;
// }

// // Function to print the contents of a stack
// void print_stack(t_stack *stack, char *name)
// {
//     printf("Stack %s: ", name);
//     t_node *current = stack->top;
//     if (current == NULL)
//     {
//         printf("Empty\n");
//         return ;
//     }
//     while (current)
//     {
//         printf("%d ", current->value);
//         current = current->next;
//     }
//     printf("\n");
// }

// void	print_stack(t_stack *stack)
// {
// 	t_node	*current;

// 	current = stack->top;
// 	while (current)
// 	{
// 		ft_printf("%d\n", current->value);
// 		current = current->next;
// 	}
// }

// int main()
// {
//     // Initialize two stacks
//     t_stack a, b;
//     init_stack(&a);
//     init_stack(&b);

//     // Add some elements to stack a
//     stack_push(&a, 5);
//     stack_push(&a, 10);
//     stack_push(&a, 15);

//     // Add some elements to stack b
//     stack_push(&b, 20);
//     stack_push(&b, 25);

//     // Print the initial stacks
//     printf("Initial stacks:\nStack A:\n");
//     print_stack(&a);
//     printf("Stack B:\n");
//     print_stack(&b);

//     // Perform pb: push top of a to b
//     pb(&a, &b);
//     printf("\nAfter pb (push top of a to b):\nStack A:\n");
//     print_stack(&a);
//     printf("Stack B:\n");
//     print_stack(&b);

//     // Perform pa: push top of b to a
//     pa(&a, &b);
//     printf("\nAfter pa (push top of b to a):\nStack A:\n");
//     print_stack(&a);
//     printf("Stack B:\n");
//     print_stack(&b);

//     // Perform pb again
//     pb(&a, &b);
//     printf("\nAfter another pb (push top of a to b):\nStack A:\n");
//     print_stack(&a);
//     printf("Stack B:\n");
//     print_stack(&b);

//     return 0;
// }
