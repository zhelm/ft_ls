#include "ft_ls.h"

int ft_isdir(char *argv, char *flags, t_ls **er)
{
    char *dir;
    struct stat sb;

    dir = argv;
    DIR *dr;
    lstat(argv, &sb);
    if (S_ISREG(sb.st_mode))
        return 2;
    else
    {
        dr = opendir(argv);
        if (dr == 0)
        {
            ft_erlst(er, argv);
            return 0;
        }
        closedir(dr);
        return 1;
    }
}