#include "../includes/ft_ls.h"

void ft_ls_print_lsub(t_ls **tmp, struct stat sb, t_ls_l val, char *flags)
{
	char buff[1024];
	struct passwd *usr;
	struct group *grp;
	(void)tmp;
	char **str;

	str = NULL;
	if(ctime(&sb.st_mtime) != NULL)
		str = ft_strsplit(ctime(&sb.st_mtime), ' ');
	ft_putspaces(val.links - ft_size_t_len(sb.st_nlink) + 2);
	ft_put_size_t(sb.st_nlink);
	ft_putchar(' ');
	if (flags[2] != '1' && (!(usr = getpwuid(sb.st_uid)) || flags[0] == '1'))
	{
		ft_putnbr(sb.st_uid);
		ft_putspaces(val.usrnm - ft_size_t_len(sb.st_uid));
	}
	else if (flags[2] != '1' && usr->pw_name)
	{
		ft_putstr(usr->pw_name);
		ft_putspaces(val.usrnm - ft_strlen(usr->pw_name));
		
	}
	if (flags[9] != '1' && (!(grp = getgrgid(sb.st_gid)) || flags[0] == '1'))
	{
		ft_putstr("  ");
		ft_putnbr(sb.st_gid);
		ft_putspaces(val.grpnm - ft_size_t_len(sb.st_gid));
	}
	else if(flags[9] != '1' && grp->gr_name)
	{
		ft_putstr("  ");
		ft_putstr(grp->gr_name);
		ft_putspaces(val.grpnm - ft_strlen(grp->gr_name) + 2);
	}
	ft_putspaces(val.size - ft_size_t_len(sb.st_size) + 2);
	ft_put_size_t(sb.st_size);
	ft_print_l_time(str, &sb);
	if(flags[8] == '1')
		ft_putchar('"');
	ft_putstr((*tmp)->name);
	if(flags[8] == '1')
		ft_putchar('"');
	size_t count;
	count = 0;
	if (S_ISLNK(sb.st_mode))
	{
		ft_putstr(" -> ");
		if((readlink((*tmp)->name, buff, sizeof(buff)) != -1))
		{
			while(count < ft_strlen_isascii(buff))
				ft_putchar(buff[count++]);
			ft_memset(buff, 0, ft_strlen(buff));
		}
		else if((readlink((*tmp)->directory, buff, sizeof(buff)) != -1))
		{
			while(count < ft_strlen_isascii(buff))
				ft_putchar(buff[count++]);
			ft_memset(buff, 0, ft_strlen(buff));
		}
	}
}