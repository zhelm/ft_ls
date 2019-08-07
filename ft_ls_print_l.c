#include "ft_ls.h"

void ft_ls_print_l(t_ls **head, struct stat sb)
{
	t_ls *tmp;
	struct passwd *usr;
	struct group *grp;
	char **str;
	char **time;
	
	tmp = *head;
	while (tmp != NULL)
	{
		lstat(tmp->directory, &sb);
		str = ft_strsplit(ctime(&sb.st_mtime), ' ');
		time = ft_strsplit(str[3], ':');
		ft_ls_check_file_type(sb);
		ft_ls_mode(sb);

		printf(" %d\t", sb.st_nlink);
		usr = getpwuid(sb.st_uid);
		grp = getgrgid(sb.st_gid);
		printf("%s %s", usr->pw_name, grp->gr_name);
		printf("\t%lld ", sb.st_size);
		printf("\t%s %s\t%s:%s", str[2], str[1], time[0], time[1]); //, sb.st_mtimespec.tv_sec,sb.st_mtimespec.tv_nsec);
		printf("\t%s", tmp->name);
		printf("\n");
		tmp = tmp->next;
	}
}