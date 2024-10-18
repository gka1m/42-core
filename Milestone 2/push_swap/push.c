/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:06:29 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 15:48:50 by kagoh            ###   ########.fr       */
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
	src->top = src_top->next;
	if (src->top == NULL)
		src->bottom = NULL;
	src_top->next = dest->top;
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
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL)
		return ;
	push(a, b);
	ft_printf("pb\n");
}

// // Function to create a new node
// t_node *create_node(int value) {
//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     if (!new_node) {
//         perror("Failed to allocate memory for node");
//         exit(EXIT_FAILURE);
//     }
//     new_node->value = value;
//     new_node->rank = 0; // Assuming rank is not used in this test
//     new_node->next = NULL;
//     return new_node;
// }

// // Function to initialize a stack
// void init_stack(t_stack *stack) {
//     stack->top = NULL;
//     stack->bottom = NULL;
//     stack->size = 0;
// }

// // Function to push a value onto a stack
// void push_value(t_stack *stack, int value) {
//     t_node *new_node = create_node(value);
//     new_node->next = stack->top;
//     stack->top = new_node;
//     if (stack->size == 0) {
//         stack->bottom = new_node;
//     }
//     stack->size++;
// }

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

// int main() {
//     t_stack a, b;

//     // Initialize stacks
//     init_stack(&a);
//     init_stack(&b);

//     // Populate stack a with some values
//     push_value(&a, 1);
//     push_value(&a, 2);
//     push_value(&a, 3);

//     // Print initial stacks
//     printf("Initial stacks:\n");
//     printf("Stack A: ");
//     print_stack(&a);
//     printf("Stack B: ");
//     print_stack(&b);

//     // Perform push operations
//     printf("\nPerforming pb (push from A to B):\n");
//     pb(&a, &b);
//     printf("Stack A: ");
//     print_stack(&a);
//     printf("Stack B: ");
//     print_stack(&b);

//     printf("\nPerforming pa (push from B to A):\n");
//     pa(&a, &b);
//     printf("Stack A: ");
//     print_stack(&a);
//     printf("Stack B: ");
//     print_stack(&b);

//     // Clean up dynamically allocated nodes (not shown here)
//     // You should implement a function to free all nodes in a stack

//     return 0;
// }