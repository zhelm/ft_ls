#include "ft_ls.h"

void ft_ls_print_lsub(t_ls **tmp, struct stat sb, t_ls_l val, char **str)
{
	char buff[1024];
	struct passwd *usr;
	struct group *grp;

	usr = getpwuid(sb.st_uid);
	grp = getgrgid(sb.st_gid);
	ft_putspaces(val.links - ft_nbrlen((int)sb.st_nlink) + 2);
	ft_putnbr((int)sb.st_nlink);
	ft_putspaces(val.usrnm - ft_strlen(usr->pw_name) + 1);
	ft_putstr(usr->pw_name);
	ft_putspaces(val.grpnm - ft_strlen(grp->gr_name) + 2);
	ft_putstr(grp->gr_name);
	ft_putspaces(val.size - ft_nbrlen((int)sb.st_size) + 2);
	ft_putnbr((int)sb.st_size);
	ft_print_l_time(str);
	ft_putstr((*tmp)->name);
	if (S_ISLNK(sb.st_mode))
	{
		ft_putstr(" -> ");
		readlink((*tmp)->name, buff, sizeof(buff));
		ft_putstr(buff);
		ft_memset(buff, 0, ft_strlen(buff));
	}
}