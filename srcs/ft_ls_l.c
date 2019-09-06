/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:26:27 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 11:26:29 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_ls_l_analize_c(struct stat *sb, t_ls_l *ret, char *flags)
{
	struct group	*grp;
	struct passwd	*usr;

	if (((usr = getpwuid(sb->st_uid)) && ft_strlen(usr->pw_name) >
	(*ret).usrnm) && flags[0] != '1')
		(*ret).usrnm = ft_strlen(usr->pw_name);
	else if ((ft_size_t_len(sb->st_uid) > (*ret).usrnm) || flags[0] == '1')
		(*ret).usrnm = ft_size_t_len(sb->st_uid);
	if (((grp = getgrgid(sb->st_gid)) && ft_strlen(grp->gr_name) >
	(*ret).grpnm) && flags[0] != '1')
		(*ret).grpnm = ft_strlen(grp->gr_name);
	else if ((ft_size_t_len(sb->st_gid) > (*ret).grpnm) && flags[0] == '1')
		(*ret).grpnm = ft_size_t_len(sb->st_gid);
	if (ft_size_t_len(sb->st_nlink) > (*ret).links)
		(*ret).links = ft_size_t_len(sb->st_nlink);
	if (ft_size_t_len((sb->st_size)) > (*ret).size)
		(*ret).size = ft_size_t_len(sb->st_size);
}

void			ft_total(t_ls **head, long long sz, struct stat sb)
{
	if (lstat((*head)->directory, &sb) != -1)
	{
		ft_putstr("total ");
		ft_putnbr((int)sz);
		ft_putchar('\n');
	}
}

void			ft_ls_l(t_ls **head, char *flags)
{
	t_ls		*tmp;
	struct stat	sb;
	long long	sz;
	t_ls_l		vals;

	sz = 0;
	tmp = NULL;
	vals = ft_ls_l_analize(head, tmp);
	tmp = *head;
	if (tmp != NULL && (!(tmp->directory == NULL
	&& tmp->name != NULL) || tmp->name != NULL))
	{
		while (tmp != NULL)
		{
			if (lstat(tmp->directory, &sb) == -1 && lstat(tmp->name, &sb) == -1)
				return ;
			ft_ls_l_analize_c(&sb, &vals, flags);
			sz = sz + sb.st_blocks;
			tmp = tmp->next;
		}
		ft_total(head, sz, sb);
	}
	ft_ls_print_l(head, flags, &vals);
}
