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

# include <stdlib.h>
# include <unistd.h> 
# include <dirent.h> 
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <stdlib.h>
# include <grp.h>
# include <uuid/uuid.h> 
# include <time.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct  st_ls
{
	char *directory;
	char *name;//this must be made into char
	struct st_ls *next;
	struct st_ls *prev;
}				t_ls;

typedef struct st_ls_l
{
	size_t 	links;
	size_t 	usrnm;
	size_t 	grpnm;
	size_t 	size;
}			t_ls_l;

void ft_print_l_time(char **str, char **time);
void 	ft_putspaces(size_t i);
t_ls_l 	ft_ls_l_analize(t_ls **head, t_ls *tmp);
void	ft_ls_free_tmplist(t_ls **head);
void	ft_ls_print_lsub(t_ls **tmp, struct stat sb, t_ls_l val);
void	ft_ls_lstadd(t_ls **alst, t_ls *new);
t_ls	*ft_ls_lstnew(struct dirent *de, char *dir);
void	ft_assign_dir(t_ls **head, char *dir);
void	ft_ls_check_file_type(struct stat sb);
void	ft_ls_mode(struct stat sb);
void	ft_ls_print_l(t_ls **head, struct stat sb);
void	ft_ls_l(t_ls **head);
void	ft_sort_time(t_ls **head, char *flags, int i);
void	ft_listsort(t_ls **head, char *flags);
void	ft_ls_seg_lstadd(t_ls **head, t_ls **seg, char *dir);
void	ft_printlist(t_ls **tmp, char *flags);
void	ft_ls_mklst(t_ls **segment, t_ls **tmp, char *flags, char *dir);
t_ls	*ft_listrec(t_ls **head, char *dir, char *flags);
void	ft_ls_mkflags(char *argv, char *flags);
void	ft_argv_analize(char **argv, char *flags, t_ls **dir);
void	ft_sortarg_time(t_ls **head, char *flags);
void	ft_argsort(t_ls **dir, char *flags);
char	*ft_ls_error(char c);
int		ft_ls_check_dir(char **argv);
char	*ft_ls_checkflags(char **argv);
void	ft_dorec(t_ls **head, char *flags, char *dir);
#endif