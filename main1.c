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

void ft_ls_print_l(t_ls **head, struct stat sb)
{
	t_ls *tmp;
	struct passwd *usr;
	struct group *grp;
	char **str;
	char **time;
	
	tmp = *head;
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
}

void ft_ls_l(t_ls **head)
{
	t_ls *tmp;
	struct stat sb;
	long long sz;

	sz = 0;
	tmp = *head;
	if (tmp)
	{
		while (tmp != NULL)
		{
			lstat(tmp->directory, &sb);
			sz = sz + sb.st_blocks;
			tmp = tmp->next;
		}
		printf("total %lld\n", sz);
	}
	ft_ls_print_l(head, sb);	
}

void ft_sort_time(t_ls **head, char *flags, int i)
{
	struct stat sb;
	struct stat sb1;
	char *tmpname;
	t_ls *ptr;
	char *tp;

	ptr = *head;
	while (ptr->next != NULL)
	{
		stat(ptr->directory, &sb);
		stat(ptr->next->directory, &sb1);
		if (((i * ((int)sb.st_mtime - (int)sb1.st_mtime)) < 0) || (((i * ((int)sb.st_mtime - (int)sb1.st_mtime) == 0 && (i * ((int)sb.st_mtimespec.tv_nsec - (int)sb1.st_mtimespec.tv_nsec)) < 0))))
		{
			tp = ptr->directory;
			tmpname = ptr->name;
			ptr->directory = ptr->next->directory;
			ptr->name = ptr->next->name;
			ptr->next->directory = tp;
			ptr->next->name = tmpname;
			ptr = *head;
		}
		else
			ptr = ptr->next;//here it is
	}
}

void ft_listsort(t_ls **head, char *flags)
{
	t_ls *tmp;
	char *tmpname;
	t_ls *ptr;
	int i;
	char *tp;

	ptr = *head;
	i = ((flags[5] == '1') ? -1 : 1);
	while (ptr->next != NULL)
	{
		if ((i * ft_strcmp(ptr->name, ptr->next->name)) > 0)
		{
			tp = ptr->directory;
			tmpname = ptr->name;
			ptr->directory = ptr->next->directory;
			ptr->name = ptr->next->name;
			ptr->next->directory = tp;
			ptr->next->name = tmpname;
			ptr = *head;
		}
		else
			ptr = ptr->next;
	}
	if(flags[4] == '1')
		ft_sort_time(head, flags, i);
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

void ft_printlist(t_ls **tmp, char *flags)
{
	t_ls *ptr;
	// printf("ok")
	ptr = *tmp;
	if (flags[7] == '1')
		ft_ls_l(tmp);
	else
	{
		while (ptr)
		{
			printf("%s   \t", ptr->name);
			ptr = ptr->next;
		}
		printf("\n\n");
	}
}
void	ft_ls_mklst(t_ls **segment, t_ls **tmp, char *flags, char *dir)
{
	struct dirent *de;
	DIR *dr;

	dr = opendir(dir);
	while((de = readdir(dr)) != NULL)
	{
		if (!(flags[6] == '0' && *de->d_name == '.') && *tmp == NULL && de != NULL) //maybe a function for the two cases
			*tmp = ft_ls_lstnew(de, NULL);
		else if (!(flags[6] == '0' && *de->d_name == '.') && de != NULL)
			ft_ls_lstadd(tmp, ft_ls_lstnew(de, NULL));
		if (!(flags[6] == '0' && *de->d_name == '.') && de)
			ft_assign_dir(tmp, dir);
		if (de->d_type == 4 && !(flags[6] == '0' && *de->d_name == '.') && strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0)
		{
			if (*segment == NULL)
				*segment = ft_ls_lstnew(de, NULL);
			else
				ft_ls_lstadd(segment, ft_ls_lstnew(de, NULL));
			if (de != NULL)
				ft_assign_dir(segment, dir);
		}
	}
	closedir(dr);
}



t_ls *ft_listrec(t_ls **head, char *dir, char *flags)
{
	t_ls *ptr;
	t_ls *segment;
	t_ls *tmp;

	segment = NULL;
	tmp = NULL;
	if (*head == NULL)
	{
		(*head) = ft_ls_lstnew(NULL, dir);
		(*head)->directory = ft_strdup(dir);
		(*head)->name = ft_strdup(dir);
	}
	if (*head != NULL)
	printf("%s:\n", dir); //need to let this work with flags aswell
	ft_ls_mklst(&segment, &tmp, flags, dir);
	if (tmp && tmp->next != NULL)
		ft_listsort(&tmp, flags);
	ft_printlist(&tmp, flags); ///////////////////////////////////////////////////////////freemthe whole list while printing it if it is not recursive
	if (segment != NULL)
		ft_listsort(&segment, flags); //was close to doing this part again. thought I was sorting the head; luckily it was only segments
	if ((*head) != NULL && segment != NULL) //sunting here
		ft_ls_seg_lstadd(head, &segment, dir);
	// ft_dorec(head, flags, dir);
	ptr = *head;
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
			ptr = ptr->next;
		}
		if (flags[3] == '1' && ptr != NULL)
		{
			printf("\n");
			ft_listrec(&ptr, ptr->directory, flags);
		}
	}
	return 0;
}



void ft_argv_analize(char **argv, char *flags, t_ls **dir)
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
				return;
			}
		}
		if (argv[i][1] == '\0')
			printf("ERROR");
		i++;
	}
	while (argv[i + count] != NULL && *argv[i + count] != '-')
		count++;
	t_ls *ptr;

	ptr = *dir;
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
		else if (ptr->next != NULL)
			ptr = ptr->next;
		else if (ptr->next == NULL)
			break;
	}
	if(flags[4] == '1')
		ft_sortarg_time(dir, flags);
}

int main(int argc, char **argv)
{
	t_ls *head;
	size_t a = 0;
	struct dirent *de;
	t_ls *dir;
	dir = NULL;
	char flags[9] = "00000000";
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