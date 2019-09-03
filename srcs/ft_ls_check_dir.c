/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_check_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:59:56 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 08:59:57 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_ls_check_dir(char **argv)
{
	size_t	i;
	DIR		*dr;

	i = 1;
	while (argv[i] && *argv[i] == '-' && argv[i][1] != '\0')
		i++;
	while (argv[i])
	{
		dr = opendir(argv[i]);
		if (dr == NULL)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(argv[i]);
			ft_putstr(": ");
			perror("");
			return (0);
		}
		else
			closedir(dr);
		i++;
	}
	return (1);
}
