/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:52:43 by event             #+#    #+#             */
/*   Updated: 2019/06/12 07:24:46 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && del != NULL)
	{
		while (*alst)
		{
			del((**alst).content, (**alst).content_size);
			free(*alst);
			*alst = (**alst).next;
		}
		*alst = NULL;
	}
}
