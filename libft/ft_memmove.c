/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:09:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 07:35:41 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst1;
	unsigned const char	*src1;
	size_t				i;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst1 > src1)
	{
		i = n;
		while (i > 0)
		{
			dst1[i - 1] = src1[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dst1, src1, n);
	return (dst);
}
