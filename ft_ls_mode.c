#include "ft_ls.h"

void ft_ls_mode(struct stat sb)
{
	size_t i;

	i = -1;
	while (++i <= 8)
	{
		if ((sb.st_mode & S_IRUSR) && i == 0)
			ft_putchar('r');
		else if ((sb.st_mode & S_IWUSR) && i == 1)
			ft_putchar('w');
		else if ((sb.st_mode & S_IXUSR) && i == 2)
		{
			if (sb.st_mode & S_ISVTX)
				ft_putchar('s');
			else
				ft_putchar('x');
		}
		else if ((sb.st_mode & S_IRGRP) && i == 3)
			ft_putchar('r');
		else if ((sb.st_mode & S_IWGRP) && i == 4)
			ft_putchar('w');
		else if ((sb.st_mode & S_IXGRP) && i == 5)
		{
			if (sb.st_mode & S_ISVTX)
				ft_putchar('s');
			else
				ft_putchar('x');
		}
		else if ((sb.st_mode & S_IROTH) && i == 6)
			ft_putchar('r');
		else if ((sb.st_mode & S_IWOTH) && i == 7)
			ft_putchar('w');
		else if ((sb.st_mode & S_IXOTH) && i == 8)
		{
			if (sb.st_mode & S_ISVTX)
				ft_putchar('s');
			else
				ft_putchar('x');
		}
		else
			ft_putchar('-');
	}
}