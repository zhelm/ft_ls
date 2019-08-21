/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 07:03:30 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 07:29:32 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*s;
	unsigned char	f;

	s = (char *)b;
	f = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		s[i] = f;
		i++;
	}
	return (b);
}
