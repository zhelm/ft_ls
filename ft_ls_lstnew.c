#include "ft_ls.h"

t_ls *ft_ls_lstnew(struct stat *sb, struct dirent *de)
{
	t_ls *new;

	if(!(new = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	// if(!(new->sb = malloc(sizeof(sb))) || !(new->de = malloc(sizeof(de))))
	// 	{
	// 		free(new);
	// 		return NULL;
	// 	}
	new->sb = sb;
	new->de = de;
	new->next = NULL;
	return(new);
}