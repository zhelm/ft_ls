#include "../includes/ft_ls.h"

void ft_sort_time(t_ls **head, int i)
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
		if (((i * ((int)sb.st_mtime - (int)sb1.st_mtime)) < 0) || (((i * ((int)sb.st_mtime - (int)sb1.st_mtime) == 0 &&
		(i * ((int)sb.st_mtim.tv_nsec - (int)sb1.st_mtim.tv_nsec)) < 0))))
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
}