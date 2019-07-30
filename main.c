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
	ptr->directory = ft_strjoin(dirtmp1, ptr->de->d_name);
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
//void ls_put_l(s)
void ft_ls_l(t_ls **head)
{
	t_ls *tmp;
	t_ls *ptr;
	struct stat sb;
	struct passwd *usr;
	struct group *grp;
	long long sz;
		char **str;
		char **time;
	sz = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		stat(tmp->directory, &sb);
		sz = sz + sb.st_blocks;
		tmp = tmp->next;
	}
	printf("total %lld\n", sz);
	tmp = *head;
	//printf("")
	while (tmp != NULL)
	{
		lstat(tmp->directory, &sb);
		//printf("%s", sb.st_flags);
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
		printf(" hello %s", tmp->de->d_name);
		printf("\n");
		//ptr = tmp;
		tmp = tmp->next;
	}

	//rwx, block size, ||links||, ||user name||, ||group name||, ||size||, day, month, time, ||name||
}

void ft_listsort(t_ls **head)
{
	t_ls *tmp;
	struct dirent *de;
	t_ls *tmp1;
	t_ls *ptr;
	size_t i;
	char *tp;

	ptr = *head;
	while (ptr->next != NULL)
	{
		if (ft_strcmp(ptr->de->d_name, ptr->next->de->d_name) > 0)
		{
			tp = ptr->directory;
			de = ptr->de;
			ptr->directory = ptr->next->directory;
			ptr->de = ptr->next->de;
			ptr->next->directory = tp;
			ptr->next->de = de;
			ptr = *head;
		}
		else if (ptr->next != NULL)
			ptr = ptr->next;
		else if (ptr->next == NULL)
			break;
	}
	ptr = *head;
}
void ft_ls_seg_lstadd(t_ls **head, t_ls **seg)
{
	t_ls *tmp;
	t_ls *ptr;
	ptr = *head;
	tmp = (*head)->next;
	(*head)->next = *seg;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
	ptr = *head;
	(*head) = (*head)->next;
	free(ptr);
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
		dir = ft_strdup(".");
	else
		dir = (*head)->directory;
	dr = opendir(dir);
	printf("%s:\n", dir);
	while ((de = readdir(dr)) != NULL)
	{
		if (tmp == NULL && de != NULL)
			tmp = ft_ls_lstnew(de, NULL);
		else if(de != NULL)
			ft_ls_lstadd(&tmp, ft_ls_lstnew(de, NULL));
		if(de)
			ft_assign_dir(&tmp, dir);
		printf("hello %s\n", tmp->de->d_name);
		if (de->d_type == 4 && strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0)
		{
			if (segment == NULL)
				segment = ft_ls_lstnew(de, NULL);
			else
				ft_ls_lstadd(&segment, ft_ls_lstnew(de, NULL));
			if(de != NULL)
				ft_assign_dir(&segment, dir);
		}
		//tmp = tmp->next;
		// printf("hello second %s\n", de->d_name);
	}
	// ptr = tmp;
	// while(ptr)
	// {
	// 	printf("hello %s\n", ptr->de->d_name);
	// 	ptr = ptr->next;
	// }
	if (tmp->next != NULL) //display tmp here before free
		ft_listsort(&tmp);
	
	// ft_printlist();///////////////////////////////////////////////////////////
	
	// ft_ls_l(&tmp);
	printf("\n\n");
	if (segment != NULL)
		ft_listsort(&segment); //was close to doing this part again. thought I was sorting the head; luckily it was only segments
	ptr = segment;

	if (*head == NULL && segment != NULL)
		*head = segment;
	else if ((*head) != NULL) //sunting here
		ft_ls_seg_lstadd(head, &segment);
	closedir(dr);
	if ((*head) != NULL)						  //close the dir maybe
		ft_listrec(dr, head, (*head)->directory); //it segfaults because of the function seg_lstadd;
	return 0;
}

int main() //main to test the ctime and mtime
{
	t_ls *head;
	struct stat buf; //ctime is the last time the inode changed and mtime is the last time the file was modified.
	head = NULL;
	struct stat sb;
	struct stat c;
	char outstr[200];
	DIR *dr;
	DIR *recu;
	struct passwd *ds;
	// list = NULL;
	dr = opendir(".");
	size_t i = 0;
	size_t b;
	char *dir;

	dir = NULL;

	b = 0;
	closedir(dr);
	dr = opendir(".");

	i = 0;
	ft_listrec(dr, &head, dir); ///////////////////////////////////////////////////////////////////////
}