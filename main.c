/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:52:22 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/24 07:48:51 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//need to make colums for -l with malloc and find a way to print chars from the end of the malloced area;

#include "ft_ls.h"
// #include <time.h>
// #include "libft/libft.h"
// #include <stdlib.h>

int main(int argc, char **argv) //the directory names are set up wrong for -l
{
	t_ls *head;
	t_ls *dir;
	char *flags;
	DIR *dr;
	int fd;

	dir = NULL;
	if(argc >= 1)
	{
		if((flags = ft_ls_checkflags(argv)) == NULL)
			return 0;
	}
	ft_argv_analize(argv, flags, &dir); //need to sort this aswell. split this up into two functions
	if (dir == NULL)
		dir = ft_ls_lstnew(NULL, ".");
	else
		ft_argsort(&dir, flags);
	head = NULL;
	while (dir != NULL) // need to see if I can open all of the argv's first
	{
		ft_listrec(&head, dir->directory, flags); //  -R does not work completely when i use multiple files e.g. ../Libftest because I think the pointer of head is not pointing to the correct spot
		if (head != NULL)
		{
			while (head)
				(head) = (head)->next;
		}
		dir = dir->next;
	}
}