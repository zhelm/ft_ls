#include "ft_ls.h"

void ft_ls_print_lsub(t_ls **tmp, struct stat sb, t_ls_l val)
{
	struct passwd *usr;
	struct group *grp;

    usr = getpwuid(sb.st_uid);
	grp = getgrgid(sb.st_gid);
	ft_putspaces(val.links - ft_strlen((ft_itoa((int)sb.st_nlink))) + 1);
	ft_putnbr((int)sb.st_nlink);
	ft_putspaces(val.usrnm - ft_strlen(usr->pw_name) + 1);
    ft_putstr(usr->pw_name);
	ft_putspaces(val.grpnm - ft_strlen(grp->gr_name) + 1);
	ft_putstr(grp->gr_name);
	ft_putspaces(val.size - ft_strlen(ft_itoa((int)sb.st_size) + 1));
	ft_putnbr((int)sb.st_size);
	
}