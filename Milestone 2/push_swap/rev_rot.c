/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:41:57 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/08 12:11:41 by kagoh            ###   ########.fr       */
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
	last = stack->bottom;
	sec_last = last->prev;
	sec_last->next = NULL;
	stack->bottom = sec_last;
	last->next = stack->top;
	stack->top->prev = last;
	last->prev = NULL;
	stack->top = last;
}

void	rra(t_stack *a)
{
	rev_rot(a);
}

void	rrb(t_stack *b)
{
	rev_rot(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
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

// // // Function to print the contents of a stack
// // void print_stack(t_stack *stack, char *name)
// // {
// //     printf("Stack %s: ", name);
// //     t_node *current = stack->top;
// //     if (current == NULL)
// //     {
// //         printf("Empty\n");
// //         return ;
// //     }
// //     while (current)
// //     {
// //         printf("%d ", current->value);
// //         current = current->next;
// //     }
// //     printf("\n");
// // }

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
//     stack_push(&a, 20);

//     // Add some elements to stack b
//     stack_push(&b, 100);
//     stack_push(&b, 200);
//     stack_push(&b, 300);

//     // Print the initial stacks
//     printf("Initial stacks:\n");
//     print_stack(&a);
//     print_stack(&b);

//     // Perform rra: reverse rotate stack a
//     rra(&a);
//     printf("\nAfter rra (reverse rotate a):\n");
//     print_stack(&a);

//     // Perform rrb: reverse rotate stack b
//     rrb(&b);
//     printf("\nAfter rrb (reverse rotate b):\n");
//     print_stack(&b);

//     // Perform rrr: reverse rotate both a and b
//     rrr(&a, &b);
//     printf("\nAfter rrr (reverse rotate both a and b):\n");
//     print_stack(&a);
//     print_stack(&b);

//     return (0);
// }
