/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:59:26 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/01 14:05:51 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	sa(t_stack *a)
{
	swap(a);
}

void	sb(t_stack *b)
{
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

// // Function to create a new node
// t_node *new_node(int value)
// {
//     t_node *node = (t_node *)malloc(sizeof(t_node));
//     if (!node)
//         return NULL;
//     node->value = value;
//     node->next = NULL;
//     node->prev = NULL;
//     return node;
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
//         return;
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
//         return;
//     }
//     while (current)
//     {
//         printf("%d ", current->value);
//         current = current->next;
//     }
//     printf("\n");
// }

// // Test function in main
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
//     stack_push(&b, 100);
//     stack_push(&b, 200);
//     stack_push(&b, 300);

//     // Print the initial stacks
//     printf("Initial stacks:\n");
//     print_stack(&a, "a");
//     print_stack(&b, "b");

//     // Perform sa: swap the first two elements of stack a
//     sa(&a);
//     printf("\nAfter sa (swap a):\n");
//     print_stack(&a, "a");

//     // Perform sb: swap the first two elements of stack b
//     sb(&b);
//     printf("\nAfter sb (swap b):\n");
//     print_stack(&b, "b");

//     // Perform ss: swap both stack a and stack b
//     ss(&a, &b);
//     printf("\nAfter ss (swap both a and b):\n");
//     print_stack(&a, "a");
//     print_stack(&b, "b");

//     return 0;
// }