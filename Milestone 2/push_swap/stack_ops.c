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
        ft_printf("Memory allocation failure.\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(t_stack *stack)
{
    int value;
    t_node *temp;

    if (stack->top == NULL)
    {
        ft_printf("Error: Stack underflow.\n");
        return (-1);
    }
    value = stack->top->value;
    temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
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
    t_node *last;

    if (stack->top == NULL || stack->top->next == NULL)
        return;
    first = stack->top;
    stack->top = stack->top->next;
    last = stack->top->next;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
}

void rev_rotate(t_stack *stack)
{
    t_node *second_last;
    t_node *last;

    if (stack->top == NULL || stack->top->next == NULL)
        return;
    second_last = NULL;
    last = stack->top;
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    last->next = stack->top;
    stack->top = last;
    second_last->next = NULL;
}