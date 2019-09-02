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

void	ft_frontbacksplit(t_ls *source, t_ls **front, t_ls **back)
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

t_ls	*ft_sortedmerge(t_ls *a, t_ls *b, int i)
{
	t_ls *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (i * ft_strcmp(a->name, b->name) > 0)
	{
		result = a;
		result->next = ft_sortedmerge(a->next, b, i);
	}
	else
	{
		result = b;
		result->next = ft_sortedmerge(a, b->next, i);
	}
	return (result);
}

t_ls	*ft_sortedmerge_time(t_ls *a, t_ls *b, int i)
{
	t_ls		*result;
	struct stat	sb;
	struct stat	sb1;

	result = NULL;
	if (a == NULL || b == NULL)
		return (a == NULL) ? b : a;
	lstat(b->directory, &sb1);
	lstat(a->directory, &sb);
	if (((i * ((int)sb.st_mtime - (int)sb1.st_mtime)) < 0) || (((i *
	((int)sb.st_mtime - (int)sb1.st_mtime) == 0 && (i *
	((int)sb.st_mtimespec.tv_nsec - (int)sb1.st_mtimespec.tv_nsec)) < 0))))
	{
		result = a;
		result->next = ft_sortedmerge_time(a->next, b, i);
	}
	else if ((((int)sb.st_mtimespec.tv_nsec -
	(int)sb1.st_mtimespec.tv_nsec)) != 0)//fixit
	{
		result = b;
		result->next = ft_sortedmerge_time(a, b->next, i);
	}
	else
		ft_sortedmerge(a, b, i);
	return (result);
}

void	ft_mergesort(t_ls **header, char *flags, int i)
{
	t_ls *head;
	t_ls *a;
	t_ls *b;

	head = *header;
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_frontbacksplit(head, &a, &b);
	ft_mergesort(&a, flags, i);
	ft_mergesort(&b, flags, i);
	if (flags[4] != '1')
		*header = ft_sortedmerge(a, b, i);
	else
		*header = ft_sortedmerge_time(a, b, i);
}
