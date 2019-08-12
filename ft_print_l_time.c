#include "ft_ls.h"

void ft_print_l_time(char **str, char **time)
{
	ft_putchar(' ');
if(ft_strlen(str[2]) != 2)
	ft_putchar(' ');
ft_putstr(str[2]);
ft_putchar(' ');
ft_putstr(str[1]);
ft_putchar(' ');
ft_putstr(time[0]);
ft_putchar(':');
ft_putstr(time[1]);
ft_putstr("  ");
}