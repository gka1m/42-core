/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:21:12 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/28 16:41:48 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (stack->size < 2)
        return;
    first = stack->top;
    second = first->next;
    stack->top = second;
    second->prev = NULL;
    first->next = NULL;
    first->prev = stack->bottom;
    stack->bottom->next = first;
    stack->bottom = first;
}

void ra(t_stack *a)
{
    rotate(a);
}

void rb(t_stack *b)
{
    rotate(b);
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
