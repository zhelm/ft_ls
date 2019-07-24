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

size_t ft_recurselen(struct dirent **list)
{
	size_t i;
	size_t count;
	size_t a;
	struct dirent **line;

	i = 0;
	a = 0;
	count = 0;
	
	while(list[i])
	{
		ft_putstr(list[i]->d_name);
		ft_putchar('\t');
		if (list[i]->d_type == 4)
			count++;
		i++;
	}
	i = 0;
	line = (struct dirent **)malloc(sizeof(struct dirent *) * (count + 1));
	while(list[i])
	{
		if(list[i]->d_type == 4 && ft_strcmp(".", list[i]->d_name) != 0 && ft_strcmp("..", list[i]->d_name) != 0)
			{
			 	line[a] = list[i];
			 	a++;
			}
			i++;
	}
	return count;
}

void ft_listsort(struct dirent **head)
{
	size_t i;
	struct dirent *tmp;
	struct dirent *tmp1;

	i = 0;
	while (head[i + 1])
	{
		if (strcmp(head[i]->d_name, head[i + 1]->d_name) > 0)
		{
			tmp = head[i];
			tmp1 = head[i + 1];;
			head[i] = tmp1;
			head[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int main() //main to test the ctime and mtime
{
	struct dirent **list;
	struct stat buf; //ctime is the last time the inode changed and mtime is the last time the file was modified.
	struct dirent *de;
	struct stat sb;
	struct stat c;
	char outstr[200];
	DIR *dr;
	DIR *recu;
	struct passwd *ds;
	list = NULL;
	dr = opendir(".");
	size_t i = 0;
	size_t b;

	b = 0;
	 while ((de = readdir(dr)) != NULL)
	// {

	 	i++;
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
	// 	//printf("%d\t", de->d_type);
	// 	//       }
	// }
	closedir(dr);
	dr = opendir(".");

	list = (struct dirent **)malloc(sizeof(struct dirent*) * (1 + i));
	i = 0;
	while ((de = readdir(dr)) != NULL)
	{
		list[i] = de;
		i++;
	}
	i = 0;
	ft_listsort(list);
	ft_recurselen(list);

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

	//printf( (sb.st_mode & S_IRUSR) ? "r\n" : "-\n");
}
//file mode, links(are these hard links or soft links or both?), owner name, group name, number of bytes ,  month, day file was last modified, time file was last modified, and the pathname
//              ||-rw-r--r--||   1//just figure out how to get this    ||zhelm||   ||student||     ||20430||           ||Jul||              ||17||                        ||12:08||                     ||Notes||                  ||Notes||
