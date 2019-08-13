#include "ft_ls.h"

void ft_ls_print_l(t_ls **head, struct stat sb)
{
	t_ls *tmp;
	t_ls *tmp1;
	t_ls_l vals;
	char **str;
	char **time;
	
	if(*head)
		vals = ft_ls_l_analize(head, tmp);
	tmp = *head;
	while (tmp != NULL)
	{
		tmp1 = tmp;
		lstat(tmp->directory, &sb);
		str = ft_strsplit(ctime(&sb.st_mtime), ' ');
		ft_ls_check_file_type(sb);
		ft_ls_mode(sb);
		ft_ls_print_lsub(&tmp, sb, vals, str);
		ft_putchar('\n');
		ft_free_arr((void **)str);
		tmp = tmp->next;
		if(tmp != NULL)
			ft_ls_free_tmplist(&tmp1);
	}
}