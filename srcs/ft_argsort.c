#include "../includes/ft_ls.h"

void	ft_argsort(t_ls **dir, char *flags)
{
	t_ls	*ptr;
	int		i;
	char	*tp;

	ptr = *dir;
	i = 1;
	if (flags[5] == '1')
		i = -1;
	while (ptr->next != NULL)
	{
		if ((i * ft_strcmp(ptr->directory, ptr->next->directory)) > 0)
		{
			tp = ptr->directory;
			ptr->directory = ptr->next->directory;
			ptr->next->directory = tp;
			ptr = *dir;
		}
		else
			ptr = ptr->next;
	}
	if (flags[4] == '1')
		ft_sortarg_time(dir, flags);
}