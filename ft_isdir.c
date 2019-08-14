#include "ft_ls.h"

int		ft_isdir(char *argv, char *flags)
{
    char *dir;

    dir = argv;
    DIR *dr;
   
    // else
    // {
        dr = opendir(argv);
        if(dr == NULL)
            return 0;
        closedir(dr);
    // }
    return 1;
}