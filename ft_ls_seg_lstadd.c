#include "ft_ls.h"

void ft_ls_seg_lstadd(t_ls **head, t_ls **seg, char *dir)
{
	t_ls *tmp;
	t_ls *ptr;

	tmp = *seg;
	ptr = *head;
	while (ptr != NULL && ft_strcmp(ptr->directory, dir) != 0)
	{
		if (ptr->next != NULL)
			ptr = ptr->next;
		else
			break;
	}
	if (ft_strcmp(ptr->directory, dir) == 0)
	{
		tmp = ptr->next;
		ptr->next = *seg;
		(*seg)->prev = ptr;
		while (ptr->next != NULL)
			(ptr) = (ptr)->next;
		if (tmp != NULL)
			tmp->prev = ptr;
		ptr->next = tmp;
	}
}