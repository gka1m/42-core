/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:39 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/02 16:57:55 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	init_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

void	to_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*new;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new = new_node(value);
		if (!new)
			return;
		if (stack->top == NULL)
		{
			stack->top = new;
			stack->bottom = new;
		}
		else
		{
			new->prev = stack->top;
			stack->top->next = new;
			stack->top = new;
		}
		stack->size++;
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->prev;
		free(temp);
	}
	free(stack);
}

t_stack *in_val(int ac, char **av)
{
	t_stack	*stack;

	if (!is_int(ac, av))
		return (NULL);
	if (!dig_input(ac, av))
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	init_stack(stack);
	to_stack(stack, ac, av);
	return (stack);
}

// void print_stack(t_stack *stack)
// {
//     t_node *current = stack->top;

//     printf("Stack contents (top to bottom):\n");
//     while (current)
//     {
//         printf("%d\n", current->value);
//         current = current->prev;
//     }
// }

// int main(int argc, char **argv)
// {
//     t_stack *stack;

//     // Call in_val to validate input and initialize stack
//     stack = in_val(argc, argv);

//     if (!stack)
//     {
//         printf("Error: Invalid input\n");
//         return (1);  // Exit if validation failed
//     }

//     // Print the contents of the stack
//     print_stack(stack);

//     // Free the stack and its nodes after testing
//     // You will need to implement a function to free the stack here
// 	free_stack(stack);
//     return (0);
// }