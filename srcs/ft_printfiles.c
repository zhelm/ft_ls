/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:01:58 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 09:02:00 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_printfiles(t_ls **file, char *flags, t_ls **dir)
{
	ft_listsort(file, flags);
	ft_printlist(file, flags);
	if(*dir != NULL)
		ft_putchar('\n');
	return (1);
	// ft_putchar('\n');
}
