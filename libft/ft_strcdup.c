/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:03:27 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/12 14:03:14 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s1, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s1)
	{
		while (i < ft_strlen(s1))
		{
			if (s1[i] == c)
			{
				str = ft_strnew(i);
				i = 0;
				while (s1[i] != c)
				{
					str[i] = s1[i];
					i++;
				}
				return (str);
			}
			i++;
		}
	}
	return (NULL);
}
