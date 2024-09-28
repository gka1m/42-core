/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:59:26 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/13 21:59:26 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* handles sa, sb and ss operations */

void swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (stack->size < 2)
        return;
    first = stack->top;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    stack->top = second;
    if (stack->size == 2)
        stack->bottom = first;
}

void sa(t_stack *a)
{
    swap(a);
}

void sb(t_stack *b)
{
    swap(b);
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}