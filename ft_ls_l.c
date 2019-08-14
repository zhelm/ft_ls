#include "ft_ls.h"

void ft_ls_l(t_ls **head)
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
			lstat(tmp->directory, &sb);
			sz = sz + sb.st_blocks;
			tmp = tmp->next;
		}
		printf("total %lld\n", sz);
	}
	ft_ls_print_l(head, sb);	
}