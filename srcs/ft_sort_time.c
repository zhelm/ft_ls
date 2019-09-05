/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:40:29 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 08:40:35 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_sort_time_c(char *tp, char *tmpname, t_ls **ptr, t_ls **head)
{
	tp = (*ptr)->directory;
	tmpname = (*ptr)->name;
	(*ptr)->directory = (*ptr)->next->directory;
	(*ptr)->name = (*ptr)->next->name;
	(*ptr)->next->directory = tp;
	(*ptr)->next->name = tmpname;
	*ptr = *head;
}

void	ft_sort_time(t_ls **head, int i)
{
	struct stat sb;
	struct stat sb1;
	char		*tmpname;
	t_ls		*ptr;
	char		*tp;

	ptr = *head;
	while (ptr->next != NULL)
	{
		stat(ptr->directory, &sb);
		stat(ptr->next->directory, &sb1);
		if (((i * (sb.st_mtime - sb1.st_mtime)) < 0) ||
		((sb.st_mtime - sb1.st_mtime) == 0 &&
		(i * (int)(sb.st_mtimespec.tv_nsec
		- sb1.st_mtimespec.tv_nsec)) < 0))
			ft_sort_time_c(tp, tmpname, &ptr, head);
		else
			ptr = ptr->next;
	}
}
