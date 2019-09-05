/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listrec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:57:48 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 08:57:51 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_listdet(t_ls **seg)
{
	struct stat sb;

	lstat((*seg)->directory, &sb);
	if(S_IRUSR & sb.st_mode)
	{
		ft_putchar('\n');
		ft_putstr((*seg)->directory);
		ft_putstr(":\n");
		return (1);
	}
	return (-1);
}

t_ls	*ft_listrec(char **dir, char *flags)
{
	t_ls *segment;
	t_ls *tmp;

	segment = NULL;
	tmp = NULL;
	ft_ls_mklst(&segment, &tmp, flags, *dir);
	if (tmp && tmp->next != NULL && flags[10] != '1')
		ft_listsort(&tmp, flags);
	ft_printlist(&tmp, flags);
	if (segment != NULL && flags[10] != '1')
		ft_listsort(&segment, flags);
	while (segment)
	{
		tmp = segment;
		if (ft_listdet(&segment) == 1)
			ft_listrec(&segment->directory, flags);
		free(tmp->directory);
		free(tmp->name);
		segment = segment->next;
		free(tmp);
	}
	return (0);
}
