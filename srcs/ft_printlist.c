#include "../includes/ft_ls.h"

void ft_printlist(t_ls **tmp, char *flags)
{
	t_ls *tmp1;

	if (flags[7] == '1')
		ft_ls_l(tmp);
	else
	{
		while (*tmp)
		{
			// write(1, (*tmp)->directory, ft_strlen((*tmp)->directory));
			ft_putstr((*tmp)->name);
			ft_putchar('\n');
			free((*tmp)->name);
			free((*tmp)->directory);
			tmp1 = *tmp;
			*tmp = (*tmp)->next;
			free(tmp1);
		}
		printf("\n");
	}
}