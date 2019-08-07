#include "ft_ls.h"

void ft_dorec(t_ls **head, char *flags, char *dir)
{
	t_ls *ptr;

	ptr = *head;
	if ((*head) != NULL)
	{
		ptr = *head;
		while (ptr)
		{
			if (ptr && ft_strcmp(ptr->directory, dir) == 0)
			{
				ptr = ptr->next;
				break;
			}
			ptr = ptr->next;
		}
		if (flags[3] == '1' && ptr != NULL)
		{
			printf("\n");
			ft_listrec(&ptr, ptr->directory, flags);
		}
	}
}