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
		printf(" %s", tmp->name);
		printf("\n");
		tmp = tmp->next;
	}
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
	// tmp = (*head)->next;
	// (*head)->next = *seg;
		// ft_putstr("OK123");

	while (ptr != NULL && ft_strcmp(ptr->directory, dir) != 0)
	{
		ft_putstr("Hello");
		if(ptr->next != NULL)
			ptr = ptr->next;
		else 
			break;
	}

	if(ft_strcmp(ptr->directory, dir) == 0)
	{
		// ft_putstr("OK123");
		tmp = ptr->next;
		ptr->next = *seg;
		(*seg)->prev = ptr;
		while(ptr->next != NULL)
			(ptr) = (ptr)->next;
		if(tmp != NULL)
			tmp->prev = ptr;
		ptr->next = tmp;
	}
}

t_ls *ft_listrec(DIR *dr, t_ls **head, char *dir)
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
		(*head) = ft_ls_lstnew(NULL, ".");
		(*head)->directory = ft_strdup(".");
		(*head)->name = ft_strdup(".");
	}
	dir = (*head)->directory;
	dr = opendir(dir);
	// if (*head != NULL && *(*head)->name != '.')
	//printf("\n%s:\n", dir); //need to let this work with flags aswell
	while ((de = readdir(dr)) != NULL)
	{
		if (tmp == NULL && de != NULL) //maybe a function for the two cases
			tmp = ft_ls_lstnew(de, NULL);
		else if (de != NULL)
			ft_ls_lstadd(&tmp, ft_ls_lstnew(de, NULL));
		if (de)
			ft_assign_dir(&tmp, dir);
			// printf("he%s\n", tmp->name);
		if (de->d_type == 4 && strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0)
		{
			if (segment == NULL)
				segment = ft_ls_lstnew(de, NULL);
			else
				ft_ls_lstadd(&segment, ft_ls_lstnew(de, NULL));
			if (de != NULL)
				ft_assign_dir(&segment, dir);
		}
	}
	if (tmp && tmp->next != NULL) //display tmp here before free
		ft_listsort(&tmp);
	// ft_printlist();///////////////////////////////////////////////////////////
//	ft_ls_l(&tmp); //if there is nothing inside a directory then do not print total
	if (segment != NULL)
		ft_listsort(&segment); //was close to doing this part again. thought I was sorting the head; luckily it was only segments
	ptr = segment;
		// ft_putstr("OK123");
	// if (*head == NULL && segment != NULL)
	// 	*head = segment;
	if ((*head) != NULL && segment != NULL) //sunting here
		ft_ls_seg_lstadd(head, &segment, dir);

	closedir(dr);
	// printf("OK");
	if ((*head) != NULL)
	{						  //close the dir maybe
		ptr = *head;
		while(ptr)
		{
			// printf("hello");
			if(ptr && ft_strcmp(ptr->directory, dir) == 0)
				{
					ptr = ptr->next;
					break;
				}
			ptr = ptr->next;
		}
	if(ptr != NULL)
		ft_listrec(dr, &ptr, ptr->directory); //it segfaults because of the function seg_lstadd;
	}
//	printf()
	 //it segfaults because of the function seg_lstadd;
	// printf("ok");
	return 0;
}

int main() //main to test the ctime and mtime
{
	t_ls *ptr;
	size_t i = 0;
	t_ls *head;
	DIR *dr;
	char *dir;

	ptr = head;
	head = NULL;
	dir = NULL;
	dr = opendir(".");

	ft_listrec(dr, &head, dir);
	ptr = head;
	while(ptr != NULL)
	{
	printf("current = %s\n", ptr->directory);
	//if(ptr->prev != NULL)
	//printf("prev = %s\n\n", ptr->prev->directory);
		if(ptr->next != NULL)
			ptr = ptr->next;
		else
		{
			break;
		}
	}
	 ///////////////////////////////////////////////////////////////////////
	 while(ptr->prev != NULL)
	 {
		 printf("reverse = %s\n", ptr->directory);
	 	 ptr = ptr->prev;
	 }
}