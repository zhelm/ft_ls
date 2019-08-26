/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:24:03 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/20 07:56:36 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
	// char	*str;
	// size_t	i;

	// i = 0;
	// str = "(null)";
	// if (!s)
	// {
	// 	while (str[i])
	// 	{
	// 		ft_putchar(str[i]);
	// 		i++;
	// 	}
	// 	// ft_putchar('\n');
	// 	return ;
	// }
	// while (*s)
	// 	ft_putchar(*s++);
	// ft_putchar('\n');
	// if (s != NULL)
    //     while (*s)
    //         ft_putchar(*s++);
}
