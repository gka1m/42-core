/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:30:16 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/23 15:55:26 by kagoh            ###   ########.fr       */
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
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	a = initialize(ac, av);
	if (!a)
		return (1);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (free_stack(a), 1);
	init_stack(b);
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
