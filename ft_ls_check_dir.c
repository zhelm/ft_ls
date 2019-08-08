#include "ft_ls.h"

void *ft_ls_check_dir(char **argv)
{
	size_t i;
	DIR *dr;

	i = 1;
	while(argv[i] && *argv[i] == '-' && argv[i][1] != '\0')
		i++;
	while(argv[i])
	{
		dr = opendir(argv[i]);
		if(dr == NULL)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(argv[i]);
			ft_putstr(": ");
			perror("");
		}
		else
			closedir(dr);		
		i++;
	}
}