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

t_ls_l			ft_ls_l_analize(t_ls **head, t_ls *tmp)
{
	t_ls_l ret;

	tmp = *head;
	ret.grpnm = 0;
	ret.links = 0;
	ret.size = 0;
	ret.usrnm = 0;
	return (ret);
}
