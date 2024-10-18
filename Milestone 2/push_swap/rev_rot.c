/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:41:57 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 15:51:33 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rev_rot(t_stack *stack)
{
	t_node	*last;
	t_node	*sec_last;

	if (stack->size < 2)
		return ;
	sec_last = stack->top;
	while (sec_last->next && sec_last->next->next)
		sec_last = sec_last->next;
	last = sec_last->next;
	sec_last->next = NULL;
	stack->bottom = sec_last;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	rev_rot(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	rev_rot(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rot(a);
	rev_rot(b);
	ft_printf("rrr\n");
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

//     // Perform reverse rotation operations
//     printf("\nPerforming rra (reverse rotate A):\n");
//     rra(&a);
//     printf("Stack A: ");
//     print_stack(&a);

//     printf("\nPerforming rrb (reverse rotate B):\n");
//     rrb(&b);
//     printf("Stack B: ");
//     print_stack(&b);

//     printf("\nPerforming rrr (reverse rotate both A and B):\n");
//     rrr(&a, &b);
//     printf("Stack A: ");
//     print_stack(&a);
//     printf("Stack B: ");
//     print_stack(&b);

//     // Clean up dynamically allocated nodes
//     free_stack(&a);
//     free_stack(&b);

//     return 0;
// }