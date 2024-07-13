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

void sa(t_stack *a)
{
    int temp;

    if (a->size < 2)
        return;
    temp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = temp;
}

void sb(t_stack *b)
{
    int temp;

    if (b->size < 2)
        return;
    temp = b->top->value;
    b->top->value = b->top->next->value;
    b->top->next->value = temp;
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}