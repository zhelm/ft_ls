#include "../includes/ft_ls.h"

void	ft_put_size_t(size_t n)
{
	if (n > 9)
		ft_put_size_t(n / 10);
	ft_putchar(n % 10 + 48);
}