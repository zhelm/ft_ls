/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 08:58:56 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/03 08:58:57 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_erlst(t_ls **er, char *argv)
{
	if (*er == NULL)
		*er = ft_ls_lstnew(NULL, NULL, ft_strdup(argv));
	else
		ft_ls_lstadd(er, ft_ls_lstnew(NULL, NULL, ft_strdup(argv)));
}
