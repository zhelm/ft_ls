/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:17:54 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/12 12:47:56 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t len)
{
	size_t	i;
	size_t	b;
	int		a;

	a = 0;
	i = 0;
	b = 0;
	while (s1[a])
		a++;
	while (s1[a] == '\0')
		a++;
	while (s1[i])
		i++;
	while (s2[b] && b < len)
	{
		s1[i] = s2[b];
		b++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
