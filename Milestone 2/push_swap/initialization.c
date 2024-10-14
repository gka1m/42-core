/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:39 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/14 17:07:04 by kagoh            ###   ########.fr       */
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
	node->prev = NULL;
	return (node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	to_stack(t_stack *stack, int *unique, int count)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < count)
	{
		new = new_node(unique[i]);
		if (!new)
			return (free_stack(stack));
		if (stack->bottom == NULL)
		{
			stack->top = new;
			stack->bottom = new;
		}
		else
		{
			new->next = stack->bottom;
			stack->bottom->prev = new;
			stack->bottom = new;
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

t_stack	*in_val(int ac, char **av)
{
	t_stack	*stack;
	int		unique[ac - 1];
	int		count;

	count = validate_input(ac, av, unique);
	if (count == 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	init_stack(stack);
	to_stack(stack, unique, count);
	if (!stack->top)
		return (free_stack(stack), NULL);
	return (stack);
}

// void	print_stack(t_stack *stack)
// {
// 	t_node	*current;

// 	current = stack->top;
// 	printf("Stack contents (top to bottom):\n");
// 	while (current)
// 	{
// 		printf("%d\n", current->value);
// 		current = current->prev;
// 	}
// }

// void	run_test(int argc, char **argv)
// {
// 	t_stack	*stack;

// 	stack = in_val(argc, argv);
// 	if (!stack)
// 	{
// 		printf("Error: Invalid input\n");
// 		return;
// 	}
// 	print_stack(stack);
// 	free_stack(stack);
// }

// int	main(void)
// {
// 	char	*test1[] = {"program", "10", "20", "30"};
// 	char	*test2[] = {"program", "10", "20", "abc"};
// 	char	*test3[] = {"program", "2147483647", "-2147483648"};
// 	char	*test4[] = {"program", "10", "20", "10"}; // Duplicate test
// 	char	*test5[] = {"program", "42"};
// 	char	*test6[] = {"program", "2147483648"}; // Overflow test

// 	printf("Running Test 1:\n");
// 	run_test(4, test1);
// 	printf("\nRunning Test 2:\n");
// 	run_test(4, test2);
// 	printf("\nRunning Test 3:\n");
// 	run_test(3, test3);
// 	printf("\nRunning Test 4:\n");
// 	run_test(4, test4);
// 	printf("\nRunning Test 5:\n");
// 	run_test(2, test5);
// 	printf("\nRunning Test 6:\n");
// 	run_test(2, test6);

// 	return (0);
// }