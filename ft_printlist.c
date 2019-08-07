#include "ft_ls.h"

void ft_printlist(t_ls **tmp, char *flags)
{
	t_ls *ptr;
	// printf("ok")
	ptr = *tmp;
	if (flags[7] == '1')
		ft_ls_l(tmp);
	else
	{
		while (ptr)
		{
			printf("%s   \t", ptr->name);
			ptr = ptr->next;
		}
		printf("\n\n");
	}
}