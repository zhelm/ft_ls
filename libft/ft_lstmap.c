/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:01:51 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 07:22:40 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *new;

	if (!lst)
		return (NULL);
	head = f(lst);
	new = head;
	while (lst->next)
	{
		lst = lst->next;
		if (!(head->next = f(lst)))
		{
			free(head);
			return (NULL);
		}
		head = head->next;
	}
	return (new);
}
