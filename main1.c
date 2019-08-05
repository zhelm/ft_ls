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

void ft_assign_dir(t_ls **head, char *dir)
{
	char *dirtmp1;
	t_ls *ptr;

	dirtmp1 = ft_strjoin(dir, "/"); //should be another function
	ptr = *head;
	while (ptr)
	{
		if (ptr->next != NULL)
			ptr = ptr->next;
		else
			break;
	}
	ptr->directory = ft_strjoin(dirtmp1, ptr->name);
}

void ft_ls_check_file_type(struct stat sb)
{
	if (S_ISBLK(sb.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(sb.st_mode))
		ft_putchar('c');
	else if (S_ISDIR(sb.st_mode))
		ft_putchar('d');
	else if (S_ISFIFO(sb.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(sb.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(sb.st_mode))
		ft_putchar('s');
	else if (S_ISREG(sb.st_mode))
		ft_putchar('-');
}

void ft_ls_mode(struct stat sb)
{
	size_t i;

	i = -1;
	while (++i <= 8)
	{
		if ((sb.st_mode & S_IRUSR) && i == 0)
			ft_putchar('r');
		else if ((sb.st_mode & S_IWUSR) && i == 1)
			ft_putchar('w');
		else if ((sb.st_mode & S_IXUSR) && i == 2)
			ft_putchar('x');
		else if ((sb.st_mode & S_IRGRP) && i == 3)
			ft_putchar('r');
		else if ((sb.st_mode & S_IWGRP) && i == 4)
			ft_putchar('w');
		else if ((sb.st_mode & S_IXGRP) && i == 5)
			ft_putchar('x');
		else if ((sb.st_mode & S_IROTH) && i == 6)
			ft_putchar('r');
		else if ((sb.st_mode & S_IWOTH) && i == 7)
			ft_putchar('w');
		else if ((sb.st_mode & S_IXOTH) && i == 8)
			ft_putchar('x');
		else
			ft_putchar('-');
	}
}

void ft_ls_l(t_ls **head)
{
	t_ls *tmp;
	t_ls *ptr;
	struct stat sb;
	struct passwd *usr;
	struct group *grp;
	long long sz;
	int i;
	char **str;
	char **time;
	sz = 0;
	tmp = *head;
	i = 0;
	if (tmp)
	{
		while (tmp != NULL)
		{
			stat(tmp->directory, &sb);
			sz = sz + sb.st_blocks;
			tmp = tmp->next;
			i++;
		}
		printf("total %lld\n", sz);
	}
	tmp = *head;
	//printf("")
	while (tmp != NULL)
	{
		lstat(tmp->directory, &sb);
		str = ft_strsplit(ctime(&sb.st_mtime), ' ');
		time = ft_strsplit(str[3], ':');
		ft_ls_check_file_type(sb);
		ft_ls_mode(sb);

		printf(" %d\t", sb.st_nlink);
		usr = getpwuid(sb.st_uid);
		grp = getgrgid(sb.st_gid);
		printf("%s %s", usr->pw_name, grp->gr_name);
		printf("\t%lld ", sb.st_size);
		printf("\t%s %s\t%s:%s", str[2], str[1], time[0], time[1]); //, sb.st_mtimespec.tv_sec,sb.st_mtimespec.tv_nsec);
		printf("\t%s", tmp->name);
		printf("\n");
		tmp = tmp->next;
	}
	//str = ft_strsplit(ctime(&sb.st_mtime), ' ');
}

void ft_listsort(t_ls **head)
{
	t_ls *tmp;
	char *tmpname;
	t_ls *tmp1;
	t_ls *ptr;
	size_t i;
	char *tp;
	ptr = *head;
	while (ptr->next != NULL)
	{
		if (ft_strcmp(ptr->name, ptr->next->name) > 0)
		{
			tp = ptr->directory;
			tmpname = ptr->name;
			ptr->directory = ptr->next->directory;
			ptr->name = ptr->next->name;
			ptr->next->directory = tp;
			ptr->next->name = tmpname;
			ptr = *head;
		}
		else if (ptr->next != NULL)
			ptr = ptr->next;
		else if (ptr->next == NULL)
			break;
	}
	ptr = *head;
}

void ft_ls_seg_lstadd(t_ls **head, t_ls **seg, char *dir)
{
	t_ls *tmp;
	t_ls *ptr;

	tmp = *seg;
	ptr = *head;
	while (ptr != NULL && ft_strcmp(ptr->directory, dir) != 0)
	{
		if (ptr->next != NULL)
			ptr = ptr->next;
		else
			break;
	}

	if (ft_strcmp(ptr->directory, dir) == 0)
	{
		// ft_putstr("OK123");
		tmp = ptr->next;
		ptr->next = *seg;
		(*seg)->prev = ptr;
		while (ptr->next != NULL)
			(ptr) = (ptr)->next;
		if (tmp != NULL)
			tmp->prev = ptr;
		ptr->next = tmp;
	}
}

t_ls *ft_listrec(DIR *dr, t_ls **head, char *dir, char *flags)
{
	char *dirtmp1;
	char *dirtmp;
	t_ls *ptr;
	t_ls *segment;
	t_ls *tmp;
	size_t i = 0;
	ptr = *head;
	segment = NULL;
	struct dirent *de;
	tmp = NULL;
	if (*head == NULL)
	{
		(*head) = ft_ls_lstnew(NULL, dir);
		(*head)->directory = ft_strdup(dir);
		(*head)->name = ft_strdup(dir);
	}
	//dir = (*head)->directory;
	dr = opendir(dir);
	// if (*head != NULL && *(*head)->name != '.')
	printf("\n%s:\n", dir); //need to let this work with flags aswell
	while ((de = readdir(dr)) != NULL)
	{
		if (!(flags[6] == '0' && *de->d_name == '.') && tmp == NULL && de != NULL) //maybe a function for the two cases
			tmp = ft_ls_lstnew(de, NULL);
		else if (!(flags[6] == '0' && *de->d_name == '.') && de != NULL)
			ft_ls_lstadd(&tmp, ft_ls_lstnew(de, NULL));
		if (!(flags[6] == '0' && *de->d_name == '.') && de)
			ft_assign_dir(&tmp, dir);
		if (de->d_type == 4 && !(flags[6] == '0' && *de->d_name == '.') && strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0)
		{
			if (segment == NULL)
				segment = ft_ls_lstnew(de, NULL);
			else
				ft_ls_lstadd(&segment, ft_ls_lstnew(de, NULL));
			if (de != NULL)
				ft_assign_dir(&segment, dir);
		}
	}
	if (tmp && tmp->next != NULL)
		ft_listsort(&tmp);
	// ft_printlist();///////////////////////////////////////////////////////////freemthe whole list while printing it if it is not recursive
	// ft_ls_l(&tmp); //if there is nothing inside a directory then do not print total
	if (segment != NULL)
		ft_listsort(&segment); //was close to doing this part again. thought I was sorting the head; luckily it was only segments
	ptr = segment;
	if ((*head) != NULL && segment != NULL) //sunting here
		ft_ls_seg_lstadd(head, &segment, dir);

	closedir(dr);
	if ((*head) != NULL)
	{
		ptr = *head;
		while (ptr)
		{
			if (ptr && ft_strcmp(ptr->directory, dir) == 0)
			{
				ptr = ptr->next;
				break;
			}
			// else
			// {
			// 	tmp = ptr->next;
			// 	free (ptr);
			// }

			ptr = ptr->next;
		}
		if (flags[3] == '1' && ptr != NULL)
			ft_listrec(dr, &ptr, ptr->directory, flags);
	}
	return 0;
}

char **ft_argv_analize(char **argv, char *flags, char ***dir)
{
	size_t i;
	size_t a;
	size_t count;

	count = 0;
	a = 1;
	i = 1;
	while (argv[i] && *argv[i] == '-')
	{
		a = 1;
		while (argv[i][a])
		{
			if (argv[i][a] == 'l' || argv[i][a] == 'r' || argv[i][a] == 't' || argv[i][a] == 'a' || argv[i][a] == 'R')
			{
				if (argv[i][a] == 'l')
					flags[7] = '1';
				else if (argv[i][a] == 'a')
					flags[6] = '1';
				else if (argv[i][a] == 'r')
					flags[5] = '1';
				else if (argv[i][a] == 't')
					flags[4] = '1';
				else if (argv[i][a] == 'R')
					flags[3] = '1';
				a++;
			}
			else
			{
				printf("ERROR");
				return NULL;
			}
		}
		if (argv[i][1] == '\0')
			printf("ERROR");
		else
			flags[a] == '\0';
		i++;
	}
	while (argv[i + count] != NULL && *argv[i + count] != '-')
		count++;
	if (count != 0)
		*dir = &argv[i];
}

int main(int argc, char **argv)
{
	t_ls *ptr;
	size_t i = 0;
	t_ls *head;
	DIR *dr;
	size_t a = 0;
	struct dirent *de;
	char **dir;
	char flags[8] = "00000000";
	dir = ft_argv_analize(argv, flags, &dir);
	if(dir == NULL)
	{
		dir = (char **)malloc(sizeof(char *) * 2);
		dir[0] = ft_strdup(".");
		dir[1] = NULL;
	}
	ptr = head;
	head = NULL;
	while (dir[a] != NULL) // need to see if I can open all of the argv's first
	{
		// printf("%s", dir[a]);
		ft_listrec(dr, &head, dir[a], flags); //  -R does not work completely when i use multiple files e.g. ../Libftest because I think the pointer of head is not pointing to the correct spot
		a++;
	}
	// else
	// {
	// 	return ;
	// }

	ptr = head;
	while(ptr != NULL)
	{
	printf("current = %s\n", ptr->directory);
	// if(ptr->prev != NULL)
	// printf("prev = %s\n\n", ptr->prev->directory);
		if(ptr->next != NULL)
			ptr = ptr->next;
		else
		{
			break;
		}
	}
	 ///////////////////////////////////////////////////////////////////////
	 while(ptr != NULL)
	 {
		 printf("reverse = %s\n", ptr->directory);
	 	if(ptr->prev != NULL)
			ptr = ptr->prev;
		else
			break;
	 }
}