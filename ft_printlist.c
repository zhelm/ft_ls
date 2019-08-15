#include "ft_ls.h"

void ft_printlist(t_ls **tmp, char *flags)
{
	t_ls *ptr;
	t_ls *tmp1;

	ptr = *tmp;
	if (flags[7] == '1')
		ft_ls_l(tmp);
	else
	{
		while (ptr)
		{
			ft_putstr(ptr->name);
			ft_putchar('\n');
			free(ptr->name);
			free(ptr->directory);
			tmp1 = ptr;
			ptr = ptr->next;
			free(tmp1);
		}
		printf("\n\n");
	}
}