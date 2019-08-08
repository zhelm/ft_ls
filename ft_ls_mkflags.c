#include "ft_ls.h"

void ft_ls_mkflags(char *argv, char *flags)
{
	size_t a;

	a = 1;
	while (argv[a])
	{
		if (argv[a] == 'l' || argv[a] == 'r' || argv[a] == 't' || argv[a] == 'a' || argv[a] == 'R')
		{
			if (argv[a] == 'l')
				flags[7] = '1';
			else if (argv[a] == 'a')
				flags[6] = '1';
			else if (argv[a] == 'r')
				flags[5] = '1';
			else if (argv[a] == 't')
				flags[4] = '1';
			else if (argv[a] == 'R')
				flags[3] = '1';
			a++;
		}
		else
			exit(EXIT_FAILURE);
	}
}