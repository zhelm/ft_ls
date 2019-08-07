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

#include "ft_ls.h"
#include <time.h>
#include "libft/libft.h"
#include <stdlib.h>

void ft_ls_mkflags(char *argv, char *flags)
{
	size_t a;

	a = 1;
	while (argv[a])
	{
		if (argv[a] == 'l' || argv[a] == 'r' || argv[a] == 't' || argv[a] == 'a' || argv[a] == 'R')
		{
			if (argv[a] == 'l')
				flags[7] = '1';
			else if (argv[a] == 'a')
				flags[6] = '1';
			else if (argv[a] == 'r')
				flags[5] = '1';
			else if (argv[a] == 't')
				flags[4] = '1';
			else if (argv[a] == 'R')
				flags[3] = '1';
			a++;
		}
		else
		{
			printf("ERROR");
			return;
		}
	}
}

void ft_argv_analize(char **argv, char *flags, t_ls **dir)
{
	size_t i;
	size_t count;

	count = 0;
	i = 1;
	while (argv[i] && *argv[i] == '-')
	{
		ft_ls_mkflags(argv[i], flags);		
		if (argv[i][1] == '\0')
			printf("ERROR");
		i++;
	}
	while (argv[i + count] != NULL && *argv[i + count] != '-')
		count++;
	if (count != 0)
	{
		while (argv[i] != NULL)
		{
			if (*dir == NULL)
				*dir = ft_ls_lstnew(NULL, argv[i]);
			else
				ft_ls_lstadd(dir, ft_ls_lstnew(NULL, argv[i]));
			i++;
		}
	}
}

void ft_sortarg_time(t_ls **head, char *flags)
{
	struct stat sb;
	struct stat sb1;
	t_ls *ptr;
	int i;
	char *tp;

	ptr = *head;
	i = -1;
	if (flags[5] == '1')
		i = 1;
	while (ptr->next != NULL)
	{
		stat(ptr->directory, &sb);
		stat(ptr->next->directory, &sb1);
		if (((i * ((int)sb.st_mtimespec.tv_sec - (int)sb1.st_mtimespec.tv_sec)) > 0) || (((i * ((int)sb.st_mtimespec.tv_sec - (int)sb1.st_mtimespec.tv_sec) == 0 && (i * ((int)sb.st_mtimespec.tv_nsec - (int)sb1.st_mtimespec.tv_nsec)) > 0))))
		{
			tp = ptr->directory;
			ptr->directory = ptr->next->directory;
			ptr->next->directory = tp;
			ptr = *head;
		}
		else
			ptr = ptr->next;
	}
}

void ft_argsort(t_ls **dir, char *flags) //This is a good way to do the other sort aswell
{
	t_ls *tmp;
	t_ls *ptr;
	int i;
	char *tp;

	ptr = *dir;
	i = 1;
	if (flags[5] == '1')
		i = -1;
	while (ptr->next != NULL)
	{
		if ((i * ft_strcmp(ptr->directory, ptr->next->directory)) > 0)
		{
			tp = ptr->directory;
			ptr->directory = ptr->next->directory;
			ptr->next->directory = tp;
			ptr = *dir;
		}
		else
			ptr = ptr->next;
	}
	if (flags[4] == '1')
		ft_sortarg_time(dir, flags);
}
// char *ft_ls_analizeargv(char **argv)
// {
// }

int main(int argc, char **argv)
{
	t_ls *head;
	t_ls *dir;
	char flags[9] = "00000000";

	dir = NULL;
	// flags = ft_ls_checkflags(argv);//returns flags
	ft_argv_analize(argv, flags, &dir); //need to sort this aswell. split this up into two functions
	if (dir == NULL)
		dir = ft_ls_lstnew(NULL, ".");
	else
		ft_argsort(&dir, flags);
	head = NULL;
	while (dir != NULL) // need to see if I can open all of the argv's first
	{
		printf("%s\n", dir->directory);
		// ft_listrec(&head, dir->directory, flags); //  -R does not work completely when i use multiple files e.g. ../Libftest because I think the pointer of head is not pointing to the correct spot
		if (head != NULL)
		{
			while (head)
				(head) = (head)->next;
		}
		dir = dir->next;
	}
}