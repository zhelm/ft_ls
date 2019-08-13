#include "ft_ls.h"

void ft_argv_analize(char **argv, char *flags, t_ls **dir, int argc)
{
	size_t i;
	size_t count;

	count = 0;
	i = 1;
	while (argv[i] && *argv[i] == '-')
	{
		if (argv[i][1] == '\0' || argv[i][1] == '-')
		{
			i++;
			break;
		}
		ft_ls_mkflags(argv[i], flags);
		i++;
	}
	t_ls *file;
	t_ls *tmp;

	file = NULL;
	tmp = file;
	while (argv[i + count] != NULL)
		count++;
	if (count != 0) //sumting
	{
		while (i < argc)
		{
			if (ft_isdir(argv[i], flags) == 1)
			{
				if (*dir == NULL)
					*dir = ft_ls_lstnew(NULL, argv[i], NULL);
				else
					ft_ls_lstadd(dir, ft_ls_lstnew(NULL, argv[i], NULL));
			}
			else
			{
				if (file == NULL)
					file = ft_ls_lstnew(NULL, argv[i], argv[i]);
				else
					ft_ls_lstadd(&file, ft_ls_lstnew(NULL, argv[i], argv[i]));
			}
			i++;
		}
		// size_t t = 0;
		// tmp = file;
		// while(tmp)
    	// {
		// 	if(tmp->name)
    	// 		printf("%s\n", (tmp)->name);
    	//     tmp = (tmp)->next;
		// 	t++;
    	// }
		// // if(file != NULL)
		// 	printf("%ld\n", t);
				ft_printfiles(&file, flags);
	}
}