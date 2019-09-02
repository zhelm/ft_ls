/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_checkflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:57:32 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/02 08:57:35 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_check(char argv, size_t *a)
{
	if (argv == 'l' || argv == 'a' || argv == 'r' ||
		argv == 'R' || argv == 't' || argv == 'g' ||
		argv == 'A' || argv == 'n' || argv == 'o' ||
		argv == 'f')
		*a = *a + 1;
	else
	{
		ft_ls_error(argv);
		return (-1);
	}
	return (1);
}

char		*ft_ls_checkflags(char **argv)
{
	size_t	i;
	size_t	a;
	char	*flags;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] != '-')
	{
		a = 1;
		while (argv[i][a] != '\0')
		{
			if (ft_check(argv[i][a], &a) == -1)
				return (NULL);
		}
		i++;
	}
	flags = ft_strnew(11);
	ft_memset(flags, '0', 11);
	flags[11] = '\0';
	return (flags);
}
