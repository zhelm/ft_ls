#include "ft_ls.h"

void ft_printfiles(t_ls **file, char *flags)
{
    t_ls *tmp;
    struct stat sb;
    
    ft_listsort(file, flags);
    ft_printlist(file, flags);
}