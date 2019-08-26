#include "../includes/ft_ls.h"

void ft_printlist(t_ls **tmp, char *flags)
{
	t_ls *tmp1;

	if (flags[7] == '1')
		ft_ls_l(tmp, flags);
	else
	{
		while (*tmp)
		{
			if (!(flags[1] == '1' && (ft_strcmp((*tmp)->name, ".") == 0 || ft_strcmp((*tmp)->name, "..") == 0)) || flags[1] == '0')
			{
				if (flags[8] == '1')
					ft_putchar('"');
				ft_putstr((*tmp)->name);
				if (flags[8] == '1')
					ft_putchar('"');
				ft_putchar('\n');
			}
			free((*tmp)->name);
			free((*tmp)->directory);
			tmp1 = *tmp;
			*tmp = (*tmp)->next;
			free(tmp1);
		}
		printf("\n");
	}
}