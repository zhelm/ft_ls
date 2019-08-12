#include "ft_ls.h"

void ft_ls_print_l(t_ls **head, struct stat sb)
{
	t_ls *tmp;
	t_ls_l vals;

	char **str;
	char **time;
	
	if(*head)
		vals = ft_ls_l_analize(head, tmp);
	tmp = *head;
	while (tmp != NULL)
	{
		lstat(tmp->directory, &sb);
		str = ft_strsplit(ctime(&sb.st_mtime), ' ');
		time = ft_strsplit(str[3], ':');
		ft_ls_check_file_type(sb);
		ft_ls_mode(sb);
		ft_ls_print_lsub(&tmp, sb, vals);
		ft_print_l_time(str, time);
		ft_putstr(tmp->name);
		ft_putchar('\n');
		ft_free_arr((void **)str);
		ft_free_arr((void **)time);
		tmp = tmp->next;
		ft_ls_free_tmplist(head);
	}
}