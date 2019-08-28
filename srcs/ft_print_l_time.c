#include "../includes/ft_ls.h"

void ft_print_l_time(char **str, struct stat *sb)
{
	char **times;

	times = ft_strsplit(str[3], ':');

	ft_putchar(' ');
	if (ft_strlen(str[2]) != 2)
		ft_putchar(' ');
	ft_putstr(str[2]);
	ft_putchar(' ');
	ft_putstr(str[1]);
	ft_putchar(' ');
	if ((time(NULL) - sb->st_mtime) >= 15770000)
	{
		ft_putchar(' ');
		write(1, str[4], 4);
		ft_putchar(' ');
	}
	else
	{
		ft_putstr(times[0]);
		ft_putchar(':');
		ft_putstr(times[1]);
		ft_putchar(' ');
	}
	ft_free_arr((void **)times);
}