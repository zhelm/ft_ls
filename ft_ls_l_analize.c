#include "ft_ls.h"

t_ls_l    ft_ls_l_analize(t_ls **head, t_ls *tmp)
{
    t_ls_l ret;
    struct passwd *usr;
    struct group *grp;
    struct stat sb;
    
    tmp = *head;

    ret.grpnm = 0;
    ret.links = 0;
    ret.size = 0;
    ret.usrnm = 0;
    while(tmp != NULL)
    {
        if(tmp->directory)
            lstat(tmp->directory, &sb);
        else
            lstat(tmp->name, &sb);
        if(!(usr = getpwuid(sb.st_uid)))
            ret.usrnm = ft_nbrlen(sb.st_uid);
	    else if(usr->pw_name && ft_strlen(usr->pw_name) > ret.usrnm)
            ret.usrnm = ft_strlen(usr->pw_name);
        if(!(grp = getgrgid(sb.st_gid)))
        ret.grpnm = ft_nbrlen(sb.st_uid);
        else if(usr->pw_name && ft_strlen(grp->gr_name) > ret.grpnm)
            ret.grpnm = ft_strlen(grp->gr_name);
        if(ft_nbrlen(sb.st_nlink) > ret.links)
            ret.links = ft_nbrlen(sb.st_nlink); 
        if(ft_nbrlen((int)sb.st_size) > ret.size)
            ret.size = ft_nbrlen(sb.st_size);
        tmp = tmp->next;
    }
    return ret;
}