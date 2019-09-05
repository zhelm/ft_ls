/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:33:45 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 11:33:58 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_isdir(char *argv, t_ls **er, int *ret, char *flags)
{
	struct stat sb;
	DIR			*dr;

	lstat(argv, &sb);
	if (S_ISREG(sb.st_mode))
	{
		if (*ret == 0)
			*ret = 1;
		return (2);
	}
	else
	{
		dr = opendir(argv);
		if (dr == 0)
		{
			if (*ret == 0)
				*ret = 1;
			ft_erlst(er, argv);
			ft_print_err(er, flags);
			return (0);
		}
		closedir(dr);
		*ret = 1;
		return (1);
	}
}
