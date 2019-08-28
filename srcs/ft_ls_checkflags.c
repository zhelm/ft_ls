#include "../includes/ft_ls.h"

char *ft_ls_checkflags(char **argv)
{
	size_t i;
	size_t a;
	char *flags;

	i = 1;
	while(argv[i] && argv[i][0] == '-' && argv[i][1] != '-')
	{
		a = 1;
		while(argv[i][a] != '\0')
		{
			if(argv[i][a] == 'l' || argv[i][a] == 'a' || argv[i][a] == 'r' || argv[i][a] == 'R' || argv[i][a] == 't' || argv[i][a] == 'g' || argv[i][a] == 'A' || argv[i][a] == 'n' || argv[i][a] == 'o' || argv[i][a] == 'f')
				a++;
			else
			{
				ft_ls_error(argv[i][a]);
				return NULL;
			}
		}
		i++;
	}
	flags = ft_strnew(11);
	ft_memset(flags, '0', 11);
	flags[11] = '\0';
	return flags;
}