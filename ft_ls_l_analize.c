#include "ft_ls.h"

t_ls_l    ft_ls_l_analize(t_ls **head, t_ls *tmp)
{
    t_ls_l ret;
    struct passwd *usr;
    struct group *grp;
    struct stat sb;
    char *d;
    
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
        usr = getpwuid(sb.st_uid);
	    grp = getgrgid(sb.st_gid);

        if(ft_strlen((d = (ft_itoa(sb.st_nlink)))) > ret.links)
            ret.links = ft_strlen(d);
        ft_strdel(&d);
        if(ft_strlen(usr->pw_name) > ret.usrnm)
            ret.usrnm = ft_strlen(usr->pw_name);

        if(ft_strlen(grp->gr_name) > ret.grpnm)
            ret.grpnm = ft_strlen(grp->gr_name);

        if(ft_strlen((d = (ft_itoa((int)sb.st_size)))) > ret.size)
            ret.size = ft_strlen(d);
        ft_strdel(&d);
        
        tmp = tmp->next;
    }
    return ret;
}