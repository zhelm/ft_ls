#include "../includes/ft_ls.h"

size_t  ft_intlen(int n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}