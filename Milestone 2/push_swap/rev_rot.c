/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:41:57 by kagoh             #+#    #+#             */
/*   Updated: 2024/09/28 16:45:23 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rot(t_stack *stack)
{
    t_node *last;
    t_node *sec_last;

    if (stack->size < 2)
        return;
    last = stack->bottom;
    sec_last = last->prev;
    sec_last->next = NULL;
    stack->bottom = sec_last;
    last->next = stack->top;
    stack->top->prev = last;
    last->prev = NULL;
    stack->top = last;
}

void rra(t_stack *a)
{
    rev_rot(a);
}

void rrb(t_stack *b)
{
    rev_rot(b);
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}
