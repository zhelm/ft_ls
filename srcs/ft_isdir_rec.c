#include "../includes/ft_ls.h"

void	ft_isdir_rec(char *dir)
{
	DIR *dr;
	if (!(dr = opendir(dir)))
	{
		ft_putstr("ft_ls: ");
		ft_putstr(dir);
		ft_putstr(": ");
		perror("");
	}
	else
		closedir(dr);
}