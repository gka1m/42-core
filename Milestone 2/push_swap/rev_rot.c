/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:41:57 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/23 11:39:51 by kagoh            ###   ########.fr       */
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
