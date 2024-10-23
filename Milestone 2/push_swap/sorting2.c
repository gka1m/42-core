/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:36:55 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/23 11:38:59 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (check_sorted(a) == 1)
		return ;
	else
	{
		if (a->size <= 5)
			simple_sort(a, b);
		else
			radix_sort(a, b);
	}
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
}

void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->bottom->value;
	if (top > mid && mid > bot)
	{
		ra(a);
		sa(a);
	}
	else if (top > bot && bot > mid)
		ra(a);
	else if (mid > top && top < bot)
	{
		rra(a);
		sa(a);
	}
	else if (mid > bot && bot > top)
		sa(a);
	else if (bot > top && top > mid)
		sa(a);
	else if (mid > top && top > bot)
		rra(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*smallest;
	int		i;

	if (a->size == 0)
		return ;
	current = a->top;
	smallest = current;
	i = 0;
	while (i < a->size)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
		i++;
	}
	while (a->top->value != smallest->value)
		ra(a);
	pb(a, b);
	if (!check_sorted(a))
		sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*smallest;
	int		i;

	if (a->size == 0)
		return ;
	i = 0;
	current = a->top;
	smallest = current;
	while (i < a->size)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
		i++;
	}
	while (a->top->value != smallest->value)
		ra(a);
	pb(a, b);
	if (!check_sorted(a))
		sort_4(a, b);
	pa(a, b);
}
