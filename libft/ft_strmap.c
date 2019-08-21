/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:43:53 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 10:34:44 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*n;

	if (!s || !f)
		return (NULL);
	i = 0;
	n = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (n == NULL)
		return (NULL);
	while (s[i])
	{
		n[i] = f(s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
