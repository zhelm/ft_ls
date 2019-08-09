#include "ft_ls.h"

char *ft_ls_checkflags(char **argv)
{
	size_t i;
	size_t a;
	char *flags;

	i = 1;
	while(argv[i] && argv[i][0] == '-')
	{
		a = 1;
		while(argv[i][a] != '\0')
		{
			if(argv[i][a] == 'l' || argv[i][a] == 'a' || argv[i][a] == 'r' || argv[i][a] == 'R' || argv[i][a] == 't')
				a++;
			else
			{

				ft_ls_error(argv[i][a]);
				return NULL;
			}
		}
			i++;
	}

	if(!(ft_ls_check_dir(argv)))
		return NULL;

	flags = ft_strnew(8);
	ft_memset(flags, '0', 8);
	flags[9] = '\0';
	return flags;
}