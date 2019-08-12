#include "ft_ls.h"

void ft_ls_print_lsub(t_ls **tmp, struct stat sb, char **time, char **str)
{
	struct passwd *usr;
	struct group *grp;

    usr = getpwuid(sb.st_uid);
	grp = getgrgid(sb.st_gid);
    printf("%s %s", usr->pw_name, grp->gr_name);
	printf("\t%lld ", sb.st_size);
	printf("\t%s %s\t%s:%s", str[2], str[1], time[0], time[1]);
	printf("\t%s", (*tmp)->name);
	printf("\n");
}