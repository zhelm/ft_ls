#include "../includes/ft_ls.h"

void    ft_erlst(t_ls **er, char *argv)
{
    if (*er == NULL)
        *er = ft_ls_lstnew(NULL, NULL, ft_strdup(argv));
    else
        ft_ls_lstadd(er, ft_ls_lstnew(NULL, NULL, ft_strdup(argv)));   
}