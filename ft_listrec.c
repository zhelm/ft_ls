#include "ft_ls.h"

t_ls *ft_listrec(t_ls **head, char *dir, char *flags)
{
	t_ls *segment;
	t_ls *tmp;

	segment = NULL;
	tmp = NULL;
	if (*head == NULL)
	{
		(*head) = ft_ls_lstnew(NULL, dir, NULL);
		(*head)->directory = ft_strdup(dir);
		(*head)->name = ft_strdup(dir);
	}
	else
		printf("%s:\n", dir);
	ft_ls_mklst(&segment, &tmp, flags, dir);//it are here
	if (tmp && tmp->next != NULL)
		ft_listsort(&tmp, flags);
	// ft_printlist(&tmp, flags);
	if (segment != NULL)
		ft_listsort(&segment, flags);
	if ((*head) != NULL && segment != NULL)
		ft_ls_seg_lstadd(head, &segment, dir);
	if((*head)->next != NULL)
		ft_dorec(head, flags, dir);
	// free((*head)->name);
	// free((*head)->directory);
	if(*head)
		free(*head);
	*head = NULL;
	return 0;
}