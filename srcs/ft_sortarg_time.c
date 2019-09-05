/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarg_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:57:59 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 08:58:00 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_sortarg_time(t_ls **head, char *flags)
{
	struct stat sb;
	struct stat sb1;
	t_ls		*ptr;
	int			i;
	char		*tp;

	ptr = *head;
	i = (flags[5] == '1') ? 1 : -1;
	while (ptr->next != NULL)
	{
		stat(ptr->directory, &sb);
		stat(ptr->next->directory, &sb1);
		if (((i * ((int)sb.st_mtime - (int)sb1.st_mtime)) > 0) ||
		(((i * ((int)sb.st_mtime - (int)sb1.st_mtime) == 0 &&
		(i * ((int)sb.st_mtim.tv_nsec -
		(int)sb1.st_mtim.tv_nsec)) > 0))))
		{
			tp = ptr->directory;
			ptr->directory = ptr->next->directory;
			ptr->next->directory = tp;
			ptr = *head;
		}
		else
			ptr = ptr->next;
	}
}
