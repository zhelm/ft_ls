#include "libft.h"
#include "ft_ls.h"


void ft_ls_lstadd(t_ls **alst, t_ls *new)
{
	if(alst)
	{
		new->next = *alst;
		*alst = new;
	}
}