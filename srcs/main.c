/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:52:22 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/24 07:48:51 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//./ft_ls testdir permision denied


#include "../includes/ft_ls.h"
//maybe -m, make sure about g and capital G
int main(int argc, char **argv)
{
	t_ls *dir;
	char *flags;
	t_ls *tmp;
	int i;

	flags = NULL;
	dir = NULL;
	if(argc >= 1)
	{
		if((flags = ft_ls_checkflags(argv)) == NULL)
			return 0;
	}
	i = ft_argv_analize(argv, flags, &dir, argc);
	if(dir != NULL)
		ft_argsort(&dir, flags);
	i = 0;
	while (dir != NULL)
	{
		tmp = dir;
		if(i != 0 && dir != NULL)
		{
			ft_putstr(dir->directory);
			ft_putchar(':');
			ft_putstr("\n");
		}
		ft_listrec(dir->directory, flags);
		dir = dir->next;
		free(tmp);
		i++;
		if(dir != NULL)
			ft_putchar('\n');
	}
	sleep(30);
}