/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:35:05 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 11:35:07 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_err(t_ls **er, char *flags)
{
	ft_listsort(er, flags);
	while (*er)
	{
		ft_putstr("ft_ls: ");
		ft_putstr((*er)->name);
		ft_putstr(": ");
		perror("");
		ft_strdel(&(*er)->name);
		free(*er);
		(*er) = (*er)->next;
	}
}
