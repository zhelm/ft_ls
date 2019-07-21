#ifndef FT_LS_H
# define FT_LS_H


# include <unistd.h> 
# include <dirent.h> 
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <stdlib.h>
# include <grp.h>
# include <uuid/uuid.h> 
# include <time.h>
# include <string.h>
# include <stdio.h>

typedef struct  st_ls
{
	struct dirent *de;
	struct stat *sb;
	struct st_ls *next;
}				t_ls;
void ft_ls_lstadd(t_ls **alst, t_ls *new);
t_ls *ft_ls_lstnew(struct stat *sb, struct dirent *de);
#endif