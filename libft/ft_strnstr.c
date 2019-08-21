/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:51:18 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/13 08:23:02 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	char	*strh;
	char	*strn;

	strh = (char *)haystack;
	strn = (char *)needle;
	i = 0;
	a = 0;
	if (*strn == '\0')
		return (&*strh);
	while (strh[i])
	{
		if (strh[i] == strn[a])
		{
			while (strh[a + i] == strn[a] && strn[a] && a + i < len)
				a++;
			if (strn[a] == '\0')
				return (&strh[i]);
		}
		else
			a = 0;
		i++;
	}
	return (NULL);
}
