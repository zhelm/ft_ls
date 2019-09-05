/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:45:20 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 10:45:22 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_fbsplit(t_ls *source, t_ls **front, t_ls **back)
{
	t_ls *fast;
	t_ls *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

t_ls	*ft_sortedmerge(t_ls *a, t_ls *b, int i, t_ls *r)
{
	if (a == NULL || b == NULL)
		return (a == NULL) ? b : a;
	if (i * ft_strcmp(a->name, b->name) > 0)
	{
		r = a;
		r->next = ft_sortedmerge(a->next, b, i, r);
	}
	else
	{
		r = b;
		r->next = ft_sortedmerge(a, b->next, i, r);
	}
	return (r);
}

t_ls	*ft_t(t_ls *a, t_ls *b, int i, t_ls *r)
{
	struct stat s;
	struct stat t;

	if (a == NULL || b == NULL)
		return (a == NULL) ? b : a;
	lstat(b->directory, &s);
	lstat(a->directory, &t);
	if ((i * (int)(t.st_mtime - s.st_mtime)) != 0)
	{
		r = ((i * (int)(t.st_mtime - s.st_mtime)) < 0) ? a : b;
		r->next = (r == a) ? ft_t(a->next, b, i, r) : ft_t(a, b->next, i, r);
	}
	else if ((i * (int)(t.st_mtim.tv_nsec - s.st_mtim.tv_nsec)) != 0)
	{
		r = ((i * (int)(t.st_mtim.tv_nsec - s.st_mtim.tv_nsec)) < 0)
		? a : b;
		r->next = (r == a) ? ft_t(a->next, b, i, r) : ft_t(a, b->next, i, r);
	}
	else
	{
		r = ((i * ft_strcmp(a->name, b->name)) > 0) ? a : b;
		r->next = (r == a) ? ft_t(a->next, b, i, r) : ft_t(a, b->next, i, r);
	}
	return (r);
}

void	ft_mergesort(t_ls **header, char *flags, int i)
{
	t_ls *head;
	t_ls *a;
	t_ls *b;
	t_ls *r;

	i = (flags[5] == '1') ? 1 : -1;
	r = NULL;
	head = *header;
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_fbsplit(head, &a, &b);
	ft_mergesort(&a, flags, i);
	ft_mergesort(&b, flags, i);
	if (flags[4] != '1')
		*header = ft_sortedmerge(a, b, i, r);
	else
		*header = ft_t(a, b, i, r);
}
