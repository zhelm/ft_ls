/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_free_tmplist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:53:44 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 08:53:46 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ls_free_tmplist(t_ls **head)
{
	if ((*head)->directory != NULL)
		ft_strdel(&(*head)->directory);
	(*head)->next = NULL;
	if ((*head)->name != NULL)
		ft_strdel(&(*head)->name);
	(*head)->name = NULL;
	if ((*head)->next == NULL)
		free(*head);
}
