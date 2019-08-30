#include "../includes/ft_ls.h"

// void ft_continue()
// {
// 	size_t count;
// 	count = 0;
// 	t_ls *file;
// 	int b;
// 	b = 0;
// 	file = NULL;
// 	while (argv[i + count] != NULL)
// 		count++;
// 	if (count != 0)
// 	{
// 		while (i < argc)
// 		{
// 			b = ft_isdir(argv[i], &er, &ret);
// 			if (b == 1)
// 			{
// 				if (*dir == NULL)
// 					*dir = ft_ls_lstnew(NULL, argv[i], NULL);
// 				else
// 					ft_ls_lstadd(dir, ft_ls_lstnew(NULL, argv[i], NULL));
// 			}
// 			else if (b == 2)
// 			{
// 				if (file == NULL)
// 					file = ft_ls_lstnew(NULL, NULL, argv[i]);
// 				else
// 					ft_ls_lstadd(&file, ft_ls_lstnew(NULL, NULL, argv[i]));
// 			}
// 			i++;
// 		}
// 	}
// }

int		ft_argv_err(char **argv, int *i, t_ls **er, int *ret)
{
			if (argv[*i][1] == '\0')//function
				ft_isdir(argv[*i], er, ret);
			if (argv[*i][2] != '\0')
			{
				ft_putstr("ft_ls: illegal option -- -\n");
				ft_putstr("usage: ls [-Ralrt] [file ...]\n");
				return -1;
			}
			i++;
			return (0);
}
int ft_argv_analize(char **argv, char *flags, t_ls **dir, int argc)
{
	int i;
	t_ls *er;
	int ret;

	ret = 0;
	er = NULL;
	i = 1;
	while (argv[i] && *argv[i] == '-')
	{
		if (argv[i][1] == '\0' || argv[i][1] == '-')
		{
			if(ft_argv_err(argv, &i, &er, &ret) == -1)
				return -1;
			break ;
		}
		ft_ls_mkflags(argv[i], flags);
		i++;
	}
	// ft_continue();
	size_t count;
	t_ls *file;
	int b;
	
	b = 0;
	file = NULL;
	count = 0;
	while (argv[i + count] != NULL)
		count++;
	if (count != 0)
	{
		while (i < argc)
		{
			b = ft_isdir(argv[i], &er, &ret);
			if (b == 1)
			{
				if (*dir == NULL)
					*dir = ft_ls_lstnew(NULL, argv[i], NULL);
				else
					ft_ls_lstadd(dir, ft_ls_lstnew(NULL, argv[i], NULL));
			}
			else if (b == 2)
			{
				if (file == NULL)
					file = ft_ls_lstnew(NULL, NULL, argv[i]);
				else
					ft_ls_lstadd(&file, ft_ls_lstnew(NULL, NULL, argv[i]));
			}
			i++;
		}
	}
	if (er != NULL)
		ft_print_err(&er, flags);
	if (*dir == NULL && file == NULL && count == 0)
		*dir = ft_ls_lstnew(NULL, ".", NULL);
	if (file != NULL)
		ft_printfiles(&file, flags);
	return ret;
}