/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_analize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:17:57 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 09:18:06 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_b(t_ls **file, char *argv, t_ls **dir, int i)
{
	if (i != 0)
	{
		if (*file == NULL && i == 2)
			*file = ft_ls_lstnew(NULL, NULL, argv);
		else if (i == 2)
			ft_ls_lstadd(file, ft_ls_lstnew(NULL, NULL, argv));
		if (*dir == NULL && i == 1)
			*dir = ft_ls_lstnew(NULL, argv, NULL);
		else if (i == 1)
			ft_ls_lstadd(dir, ft_ls_lstnew(NULL, argv, NULL));
	}
}

static int		ft_continue(char **argv, t_ls **er, t_ls **dir, t_argv *args)
{
	size_t	count;
	t_ls	*file;

	count = 0;
	file = NULL;
	while (argv[*(args->i) + count] != NULL)
		count++;
	if (count != 0)
	{
		while (*(args->i) < *(args->argc))
		{
			ft_b(&file, argv[*(args->i)], dir,
			ft_isdir(argv[*(args->i)], er, (args->ret), (args->flags)));
			*(args->i) = *(args->i) + 1;
		}
	}
	if (*dir == NULL && file == NULL && count == 0 && errno == 0)
		*dir = ft_ls_lstnew(NULL, ".", NULL);
	if (file != NULL)
		return (ft_printfiles(&file, (args->flags), dir));
	return (count > 1) ? 1 : 0;
}

int				ft_argv_err(char **argv, int *i, t_ls **er, int *ret)
{
	if (argv[*i][1] == '\0')
		ft_isdir(argv[*i], er, ret, NULL);
	if (argv[*i][2] != '\0' && ft_strcmp("-", argv[*i]) != 0)
	{
		ft_putstr("ft_ls: illegal option -- -\n");
		ft_putstr("usage: ls [-ARafglnort] [file ...]\n");
		return (-1);
	}
	i++;
	return (0);
}

int				ft_argv_analize(char **argv, char *flags, t_ls **dir, int argc)
{
	int		i;
	t_ls	*er;
	int		ret;
	t_argv	args;

	ret = 0;
	er = NULL;
	i = 1;
	while (argv[i] && *argv[i] == '-')
	{
		if (argv[i][1] == '\0' || argv[i][1] == '-')
		{
			if (ft_argv_err(argv, &i, &er, &ret) == -1)
				return (-1);
			i++;
			break ;
		}
		ft_ls_mkflags(argv[i], flags);
		i++;
	}
	args.ret = &ret;
	args.i = &i;
	args.argc = &argc;
	args.flags = flags;
	return (ft_continue(argv, &er, dir, &args));
}
