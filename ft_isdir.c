#include "ft_ls.h"

int ft_isdir(char *argv, t_ls **er, int *ret)
{
    char *dir;
    struct stat sb;

    dir = argv;
    DIR *dr;
    lstat(argv, &sb);
    if (S_ISREG(sb.st_mode))
    {
        if(*ret == 0)
                *ret = 1;
        return 2;
    }
    else
    {
        dr = opendir(argv);
        if (dr == 0)
        {
            if(*ret == 0)
                *ret = 1;
            ft_erlst(er, argv);
            return 0;
        }
        closedir(dr);
        return 1;
    }
}