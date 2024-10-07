/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:30:16 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/07 17:43:35 by kagoh            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (ft_printf("Error: No input\n"), 1);
	if (!is_int(ac, av) || !dig_input(ac, av))
		return (ft_printf("Input(s) are invalid\n"), 1);
	a = in_val(ac, av);
	if (!a)
		return (1);
	print_stack(a);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (ft_printf("Memory allocation failed\n"), 1);
	init_stack(b);
	sort_stack(a, b);
	ft_printf("Sorted stack B: \n");
	print_stack(b);
	free_stack(a);
	free_stack(b);
	return (0);
}
