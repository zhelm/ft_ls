#include "../includes/ft_ls.h"

int		ft_dorec(t_ls **head, char *flags, char *dir)
{
	t_ls *tmp;
	if ((*head) != NULL)
	{
		while (*head)
		{
			if ((*head) && ft_strcmp((*head)->directory, dir) == 0)
			{
				printf("\n");
				tmp = *head;
				free((*head)->name);
				(*head)->name = NULL;
				free((*head)->directory);
				(*head)->directory = NULL;
				*head = (*head)->next;
				free(tmp);
				break;
			}
			(*head) = (*head)->next;
		}
		if (flags[3] == '1' && (*head) != NULL)
			return 1;
	}
	return 0;
}