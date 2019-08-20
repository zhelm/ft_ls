#include "ft_ls.h"

void ft_ls_print_l(t_ls **head)
{
	t_ls *tmp;
	t_ls *tmp1;
	t_ls_l vals;
	char **str;
	struct stat sb;
	
	tmp = NULL;
	if(*head)
		vals = ft_ls_l_analize(head, tmp);
	tmp = *head;
	while (tmp != NULL)
	{
		tmp1 = tmp;
		if(tmp->directory)
			lstat(tmp->directory, &sb);
		else
			lstat(tmp->name, &sb);
		str = ft_strsplit(ctime(&sb.st_mtime), ' ');
		ft_ls_check_file_type(sb);
		ft_ls_mode(sb);
		if((S_IRUSR & sb.st_mode) && listxattr(tmp->directory, NULL, 0, XATTR_NOFOLLOW) > 0)
			ft_putchar('@');
		else 
			ft_putchar(' ');
		ft_ls_print_lsub(&tmp, sb, vals, str);
		ft_putchar('\n');
		ft_free_arr((void **)str);
		tmp = tmp->next;
		// if(tmp1 != NULL)
			ft_ls_free_tmplist(&tmp1);
		// if(tmp == NULL)
		// 	free(tmp1);
	}
}