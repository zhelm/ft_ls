#include "../includes/ft_ls.h"

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
			else if (argv[a] == 'g')
			{
				flags[7] = '1';
				flags[2] = '1';
			}
			else if (argv[a] == 'A')//get -l working if statement already done for normal print
			{
				flags[6] = '1';
				flags[1] = '1';
			}
			else if (argv[a] == 'n')//done
			{
				flags[7] = '1';
				flags[0] = '1';
			}
			else if (argv[a] == 'o')//done
			{
				flags[7] = '1';
				flags[9] = '1';
			}
			else if (argv[a] == 'f')//done
			{
				flags[10] = '1';
				flags[6] = '1';
			}
			a++;
		}
		else
			exit(EXIT_FAILURE);
	}
}