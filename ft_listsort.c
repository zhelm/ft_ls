#include "ft_ls.h"

void ft_listsort(t_ls **head, char *flags)
{
	char *tmpname;
	t_ls *ptr;
	int i;
	char *tp;

	ptr = *head;
	i = ((flags[5] == '1') ? -1 : 1);

	// MergeSort(head);
	// while (ptr->next != NULL)
	// {
	// 	if ((i * ft_strcmp(ptr->name, ptr->next->name)) > 0)
	// 	{
	// 		tp = ptr->directory;
	// 		tmpname = ptr->name;
	// 		ptr->directory = ptr->next->directory;
	// 		ptr->name = ptr->next->name;
	// 		ptr->next->directory = tp;
	// 		ptr->next->name = tmpname;
	// 		ptr = *head;
	// 	}
	// 	else
	// 		ptr = ptr->next;
	// }
	// if(flags[4] == '1')
	// 	ft_sort_time(head, i);
}