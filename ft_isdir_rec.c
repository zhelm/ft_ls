#include "ft_ls.h"

void ft_isdir_rec(char *dir)
{
	if(!opendir(dir));
	{
		ft_putstr("ft_ls: cannot open directory '");
		ft_putstr(dir);
		ft_putstr("': ");
		perror("");
	}
}