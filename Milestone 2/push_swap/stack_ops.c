/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:28:18 by kagoh             #+#    #+#             */
/*   Updated: 2024/07/14 14:28:18 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* handles all the basic stack operations: push, pop, swap, rotate, reverse rotate */

#include "push_swap.h"

void push(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
    {
        ft_printf("Memoryt allocation failure.\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = stack->top;
    stack->size++;
}

int pop(t_stack *stack)
{
    int value;
    t_node *temp;

    if (stack->top == NULL)
        return (-1);
    value = stack->top->value;
    temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return (value);
}

void swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (stack->top == NULL || stack->top->next == NULL)
        return;
    first = stack->top;
    second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void rotate(t_stack *stack)
{
    t_node *first;
    t_node *temp;
    if (stack->top == NULL || stack->top->next == NULL)
        return;
    first = stack->top;
    stack->top = stack->top->next;
    temp = stack->top->next;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = first;
    first->next = NULL;
}
