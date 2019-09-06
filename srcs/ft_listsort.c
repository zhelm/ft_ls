/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:45:08 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 09:45:11 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_listsort(t_ls **head, char *flags)
{
	int i;

	i = 0;
	if (flags)
		i = ((flags[5] == '1') ? 1 : -1);
	ft_mergesort(head, flags, i);
}
