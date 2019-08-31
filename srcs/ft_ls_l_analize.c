#include "../includes/ft_ls.h"

t_ls_l      ft_ls_l_analize(t_ls **head, t_ls *tmp, char *flags)
{
    t_ls_l          ret;
    struct passwd   *usr;
    struct group    *grp;
    struct stat     sb;

    tmp = *head;
    ret.grpnm = 0;
    ret.links = 0;
    ret.size = 0;
    ret.usrnm = 0;
    while (tmp != NULL)
    {
        if (tmp->directory)
            lstat(tmp->directory, &sb);
        else
            lstat(tmp->name, &sb);
        if (((usr = getpwuid(sb.st_uid)) && ft_strlen(usr->pw_name) > ret.usrnm) && flags[0] != '1')
            ret.usrnm = ft_strlen(usr->pw_name);
        else if ((ft_size_t_len(sb.st_uid) > ret.usrnm) || flags[0] == '1')
            ret.usrnm = ft_size_t_len(sb.st_uid);
        if (((grp = getgrgid(sb.st_gid)) && ft_strlen(grp->gr_name) > ret.grpnm) && flags[0] != '1')
            ret.grpnm = ft_strlen(grp->gr_name);
        else if ((ft_size_t_len(sb.st_gid) > ret.grpnm) && flags[0] == '1')
            ret.grpnm = ft_size_t_len(sb.st_gid);
        if (ft_size_t_len(sb.st_nlink) > ret.links)
            ret.links = ft_size_t_len(sb.st_nlink);
        if (ft_size_t_len((sb.st_size)) > ret.size)
            ret.size = ft_size_t_len(sb.st_size);
        tmp = tmp->next;
    }
    return (ret);
}