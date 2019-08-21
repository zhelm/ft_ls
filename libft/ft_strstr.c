/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:49:17 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 07:49:31 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
			while (strh[a + i] == strn[a] && strn[a])
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
