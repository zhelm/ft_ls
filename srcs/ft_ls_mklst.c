/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_mklst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:33:27 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 11:33:29 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ls_tmp(char *flags, struct dirent *de, t_ls **tmp, char *dir)
{
	if (!(flags[6] == '0' && *de->d_name == '.') && *tmp == NULL && de != NULL)
		*tmp = ft_ls_lstnew(de, NULL, NULL);
	else if (!(flags[6] == '0' && *de->d_name == '.') && de != NULL)
		ft_ls_lstadd(tmp, ft_ls_lstnew(de, NULL, NULL));
	if (!(flags[6] == '0' && *de->d_name == '.') && de)
		ft_assign_dir(tmp, dir);
}

void	ft_ls_seg(struct dirent *de, t_ls **segment, char *dir)
{
	if (*segment == NULL)
		*segment = ft_ls_lstnew(de, NULL, de->d_name);
	else
		ft_ls_lstadd(segment, ft_ls_lstnew(de, NULL, de->d_name));
	if (de != NULL)
		ft_assign_dir(segment, dir);
}

void	ft_ls_mklst(t_ls **segment, t_ls **tmp, char *flags, char *dir)
{
	struct stat		sb;
	struct dirent	*de;
	DIR				*dr;

	if (lstat(dir, &sb) != -1 && (((sb.st_mode & S_IRUSR) &&
	(sb.st_mode & S_IXUSR)) || flags[7] != '1') && (dr = opendir(dir)))
	{
		if (dr != NULL)
		{
			while ((de = readdir(dr)) != NULL)
			{
				ft_ls_tmp(flags, de, tmp, dir);
				if (de->d_type == 4 && flags[3] == '1' && !(flags[6] == '0' &&
				*de->d_name == '.') && strcmp(de->d_name, ".") != 0 &&
				ft_strcmp(de->d_name, "..") != 0)
					ft_ls_seg(de, segment, dir);
			}
			closedir(dr);
		}
	}
	else
		ft_isdir_rec(dir);
}
