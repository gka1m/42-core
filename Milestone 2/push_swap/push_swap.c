/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:30:16 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/15 12:17:42 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL)
		return ;
	current = stack->top;
	if (current == NULL)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->prev;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		uniq_nums[argc - 1];
	int		count;

	count = validate_input(argc, argv, uniq_nums);
	if (count == 0)
		return (ft_printf("Error: Invalid input\n"), 1);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (ft_printf("Error: Stack allocation failed\n"), 1);
	init_stack(a);
	init_stack(b);
	to_stack(a, uniq_nums, count);
	ft_printf("Original Stack A:\n");
	print_stack(a);
	sort_stack(a, b);
	ft_printf("Sorted Stack A:\n");
	print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
