/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 07:30:57 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/24 07:32:04 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls *ft_ls_lstnew(struct dirent *de)
{
	t_ls *new;

	if(!(new = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	// if(!(new->sb = malloc(sizeof(sb))) || !(new->de = malloc(sizeof(de))))
	// 	{
	// 		free(new);
	// 		return NULL;
	// 	}
	new->de = de;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}
