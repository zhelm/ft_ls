/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 07:31:01 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/24 07:32:01 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "libft.h"

typedef struct  st_ls
{
	char *directory;
	char *name;//this must be made into char
	struct st_ls *next;
	struct st_ls *prev;
}				t_ls;
void ft_ls_lstadd(t_ls **alst, t_ls *new);
t_ls *ft_ls_lstnew(struct dirent *de, char *dir);
#endif
