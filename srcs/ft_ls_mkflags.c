#include "../includes/ft_ls.h"

void ft_bonus_flags(char argv, char *flags)
{
	if (argv == 'g')
	{
		flags[7] = '1';
		flags[2] = '1';
	}
	else if (argv == 'A' && flags[10] != '1')
	{
		flags[6] = '1';
		flags[1] = '1';
	}
	else if (argv == 'n')
	{
		flags[7] = '1';
		flags[0] = '1';
	}
	else if (argv == 'o')
	{
		flags[7] = '1';
		flags[9] = '1';
	}
	else if (argv == 'f' || (argv == 'A' && flags[10] == '1'))
	{
		flags[1] = (flags[1] == '1' && argv == 'A') ? '1' : '0';
		flags[10] = '1';
		flags[6] = '1';
	}
}
void ft_ls_mkflags(char *argv, char *flags)
{
	size_t a;
	a = 1;
	while (argv[a])
	{
		if (argv[a] == 'l' || argv[a] == 'r' || argv[a] == 't' || argv[a] == 'a' || argv[a] == 'R' || argv[a] == 'g' || argv[a] == 'A' || argv[a] == 'n' || argv[a] == 'o' || argv[a] == 'f')
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
			else if (argv[a] == 'g' || argv[a] == 'A' || argv[a] == 'n' || argv[a] == 'o' || argv[a] == 'f')
				ft_bonus_flags(argv[a], flags);
			a++;
		}
		else
			exit(EXIT_FAILURE);
	}
}