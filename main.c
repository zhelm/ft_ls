/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:52:22 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/15 10:56:10 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"

void ft_listsort(t_ls *head)
{
	t_ls *ptr;
	t_ls *hold;
	t_ls *test;
	t_ls *tmp;

	test = head;
	while (test->next != NULL)
	{
		printf("%s\t", test->de->d_name);
		test = test->next;
	}
	printf("\n");
	ptr = head;
	while (ptr->next != NULL)
	{
		if (ft_strcmp(ptr->de->d_name, ptr->next->de->d_name) > 0)
		{
			hold = ptr->next;
			ptr->next = ptr->next->next;
			//hold->next = NULL;
			ptr = head;
			while (ptr->next != NULL)
			{
				if (ft_strcmp(hold->de->d_name, ptr->de->d_name) > 0 && ft_strcmp(hold->de->d_name, ptr->next->de->d_name) < 0)
				{
					hold->next = ptr->next;
					ptr->next = hold;
					ptr = head;
					break;
				}else
					ptr = ptr->next;
			}
			break;
			//ptr = ptr->next;
		}
		else
			ptr = ptr->next;
		// else
		//break;
	}
	while (head->next != NULL)
	{
		printf("%s\t", head->de->d_name);
		head = head->next;
	}
}
int main() //main to test the ctime and mtime
{
	t_ls *list;
	t_ls *ptr;
	struct stat buf; //ctime is the last time the inode changed and mtime is the last time the file was modified.
	char mtime[100];
	struct dirent *de;
	struct dirent *rec;
	struct stat sb;
	struct stat c;
	char outstr[200];
	DIR *dr;
	DIR *recu;
	list = NULL;
	ptr = list;
	dr = opendir(".");
	while ((de = readdir(dr)) != NULL)
	{
		stat(de->d_name, &sb);
		if (list == NULL)
			list = ft_ls_lstnew(&sb, de);
		else
			ft_ls_lstadd(&list, ft_ls_lstnew(&sb, de));

		//printf("OK");printf("%s", list->de->d_name);
		//if(list->de->d_type == 8)
		//{
		//printf("%s\t", list->de->d_name);
		//printf("%o\n", sb.st_uid);
		//printf("%ld\n", list->sb->st_nlink);//number of links
		//}
		//printf("%o\n", list->sb->st_mode);
		//printf("%d\t", de->d_type);
		// 	  if(de->d_type == 4 && de->d_name != "." && de->d_name != "..")
		//		{
		// 			printf("   ||   ");
		// 			recu = opendir(de->d_name);
		//			while((rec = readdir(recu)) != NULL)
		// 	 	{
		// 	 		printf("%s\t", rec->d_name);
		// 	 		stat(rec->d_name, &c);
		// 	 	 }
		// 		  printf("   ||   ");
		// 	 }
	}
	ft_listsort(list);
	// printf(" file position within stream = 		%d\n", de->d_reclen);
	// printf("		           File Type = 		%d\n", de->d_type);
	// printf("		           stat mode = 		%o\n", sb.st_mode);//prints mode in octal
	// printf("		           stat size =		%ld\n", sb.st_size);//prints size of file
	// printf("					   links =      %ld\n", sb.st_nlink);
	// struct passwd *pw = getpwuid(sb.st_uid);//this gets the name
	// printf("		   		   user name =		%s\n", pw->pw_name);//
	// struct group  *gr = getgrgid(sb.st_gid);//this gets the group name
	// printf("		          group name =		%s\n", gr->gr_name);
	// printf("   time of last modification =		%s\n\n", ctime(&sb.st_ctime));
	// 	printf("name = %s\n", de->d_name);

	//printf( (sb.st_mode & S_IRUSR) ? "r\n" : "-\n");
}
//file mode, links(are these hard links or soft links or both?), owner name, group name, number of bytes ,  month, day file was last modified, time file was last modified, and the pathname
//		||-rw-r--r--||   1//just figure out how to get this    ||zhelm||   ||student||     ||20430||           ||Jul||              ||17||                        ||12:08||                     ||Notes||
