#include "ft_ls.h"

t_ls_l    *ft_ls_l_analize(t_ls **head)
{
    t_ls_l *ret;
    t_ls *tmp;
    struct passwd *usr;
    struct group *grp;
    struct stat sb;
    
    tmp = *head;

    ret->grpnm = 0;
    ret->links = 0;
    ret->size = 0;
    ret->usrnm = 0;
    while(tmp != NULL)
    {
        lstat(tmp->directory, &sb);
        usr = getpwuid(sb.st_uid);
	    grp = getgrgid(sb.st_gid);
        if(sb.st_nlink > ret->links)
            ret->links = sb.st_nlink;
        if(ft_strlen(usr->pw_name) > ret->usrnm)
            ret->usrnm = ft_strlen(usr->pw_name);
        if(ft_strlen(grp->gr_name) > ret->grpnm)
            ret->grpnm = ft_strlen(grp->gr_name);
        if(sb.st_size > ret->size)
            ret->size = sb.st_size;
            tmp = tmp->next;
    }
    return ret;
}