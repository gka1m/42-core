/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:27:57 by kagoh             #+#    #+#             */
/*   Updated: 2024/10/18 14:47:49 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *stack)
{
	int		count;
	t_node	*current;

	count = 0;
	current = stack->top;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
