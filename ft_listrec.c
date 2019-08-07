#include "ft_ls.h"

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