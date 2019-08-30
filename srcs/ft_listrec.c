#include "../includes/ft_ls.h"

t_ls	*ft_listrec(char *dir, char *flags)
{
	t_ls *segment;
	t_ls *tmp;

	segment = NULL;
	tmp = NULL;
	ft_ls_mklst(&segment, &tmp, flags, dir);
	if (tmp && tmp->next != NULL && flags[10] != '1')
		ft_listsort(&tmp, flags);
	ft_printlist(&tmp, flags);
	if (segment != NULL && flags[10] != '1')
		ft_listsort(&segment, flags);
	while (segment != NULL)
	{
		ft_putchar('\n');
		ft_putstr(segment->directory);
		ft_putstr(":\n");
		tmp = segment;
		ft_listrec(segment->directory, flags);
		free(tmp->directory);
		free(tmp->name);
		free(tmp);
		segment = segment->next;
	}
	return (0);
}
