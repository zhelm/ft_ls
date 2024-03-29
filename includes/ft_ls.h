/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 07:31:01 by zhelm             #+#    #+#             */
/*   Updated: 2019/08/21 12:08:25 by event            ###   ########.fr       */
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
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/errno.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct	s_ls
{
	char			*directory;
	char			*name;
	struct s_ls		*next;
	struct s_ls		*prev;
}				t_ls;

typedef struct	s_ls_l
{
	size_t links;
	size_t usrnm;
	size_t grpnm;
	size_t size;
}				t_ls_l;

typedef struct	s_argv
{
	int		*ret;
	int		*i;
	int		*argc;
	char	*flags;
}				t_argv;

void			ft_mergesort(t_ls **head, char *flags, int i);
void			ft_merge_sort_list(t_ls **head, char *flags);
void			ft_isdir_rec(char *dir);
size_t			ft_size_t_len(size_t n);
void			ft_put_size_t(size_t n);
void			ft_print_err(t_ls **er, char *flags);
void			ft_erlst(t_ls **er, char *argv);
int				ft_printfiles(t_ls **file, char *flags, t_ls **dir);
int				ft_isdir(char *argv, t_ls **er, int *ret, char *flags);
size_t			ft_intlen(int n);
void			ft_print_l_time(char **str, struct stat *sb);
void			ft_putspaces(size_t i);
t_ls_l			ft_ls_l_analize(t_ls **head, t_ls *tmp);
void			ft_ls_free_tmplist(t_ls **head);
void			ft_ls_print_lsub(t_ls **t, struct stat *s, t_ls_l *v, char *f);
void			ft_ls_lstadd(t_ls **alst, t_ls *new);
t_ls			*ft_ls_lstnew(struct dirent *de, char *dir, char *name);
void			ft_assign_dir(t_ls **head, char *dir);
void			ft_ls_check_file_type(struct stat sb);
void			ft_ls_mode(struct stat sb, t_ls *tmp);
void			ft_ls_print_l(t_ls **head, char *flags, t_ls_l *vals);
void			ft_ls_l(t_ls **head, char *flags);
void			ft_sort_time(t_ls **head, int i);
void			ft_listsort(t_ls **head, char *flags);
void			ft_ls_seg_lstadd(t_ls **head, t_ls **seg, char *dir);
void			ft_printlist(t_ls **tmp, char *flags);
void			ft_ls_mklst(t_ls **segment, t_ls **tmp, char *flags, char *dir);
t_ls			*ft_listrec(char **dir, char *flags);
void			ft_ls_mkflags(char *argv, char *flags);
int				ft_argv_analize(char **argv, char *flags, t_ls **dir, int argc);
void			ft_sortarg_time(t_ls **head, char *flags);
void			ft_argsort(t_ls **dir, char *flags);
char			*ft_ls_error(char c);
int				ft_ls_check_dir(char **argv);
char			*ft_ls_checkflags(char **argv);
int				ft_dorec(t_ls **head, char *flags, char *dir);
#endif
