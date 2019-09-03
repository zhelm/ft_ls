/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:58:02 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 08:58:04 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_ls_print_lc(t_ls *tmp, t_ls_l vals, char *flags)
{
	struct stat sb;

	if (tmp->directory)
		lstat(tmp->directory, &sb);
	else
		lstat(tmp->name, &sb);
	ft_ls_check_file_type(sb);
	ft_ls_mode(sb, tmp);
	ft_ls_print_lsub(&tmp, sb, vals, flags);
	ft_putchar('\n');
}

void		ft_ls_print_l(t_ls **head, char *flags)
{
	t_ls	*tmp;
	t_ls	*tmp1;
	t_ls_l	vals;

	tmp = NULL;
	if (*head)
		vals = ft_ls_l_analize(head, tmp, flags);
	tmp = *head;
	while (tmp != NULL)
	{
		tmp1 = tmp;
		if (!(flags[1] == '1' && (ft_strcmp((tmp)->name, ".") == 0 ||
		ft_strcmp((tmp)->name, "..") == 0)) ||
			flags[1] == '0')
			ft_ls_print_lc(tmp, vals, flags);
		tmp = tmp->next;
		if (tmp1 != NULL)
			ft_ls_free_tmplist(&tmp1);
	}
}
