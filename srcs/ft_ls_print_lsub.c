#include "../includes/ft_ls.h"

void ft_ls_print_lsub(t_ls **tmp, struct stat sb, t_ls_l val)
{
	char buff[1024];
	struct passwd *usr;
	struct group *grp;
	(void)tmp;
	char **str;

	ft_putstr("11");
	str = NULL;
	ft_putstr("22");
	if(ctime(&sb.st_mtime) != NULL)
		str = ft_strsplit(ctime(&sb.st_mtime), ' ');
	ft_putstr("33");
	ft_putspaces(val.links - ft_intlen((int)sb.st_nlink) + 2);
	ft_putchar('1');
	// ft_putnbr((int)sb.st_nlink);

	ft_putchar('2');
	if (!(usr = getpwuid(sb.st_uid)))
	{
		ft_putspaces(val.usrnm - ft_intlen(sb.st_uid) + 1);
		ft_putnbr(sb.st_uid);
	ft_putchar('3');
	}
	else if (usr->pw_name)
	{
		ft_putspaces(val.usrnm - ft_strlen(usr->pw_name) + 1);
		ft_putstr(usr->pw_name);
	ft_putchar('4');
	}
	if (!(grp = getgrgid(sb.st_gid)))
	{
		ft_putspaces(val.grpnm - ft_intlen(sb.st_gid) + 2);
		ft_putnbr(sb.st_gid);
	ft_putchar('5');
	}
	else if(grp->gr_name)
	{
		ft_putspaces(val.grpnm - ft_strlen(grp->gr_name) + 2);
		ft_putstr(grp->gr_name);
	ft_putchar('6');
	}
	ft_putchar('7');
	ft_putspaces(val.size - ft_size_t_len(sb.st_size) + 2);
	ft_put_size_t(sb.st_size);
	ft_putchar('8');
	ft_print_l_time(str);
	ft_putchar('9');
	ft_putstr((*tmp)->name);
	if (S_ISLNK(sb.st_mode))
	{
		ft_putstr(" -> ");
		if((readlink((*tmp)->name, buff, sizeof(buff)) != -1))
		{
			ft_putstr(buff);
			ft_memset(buff, 0, ft_strlen(buff));
		}
		else if((readlink((*tmp)->directory, buff, sizeof(buff)) != -1))
		{
			ft_putstr(buff);
			ft_memset(buff, 0, ft_strlen(buff));
		}
	}
}