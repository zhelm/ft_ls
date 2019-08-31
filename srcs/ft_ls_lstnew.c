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

#include "../includes/ft_ls.h"

t_ls	*ft_ls_lstnew(struct dirent *de, char *dir, char *name)
{
	t_ls *new;

	if (!(new = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	new->directory = dir;
	if (de != NULL)
		new->name = ft_strdup(de->d_name);
	else if (name != NULL)
		new->name = ft_strdup(name);
	else
		new->name = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
