#include "../includes/ft_ls.h"

void ft_assign_dir(t_ls **head, char *dir)
{
	char *dirtmp1;
	t_ls *ptr;
	if(ft_strcmp(dir, "/") != 0)
		dirtmp1 = ft_strjoin(dir, "/");
	else
		dirtmp1 = ft_strdup("/");
	ptr = *head;
	while (ptr)
	{
		if (ptr->next != NULL)
			ptr = ptr->next;
		else
			break;
	}
	ptr->directory = ft_strjoin(dirtmp1, ptr->name);
	ft_strdel(&dirtmp1);
}