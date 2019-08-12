#include "ft_ls.h"

void ft_putspaces(size_t i)
{
	while(i != 0)
	{
		ft_putchar(' ');
		i--;
	}
}