#include "ft_ls.h"

void	ft_ls_mklst(t_ls **segment, t_ls **tmp, char *flags, char *dir)
{
	struct dirent *de;
	DIR *dr;

	dr = opendir(dir);
	while((de = readdir(dr)) != NULL)
	{
		if (!(flags[6] == '0' && *de->d_name == '.') && *tmp == NULL && de != NULL) //maybe a function for the two cases
			*tmp = ft_ls_lstnew(de, NULL, NULL);
		else if (!(flags[6] == '0' && *de->d_name == '.') && de != NULL)
			ft_ls_lstadd(tmp, ft_ls_lstnew(de, NULL, NULL));
		if (!(flags[6] == '0' && *de->d_name == '.') && de)
			ft_assign_dir(tmp, dir);
		if (de->d_type == 4 && flags[3] == '1' && !(flags[6] == '0' && *de->d_name == '.') && strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0)
		{
			if (*segment == NULL)
				*segment = ft_ls_lstnew(de, NULL, NULL);
			else
				ft_ls_lstadd(segment, ft_ls_lstnew(de, NULL, NULL));
			if (de != NULL)
				ft_assign_dir(segment, dir);
		}
	}
	closedir(dr);
}