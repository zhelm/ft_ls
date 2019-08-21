/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:23:08 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/12 14:05:49 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	a;
	char	*n;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (NULL);
	n = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + (ft_strlen(s2))) + 1));
	if (n == NULL)
		return (NULL);
	while (s1[i])
	{
		n[i] = s1[i];
		i++;
	}
	while (s2[a])
	{
		n[i] = s2[a];
		a++;
		i++;
	}
	n[i] = '\0';
	return (n);
}
