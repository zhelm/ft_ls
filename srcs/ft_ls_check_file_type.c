/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_check_file_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:27:21 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 11:27:24 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ls_check_file_type(struct stat sb)
{
	if (S_ISBLK(sb.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(sb.st_mode))
		ft_putchar('c');
	else if (S_ISDIR(sb.st_mode))
		ft_putchar('d');
	else if (S_ISFIFO(sb.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(sb.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(sb.st_mode))
		ft_putchar('s');
	else if (S_ISREG(sb.st_mode))
		ft_putchar('-');
}
