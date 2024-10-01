/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:39 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/01 17:06:44 by kagoh            ###   ########.fr       */
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

