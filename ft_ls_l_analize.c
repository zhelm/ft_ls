#include "ft_ls.h"

t_ls_l    *ft_ls_l_analize(t_ls **head)
{
    t_ls_l *ret;
    t_ls *tmp;
    struct stat sb;
    tmp = *head;

    ret->grpnm = 0;
    ret->links = 0;
    ret->size = 0;
    ret->usrnm = 0;
    while(tmp != NULL)
    {
         lstat(tmp->directory, &sb);
    }
}