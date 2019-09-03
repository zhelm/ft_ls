/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir_rec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:02:16 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 09:02:17 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_isdir_rec(char *dir)
{
	DIR *dr;

	if (!(dr = opendir(dir)))
	{
		ft_putstr("ft_ls: ");
		ft_putstr(dir);
		ft_putstr(": ");
		perror("");
	}
	else
		closedir(dr);
}
