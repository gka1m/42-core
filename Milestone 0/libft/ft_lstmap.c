/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:46:26 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/28 21:02:40 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new_node;
	void	*wtf;

	result = NULL;
	if (lst == NULL || f == NULL)
	{
		return (NULL);
	}
	while (lst != NULL)
	{
		wtf = f(lst -> content);
		new_node = ft_lstnew(wtf);
		if (new_node == NULL)
		{
			ft_lstclear(&result, del);
			del(wtf);
			return (NULL);
		}
		ft_lstadd_back(&result, new_node);
		lst = lst -> next;
	}
	return (result);
}
