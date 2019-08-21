#include "../includes/ft_ls.h"


void ft_ls_lstadd(t_ls **alst, t_ls *new)
{
	t_ls *ptr;

	ptr = *alst;
	if(alst)
	{
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
		new->next = NULL;
	}
}