#include "../includes/ft_ls.h"

void    ft_printfiles(t_ls **file, char *flags)
{
    ft_listsort(file, flags);
    ft_printlist(file, flags);
    ft_putchar('\n');
}