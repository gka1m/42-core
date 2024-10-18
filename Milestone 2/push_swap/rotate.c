/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:21:12 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 15:52:21 by kagoh            ###   ########.fr       */
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
	stack->bottom->next = first;
	stack->bottom = first;
	first->next = NULL;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

// // Function to create a new node
// t_node *create_node(int value) {
//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     if (!new_node) {
//         perror("Failed to allocate memory for node");
//         exit(EXIT_FAILURE);
//     }
//     new_node->value = value;
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
//     if (stack->size == 0) {
//         stack->top = new_node;
//         stack->bottom = new_node;
//     } else {
//         new_node->next = stack->top;
//         stack->top = new_node;
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

// // Function to free all nodes in a stack
// void free_stack(t_stack *stack) {
//     t_node *current = stack->top;
//     t_node *next;
//     while (current) {
//         next = current->next;
//         free(current);
//         current = next;
//     }
//     stack->top = NULL;
//     stack->bottom = NULL;
//     stack->size = 0;
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

//     // Populate stack b with some values
//     push_value(&b, 4);
//     push_value(&b, 5);
//     push_value(&b, 6);

//     // Print initial stacks
//     printf("Initial stacks:\n");
//     printf("Stack A: ");
//     print_stack(&a);
//     printf("Stack B: ");
//     print_stack(&b);

//     // Perform rotation operations
//     printf("\nPerforming ra (rotate A):\n");
//     ra(&a);
//     printf("Stack A: ");
//     print_stack(&a);

//     printf("\nPerforming rb (rotate B):\n");
//     rb(&b);
//     printf("Stack B: ");
//     print_stack(&b);

//     printf("\nPerforming rr (rotate both A and B):\n");
//     rr(&a, &b);
//     printf("Stack A: ");
//     print_stack(&a);
//     printf("Stack B: ");
//     print_stack(&b);

//     // Clean up dynamically allocated nodes
//     free_stack(&a);
//     free_stack(&b);

//     return 0;
// }