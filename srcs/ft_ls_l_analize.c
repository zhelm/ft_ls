/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l_analize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:55:56 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 08:55:58 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_ls_l_analize_c(t_ls **tmp, t_ls_l *ret, char *flags)
{
	struct stat		sb;
	struct group	*grp;
	struct passwd	*usr;

	if ((*tmp)->directory)
		if(lstat((*tmp)->directory, &sb) == -1)
			lstat((*tmp)->name, &sb);
	if (((usr = getpwuid(sb.st_uid)) && ft_strlen(usr->pw_name) >
	(*ret).usrnm) && flags[0] != '1')
		(*ret).usrnm = ft_strlen(usr->pw_name);
	else if ((ft_size_t_len(sb.st_uid) > (*ret).usrnm) || flags[0] == '1')
		(*ret).usrnm = ft_size_t_len(sb.st_uid);
	if (((grp = getgrgid(sb.st_gid)) && ft_strlen(grp->gr_name) >
	(*ret).grpnm) && flags[0] != '1')
		(*ret).grpnm = ft_strlen(grp->gr_name);
	else if ((ft_size_t_len(sb.st_gid) > (*ret).grpnm) && flags[0] == '1')
		(*ret).grpnm = ft_size_t_len(sb.st_gid);
	if (ft_size_t_len(sb.st_nlink) > (*ret).links)
		(*ret).links = ft_size_t_len(sb.st_nlink);
	if (ft_size_t_len((sb.st_size)) > (*ret).size)
		(*ret).size = ft_size_t_len(sb.st_size);
	*tmp = (*tmp)->next;
}

t_ls_l			ft_ls_l_analize(t_ls **head, t_ls *tmp, char *flags)
{
	t_ls_l ret;

	tmp = *head;
	ret.grpnm = 0;
	ret.links = 0;
	ret.size = 0;
	ret.usrnm = 0;
	while (tmp != NULL)
		ft_ls_l_analize_c(&tmp, &ret, flags);
	return (ret);
}
