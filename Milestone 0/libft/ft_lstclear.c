/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:36:54 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/28 20:25:47 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
	{
		return ;
	}
	current = *lst;
	while (current != NULL)
	{
		next = current -> next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
