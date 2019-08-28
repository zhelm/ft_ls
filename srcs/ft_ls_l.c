#include "../includes/ft_ls.h"

void ft_ls_l(t_ls **head, char *flags)
{
	t_ls *tmp;
	struct stat sb;
	long long sz;

	sz = 0;
	tmp = *head;
	if (tmp != NULL && !(tmp->directory == NULL && tmp->name != NULL))
	{
		while (tmp != NULL)
		{
			if(lstat(tmp->directory, &sb) == -1)
			{
				return ;
			}
			sz = sz + sb.st_blocks;
			tmp = tmp->next;
		}
		printf("total %lld\n", sz);
	}
	ft_ls_print_l(head, flags);
}