/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:06:29 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/13 22:06:29 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack *src, t_stack *dest)
{
    t_node *src_top;

    if (src->size == 0)
        return;
    src_top = src->top;
    src->top = src_top->next;
    if (src->top)
        src->top->prev = NULL;
    else
        src->bottom = NULL;
    src_top->next = dest->top;
    if (dest->top)
        dest->top->prev = src_top;
    src_top->prev = NULL;
    dest->top = src_top;
    if (dest->size == 0)
        dest->bottom = src_top;
    src->size--;
    dest->size++;
}

void pa(t_stack *a, t_stack *b)
{
    push(b, a);
}

void pb(t_stack *a, t_stack *b)
{
    push(a, b);
}
