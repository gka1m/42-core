/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:06:29 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/23 11:39:42 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push(t_stack *src, t_stack *dest)
{
	t_node	*src_top;

	if (src->size == 0)
		return ;
	src_top = src->top;
	src->top = src_top->next;
	if (src->top == NULL)
		src->bottom = NULL;
	src_top->next = dest->top;
	dest->top = src_top;
	if (dest->size == 0)
		dest->bottom = src_top;
	src->size--;
	dest->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL)
		return ;
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL)
		return ;
	push(a, b);
	ft_printf("pb\n");
}
