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

void ft_ls_mode(struct stat sb)
{
	size_t i;

	i = -1;
	while (++i <= 8)
	{
		if ((sb.st_mode & S_IRUSR) && i == 0)
			ft_putchar('r');
		else if( (sb.st_mode & S_IWUSR) && i == 1)
			ft_putchar('w');
		else if( (sb.st_mode & S_IXUSR) && i == 2)
			ft_putchar('x');
		else if( (sb.st_mode & S_IRGRP) && i == 3)
			ft_putchar('r');
		else if( (sb.st_mode & S_IWGRP) && i == 4)
			ft_putchar('w');
		else if( (sb.st_mode & S_IXGRP) && i == 5)
			ft_putchar('x');
		else if( (sb.st_mode & S_IROTH) && i == 6)
			ft_putchar('r');
		else if( (sb.st_mode & S_IWOTH) && i == 7)
			ft_putchar('w');
		else if( (sb.st_mode & S_IXOTH) && i == 8)
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

	tmp = *head;
	while (tmp != NULL)
	{
		//printf("%s\t", tmp->de->d_name);//not sorted yet

		stat(tmp->directory, &sb);
		ft_ls_mode(sb);
		printf("\n");
		ptr = tmp;
		// if(tmp->next == NULL)
		// 	break;
		tmp = tmp->next;
		//free(ptr);
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

		if (tmp == NULL)
			tmp = ft_ls_lstnew(de, NULL);
		else
			ft_ls_lstadd(&tmp, ft_ls_lstnew(de, NULL));
		ft_assign_dir(&tmp, dir);
		if (de->d_type == 4 && strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0)
		{
			if (segment == NULL)
				segment = ft_ls_lstnew(de, NULL);
			else
				ft_ls_lstadd(&segment, ft_ls_lstnew(de, NULL));
			ft_assign_dir(&segment, dir);
		}
	}
	if (tmp->next != NULL) //display tmp here before free
		ft_listsort(&tmp);
	ptr = tmp;
	// while(ptr != NULL)
	// {
	// 	printf("%s\t", ptr->de->d_name);
	ft_ls_l(&tmp);
	// ptr = ptr->next;
	// }
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
												  // else
	return 0;
	// return *head;
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
	//  while ((de = readdir(dr)) != NULL)
	// {

	// i++;
	// 	// if (list == NULL)
	// 	//      list = ft_ls_lstnew(&sb, de);
	// 	// else
	// 	//      ft_ls_lstadd(&list, ft_ls_lstnew(&sb, de));

	// 	//printf("OK");printf("%s", list->de->d_name);
	// 	//if(list->de->d_type == 8)
	// 	//{
	// 	//printf("%s\t", list->de->d_name);
	// 	//printf("%o\n", sb.st_uid);
	// 	//printf("%ld\n", list->sb->st_nlink);//number of links
	// 	//}
	// 	//printf("%o\n", list->sb->st_mode);
	//	//printf("%d\t", de->d_type);
	// 	//       }
	// }
	closedir(dr);
	dr = opendir(".");

	i = 0;
	ft_listrec(dr, &head, dir); ///////////////////////////////////////////////////////////////////////

	// ft_ls_l(dir);
	// ft_recurselen(list);

	//line = ft_memalloc(12);

	// printf(" file position within stream =               %d\n", de->d_reclen);
	// printf("                        File Type =          %d\n", de->d_type);
	// printf("                        stat mode =          %o\n", sb.st_mode);//prints mode in octal
	// printf("                        stat size =          %ld\n", sb.st_size);//prints size of file
	// printf("                                        links =      %ld\n", sb.st_nlink);
	// struct passwd *pw = getpwuid(sb.st_uid);//this gets the name
	// printf("                                user name =          %s\n", pw->pw_name);//
	// struct group  *gr = getgrgid(sb.st_gid);//this gets the group name
	// printf("                       group name =          %s\n", gr->gr_name);
	// printf("   time of last modification =               %s\n\n", ctime(&sb.st_ctime));
	//      printf("name = %s\n", de->d_name);
}
//file mode, links(are these hard links or soft links or both?), owner name, group name, number of bytes ,  month, day file was last modified, time file was last modified, and the pathname
//              ||-rw-r--r--||   1//just figure out how to get this    ||zhelm||   ||student||     ||20430||           ||Jul||              ||17||                        ||12:08||                     ||Notes||                  ||Notes||
//