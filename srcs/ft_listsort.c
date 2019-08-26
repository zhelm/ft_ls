#include "../includes/ft_ls.h"

void ft_listsort(t_ls **head, char *flags)
{
	int i;

	i = ((flags[5] == '1') ? 1 : -1);
	ft_mergesort(head, flags, i);
}