#include "../includes/ft_ls.h"

char *ft_ls_error(char c)
{
	ft_putstr("ft_ls: invalid option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-Ralrt] [file ...]\n");
	return NULL;
}