/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:53:16 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 08:53:18 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_ls_mode_else(struct stat sb, size_t i)
{
	if (i == 2 && S_ISUID & sb.st_mode)
		ft_putchar('S');
	else if ((sb.st_mode & S_IRGRP) && i == 3)
		ft_putchar('r');
	else if ((sb.st_mode & S_IWGRP) && i == 4)
		ft_putchar('w');
	else if ((sb.st_mode & S_IXGRP) && i == 5)
		(S_ISGID & sb.st_mode) ? ft_putchar('s') : ft_putchar('x');
	else if (i == 5 && S_ISGID & sb.st_mode)
		ft_putchar('S');
	else if ((sb.st_mode & S_IROTH) && i == 6)
		ft_putchar('r');
	else if ((sb.st_mode & S_IWOTH) && i == 7)
		ft_putchar('w');
	else if ((sb.st_mode & S_IXOTH) && i == 8)
		(S_ISVTX & sb.st_mode) ? ft_putchar('t') : ft_putchar('x');
	else if (i == 8 && S_ISVTX & sb.st_mode)
		ft_putchar('T');
	else
		ft_putchar('-');
}

void		ft_ls_mode(struct stat sb, t_ls *tmp)
{
	acl_t	acl;
	size_t	i;

	i = -1;
	while (++i <= 8 && sb.st_mode)
	{
		if ((sb.st_mode & S_IRUSR) && i == 0)
			ft_putchar('r');
		else if ((sb.st_mode & S_IWUSR) && i == 1)
			ft_putchar('w');
		else if ((sb.st_mode & S_IXUSR) && i == 2)
			(S_ISUID & sb.st_mode) ? ft_putchar('s') : ft_putchar('x');
		else
			ft_ls_mode_else(sb, i);
	}
	if ((S_IRUSR & sb.st_mode) &&
	listxattr(tmp->directory, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if ((acl = acl_get_link_np(tmp->directory, ACL_TYPE_EXTENDED)))
	{
		ft_putchar('+');
		acl_free(acl);
	}
	else
		ft_putchar(' ');
}
