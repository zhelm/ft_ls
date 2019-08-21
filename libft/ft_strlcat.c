/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:44:06 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 07:44:30 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t a;
	size_t b;

	a = 0;
	i = 0;
	b = ft_strlen(src);
	while (dst[a] && a < dstsize)
		a++;
	if (a + i + 1 < dstsize)
	{
		while (a + i + 1 < dstsize && src[i])
		{
			dst[a + i] = src[i];
			i++;
		}
		dst[a + i] = '\0';
	}
	return (a + b);
}
