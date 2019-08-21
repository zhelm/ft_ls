#include "../includes/ft_ls.h"

void ft_dorec(t_ls **head, char *flags, char *dir)
{
	t_ls *ptr;
	t_ls *tmp;
	ptr = *head;
	if ((*head) != NULL)
	{
		ptr = *head;
		while (ptr)
		{
			if (ptr && ft_strcmp(ptr->directory, dir) == 0)
			{
				printf("\n");
				tmp = ptr;
				free(ptr->name);
				ptr->name = NULL;
				free(ptr->directory);
				ptr->directory = NULL;
				ptr = ptr->next;
				break;
			}
			ptr = ptr->next;
		}
		if (flags[3] == '1' && ptr != NULL)
		{
			// printf("\n");
			ft_listrec(&ptr, ptr->directory, flags);
		}
	}
}