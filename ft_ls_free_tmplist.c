#include "ft_ls.h"

void    ft_ls_free_tmplist(t_ls **head)
{
    if((*head)->prev != NULL)
        free((*head)->prev);
    (*head)->prev = NULL;
    if((*head)->directory != NULL)
        ft_strdel(&(*head)->directory);
    (*head)->next = NULL;
    if((*head)->name != NULL)
        ft_strdel(&(*head)->name);
    (*head)->name = NULL;
}