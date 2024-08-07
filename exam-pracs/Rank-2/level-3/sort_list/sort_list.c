#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *tmp = lst;
	int temp_hold;

	while (lst -> next != NULL)
	{
		if ((*cmp)(lst -> data, lst -> next -> data) == 0)
		{
			temp_hold = lst -> data;
			lst -> data = lst -> next -> data;
			lst -> next -> data = temp_hold;
			lst = tmp;
		}
		else
			lst = lst -> next;
	}
	lst = tmp;
	return (lst);
}