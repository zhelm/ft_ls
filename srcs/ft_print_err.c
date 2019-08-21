#include "../includes/ft_ls.h"

void ft_print_err(t_ls **er, char *flags)
{
    ft_listsort(er, flags);
    while(*er)
    {
        ft_putstr("ft_ls: ");
	    ft_putstr((*er)->name);
	    ft_putstr(": ");
	    perror("");
        (*er) = (*er)->next;
    }
}