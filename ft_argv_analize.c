#include "ft_ls.h"

void ft_argv_analize(char **argv, char *flags, t_ls **dir)
{
	size_t i;
	size_t count;

	count = 0;
	i = 1;
	while (argv[i] && *argv[i] == '-')
	{
		ft_ls_mkflags(argv[i], flags);		
		if (argv[i][1] == '\0')
			exit(EXIT_FAILURE);
		i++;
	}
	while (argv[i + count] != NULL && *argv[i + count] != '-')
		count++;
	if (count != 0)
	{
		while (argv[i] != NULL)
		{
			if (*dir == NULL)
				*dir = ft_ls_lstnew(NULL, argv[i]);
			else
				ft_ls_lstadd(dir, ft_ls_lstnew(NULL, argv[i]));
			i++;
		}
	}
}