/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:03:27 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 11:34:32 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	const char		*b;
	unsigned char	d;
	size_t			i;

	a = (unsigned char *)dst;
	b = (const char *)src;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (a[i] == d)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
